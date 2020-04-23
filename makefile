compile: main.c converter/QRCodeStructToRaw.c
	gcc main.c converter/QRCodeStructToRaw.c

test: test.c converter/QRCodeStructToRaw.c
	gcc test.c converter/QRCodeStructToRaw.c

clean: 
	rm -f *.out
	rm -f *.exe


