echo "Enter your Starting number"
read s
echo "Enter your last number"
read l
while [ $s -le $l ]
do
if [ $((s % 2)) -eq 0 ]
then 
sum=`expr $sum + $s`
fi
s=`expr $s + 1`
done
echo "The sum of all the even numbers is $sum"
