#!/bin/bash

# Function to display menu
function display_menu {
    echo "1. Search word with grep"
    echo "2. Search pattern with egrep"
    echo "3. Search fixed string with fgrep"
    echo "4. Quit"
}

# Main loop
while true
do
    display_menu
    read -p "Choose an option: " option
    case $option in
        1)
            read -p "Enter a word to search: " word
            grep "$word" filename.txt
            ;;
        2)
            read -p "Enter a pattern to search: " pattern
            egrep "$pattern" filename.txt
            ;;
        3)
            read -p "Enter a fixed string to search: " string
            fgrep "$string" filename.txt
            ;;
        4)
            break
            ;;
        *)
            echo "Invalid option"
            ;;
    esac
done