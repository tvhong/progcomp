rm $1
touch $1
for i in {-3..-300000..3}
do
    echo "$i" >> in1
done
