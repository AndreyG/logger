#include "stdafx.h"
#include "logger/stopwatch.h"
#include "logger/debug_stream.h"

namespace util
{
    stopwatch::stopwatch( const char * message )
    {
		if (!debug_stream::is_first())
			debug_stream() << "";
        debug_stream() << message << "...";
		debug_stream::inc_indent();
        start = clock_t::now();
    }

    stopwatch::stopwatch( std::string const & message ) 
        : stopwatch(message.c_str()) 
    {}
    
    stopwatch::stopwatch( boost::format const & message )
        : stopwatch(message.str())
    {}

    stopwatch::~stopwatch()
    {
        using namespace boost::chrono;

        clock_t::time_point finish = clock_t::now();
		debug_stream::dec_indent();
        auto duration = duration_cast<milliseconds>(finish - start);
        debug_stream() << (duration.count() / 1000.0) << " sec";
    }
}
