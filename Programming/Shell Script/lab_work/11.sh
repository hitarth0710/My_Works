#!/bin/bash

# Ask for the string
read -p "Enter a string: " str

# Remove spaces
str=${str// /}

# Reverse the string
rev=$(echo "$str" | rev)

# Check if the string is a palindrome
if [ "$str" = "$rev" ]; then
    echo "The string is a palindrome."
else
    echo "The string is not a palindrome."
fi