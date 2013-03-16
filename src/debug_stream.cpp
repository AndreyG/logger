#include "stdafx.h"

#include "logger/debug_stream.h"

namespace logger
{
    debug_stream::debug_stream(stream_type st, message_type mt)
        : type_(mt)
        , deferred_(st == START_BLOCK)
    {
        switch (st)
        {
        case START_BLOCK:
            if (!is_first_.empty() && !is_first_.top())
            {
                for (size_t i = indent_; i != 0; --i)
                   std::cout << "|   ";
                std::cout << "\n";

                last_deferred_ = false;
                last_indent_ = indent_;
            }
            if (is_first_.empty())
                is_first_.push(false);
            else
                is_first_.top() = false;
            is_first_.push(true);
            break;
        case FINISH_BLOCK:
            --indent_;
            is_first_.pop();
            break;
        case REGULAR: break;
        }
    }

	debug_stream::~debug_stream()
	{
        static const char * color[] =
        {
            "\033[0;37m", 
            "\033[0;32m", 
            "\033[0;31m" 
        };

        using std::cout;

        if (last_deferred_ && (last_indent_ != indent_))
            cout << "\n";

        if (!last_deferred_ || (last_indent_ != indent_))
        {
           cout << color[INFO];
           for (size_t i = indent_; i != 0; --i)
              cout << "|   ";
        }

        cout << color[type_] << ss_.str();

        if (deferred_)
           cout.flush();
        else
           cout << std::endl;

        last_deferred_ = deferred_;
        last_indent_ = indent_;

        if (deferred_)
            ++indent_;
	}

    size_t debug_stream::indent_ = 0, debug_stream::last_indent_;
    bool debug_stream::last_deferred_ = false;

    std::stack< bool > debug_stream::is_first_;
} 

