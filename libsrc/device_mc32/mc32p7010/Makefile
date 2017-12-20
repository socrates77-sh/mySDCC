PATH = /e/tools/snutils/gpasm
SDCC_EXE = /e/tools/sn-sdcc/bin/sdcc
ASM_EXE = /e/tools/snutils/gpasm/gpasm
LIB_EXE = /e/tools/snutils/gputils/gplib
LIB = 3221.lib
OBJ = mc32p7010.o _divschar.o _divsint.o _divslong.o _divuchar.o _divuint.o _divulong.o fs2schar.o fs2sint.o fs2slong.o fs2uchar.o fs2uint.o fs2ulong.o fsadd.o fsdiv.o fseq.o fsgt.o fslt.o fsmul.o fsneq.o fssub.o _modschar.o _modsint.o _modslong.o _moduchar.o _moduint.o _modulong.o _mulchar.o _mulint.o _mullong.o schar2fs.o sint2fs.o slong2fs.o uchar2fs.o uint2fs.o ulong2fs.o _gptrget1.o _gptrget2.o _gptrget3.o _gptrget4.o _gptrput1.o _gptrput2.o _gptrput3.o _gptrput4.o 

SDCC_ARG = -V --verbose -mmc32 -p3221 -Wa-Ie:\tools\sn-sdcc\share\header \
    -I/e/tools/sn-sdcc/share/include \
    --std-c99 --i-code-in-asm  -c -o 

ASM_ARG = -p 3221 -I/e/tools/sn-sdcc/share/include -I. -I../../libsdcc_mc32 -c -o 

all : $(OBJ) $(LIB)

$(LIB) : $(OBJ)
	$(LIB_EXE) -c $(LIB) *.o
	/bin/cp -av $(LIB) /e/tools/sn-sdcc/share/lib 

mc32p7010.o : mc32p7010.c
	$(SDCC_EXE) $(SDCC_ARG) mc32p7010.o mc32p7010.c
_divschar.o : ../../libsdcc_mc32/_divschar.c
	$(SDCC_EXE) $(SDCC_ARG) _divschar.o ../../libsdcc_mc32/_divschar.c
_divsint.o : ../../libsdcc_mc32/_divsint.c
	$(SDCC_EXE) $(SDCC_ARG) _divsint.o ../../libsdcc_mc32/_divsint.c
_divslong.o : ../../libsdcc_mc32/_divslong.c
	$(SDCC_EXE) $(SDCC_ARG) _divslong.o ../../libsdcc_mc32/_divslong.c
_divuchar.o : ../../libsdcc_mc32/_divuchar.c
	$(SDCC_EXE) $(SDCC_ARG) _divuchar.o ../../libsdcc_mc32/_divuchar.c
_divuint.o : ../../libsdcc_mc32/_divuint.c
	$(SDCC_EXE) $(SDCC_ARG) _divuint.o ../../libsdcc_mc32/_divuint.c
_divulong.o : ../../libsdcc_mc32/_divulong.c
	$(SDCC_EXE) $(SDCC_ARG) _divulong.o ../../libsdcc_mc32/_divulong.c
fs2schar.o : ../../libsdcc_mc32/fs2schar.c
	$(SDCC_EXE) $(SDCC_ARG) fs2schar.o ../../libsdcc_mc32/fs2schar.c
fs2sint.o : ../../libsdcc_mc32/fs2sint.c
	$(SDCC_EXE) $(SDCC_ARG) fs2sint.o ../../libsdcc_mc32/fs2sint.c
fs2slong.o : ../../libsdcc_mc32/fs2slong.c
	$(SDCC_EXE) $(SDCC_ARG) fs2slong.o ../../libsdcc_mc32/fs2slong.c
fs2uchar.o : ../../libsdcc_mc32/fs2uchar.c
	$(SDCC_EXE) $(SDCC_ARG) fs2uchar.o ../../libsdcc_mc32/fs2uchar.c
fs2uint.o : ../../libsdcc_mc32/fs2uint.c
	$(SDCC_EXE) $(SDCC_ARG) fs2uint.o ../../libsdcc_mc32/fs2uint.c
fs2ulong.o : ../../libsdcc_mc32/fs2ulong.c
	$(SDCC_EXE) $(SDCC_ARG) fs2ulong.o ../../libsdcc_mc32/fs2ulong.c
fsadd.o : ../../libsdcc_mc32/fsadd.c
	$(SDCC_EXE) $(SDCC_ARG) fsadd.o ../../libsdcc_mc32/fsadd.c
fsdiv.o : ../../libsdcc_mc32/fsdiv.c
	$(SDCC_EXE) $(SDCC_ARG) fsdiv.o ../../libsdcc_mc32/fsdiv.c
fseq.o : ../../libsdcc_mc32/fseq.c
	$(SDCC_EXE) $(SDCC_ARG) fseq.o ../../libsdcc_mc32/fseq.c
fsgt.o : ../../libsdcc_mc32/fsgt.c
	$(SDCC_EXE) $(SDCC_ARG) fsgt.o ../../libsdcc_mc32/fsgt.c
fslt.o : ../../libsdcc_mc32/fslt.c
	$(SDCC_EXE) $(SDCC_ARG) fslt.o ../../libsdcc_mc32/fslt.c
