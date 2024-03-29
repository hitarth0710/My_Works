echo "Enter the number"
read n
if [[ $n -gt 0 ]]
then 
echo "Entered number is positive"
elif [[ $n -eq 0 ]]
then
echo "Entered number is zero"
else
echo "Entered number is negative"
fi
