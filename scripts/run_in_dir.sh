#!/bin/bash
BUILDDIR=$(pwd)
cd $1

COMMAND=""
for (( i=2; i<=$#; i+=1 ))
do
    COMMAND=$COMMAND"${!i} "
done

if [[ "$(uname -s)" =~ ^MSYS_NT.* ]]; then
	COMMAND="${COMMAND//\\//}"
fi

eval $COMMAND
cd $BUILDDIR
