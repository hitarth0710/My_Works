#!/bin/bash

# Display all executable files
echo "Executable files:"
find . -maxdepth 1 -perm /a=x -type f -exec echo {} \;

# Display all directories
echo "Directories:"
find . -maxdepth 1 -type d -exec echo {} \;

# Display all zero-sized files
echo "Zero-sized files:"
find . -maxdepth 1 -type f -size 0 -exec echo {} \;