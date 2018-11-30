#!/bin/bash

gcc time_main.c
gcc -shared -fPIC -o time_hack.dylib time_hack.c
DYLD_INSERT_LIBRARIES=$PWD/time_hack.dylib DYLD_FORCE_FLAT_NAMESPACE=1 ./a.out
