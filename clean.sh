
# clean c++ a.out
for it in `find -name "a.out"`
do
	echo delete $it
	rm -rf $it
done

# clean java *.class
for it in `find -name "*.class"`
do
	echo delete $it
	rm -rf $it
done

# clean vim swp file
for it in `find -name "*.swp"`
do
	echo delete $it
	rm -rf $it
done


