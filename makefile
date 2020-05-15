compile: src/main.c lib/QRCodeStructToRaw/QRCodeStructToRaw.c lib/binaryConverter/binaryConverter.c lib/reedSolomon/reedSolomon.c
	gcc -Wall src/main.c lib/QRCodeStructToRaw/QRCodeStructToRaw.c lib/binaryConverter/binaryConverter.c lib/reedSolomon/reedSolomon.c

test: tests/test.c lib/QRCodeStructToRaw/QRCodeStructToRaw.c lib/binaryConverter/binaryConverter.c lib/reedSolomon/reedSolomon.c
	gcc -Wall tests/test.c lib/QRCodeStructToRaw/QRCodeStructToRaw.c lib/binaryConverter/binaryConverter.c lib/reedSolomon/reedSolomon.c

clean: 
	rm -f *.out
	rm -f *.exe


