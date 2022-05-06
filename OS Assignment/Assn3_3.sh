#Write a shell script to print all the numbers from 1 to 100 which are divisible by 3.
echo "the numbers from 1 to 100 which are divisible by 3 are : "
for i in {1..100}
do
    if [ `expr $i % 3` = 0 ]
    then 
        echo $i
    fi
done