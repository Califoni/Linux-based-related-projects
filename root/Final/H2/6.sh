#! /bin/bash

read -p "请输入要删除的文件名: " file

if [ -f $file  ]
then
	size= stat -c %B $file
	max=1048576
	echo ${size}
	if [[ $size -lt $max ]]
	then
		mv $file /root/Final/H2/.Trash
	else
		read -p "文件大于100MB，确定要删除吗(yes/no)" ans
		if [ "$ans" = "yes" ]
		then
			mv $file /root/Final/H2/.Trash
		else
			echo "取消删除"
		fi
	fi
fi	
