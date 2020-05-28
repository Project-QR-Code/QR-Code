QRCodeStructToRaw = $(wildcard lib/QRCodeStructToRaw/*.c)
binaryConverter = $(wildcard lib/binaryConverter/*.c)
reedSolomon = $(wildcard lib/reedSolomon/*.c)
rawToQrCodeStruct = $(wildcard lib/rawToQrCodeStruct/*.c)

libs = $(QRCodeStructToRaw) $(binaryConverter) $(reedSolomon) $(rawToQrCodeStruct)

main_write = src/write.c
main_read = src/read.c
test = $(wildcard tests/*.c)

FLAGS = -g -Wall


.PHONY: compile

compile: $(main_write) $(main_read) $(libs)
	gcc $(FLAGS) $(libs) $(main_write) -o write
	gcc $(FLAGS) $(libs) $(main_read) -o read


.PHONY: test

test: $(test) $(libs)
	gcc $(FLAGS) $^


.PHONY: clean

clean:
	rm -f read
	rm -f write
	rm -f *.out
	rm -f *.exe


