SDCC_EXE = /home/zwr/work/tool/sn-sdcc/bin/sdcc
ASM_EXE = /home/zwr/work/tool/snutils/gpasm/gpasm
LIB_EXE = /home/zwr/work/tool/snutils/gputils/gplib
LIB = libsdcc.lib
OBJ = shadowregs.o _divschar.o _divsint.o _divslong.o _divuchar.o _divuint.o _divulong.o fs2schar.o fs2sint.o fs2slong.o fs2uchar.o fs2uint.o fs2ulong.o fsadd.o fsdiv.o fseq.o fsgt.o fslt.o fsmul.o fsneq.o fssub.o idata.o _modschar.o _modsint.o _modslong.o _moduchar.o _moduint.o _modulong.o _mulchar.o _mulint.o _mullong.o schar2fs.o sint2fs.o slong2fs.o uchar2fs.o uint2fs.o ulong2fs.o acosf.o asincosf.o asinf.o atan2f.o atanf.o ceilf.o cosf.o coshf.o cotf.o errno.o expf.o fabsf.o floorf.o frexpf.o ldexpf.o log10f.o logf.o modff.o powf.o sincosf.o sincoshf.o sinf.o sinhf.o sqrtf.o tancotf.o tanf.o tanhf.o _gptrget1.o _gptrget2.o _gptrget3.o _gptrget4.o _gptrput1.o _gptrput2.o _gptrput3.o _gptrput4.o 

SDCC_ARG = -V --verbose --use-non-free -mmc30 -p30p011 -Wa-I$(SDCC_HOME)/share/header/mc30 \
    -I$(SDCC_HOME)/share/include/mc30 \
    --std-c99 --i-code-in-asm  -c -o 

ASM_ARG = -p mc30p011 -I../../../../include/mc30 -I../../../../non-free/include/mc30 -I. -c -o 

all : $(OBJ) $(LIB)

$(LIB) : $(OBJ)
	$(LIB_EXE) -c $(LIB) *.o
	cp -av $(LIB) ../..
shadowregs.o : shadowregs.c
	$(SDCC_EXE) $(SDCC_ARG) shadowregs.o shadowregs.c
_divschar.o : ../_divschar.c
	$(SDCC_EXE) $(SDCC_ARG) _divschar.o ../_divschar.c
_divsint.o : ../_divsint.c
	$(SDCC_EXE) $(SDCC_ARG) _divsint.o ../_divsint.c
_divslong.o : ../_divslong.c
	$(SDCC_EXE) $(SDCC_ARG) _divslong.o ../_divslong.c
_divuchar.o : ../_divuchar.c
	$(SDCC_EXE) $(SDCC_ARG) _divuchar.o ../_divuchar.c
_divuint.o : ../_divuint.c
	$(SDCC_EXE) $(SDCC_ARG) _divuint.o ../_divuint.c
_divulong.o : ../_divulong.c
	$(SDCC_EXE) $(SDCC_ARG) _divulong.o ../_divulong.c
fs2schar.o : ../fs2schar.c
	$(SDCC_EXE) $(SDCC_ARG) fs2schar.o ../fs2schar.c
fs2sint.o : ../fs2sint.c
	$(SDCC_EXE) $(SDCC_ARG) fs2sint.o ../fs2sint.c
fs2slong.o : ../fs2slong.c
	$(SDCC_EXE) $(SDCC_ARG) fs2slong.o ../fs2slong.c
fs2uchar.o : ../fs2uchar.c
	$(SDCC_EXE) $(SDCC_ARG) fs2uchar.o ../fs2uchar.c
fs2uint.o : ../fs2uint.c
	$(SDCC_EXE) $(SDCC_ARG) fs2uint.o ../fs2uint.c
fs2ulong.o : ../fs2ulong.c
	$(SDCC_EXE) $(SDCC_ARG) fs2ulong.o ../fs2ulong.c
fsadd.o : ../fsadd.c
	$(SDCC_EXE) $(SDCC_ARG) fsadd.o ../fsadd.c
fsdiv.o : ../fsdiv.c
	$(SDCC_EXE) $(SDCC_ARG) fsdiv.o ../fsdiv.c
