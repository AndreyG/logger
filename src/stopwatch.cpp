#include "stdafx.h"

#include "logger/stopwatch.h"

namespace logger
{
    stopwatch::~stopwatch()
    {
        clock_t::time_point finish = clock_t::now();

        auto duration = boost::chrono::duration_cast<boost::chrono::milliseconds>(finish - start);
        auto message = boost::lexical_cast<std::string>(duration.count() / 1000.0) + " sec"; 
        block::finish(message, INFO);
    }
}

