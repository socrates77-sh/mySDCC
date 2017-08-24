SDCC_EXE = /home/sinomcu/aaa/sn-sdcc/bin/sdcc
ASM_EXE = /home/sinomcu/aaa/snutils/gpasm/gpasm
LIB_EXE = /home/sinomcu/aaa/snutils/gputils/gplib
LIB = mc32p21.lib
OBJ = mc32p21.o _divschar.o _divsint.o _divslong.o _divuchar.o _divuint.o _divulong.o fs2schar.o fs2sint.o fs2slong.o fs2uchar.o fs2uint.o fs2ulong.o fsadd.o fsdiv.o fseq.o fsgt.o fslt.o fsmul.o fsneq.o fssub.o idata.o _modschar.o _modsint.o _modslong.o _moduchar.o _moduint.o _modulong.o _mulchar.o _mulint.o _mullong.o schar2fs.o sint2fs.o slong2fs.o uchar2fs.o uint2fs.o ulong2fs.o _gptrget1.o _gptrget2.o _gptrget3.o _gptrget4.o _gptrput1.o _gptrput2.o _gptrput3.o _gptrput4.o 

SDCC_ARG = -V --verbose -mmc3x -p32p21 -Wa-I$(SDCC_HOME)/share/header \
    -I$(SDCC_HOME)/share/include \
    --std-c99 --i-code-in-asm  -c -o 

ASM_ARG = -p mc32p21 -I$(SDCC_HOME)/share/include -I. -I../libsdcc -c -o 

all : $(OBJ) $(LIB)

$(LIB) : $(OBJ)
	$(LIB_EXE) -c $(LIB) *.o
	cp -av $(LIB) $(SDCC_HOME)/share/lib

mc32p21.o : mc32p21.c
	$(SDCC_EXE) $(SDCC_ARG) mc32p21.o mc32p21.c
_divschar.o : ../libsdcc/_divschar.c
	$(SDCC_EXE) $(SDCC_ARG) _divschar.o ../libsdcc/_divschar.c
_divsint.o : ../libsdcc/_divsint.c
	$(SDCC_EXE) $(SDCC_ARG) _divsint.o ../libsdcc/_divsint.c
_divslong.o : ../libsdcc/_divslong.c
	$(SDCC_EXE) $(SDCC_ARG) _divslong.o ../libsdcc/_divslong.c
_divuchar.o : ../libsdcc/_divuchar.c
	$(SDCC_EXE) $(SDCC_ARG) _divuchar.o ../libsdcc/_divuchar.c
_divuint.o : ../libsdcc/_divuint.c
	$(SDCC_EXE) $(SDCC_ARG) _divuint.o ../libsdcc/_divuint.c
_divulong.o : ../libsdcc/_divulong.c
	$(SDCC_EXE) $(SDCC_ARG) _divulong.o ../libsdcc/_divulong.c
fs2schar.o : ../libsdcc/fs2schar.c
	$(SDCC_EXE) $(SDCC_ARG) fs2schar.o ../libsdcc/fs2schar.c
fs2sint.o : ../libsdcc/fs2sint.c
	$(SDCC_EXE) $(SDCC_ARG) fs2sint.o ../libsdcc/fs2sint.c
fs2slong.o : ../libsdcc/fs2slong.c
	$(SDCC_EXE) $(SDCC_ARG) fs2slong.o ../libsdcc/fs2slong.c
fs2uchar.o : ../libsdcc/fs2uchar.c
	$(SDCC_EXE) $(SDCC_ARG) fs2uchar.o ../libsdcc/fs2uchar.c
fs2uint.o : ../libsdcc/fs2uint.c
	$(SDCC_EXE) $(SDCC_ARG) fs2uint.o ../libsdcc/fs2uint.c
fs2ulong.o : ../libsdcc/fs2ulong.c
	$(SDCC_EXE) $(SDCC_ARG) fs2ulong.o ../libsdcc/fs2ulong.c
fsadd.o : ../libsdcc/fsadd.c
	$(SDCC_EXE) $(SDCC_ARG) fsadd.o ../libsdcc/fsadd.c
fsdiv.o : ../libsdcc/fsdiv.c
	$(SDCC_EXE) $(SDCC_ARG) fsdiv.o ../libsdcc/fsdiv.c
fseq.o : ../libsdcc/fseq.c
	$(SDCC_EXE) $(SDCC_ARG) fseq.o ../libsdcc/fseq.c
fsgt.o : ../libsdcc/fsgt.c
	$(SDCC_EXE) $(SDCC_ARG) fsgt.o ../libsdcc/fsgt.c
fslt.o : ../libsdcc/fslt.c
	$(SDCC_EXE) $(SDCC_ARG) fslt.o ../libsdcc/fslt.c
