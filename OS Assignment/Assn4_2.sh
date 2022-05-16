# #Write a Shell script to take 'n' number of elements in an array and print the third largest number.  Value of 'n' must be taken from the terminal.
n=$1
echo "Enter elements : "
for ((i=0;i<n;i++))
do
    read array[$i]
done
echo "The array is : " ${array[@]}
# #Bubble-sort

for(( i = 0; i < n - 1; i++ )) 
do
	for(( j = 0; j < n - i - 1; j++ ))
	do
		if [ ${array[$j]} -gt ${array[$((j+1))]} ]
		then
			temp=${array[$j]}
			array[$j]=${array[$((j+1))]}
			array[$((j+1))]=$temp
		fi
	done
done

echo -n "The 3rd greatest element of the array is : "
echo ${array[$((n-3))]}
#echo ${array[@]}

