#LIB_PATH = /usr/local/share/sdcc/non-free/lib/pic14
SDCC_EXE = ../../../bin/sdcc
SDCC_ARG = -V --verbose --use-non-free -mmc30 -p30p011 \
	-I$(SDCC_HOME)/share/include/mc30 \
	-Wa-I$(SDCC_HOME)/share/header/mc30 \
	-Wl-s$(SDCC_HOME)/share/lkr/mc30/mc30p011.lkr
PRJ = i2c
OUTPUT = $(PRJ).hex

all : $(OUTPUT)

$(OUTPUT) : *.c
	$(SDCC_EXE) $(SDCC_ARG) -c fun.c
	$(SDCC_EXE) $(SDCC_ARG) -c main.c
	$(SDCC_EXE) $(SDCC_ARG) main.o fun.o -o $(PRJ)

clean:
	rm -f *.asm *.cod *.hex *.lst *.o *.map *.cof *.s19
