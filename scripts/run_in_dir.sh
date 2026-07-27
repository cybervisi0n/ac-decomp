#!/bin/bash
BUILDDIR=$(pwd)
cd $1

COMMAND=""
for (( i=2; i<=$#; i+=1 ))
do
    COMMAND=$COMMAND"${!i} "
done

eval $COMMAND
cd $(BUILDDIR)
