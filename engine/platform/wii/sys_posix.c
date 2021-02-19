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
#include "vid_common.h"
#include "menu_int.h"

#include <fat.h>

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

}

void Platform_RunEvents( void )
{

}

void Platform_GetClipboardText( char *buffer, size_t size )
{

}

void Platform_SetClipboardText( const char *buffer, size_t size )
{

}

void GAME_EXPORT Platform_GetMousePos( int *x, int *y )
{
	*x = *y = 0;
}

void Platform_PreCreateMove( void )
{

}

void GAME_EXPORT Platform_SetMousePos(int x, int y)
{

}

void Platform_Vibrate(float life, char flags)
{

}
int Platform_JoyInit( int numjoy )
{
	return 0;
}

void *Platform_GetNativeObject( const char *name )
{
	return NULL;
}

void Platform_Init( void ) {
	printf("\n---Platform-Init---\n");
	if (!fatInitDefault()) {
		printf("Couldn't initialize fat\n");
    } 
}
void Platform_Shutdown( void ) {}


void Platform_MouseMove( float *x, float *y )
{

}

void Platform_EnableTextInput( qboolean enable )
{

}

void SNDDMA_BeginPainting( void )
{

}

void SNDDMA_Submit( void )
{

}

int SNDDMA_GetSoundtime( void )
{

}

qboolean SNDDMA_Init( void )
{

}

void SNDDMA_Shutdown( void )
{

}

// GX probably?

void GL_UpdateSwapInterval( void )
{

}

qboolean  R_Init_Video( const int type )
{

}

void R_Free_Video( void )
{

}

int GL_SetAttribute( int attr, int val )
{

}

int GL_GetAttribute( int attr, int *val )
{

}

void* GL_GetProcAddress( const char *name )
{

}

void GL_SwapBuffers( void )
{

}

qboolean SW_CreateBuffer( int width, int height, uint *stride, uint *bpp, uint *r, uint *g, uint *b )
{

}

void *SW_LockBuffer( void )
{

}

void SW_UnlockBuffer( void )
{

}

vidmode_t* R_GetVideoMode( int num )
{
	return NULL;
}

rserr_t   R_ChangeDisplaySettings( int width, int height, qboolean fullscreen )
{

}

int R_MaxVideoModes( void )
{
	return 0;
}

qboolean VID_SetMode( void )
{

}