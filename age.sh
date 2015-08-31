#!/bin/bash
while true; do
echo "enter your name:"
read name
if [[ -z $name ]]
then
echo "bye"
exit 0
fi

echo "enter your age:"
read age

if [[ $age -eq 0 ]]
then
echo "bye"
exit 0
fi

case ${age} in
  [1-9]|1[1-6]) group=child;;
  1[7-9]|2[0-5]) group=youth;;
  *) group=adult;;
esac
echo "$name, your group is $group"

done
