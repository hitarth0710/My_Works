#!/bin/bash

# Function to display menu
function display_menu {
    echo "a. Display calendar of current month"
    echo "b. Display today’s date and time"
    echo "c. Display usernames those are currently logged in the system"
    echo "d. Display your name at given x, y position"
    echo "e. Display your terminal number"
    echo "q. Quit"
}

# Main loop
while true
do
    display_menu
    read -p "Choose an option: " option
    case $option in
        a)
            cal
            ;;
        b)
            date
            ;;
        c)
            who
            ;;
        d)
            read -p "Enter your name: " name
            read -p "Enter x position: " x
            read -p "Enter y position: " y
            tput cup $y $x
            echo $name
            ;;
        e)
            tty
            ;;
        q)
            break
            ;;
        *)
            echo "Invalid option"
            ;;
    esac
done