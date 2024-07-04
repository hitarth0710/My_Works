echo "Enter number"
read n
echo
i=1
while [ $i -le 10 ]
do
echo "$n * $i = $(expr $n \* $i)"
i=$(expr $i + 1)
done