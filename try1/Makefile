#LIB_PATH = /usr/local/share/sdcc/non-free/lib/pic14
OUTPUT = test.hex

all : $(OUTPUT)

$(OUTPUT) : test.c
	#sdcc -mpic14 -p12f629 -L $(LIB_PATH) test.c
	sdcc -V --verbose --use-non-free -p16f877 test.c

clean:
	rm -f test.asm test.cod test.hex test.lst test.o
