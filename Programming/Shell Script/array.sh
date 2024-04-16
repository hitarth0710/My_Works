#a shell program to print sum of n numbers given by user as command line argument
echo "Enter the number of elements"
read n

arr=("$@")
sum=0

for ((i=0; i<n; i++))
do
    echo "Enter Number:"
    read num
    arr[i]=$num
done

# Loop through the array
for num in "${arr[@]}"
do
    # Add each number to the sum
    sum=`expr $sum + $num`
done

# Print the sum
echo "The sum is: $sum"

