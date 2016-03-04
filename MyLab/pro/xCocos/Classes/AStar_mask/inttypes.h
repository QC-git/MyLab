#pragma once
// #include "basecode.h"
// #include "basecode.inl"
typedef unsigned uint32_t;

#undef	SAFE_DELETE
#define SAFE_DELETE(ptr)		{ if(ptr){ try{ delete (ptr); }catch(...){} (ptr) = 0; } }

#undef	SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(ptr)		{ if(ptr){ try{ delete [] (ptr); }catch(...){} (ptr) = 0; } }

#undef	SAFE_RELEASE
#define SAFE_RELEASE(ptr)		{ if(ptr){ try{ (ptr)->Release(); }catch(...){} (ptr) = 0; } }

