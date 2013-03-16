#pragma once

#include <stack>
#include <sstream>

#include "message_type.h"

namespace logger
{
	struct debug_stream
	{
		template<class Data>
		debug_stream& operator << (Data const & data)
		{
			ss_ << data;
			return *this;
		}

        enum stream_type 
        { 
            START_BLOCK, FINISH_BLOCK, REGULAR 
        };

        debug_stream(stream_type t = REGULAR, message_type mt = INFO);
		~debug_stream();

	private:
        message_type type_;
        bool deferred_;

		std::stringstream ss_;

        static size_t indent_, last_indent_;
        static std::stack<bool> is_first_;

        static bool last_deferred_;
	};
}

