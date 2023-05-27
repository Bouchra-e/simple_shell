#!/bin/bash

directory="${1:-.}"

if [ ! -d "$directory" ]; then
  echo "the repository does not exist"
  exit 1
fi

ls -al "$directory"
