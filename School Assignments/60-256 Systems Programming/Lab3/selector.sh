a=`grep -n $1 headandtail | cut -d ":" -f 1 | head -n 1`
b=`grep -n $2 headandtail | cut -d ":" -f 1 | head -n 1`
c=$(($b - $a + 1))

if((c>0))
	then head -n $b headandtail | tail -n $c
else
	echo "Error."
fi