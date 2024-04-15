while true  
do 
    echo "Calculator"
    echo "1. Addition "
    echo "2. Substraction " 
    echo "3. Multiplication " 
    echo "4. Division "
    echo "5. Exit  "
    echo "Enter Your choice :"
    read ch 
    if [ $ch -eq 5 ]
    then 
        echo "Quitting" 
        break 
    fi 
    echo "Enter First number : "
    read a 
    echo "Enter Second number : " 
    read b 

    case $ch in 
        1)  c=$(expr $a + $b) 
            echo "Addition of the two numbers : $c" ;; 
        2)  if [ $a -lt $b ] 
            then 
                echo "Can't subtract bigger number from smaller one."
            else 
                s=$(expr $a - $b)
                echo "Substraction of the two numbers are : $s "
            fi ;;
        3)  m=$(expr $a \* $b)
            echo "Multiplication of the two numbers are : $m" ;;
        4)  d=$(expr $a \/ $b)
            echo "Division of the two numbers are : $d" ;; 
        *)  echo "Enter valid choice !! " ;;
    esac 
done