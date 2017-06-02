#LIB_PATH = /usr/local/share/sdcc/non-free/lib/pic14
SDCC_EXE = ../../../bin/sdcc
SDCC_ARG = -V --verbose --use-non-free -mmc30 -p30p011 \
	-I$(SDCC_HOME)/share/include/mc30 \
	-I.\
	--opt-code-size \
	-Wa-I$(SDCC_HOME)/share/header/mc30 \
	-Wl-s$(SDCC_HOME)/share/lkr/mc30/mc30p011.lkr
PRJ = top
OUTPUT = $(PRJ).hex

all : $(OUTPUT)

$(OUTPUT) : *.c
	$(SDCC_EXE) $(SDCC_ARG) -c CtrlSbr.c
	$(SDCC_EXE) $(SDCC_ARG) -c initSys.c
	$(SDCC_EXE) $(SDCC_ARG) -c IR.c
	$(SDCC_EXE) $(SDCC_ARG) -c T1sSbr.c
	$(SDCC_EXE) $(SDCC_ARG) -c YKQ3011.c
	$(SDCC_EXE) $(SDCC_ARG) CtrlSbr.o initSys.o IR.o T1sSbr.o YKQ3011.o -o $(PRJ)

clean:
	rm -f *.asm *.cod *.hex *.lst *.o *.map *.cof *.s19
