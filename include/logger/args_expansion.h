#pragma once

#include <boost/format.hpp>

namespace logger
{
    template<typename... Args>
    boost::format expand(boost::format const & fmt, Args... args);

    template<typename... Args>
    std::string expand(const char * format, Args... args)
    {
        return str(expand(boost::format(format), args...));
    }

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
}

