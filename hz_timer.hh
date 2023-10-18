/**
 * HZ Timer
 * Make sure a code segment is executed under a specified Hertz rate
 * 
 * Author: Chester Abrahams
 * GitHub: https://github.com/ChesterOfTheSemester/hz_timer.hh
 */

#ifndef HZ_TIMER
#define HZ_TIMER

#include <iostream>
#include <vector>
#include <unordered_map>

class Timer
{
private:
    std::unordered_map<int, std::vector<long long> > stack_lapsed;
    std::unordered_map<int, double> threshold;

public:
    bool test(int hz, int uuid = 0, long long timespan = 1000)
    {
        // Precompute threshold if not available.
        if (threshold.find(uuid) == threshold.end())
            threshold[uuid] = static_cast<double>(timespan) / hz;

        long long now = static_cast<long long>(std::time(NULL)) * 1000;
        long long elapsed = now - (stack_lapsed[uuid].empty() ? 0 : stack_lapsed[uuid].back());

        if (elapsed > threshold[uuid]) {
            stack_lapsed[uuid].push_back(now - (elapsed % static_cast<long long>(threshold[uuid])));
            return true;
        }

        return false;
    }
};

#endif
