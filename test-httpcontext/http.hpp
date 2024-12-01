#pragma once
#include "Util.hpp"
#include "Buffer.hpp"
#include <string>
#include <sstream>
#include <unordered_map>

class HttpRequest;

using HeaderMap = std::unordered_map<std::string, std::string>;
using ParamsMap = std::unordered_map<std::string, std::string>;

const int DefaultSize = 1024;
const std::string DefaultLineSep = "\r\n";
const std::string DefaultHeaderSep = ": ";

class HttpRequest
{
public:
    std::string _method;  // ���󷽷�
    std::string _path;    // ��Դ·��
    std::string _version; // Э��汾
    std::string _body;    // ��������
    HeaderMap   _headers; // ����ͷ
    ParamsMap   _params;  // �������

    bool HasHeader(const std::string& key)
    {
        auto iter = _headers.find(key);
        return iter != _headers.end();
    }

    void SetHeader(const std::string& key, const std::string& val)
    {
        if (_headers.find(key) == _headers.end())
        {
            _headers.insert(std::make_pair(key, val));
        }
    }

    std::string GetHeader(const std::string& key)
    {
        auto iter = _headers.find(key);
        if (iter != _headers.end())
        {
            return iter->second;
        }
        return "";
    }

    size_t GetContentLength()
    {
        auto iter = _headers.find("Content-Length");
        if (iter != _headers.end())
        {
            return std::stoi(GetHeader("Content-Length"));
        }
        return 0;
    }

    /*
    �ض����ݵĻ�ȡ:
    ��̬��Դ   -> ��Դ����
    �ض��Ĺ��� -> ���ܷ���
    */
    std::string GetSrc()
    {
        auto pos = _path.find_last_of('/');
        return _path.substr(pos + 1);
    }

    // �жϳ�������
    bool Close()
    {
        // û��Connection�ֶΣ�������Connection����ֵ��close�����Ƕ����ӣ�������ǳ�����
        if (HasHeader("Connection") == true && GetHeader("Connection") == "keep-alive")
        {
            return false;
        }
        return true;
    }

    // �������
    void Clear()
    {
        _method = _path = _version = _body = "";
        _headers.clear();
        _params.clear();
    }
};

class HttpResponse
{
public:
    HttpResponse()
        : _redirect(false), _status(200)
    {}

    bool HashHeader(const std::string& key)
    {
        auto iter = _headers.find(key);
        return iter != _headers.end();
    }

    void SetHeader(const std::string& key, const std::string& val)
    {
        if (_headers.find(key) == _headers.end())
        {
            _headers.insert(std::make_pair(key, val));
        }
    }

    std::string GetHeader(const std::string& key)
    {
        auto iter = _headers.find(key);
        if (iter != _headers.end())
        {
            return iter->second;
        }
        return "";
    }

    void SetContent(const std::string& content, const std::string& type)
    {
        _body = content;
        SetHeader("Content-Length", std::to_string(content.size()));
        SetHeader("Content-Type", type);
    }

    void SetRedirect(std::string& url, int status = 302)
    {
        _status = status;
        _redirect = true;
        _reurl = url;
        SetHeader("Location", url);
    }

    // ����һ�� HTTP ��Ӧ����
    void InitMsg(std::string& msg)
    {
        std::ostringstream responseStream;
        // �汾 ״̬�� ״̬������
        responseStream << "HTTP/1.1 " << _status << " " << Util::getHttpStatusDescription(_status) << DefaultLineSep;
        // ͷ����Ϣ
        for (auto& header : _headers)
        {
            responseStream << header.first << DefaultHeaderSep << header.second << DefaultLineSep;
        }
        // ���� + ����
        responseStream << DefaultLineSep << _body;

        msg = responseStream.str();
    }

    // ����״̬��
    void SetStatus(int status) { _status = status; }

private:
    int          _status;        // ״̬��
    bool         _redirect;      // �ض����־
    std::string  _reurl;         // �ض��� url
    std::string  _body;          // ��Ӧ����
    HeaderMap    _headers;       // ��Ӧͷ
};

