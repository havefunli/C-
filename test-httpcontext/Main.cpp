#include "Http.hpp"

void test_1()
{
    std::string msg =

        "GET /path/resource HTTP/1.1\r\n"
        "Host: www.example.com\r\n"
        "User-Agent: CustomHttpClient/1.0\r\n"
        "Content-Length: 24\r\n"
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
        "Connection: keep-alive\r\n\r\n"
        "这是一个测试文本"; // 空行结束请求头

    BufferPtr buffer(new Buffer());
    buffer->Write(msg);

    HttpContext context;
    context.ParseHttpRequest(buffer);
    HttpRequest req = context.GetRequest();
    std::cout << req._method << " " << req._path << " " << req._version << std::endl;
    for (auto& pair : req._headers)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << req._body << std::endl;
}

void test_2()
{
    std::string str = "Abcdefg";
    std::vector<std::string> tmp;
    Util::Split(str, " ", tmp);

}

void test_3()
{
    std::string msg =

        "GET /path/resource HTTP/1.1\r\n"
        "Host: www.example.com\r\n"
        "User-Agent: CustomHttpClient/1.0\r\n"
        "Content-Length: 24\r\n"
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
        "Connection: keep-alive\r\n\r\n"
        "这是一个测试文本"; // 空行结束请求头

    Buffer buf;
    buf.Write(msg);


    std::string tmp = buf.ReadAllContent();
    buf.Write(tmp);
    std::cout << buf.ReadAllContent() << std::endl;
}

int main()
{
    // test_1();
    // test_2();
    test_3();
    return 0;
}