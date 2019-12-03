#!/bin/bash

# This only works if you are in the root of the mavlink library directory

if [ -z "$1" ]; then
    echo specify dialect
    exit 1
fi

# Get dialect from arg 1, remove trailing slash if present
dialect=${1%/}

if [ ! -d "$dialect" ]; then
   echo $dialect is not a subdirectory
   exit 1
fi

# If the directory is called mavlink2, output mavlink2.h
output="mavlink.h"
if [[ "$PWD" =~ "mavlink2" ]]; then
    output="mavlink2.h"
fi

# Copy the file and convert it as we do
cat $dialect/mavlink.h | awk -v subdir=$dialect 'match($0, /(#include.*)"(.*)"/, xx) {print xx[1] "\"" subdir "/" xx[2] "\"";next}{print $0}' > $output
