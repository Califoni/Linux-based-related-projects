#! /bin/bash

read -p "please input n: " n

sum=0.0000
an=0.0000

for ((i=1;i<=$n;i++))
do
	if [ `expr $i % 2` -eq 0 ]
	then
	        an=`echo "scale=4;-1.0000/$i"|bc`
	else
	        an=`echo "scale=4;1.0000/$i"|bc`
	fi
        sum=`echo "scale=4;$sum+$an"|bc`
done
echo $sum
