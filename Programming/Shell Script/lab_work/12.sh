#!/bin/bash

# Ask for the date
read -p "Enter a date (dd-mm-yyyy): " date

# Check if the date is valid
if [[ "$date" =~ ^[0-3][0-9]-[0-1][0-9]-[0-9]{4}$ ]]; then
    echo "The date is valid."
else
    echo "The date is not valid."
fi