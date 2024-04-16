a=("$@")
max=${a[0]}
for num in "${a[@]}"
do
    if [ $num -gt $max ]
    then
        max=$num
    fi
done
echo "The maximum no. is $max"