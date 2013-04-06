#pragma once

#include <boost/format.hpp>

namespace logger
{
    template<typename... Args>
    boost::format expand(boost::format fmt, const Args&... args);

    template<>
    inline boost::format expand(boost::format fmt)
    {
        return fmt;
    }

    template<typename Arg, typename... Rest>
    boost::format expand(boost::format fmt, const Arg& arg, const Rest&... rest)
    {
        return expand(fmt % arg, rest...);
    }

    template<typename... Args>
    std::string expand(const char * format, Args... args)
    {
        return str(expand(boost::format(format), args...));
    }
}

