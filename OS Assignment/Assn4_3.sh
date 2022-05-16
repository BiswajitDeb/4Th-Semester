#Store ‘n’ number of elements in an array and find out the sum of the array elements. Value of 'n' must be taken from the terminal
n=$1
echo "Enter the array elements : "
sum=0
for (( i=0;i<n;i++))
do
    # read ${array[i]}
    read temp
    array[$i]=$temp
    sum=$((sum+temp))
    # read $array[i]
    # read $array[$i]
done
echo "The array is : " ${array[@]}
echo "The sum of all the elements of the array is : " $sum
# sum=0
# for (( i=0;i<n;i++))
# do
#     # sum=$(($sum + ${num[i]}))
#     sum=`expr $sum + ${num[$i]}`
#     # array[$i]=$temp
# done

# echo "The sum of all the elements in the array is : " $sum
# echo ${array[@]}