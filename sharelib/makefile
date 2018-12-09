message_lib_src=message.c message.h
output_lib_src=output.c output.h
strhel_lib_src=str_help.c str_help.h
send_lib_src=oncesend.c oncesend.h
junk_file=*.o *.h.gch
last: libsend.a libmessage.a liboutput.a libstrhel.a
	rm $(junk_file)
clean:
	rm *.o *.a
libsend.a:oncesend.o
	ar cr libsend.a oncesend.o
libmessage.a:message.o
	ar cr libmessage.a message.o
liboutput.a:output.o
	ar cr liboutput.a output.o
libstrhel.a:str_help.o
	ar cr libstrhel.a str_help.o
message.o:$(message_lib_src)
	gcc -c $(message_lib_src)
output.o:$(output_lib_src)
	gcc -c $(output_lib_src)
str_help.o:$(strhel_lib_src)
	gcc -c $(strhel_lib_src)
oncesend.o:$(send_lib_src)
	gcc -c $(send_lib_src)
