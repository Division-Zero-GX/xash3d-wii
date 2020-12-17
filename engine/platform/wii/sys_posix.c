/*
sys_win.c - posix system utils
Copyright (C) 2019 a1batross

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "platform/platform.h"
#include "menu_int.h"

void Platform_Sleep(int msec) {

	usleep( msec * 1000 );
}

double Platform_DoubleTime(void) {

	struct timespec ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);

	return (double) ts.tv_sec + (double) ts.tv_nsec/1000000000.0;
}

void Platform_ShellExecute( const char *path, const char *parms )
{
 //   fprintf("");
}



void Platform_Init( void ) {
	printf("Platform Init");    
}
void Platform_Shutdown( void ) {}
