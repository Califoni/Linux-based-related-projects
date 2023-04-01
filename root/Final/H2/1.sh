#! /bin/bash
for i in $*
do		
    if [ $i -ge 90 ]
    then
        echo ${i} A
    elif [ $i -ge 80 ]
    then
        echo ${i} B
    elif [ $i -ge 70 ]
    then
        echo ${i} C
    elif [ $i -ge 60 ]
    then
        echo ${i} D
    else                                                                                                                                                  
        echo ${i} 不及格
    fi
done
