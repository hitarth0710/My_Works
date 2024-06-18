#!/usr/bin/awk -f

{
    # Split the line into words
    n = split($0, words, " ")

    # Convert each word to uppercase and print it
    for (i = 1; i <= n; i++) {
        printf "%s ", toupper(words[i])
    }

    # Print a newline character
    printf "\n"
}