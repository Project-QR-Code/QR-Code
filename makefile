compile: src/main.c lib/QRCodeStructToRaw/QRCodeStructToRaw.c lib/binaryConverter/binaryConverter.c
	gcc -Wall src/main.c lib/QRCodeStructToRaw/QRCodeStructToRaw.c lib/binaryConverter/binaryConverter.c

test: tests/test.c lib/QRCodeStructToRaw/QRCodeStructToRaw.c lib/binaryConverter/binaryConverter.c
	gcc -Wall tests/test.c lib/QRCodeStructToRaw/QRCodeStructToRaw.c lib/binaryConverter/binaryConverter.c

clean: 
	rm -f *.out
	rm -f *.exe


