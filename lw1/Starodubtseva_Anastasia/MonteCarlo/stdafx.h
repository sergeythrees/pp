#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include "windows.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Messenger.h"

static const int MIN_THREAD_COUNT = 1;
static const int MAX_THREAD_COUNT = 64;
static const int MIN_ITERATION_COUNT = 0;
static const size_t CIRCLE_RADIUS = 1;
static const size_t DIAMETER = 2 * CIRCLE_RADIUS;