fseq.o : ../fseq.c
	$(SDCC_EXE) $(SDCC_ARG) fseq.o ../fseq.c
fsgt.o : ../fsgt.c
	$(SDCC_EXE) $(SDCC_ARG) fsgt.o ../fsgt.c
fslt.o : ../fslt.c
	$(SDCC_EXE) $(SDCC_ARG) fslt.o ../fslt.c
fsmul.o : ../fsmul.c
	$(SDCC_EXE) $(SDCC_ARG) fsmul.o ../fsmul.c
fsneq.o : ../fsneq.c
	$(SDCC_EXE) $(SDCC_ARG) fsneq.o ../fsneq.c
fssub.o : ../fssub.c
	$(SDCC_EXE) $(SDCC_ARG) fssub.o ../fssub.c
idata.o : ../idata.c
	$(SDCC_EXE) $(SDCC_ARG) idata.o ../idata.c
_modschar.o : ../_modschar.c
	$(SDCC_EXE) $(SDCC_ARG) _modschar.o ../_modschar.c
_modsint.o : ../_modsint.c
	$(SDCC_EXE) $(SDCC_ARG) _modsint.o ../_modsint.c
_modslong.o : ../_modslong.c
	$(SDCC_EXE) $(SDCC_ARG) _modslong.o ../_modslong.c
_moduchar.o : ../_moduchar.c
	$(SDCC_EXE) $(SDCC_ARG) _moduchar.o ../_moduchar.c
_moduint.o : ../_moduint.c
	$(SDCC_EXE) $(SDCC_ARG) _moduint.o ../_moduint.c
_modulong.o : ../_modulong.c
	$(SDCC_EXE) $(SDCC_ARG) _modulong.o ../_modulong.c
_mulchar.o : ../_mulchar.c
	$(SDCC_EXE) $(SDCC_ARG) _mulchar.o ../_mulchar.c
_mulint.o : ../_mulint.c
	$(SDCC_EXE) $(SDCC_ARG) _mulint.o ../_mulint.c
_mullong.o : ../_mullong.c
	$(SDCC_EXE) $(SDCC_ARG) _mullong.o ../_mullong.c
schar2fs.o : ../schar2fs.c
	$(SDCC_EXE) $(SDCC_ARG) schar2fs.o ../schar2fs.c
sint2fs.o : ../sint2fs.c
	$(SDCC_EXE) $(SDCC_ARG) sint2fs.o ../sint2fs.c
slong2fs.o : ../slong2fs.c
	$(SDCC_EXE) $(SDCC_ARG) slong2fs.o ../slong2fs.c
uchar2fs.o : ../uchar2fs.c
	$(SDCC_EXE) $(SDCC_ARG) uchar2fs.o ../uchar2fs.c
uint2fs.o : ../uint2fs.c
	$(SDCC_EXE) $(SDCC_ARG) uint2fs.o ../uint2fs.c
ulong2fs.o : ../ulong2fs.c
	$(SDCC_EXE) $(SDCC_ARG) ulong2fs.o ../ulong2fs.c
acosf.o : ../../libm/acosf.c
	$(SDCC_EXE) $(SDCC_ARG) acosf.o ../../libm/acosf.c
asincosf.o : ../../libm/asincosf.c
	$(SDCC_EXE) $(SDCC_ARG) asincosf.o ../../libm/asincosf.c
asinf.o : ../../libm/asinf.c
	$(SDCC_EXE) $(SDCC_ARG) asinf.o ../../libm/asinf.c
atan2f.o : ../../libm/atan2f.c
	$(SDCC_EXE) $(SDCC_ARG) atan2f.o ../../libm/atan2f.c
atanf.o : ../../libm/atanf.c
	$(SDCC_EXE) $(SDCC_ARG) atanf.o ../../libm/atanf.c
ceilf.o : ../../libm/ceilf.c
	$(SDCC_EXE) $(SDCC_ARG) ceilf.o ../../libm/ceilf.c
cosf.o : ../../libm/cosf.c
	$(SDCC_EXE) $(SDCC_ARG) cosf.o ../../libm/cosf.c
