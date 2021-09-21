if [ ! -f num.txt ]; then
echo 0 > num.txt
fi

counter=$( tail -1 num.txt )

while [ $counter -lt 100 ]; do

counter=$(expr $counter + 1)

echo $counter >> num.txt

done
