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
    
    // 添加定时任务
    void AddTask(TaskFunc callback, int timeout) 
    {
        auto execute_time = std::chrono::steady_clock::now() + std::chrono::seconds(timeout); // 计算执行时间
        _tasks.push_back({ execute_time, callback });
    }

    // 运行定时器
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
    // 每一个定时任务
    struct Task 
    {
        Timer    _execute_time; // 定时器
        TaskFunc _call_back;   // 回调函数
    };

    std::vector<Task> _tasks;
};
