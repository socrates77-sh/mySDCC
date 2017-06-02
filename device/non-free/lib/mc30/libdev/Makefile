SDCC_EXE = /home/zwr/work/tool/sn-sdcc/bin/sdcc
LIB_EXE = /home/zwr/work/tool/snutils/gputils/gplib
LIB = mc30p011.lib 
OBJ = mc30p011.o 
SDCC_ARG = -V --verbose --use-non-free -mmc30 -Wa-I$(SDCC_HOME)/share/header/mc30 \
    -I$(SDCC_HOME)/share/include/mc30 \
    --std-c99 --i-code-in-asm  -c -o 

all : $(OBJ) $(LIB)

mc30p011.o : mc30p011.c
	$(SDCC_EXE) -p30p011 $(SDCC_ARG) mc30p011.o mc30p011.c
mc30p011.lib : mc30p011.c
	$(LIB_EXE) -c ../mc30p011.lib mc30p011.o

clean:
	rm -f *.o *.lst *.asm *.lib ../*.lib