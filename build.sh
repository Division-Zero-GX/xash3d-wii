#!/bin/sh

# No parameteres is a debug compile and run
if [ $# -lt 1 ] ; then
   	./waf build || exit 1
	./waf install
	elf2dol OUT/lib/xash3d/xash OUT/lib/xash3d/xash.dol
	wiiload OUT/lib/xash3d/xash.dol
	# Hardcoded path, beware
fi;

# ADD - Clean build
#if [ $1 == "" ]
#then
#fi

#./waf clean
#./waf configure -T release -WII --prefix=OUT --low-memory-mode=1 --single-binary
#./waf build
