#2.Write a shell script program to check whether a number is positive, negative or equal to zero and print the output.
echo "Enter a Number : "
read n

if [ $n -lt 0 ]
then 
    echo "The number is -ve "
elif [ $n -gt 0 ]
then 
    echo "The number is +ve "
else
    echo "The number is 0 "
fi