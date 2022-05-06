echo "Enter two numbers : "
read m
read n
echo 'choose an option'
echo $'1. Addition \n2. Subtraction \n3. Multiplication \n4. Division'
echo "Enter choice : "
read choice

if [ $choice = 1 ]
then
    result=$((m+n))
elif [ $choice = 2 ]
then
    result=$((m-n))
elif [ $choice = 3 ]
then
    result=$((m*n))
elif [ $choice = 4 ]
then
    result=$((m/n))
else
    echo "Invalid choice"
fi
echo $result