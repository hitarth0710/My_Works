#!/bin/bash

# Fork a new child process
echo "Starting a new child process..."
sleep 3 &  # This is a stand-in for a more complex process you might fork

# Capture the PID of the process we just started
PID=$!

# Now in the parent process, wait for the child process to finish
echo "Waiting for child process to finish..."
wait $PID

# Print a message when the child process has finished
echo "Child process has finished."

# Demonstrate exec - this will replace the current shell with /bin/ls
echo "Executing ls..."
exec ls