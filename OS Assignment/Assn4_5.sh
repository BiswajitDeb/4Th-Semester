n=$1
echo "Enter elements : "
for ((i=0;i<n;i++))
do
    read array[$i]
done
echo "The input array is : " ${array[@]}
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
echo "The sorted array is : " ${array[@]}