fsmul.o : ../libsdcc/fsmul.c
	$(SDCC_EXE) $(SDCC_ARG) fsmul.o ../libsdcc/fsmul.c
fsneq.o : ../libsdcc/fsneq.c
	$(SDCC_EXE) $(SDCC_ARG) fsneq.o ../libsdcc/fsneq.c
fssub.o : ../libsdcc/fssub.c
	$(SDCC_EXE) $(SDCC_ARG) fssub.o ../libsdcc/fssub.c
idata.o : ../libsdcc/idata.c
	$(SDCC_EXE) $(SDCC_ARG) idata.o ../libsdcc/idata.c
_modschar.o : ../libsdcc/_modschar.c
	$(SDCC_EXE) $(SDCC_ARG) _modschar.o ../libsdcc/_modschar.c
_modsint.o : ../libsdcc/_modsint.c
	$(SDCC_EXE) $(SDCC_ARG) _modsint.o ../libsdcc/_modsint.c
_modslong.o : ../libsdcc/_modslong.c
	$(SDCC_EXE) $(SDCC_ARG) _modslong.o ../libsdcc/_modslong.c
_moduchar.o : ../libsdcc/_moduchar.c
	$(SDCC_EXE) $(SDCC_ARG) _moduchar.o ../libsdcc/_moduchar.c
_moduint.o : ../libsdcc/_moduint.c
	$(SDCC_EXE) $(SDCC_ARG) _moduint.o ../libsdcc/_moduint.c
_modulong.o : ../libsdcc/_modulong.c
	$(SDCC_EXE) $(SDCC_ARG) _modulong.o ../libsdcc/_modulong.c
_mulchar.o : ../libsdcc/_mulchar.c
	$(SDCC_EXE) $(SDCC_ARG) _mulchar.o ../libsdcc/_mulchar.c
_mulint.o : ../libsdcc/_mulint.c
	$(SDCC_EXE) $(SDCC_ARG) _mulint.o ../libsdcc/_mulint.c
_mullong.o : ../libsdcc/_mullong.c
	$(SDCC_EXE) $(SDCC_ARG) _mullong.o ../libsdcc/_mullong.c
schar2fs.o : ../libsdcc/schar2fs.c
	$(SDCC_EXE) $(SDCC_ARG) schar2fs.o ../libsdcc/schar2fs.c
sint2fs.o : ../libsdcc/sint2fs.c
	$(SDCC_EXE) $(SDCC_ARG) sint2fs.o ../libsdcc/sint2fs.c
slong2fs.o : ../libsdcc/slong2fs.c
	$(SDCC_EXE) $(SDCC_ARG) slong2fs.o ../libsdcc/slong2fs.c
uchar2fs.o : ../libsdcc/uchar2fs.c
	$(SDCC_EXE) $(SDCC_ARG) uchar2fs.o ../libsdcc/uchar2fs.c
uint2fs.o : ../libsdcc/uint2fs.c
	$(SDCC_EXE) $(SDCC_ARG) uint2fs.o ../libsdcc/uint2fs.c
ulong2fs.o : ../libsdcc/ulong2fs.c
	$(SDCC_EXE) $(SDCC_ARG) ulong2fs.o ../libsdcc/ulong2fs.c
_gptrget1.o : _gptrget1.S
	$(ASM_EXE) $(ASM_ARG) _gptrget1.o _gptrget1.S
_gptrget2.o : ../libsdcc/_gptrget2.S
	$(ASM_EXE) $(ASM_ARG) _gptrget2.o ../libsdcc/_gptrget2.S
_gptrget3.o : ../libsdcc/_gptrget3.S
	$(ASM_EXE) $(ASM_ARG) _gptrget3.o ../libsdcc/_gptrget3.S
_gptrget4.o : ../libsdcc/_gptrget4.S
	$(ASM_EXE) $(ASM_ARG) _gptrget4.o ../libsdcc/_gptrget4.S
_gptrput1.o : ../libsdcc/_gptrput1.S
	$(ASM_EXE) $(ASM_ARG) _gptrput1.o ../libsdcc/_gptrput1.S
_gptrput2.o : ../libsdcc/_gptrput2.S
	$(ASM_EXE) $(ASM_ARG) _gptrput2.o ../libsdcc/_gptrput2.S
_gptrput3.o : ../libsdcc/_gptrput3.S
	$(ASM_EXE) $(ASM_ARG) _gptrput3.o ../libsdcc/_gptrput3.S
_gptrput4.o : ../libsdcc/_gptrput4.S
	$(ASM_EXE) $(ASM_ARG) _gptrput4.o ../libsdcc/_gptrput4.S

clean:
	rm -f *.o *.lst *.asm *.lib