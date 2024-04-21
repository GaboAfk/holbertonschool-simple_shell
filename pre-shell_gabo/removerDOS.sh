#!/bin/bash

gcc DOSdeleter.c -o DOSdeleter

echo "file?"
read $file

./DOSdeleter "$file" "$file.DOS"

./remove_m.sh "$file.DOS"