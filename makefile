	find . -name "a.out"|xargs rm -f
	find . -name "*.o"|xargs rm -f
	find . -name "*.a"|xargs rm -f
	git add *
if [ $# -eq 0 ]; then
	echo "please input commit message"
else
	git commit -m "$1"
	git push origin master
fi
