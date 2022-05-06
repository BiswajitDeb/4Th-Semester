#Write a shell scripts to calculate the factorial of an integer no.
echo "Enter a number : "
read num
factorial=1
for ((i=$num;i>=2;i--))
#for i in {$num..1}
do
    factorial=$((factorial * i))
    #echo $factorial
done
echo "Factorial of $num is $factorial"