echo "Enter your Starting number"
read s
echo "Enter your last number"
read l
echo "Your odd numbers are"
while [ $s -le $l ]
do
if [ $((s % 2)) -ne 0 ]
then
echo $s
fi
s=`expr $s + 1`
done

