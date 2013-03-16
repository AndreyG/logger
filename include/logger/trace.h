#pragma once

#include "debug_stream.h"

#define TRACE(var) \
    logger::debug_stream() << #var << " = " << var;
