#include "stdafx.h"

#include "logger/block.h"

#include <exception>

#include "logger/debug_stream.h"

namespace logger
{
    block::block(std::string const & message)
        : is_finished_(false)
    {
        debug_stream(debug_stream::START_BLOCK) << message << "... ";
    }

    void block::finish(std::string const & message, message_type mt)
    {
        if (std::uncaught_exception())
            debug_stream(debug_stream::REGULAR, ERROR) << "exception was thrown"; 
        
        debug_stream(debug_stream::FINISH_BLOCK, mt) << message;

        is_finished_ = true;
    }

    block::~block()
    {
        if (!is_finished_)
            finish("done", INFO);
    }
}

