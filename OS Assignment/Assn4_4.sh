# #Write a shell program that will accept 10 numbers from the terminals and will search the position of a given no in the supplied nos.
# echo "Enter 10 numbers : "
# for ((i=0;i<10;i++))
# do
#     read array[$i]
# done

# echo -n "Enter an element to search in the array : "
# read n

# for ((i=0;i<10;i++))
# do
#     if (( array[$i] == $n ))
#     then
#         echo "The index / position of the element in the array is : " $i
#     fi

# done
# # echo $n
# # echo ${array[@]}


num=( "$@" )

echo "Enter the number to be searched:"
read n

flag=-1

for(( i = 0; i < 10; i++ ))
do
	if [ ${num[$i]} -eq $n ]
	then 
		flag=$i
		break
	fi
done

if [ $flag -ne -1 ]
then
	echo "The element $n is at the position: $((flag+1)) "
else
	echo "The element $n is not present in the given array "
fi