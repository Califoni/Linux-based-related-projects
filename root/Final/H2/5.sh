#! /bin/bash

secret="222555"

n=1
while [ $n -le 3 ]
do
	read -p "please input right numbers,this is ${n}th time:" input
	if [ $input -eq $secret ]
	then
		echo "密码正确！"
		break
	else
		echo "密码错误~"
		n=`expr $n + 1`
	fi
done
