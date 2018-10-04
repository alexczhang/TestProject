#pragma once

#define NONE

#ifdef ALL
#define STACK
#define FRAME
#define STAR
#define WORLD
#define GETNUM
#endif


#ifdef STACK
#include "stack.h"
#endif //STACK

#ifdef FRAME
#include "frame.h"
#endif //FRAME

#ifdef STAR
#include "star.h"
#endif //FRAME

#ifdef WORLD
#include "word.h"
#endif //FRAME

#ifdef GETNUM
#include "getnum.h"
#endif //GETNUM

