#pragma once

#include <boost/chrono/process_cpu_clocks.hpp>
#include "block.h"

namespace logger
{
    struct stopwatch : block
    {
        template<typename... Args>
        stopwatch(const char * format, Args... args)
            : block(format, args...)
            , start(clock_t::now())
        {}

        ~stopwatch();

    private:
        typedef boost::chrono::process_real_cpu_clock clock_t;

    private:
        clock_t::time_point start;
    };
}

