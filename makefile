	find . -name "a.out"|xargs rm -f
	find . -name "*.o"|xargs rm -f
	find . -name "*.h.gch"|xargs rm -f
	git add *
if [ $# -eq 0 ]; then
	echo "please input commit message"
elif [ $1 == '-t' ]; then
	find . -name "*.a"|xargs rm -f
	echo "delete succeed"
else
	git commit -m "$1"
	git config --global user.emall "lnpj.office@icloud.com"
	git config --global user.name "frank_albert"
	git push origin master
fi
