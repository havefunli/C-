#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <functional>

using TaskFunc = std::function<void()>;
using Timer    = std::chrono::steady_clock::time_point;

class LoopTimer 
{
public:
    LoopTimer()  = default;
    ~LoopTimer() = default;
    
    // ��Ӷ�ʱ����
    void AddTask(TaskFunc callback, int timeout) 
    {
        auto execute_time = std::chrono::steady_clock::now() + std::chrono::seconds(timeout); // ����ִ��ʱ��
        _tasks.push_back({ execute_time, callback });
    }

    // ���ж�ʱ��
    void Loop() 
    {
        while (true) 
        {
            auto now = std::chrono::steady_clock::now();
            for (auto it = _tasks.begin(); it != _tasks.end(); ++it)
            {
                if (now >= it->_execute_time)
                {
                    it->_call_back;
                    it = _tasks.erase(it);
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

private:
    // ÿһ����ʱ����
    struct Task 
    {
        Timer    _execute_time; // ��ʱ��
        TaskFunc _call_back;   // �ص�����
    };

    std::vector<Task> _tasks;
};
