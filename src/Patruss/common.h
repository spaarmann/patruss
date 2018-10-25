#pragma once

#include "util/log.h"

#define DELETE_COPY_AND_MOVE(classname) \
	classname(const classname& other) = delete; \
	classname(const classname&& other) = delete; \
	classname operator=(const classname& other) = delete; \
	classname operator=(const classname&& other) = delete;