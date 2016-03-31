#pragma once

#include "x_all.h"

typedef std::function<void(int)> CFuncCb_T;

typedef std::function<void(CFuncCb_T)> CFuncNode_T;

typedef std::vector<CFuncNode_T> CFuncList_T;

void AsyncRun(CFuncList_T& list);