coshf.o : ../../libm/coshf.c
	$(SDCC_EXE) $(SDCC_ARG) coshf.o ../../libm/coshf.c
cotf.o : ../../libm/cotf.c
	$(SDCC_EXE) $(SDCC_ARG) cotf.o ../../libm/cotf.c
errno.o : ../../libm/errno.c
	$(SDCC_EXE) $(SDCC_ARG) errno.o ../../libm/errno.c
expf.o : ../../libm/expf.c
	$(SDCC_EXE) $(SDCC_ARG) expf.o ../../libm/expf.c
fabsf.o : ../../libm/fabsf.c
	$(SDCC_EXE) $(SDCC_ARG) fabsf.o ../../libm/fabsf.c
floorf.o : ../../libm/floorf.c
	$(SDCC_EXE) $(SDCC_ARG) floorf.o ../../libm/floorf.c
frexpf.o : ../../libm/frexpf.c
	$(SDCC_EXE) $(SDCC_ARG) frexpf.o ../../libm/frexpf.c
ldexpf.o : ../../libm/ldexpf.c
	$(SDCC_EXE) $(SDCC_ARG) ldexpf.o ../../libm/ldexpf.c
log10f.o : ../../libm/log10f.c
	$(SDCC_EXE) $(SDCC_ARG) log10f.o ../../libm/log10f.c
logf.o : ../../libm/logf.c
	$(SDCC_EXE) $(SDCC_ARG) logf.o ../../libm/logf.c
modff.o : ../../libm/modff.c
	$(SDCC_EXE) $(SDCC_ARG) modff.o ../../libm/modff.c
powf.o : ../../libm/powf.c
	$(SDCC_EXE) $(SDCC_ARG) powf.o ../../libm/powf.c
sincosf.o : ../../libm/sincosf.c
	$(SDCC_EXE) $(SDCC_ARG) sincosf.o ../../libm/sincosf.c
sincoshf.o : ../../libm/sincoshf.c
	$(SDCC_EXE) $(SDCC_ARG) sincoshf.o ../../libm/sincoshf.c
sinf.o : ../../libm/sinf.c
	$(SDCC_EXE) $(SDCC_ARG) sinf.o ../../libm/sinf.c
sinhf.o : ../../libm/sinhf.c
	$(SDCC_EXE) $(SDCC_ARG) sinhf.o ../../libm/sinhf.c
sqrtf.o : ../../libm/sqrtf.c
	$(SDCC_EXE) $(SDCC_ARG) sqrtf.o ../../libm/sqrtf.c
tancotf.o : ../../libm/tancotf.c
	$(SDCC_EXE) $(SDCC_ARG) tancotf.o ../../libm/tancotf.c
tanf.o : ../../libm/tanf.c
	$(SDCC_EXE) $(SDCC_ARG) tanf.o ../../libm/tanf.c
tanhf.o : ../../libm/tanhf.c
	$(SDCC_EXE) $(SDCC_ARG) tanhf.o ../../libm/tanhf.c
_gptrget1.o : _gptrget1.S
	$(ASM_EXE) $(ASM_ARG) _gptrget1.o _gptrget1.S
_gptrget2.o : _gptrget2.S
	$(ASM_EXE) $(ASM_ARG) _gptrget2.o _gptrget2.S
_gptrget3.o : _gptrget3.S
	$(ASM_EXE) $(ASM_ARG) _gptrget3.o _gptrget3.S
_gptrget4.o : _gptrget4.S
	$(ASM_EXE) $(ASM_ARG) _gptrget4.o _gptrget4.S
_gptrput1.o : _gptrput1.S
	$(ASM_EXE) $(ASM_ARG) _gptrput1.o _gptrput1.S
_gptrput2.o : _gptrput2.S
	$(ASM_EXE) $(ASM_ARG) _gptrput2.o _gptrput2.S
_gptrput3.o : _gptrput3.S
	$(ASM_EXE) $(ASM_ARG) _gptrput3.o _gptrput3.S
_gptrput4.o : _gptrput4.S
	$(ASM_EXE) $(ASM_ARG) _gptrput4.o _gptrput4.S

clean:
	rm -f *.o *.lst *.asm *.lib ../../*.lib