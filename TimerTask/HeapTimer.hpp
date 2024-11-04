#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <queue>
#include <functional>

using TaskFunc = std::function<void()>;
using Timer    = std::chrono::steady_clock::time_point;

class HeapTimer 
{
public:
    void AddTask(TaskFunc callback, int timeout)
    {
        auto execute_time = std::chrono::steady_clock::now() + std::chrono::seconds(timeout); // 计算执行时间
        _tasks.emplace(execute_time, callback);
    }

    void Loop() 
    {
        while (true) 
        {
            auto now = std::chrono::steady_clock::now();
            while (! _tasks.empty() && _tasks.top()._execute_time <= now) 
            {
                auto task = _tasks.top();
                _tasks.pop();
                task._call_back();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

private:
    struct TimerTask
    {
        TimerTask(Timer time, TaskFunc callback)
            : _execute_time(time), _call_back(callback)
        {}

        bool operator<(const TimerTask& other) const 
        {
            return _execute_time > other._execute_time;
        }

        Timer    _execute_time; // 定时器
        TaskFunc _call_back;    // 回调函数
    };

    std::priority_queue<TimerTask> _tasks;
};



