	find . -name "a.out"|xargs rm -f
	find . -name "*.o"|xargs rm -f
	find . -name "*.a"|xargs rm -f
	git add *

	git commit -m "$1"
	git push origin master

