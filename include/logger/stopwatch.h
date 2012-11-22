#ifndef _STOPWATCH_H_
#define _STOPWATCH_H_

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
        explicit stopwatch(boost::format const &    message);
        ~stopwatch();

    private:
        typedef boost::chrono::process_real_cpu_clock clock_t;

    private:
        clock_t::time_point start;
    };
}

#define SET_STOPWATCH(message) \
    util::stopwatch long_unique_stopwatch_name(message);

#endif /* _STOPWATCH_H_ */
