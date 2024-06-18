

# Ask for marks
echo "Enter marks for subject 1:"
read sub1
echo "Enter marks for subject 2:"
read sub2
echo "Enter marks for subject 3:"
read sub3

# Calculate total marks
total=$((sub1 + sub2 + sub3))
echo "Total marks: $total"


# Calculate percentage
percentage=$((total / 3))
echo "Percentage: $percentage%"

# Determine class
if (( percentage >= 70 )); then
    echo "Class: First Class"
elif (( percentage >= 60 )); then
    echo "Class: Second Class"
elif (( percentage >= 50 )); then
    echo "Class: Third Class"
else
    echo "Class: Fail"
fi
