/*
backends.h - backend macro definitions
Copyright (C) 2016 Mittorn

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/
#ifndef BACKENDS_H
#define BACKENDS_H

// video backends (XASH_VIDEO)
#define VIDEO_NULL    0
#define VIDEO_SDL     1
#define VIDEO_ANDROID 2
#define VIDEO_FBDEV   3
#define VIDEO_DOS     4
// half-life wii video backend
#define VIDEO_WII     5


// audio backends (XASH_SOUND)
#define SOUND_NULL     0
#define SOUND_SDL      1
#define SOUND_OPENSLES 2
#define SOUND_ALSA     3
// half-life wii audio backend
#define SOUND_WII     5

// crash handler (XASH_CRASHHANDLER)
#define CRASHHANDLER_NULL     0
#define CRASHHANDLER_UCONTEXT 1
#define CRASHHANDLER_DBGHELP  2
#define CRASHHANDLER_WIN32    3

// input (XASH_INPUT)
#define INPUT_NULL    0
#define INPUT_SDL     1
#define INPUT_ANDROID 2
#define INPUT_EVDEV   3
// half-life wii input backend
#define INPUT_WII     5

// timer (XASH_TIMER)
#define TIMER_NULL  0 // not used
#define TIMER_SDL   1
#define TIMER_LINUX 2
#define TIMER_WIN32 3
#define TIMER_DOS   4

// messageboxes (XASH_MESSAGEBOX)
#define MSGBOX_STDERR  0
#define MSGBOX_SDL     1
#define MSGBOX_ANDROID 2
#define MSGBOX_WIN32   3


// library loading (XASH_LIB)
#define LIB_NULL 0
#define LIB_POSIX 1
#define LIB_WIN32 2
#define LIB_STATIC 3


#endif /* BACKENDS_H */
