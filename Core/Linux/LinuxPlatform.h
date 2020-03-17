#pragma once

// Base defines, must define these for the platform, there are no defaults
#ifndef PLATFORM_DESKTOP
	#define PLATFORM_DESKTOP					1
#endif

#include "Unix/UnixPlatform.h"

#define PLATFORM_GLOBAL_LOG_CATEGORY			LogLinux