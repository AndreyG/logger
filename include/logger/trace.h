#pragma once

#include "debug_stream.h"

#define TRACE(var) \
    util::debug_stream() << #var << " = " << var;
