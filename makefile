QRCodeStructToRaw = $(wildcard lib/QRCodeStructToRaw/*.c)
binaryConverter = $(wildcard lib/binaryConverter/*.c)
reedSolomon = $(wildcard lib/reedSolomon/*.c)

libs = $(QRCodeStructToRaw) $(binaryConverter) $(reedSolomon)

main = $(wildcard src/*.c)
test = $(wildcard tests/*.c)

FLAGS = -g -Wall


.PHONY: compile

compile: $(main) $(libs)
	gcc $(FLAGS) $^


.PHONY: test

test: $(test) $(libs)
	gcc $(FLAGS) $^


.PHONY: clean

clean: 
	rm -f *.out
	rm -f *.exe


