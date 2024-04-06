echo "Enter your number"
read n
fac=1
while [ $n -ge 1 ]
do
fac=`expr $((fac*n))`
n=`expr $n - 1`
done
echo "Your Factorial is $fac"