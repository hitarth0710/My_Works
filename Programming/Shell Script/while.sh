#echo "Enter n"
#read n
#echo "your numbers are"
#i=1
#while [ $i -le $n ]
#do
#echo $i
#i=`expr $i + 1`
#done

echo "Enter your Starting number"
read s
echo "Enter your last number"
read l
echo "Your numbers are"
while [ $s -le $l ]
do
echo $s
s=`expr $s + 1`
done