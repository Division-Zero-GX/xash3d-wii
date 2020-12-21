#!/bin/sh
./waf clean
./waf configure -T release -WII --prefix=OUT --low-memory-mode=1 --single-binary
./waf build
