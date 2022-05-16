#Write a Shell script to take two numbers as range from the terminal and print non-prime numbers between the given range
# echo "Enter the starting and ending of the range : "
# read start end
#echo $start $end
start=$1
end=$2

# for i in {$start..$end}
echo "All the non-prime numbers in the given range : "
for (( i=$start; i<=$end; i++ ))
do
    # echo $i
    range=$((i/2))
    # for j in {2..$range}
    for ((j=2; j<=$range; j++))
    do
        flag=0
        if (( $i % $j == 0 ))
        then
            # flag=1
            # break
            echo $i
            break
        fi
    # echo $i
    #     if (( $flag==1 ))
    #     then
    #         echo $i
    #     fi
    done
done
