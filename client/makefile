#make file
basepath=$(shell pwd)
output:$(basepath)/*.c $(basepath)/utils/*.c
	gcc $^ -static-libgfortran $(basepath)/lib/*.a -o client.gun -std=gnu11 
debug:$(basepath)/*.c $(basepath)/utils/*.c
	gcc $^ -static-libgfortran $(basepath)/lib/*.a -o client_debug.gun -std=gnu11 -g
clean:
	rm  client*
