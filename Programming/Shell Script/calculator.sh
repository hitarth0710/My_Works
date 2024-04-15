echo "CALCULATOR"
while true
do 
echo "1. Addition "
echo "2. Substraction " 
echo "3. Multiplication " 
echo "4. Division "
echo "5. Exit"
echo "Enter Your choice :"
read option
if [ $option -eq 5 ]
then
break
fi
echo "Enter number 1 :"
read a
echo "Enter number 2 :"
read b
case $option in
    1) c=`expr $a + $b`
       echo "Addition of the numbers is $c" ;;
    2) c=`expr $a - $b`
       if [ $c -lt 0 ]
       then
       echo "Answer is negative so pls again enter your numbers"
       else
       echo "Subtraction of given number is $c" 
       fi;;
    3) c=`expr $a \* $b`
       echo "Multiplication of given number is $c" ;;
    4) c=`expr $a / $b`
       echo "Divison of given number is $c" ;;
    *) echo "Enter Valid Choice" ;;
esac
done
