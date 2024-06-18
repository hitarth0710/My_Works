echo "Enter your number"
read n
echo "Your multiplication table is"
i=1
while [ $i -le 10 ]
do
s=`expr $((n*i))`
echo $n " * " $i " = " $s
i=`expr $i + 1`
done
