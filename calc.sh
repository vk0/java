while true; do
read n1 operand n2

if [[ $n1 = "exit" ]]
then
echo "bye"
exit 0
fi

case $operand in
    "+") op='+';;
    "-") op='-';;
    "*") op='*';;
    "/") op='/';;
    "%") op='%';;
    "**") op='^';;
    *) op='error';;
esac

if [[ $op = "error" ]]
then
echo "error"
exit 0
fi

ans=$(echo "$n1 $op $n2" | bc -l)
echo $ans
#printf "%s %s %s = %s\n\n" "$n1" "$op" "$n2" "$ans"

done