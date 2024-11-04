#pragma once
#include <iostream>
#include <chrono>
#include <list>
#include <thread>
#include <vector>
#include <functional>

using TaskFunc = std::function<void()>;
using Wheel = std::vector<std::list<TaskFunc>>;

class TimeWheel 
{
public:
    TimeWheel(int capacity) 
        : _tick(0), _capacity(capacity), _wheel(_capacity)
    {}

    void AddTask(TaskFunc callback, int timeout) 
    {
        int index = (_tick + timeout) % _capacity;
        _wheel[index].push_back(callback);
    }

    void Loop() 
    {
        while (true) 
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            _tick = (_tick + 1) % _capacity;    // 秒针移动
            
            // 执行该位置的函数
            for (auto& func : _wheel[_tick])
            {
                func();
            }
            // 清除
            _wheel[_tick].clear();
        }
    }

private:
    int   _tick;     // 秒针
    int   _capacity; // 最大容量（刻度）
    Wheel _wheel;    // 时间轮 
};