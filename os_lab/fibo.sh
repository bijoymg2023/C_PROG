echo "ENTER FIBONACCI LIMIT"
read n
var=2
a=0
b=1
if [ $n -eq 0 ]
then 
    echo " "
elif [ $n -eq 1 ]
then 
    echo " "
    echo "0"
else
    echo " "
    echo "0" 
    echo "1"
    while [ $var -le $n ]
    do
    c=`expr $a + $b`
    echo "$c"
    a=$b
    b=$c
    var=`expr $var + 1`
    done
fi