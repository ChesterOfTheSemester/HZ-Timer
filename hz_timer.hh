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

class 
{
private:
    std::unordered_map<unsigned int, std::vector<unsigned int> > stack_lapsed;
    std::unordered_map<unsigned int, double> threshold;

public:
    bool test(unsigned int hz, unsigned int uuid = 0, unsigned int timespan = 1000)
    {
        // Precompute threshold if not available.
        if (threshold.find(uuid) == threshold.end())
            threshold[uuid] = static_cast<double>(timespan) / hz;

        unsigned int now = static_cast<unsigned int>(std::time(NULL)) * 1000;
        unsigned int elapsed = now - (stack_lapsed[uuid].empty() ? 0 : stack_lapsed[uuid].back());

        if (elapsed > threshold[uuid]) {
            stack_lapsed[uuid].push_back(now - (elapsed % static_cast<unsigned int>(threshold[uuid])));
            return true;
        }

        return false;
    }
} hz_timer;

#endif
