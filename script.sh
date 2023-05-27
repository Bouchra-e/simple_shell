#!/bin/bash

directory="$1"
if [ -z "$directory" ]; then
  directory="."
fi

/bin/ls "$directory"
