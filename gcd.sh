#!/bin/bash
while true; do
read num1 num2

if [[ -z $num1 ]]
then
echo "bye"
exit 0
fi

gcd ()
{
if [[ $2 -eq 0 ]]; then
    return $1
else
gcd $2 $(($1%$2))
fi
}

gcd $num1 $num2

echo "GCD is $?"
done