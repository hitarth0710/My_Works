echo "1. List of Directory :"
echo "2. Today's date :"
echo "3. Working Directory :"
echo "Enter Your choice :"
read option
case $option in
    1) ls ;;
    2) date ;;
    3) pwd ;;
    *) echo "Enter valid choice" ;;
esac
