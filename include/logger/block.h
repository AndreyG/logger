#pragma once

#include "message_type.h"
#include "args_expansion.h"

namespace logger
{
    struct block
    {
        template<typename... Args>
        block(const char * format, Args... args);

        ~block();

        void finish(std::string const & message, message_type mt);

    private:
        explicit block(std::string const & message);

        bool is_finished_;
    };

    template<typename... Args>
    block::block(const char * format, Args... args)
        : block(expand(format, args...))
    {}
}

#define LOG_BLOCK(args...) \
    logger::block long_unique_block_name(args);

