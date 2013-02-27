#pragma once

#include <chrono>
#include <boost/chrono/process_cpu_clocks.hpp>
#include <boost/format.hpp>

namespace util
{
    struct stopwatch
    {
    public:
        explicit stopwatch(const char *             message);
        explicit stopwatch(std::string const &      message);

        template<typename... Args>
        stopwatch(const char * format, Args... args);

        ~stopwatch();

    private:
        typedef boost::chrono::process_real_cpu_clock clock_t;

    private:
        clock_t::time_point start;
    };

    template<typename... Args>
    boost::format expand(boost::format const & fmt, Args... args);

    template<>
    inline boost::format expand(boost::format const & fmt)
    {
        return fmt;
    }

    template<typename Arg, typename... Rest>
    boost::format expand(boost::format fmt, Arg const & arg, Rest... rest)
    {
        return expand(fmt % arg, rest...);
    }

    template<typename... Args>
    stopwatch::stopwatch(const char * format, Args... args)
        : stopwatch(str(expand(boost::format(format), args...)))
    {}
}

#define SET_STOPWATCH(args...) \
    util::stopwatch long_unique_stopwatch_name(args);

