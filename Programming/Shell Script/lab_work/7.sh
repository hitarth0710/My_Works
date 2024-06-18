#!/bin/bash

# Check if any arguments were passed
if [ $# -eq 0 ]; then
    echo "No arguments provided"
    exit 1
fi

# Read arguments into an array
numbers=("$@")

# Sort numbers in descending order
IFS=$'\n' sorted=($(sort -nr <<<"${numbers[*]}"))
unset IFS

# Print sorted numbers
echo "Numbers in descending order:"
printf "%s\n" "${sorted[@]}"