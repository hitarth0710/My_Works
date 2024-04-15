echo "File Operations"
while true
do 
echo "1. Copy "
echo "2. Edit " 
echo "3. Delete " 
echo "4. Rename "
echo "5. Exit"
echo "Enter Your choice :"
read option
if [ $option -eq 5 ]
then
     echo "Exiting..."
     break
fi
echo "Enter the file name:"
read filename
case $option in
     1) echo "Enter the destination file name:"
         read dest
         cp $filename $dest
         echo "File copied successfully." ;;
     2) nano $filename ;;
     3) rm $filename
         echo "File deleted successfully." ;;
     4) echo "Enter the new file name:"
         read newname
         mv $filename $newname
         echo "File renamed successfully." ;;
     *) echo "Invalid choice." ;;
esac
done