enum HttpRecvStatus
{
    LINE,
    HEAD,
    BODY,
    OVER,
    ERROR
};

class HttpContext
{
private:
    void RecvHttpLine(BufferPtr buffer)
    {

        std::string line = buffer->PeekLine();
        Util::RemoveNewline(line);
        if (line == "Line Empty...")
        {
            return;
        }
        ParseHttpLine(line);
        buffer->Update(); // ������˲���ȡ
        _recv_status = HttpRecvStatus::HEAD;
    }

    // GET /.../index?user=..&passward=.. HTTP/1.1
    void ParseHttpLine(const std::string& line)
    {
        std::vector<std::string> str;
        Util::Split(line, " ", str);
        // ��ȡ��ʽ
        if (line.size() > 0) { _request._method = str[0]; }
        // ��ȡ�汾
        if (line.size() > 2) 
        { 
            _request._version = str[2]; 
        }
        // ��ȡ��Դ·���Ͳ���
        if (line.size() > 1)
        {
            std::string path_params = str[1];
            int pos = path_params.find("?");
            // û�в���
            if (pos == std::string::npos)
            {
                _request._path = path_params;
                return;
            }
            else
            {
                _request._path = path_params.substr(0, pos);
                std::string params = path_params.substr(pos + 1);
                ParamsMap parmap;
                Util::SplitParams(params, parmap);
                _request._params = parmap;
            }
        }
    }

    // key: val\r\nkey: val\r\n\r\n...
    void RecvHttpHeader(BufferPtr buffer)
    {
        while (true)
        {
            std::string header = buffer->ReadLine();
            // ͷ���ֶβ�ȫ
            if (header == "") { return; }
            // "\r\n" ��ʾͷ������
            if (header == "\r\n" || header == "\n") { break; }
            // ȥ�����з�
            Util::RemoveNewline(header);
            ParseHttpHeader(header);
        }
    }

    void ParseHttpHeader(const std::string& header)
    {
        // �ָ��ֵ��
        size_t sep_pos = header.find(DefaultHeaderSep);
        if (sep_pos == std::string::npos)
        {
            _status = 400;
            return;
        }
        std::string key = header.substr(0, sep_pos);
        std::string value = header.substr(sep_pos + DefaultHeaderSep.size());

        // ���뵽����ͷ��
        if (!key.empty() && !value.empty())
        {
            _request._headers.insert(std::make_pair(key, value));
            return;
        }
        _status = 400;
    }

    void RecvHttpBody(BufferPtr buffer)
    {
        size_t len = _request.GetContentLength();
        // ���Ĳ�����
        if (len == 0)
        {
            _recv_status = HttpRecvStatus::OVER;
            return;
        }

        // ��Ҫ�Ĵ�С = ʵ�ʴ�С - �Ѿ����ܴ�С
        // �������Ĵ�С�Ѿ��㹻
        int need_size = len - _request._body.size();
        if (buffer->ReadableBytes() >= need_size)
        {
            char tmp[DefaultSize];
            buffer->Read(tmp, need_size);
            _request._body += tmp;
            _recv_status = HttpRecvStatus::OVER;
            return;
        }
        // �������Ĵ�С���㹻����ȡ����
        _request._body += buffer->ReadAllContent();
    }

public:
    HttpContext()
        : _status(200)
        , _recv_status(LINE)
    {}

    int RepStatus() { return _status; }

    int RecvStatus() { return _recv_status; }

    HttpRequest& GetRequest() { return _request; }

    void ParseHttpRequest(BufferPtr buffer)
    {
        switch (_recv_status)
        {
        case HttpRecvStatus::LINE:
            RecvHttpLine(buffer);
        case HttpRecvStatus::HEAD:
            RecvHttpHeader(buffer);
        case HttpRecvStatus::BODY:
            RecvHttpBody(buffer);
        }
    }

    void Clear()
    {
        _status = 200;
        _recv_status = HttpRecvStatus::LINE;
        _request.Clear();
    }

private:
    int             _status;
    HttpRecvStatus  _recv_status;
    HttpRequest     _request;
};