fsmul.o : ../../libsdcc_mc32/fsmul.c
	$(SDCC_EXE) $(SDCC_ARG) fsmul.o ../../libsdcc_mc32/fsmul.c
fsneq.o : ../../libsdcc_mc32/fsneq.c
	$(SDCC_EXE) $(SDCC_ARG) fsneq.o ../../libsdcc_mc32/fsneq.c
fssub.o : ../../libsdcc_mc32/fssub.c
	$(SDCC_EXE) $(SDCC_ARG) fssub.o ../../libsdcc_mc32/fssub.c
_modschar.o : ../../libsdcc_mc32/_modschar.c
	$(SDCC_EXE) $(SDCC_ARG) _modschar.o ../../libsdcc_mc32/_modschar.c
_modsint.o : ../../libsdcc_mc32/_modsint.c
	$(SDCC_EXE) $(SDCC_ARG) _modsint.o ../../libsdcc_mc32/_modsint.c
_modslong.o : ../../libsdcc_mc32/_modslong.c
	$(SDCC_EXE) $(SDCC_ARG) _modslong.o ../../libsdcc_mc32/_modslong.c
_moduchar.o : ../../libsdcc_mc32/_moduchar.c
	$(SDCC_EXE) $(SDCC_ARG) _moduchar.o ../../libsdcc_mc32/_moduchar.c
_moduint.o : ../../libsdcc_mc32/_moduint.c
	$(SDCC_EXE) $(SDCC_ARG) _moduint.o ../../libsdcc_mc32/_moduint.c
_modulong.o : ../../libsdcc_mc32/_modulong.c
	$(SDCC_EXE) $(SDCC_ARG) _modulong.o ../../libsdcc_mc32/_modulong.c
_mulchar.o : ../../libsdcc_mc32/_mulchar.c
	$(SDCC_EXE) $(SDCC_ARG) _mulchar.o ../../libsdcc_mc32/_mulchar.c
_mulint.o : ../../libsdcc_mc32/_mulint.c
	$(SDCC_EXE) $(SDCC_ARG) _mulint.o ../../libsdcc_mc32/_mulint.c
_mullong.o : ../../libsdcc_mc32/_mullong.c
	$(SDCC_EXE) $(SDCC_ARG) _mullong.o ../../libsdcc_mc32/_mullong.c
schar2fs.o : ../../libsdcc_mc32/schar2fs.c
	$(SDCC_EXE) $(SDCC_ARG) schar2fs.o ../../libsdcc_mc32/schar2fs.c
sint2fs.o : ../../libsdcc_mc32/sint2fs.c
	$(SDCC_EXE) $(SDCC_ARG) sint2fs.o ../../libsdcc_mc32/sint2fs.c
slong2fs.o : ../../libsdcc_mc32/slong2fs.c
	$(SDCC_EXE) $(SDCC_ARG) slong2fs.o ../../libsdcc_mc32/slong2fs.c
uchar2fs.o : ../../libsdcc_mc32/uchar2fs.c
	$(SDCC_EXE) $(SDCC_ARG) uchar2fs.o ../../libsdcc_mc32/uchar2fs.c
uint2fs.o : ../../libsdcc_mc32/uint2fs.c
	$(SDCC_EXE) $(SDCC_ARG) uint2fs.o ../../libsdcc_mc32/uint2fs.c
ulong2fs.o : ../../libsdcc_mc32/ulong2fs.c
	$(SDCC_EXE) $(SDCC_ARG) ulong2fs.o ../../libsdcc_mc32/ulong2fs.c
_gptrget1.o : ../../libsdcc_mc32/_gptrget1.asm
	$(ASM_EXE) $(ASM_ARG) _gptrget1.o ../../libsdcc_mc32/_gptrget1.asm
_gptrget2.o : ../../libsdcc_mc32/_gptrget2.asm
	$(ASM_EXE) $(ASM_ARG) _gptrget2.o ../../libsdcc_mc32/_gptrget2.asm
_gptrget3.o : ../../libsdcc_mc32/_gptrget3.asm
	$(ASM_EXE) $(ASM_ARG) _gptrget3.o ../../libsdcc_mc32/_gptrget3.asm
_gptrget4.o : ../../libsdcc_mc32/_gptrget4.asm
	$(ASM_EXE) $(ASM_ARG) _gptrget4.o ../../libsdcc_mc32/_gptrget4.asm
_gptrput1.o : ../../libsdcc_mc32/_gptrput1.asm
	$(ASM_EXE) $(ASM_ARG) _gptrput1.o ../../libsdcc_mc32/_gptrput1.asm
_gptrput2.o : ../../libsdcc_mc32/_gptrput2.asm
	$(ASM_EXE) $(ASM_ARG) _gptrput2.o ../../libsdcc_mc32/_gptrput2.asm
_gptrput3.o : ../../libsdcc_mc32/_gptrput3.asm
	$(ASM_EXE) $(ASM_ARG) _gptrput3.o ../../libsdcc_mc32/_gptrput3.asm
_gptrput4.o : ../../libsdcc_mc32/_gptrput4.asm
	$(ASM_EXE) $(ASM_ARG) _gptrput4.o ../../libsdcc_mc32/_gptrput4.asm

clean:
	/bin/rm -f *.o *.lst *.asm *.lib