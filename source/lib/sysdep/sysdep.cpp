#include "precompiled.h"

#include "sysdep.h"

// portable debug output routines. Win32 offers better versions, which
// override these.

#ifndef _WIN32

// portable output routines (win.cpp overrides these)

void display_msg(const char* caption, const char* msg)
{
	fprintf(stderr, "%s: %s\n", caption, msg);
}

void wdisplay_msg(const wchar_t* caption, const wchar_t* msg)
{
	fwprintf(stderr, L"%ls: %ls\n", caption, msg);
}



void debug_out(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
	fflush(stdout);
}


void check_heap()
{
}

#endif	// #ifndef _WIN32

#ifdef _MSC_VER

double round(double x)
{
	return (long)(x + 0.5);
}

#endif
