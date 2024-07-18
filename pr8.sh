#!/bin/bash

# Check if filename is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 filename"
    exit 1
fi

filename=$1

# Count lines without vowels
count=$(grep -civ '[aeiou]' "$filename")

echo "Number of lines without vowels in $filename: $count"
