echo "Enter your number"
read n

flag=1
i=2

while [ $i -lt $n ]
do
    if [ `expr $n % $i` -eq 0 ]
    then
        flag=0
    fi
    i=`expr $i + 1`
done

if [ $flag -eq 1 ]
then
    echo "$n is a prime number"
else
    echo "$n is not a prime number"
fi
