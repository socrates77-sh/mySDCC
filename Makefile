#
# sdcc project main Makefile
#

SHELL           = /bin/sh


srcdir          = .
top_builddir    = .
top_srcdir      = .

EXEEXT          = .exe

include Makefile.common

SDCC_LIBS       = support/makebin
SDCC_SCRIPTS    = support/scripts
SDCC_DOC        = doc

# Parts that are not normally compiled but need to be cleaned
SDCC_EXTRA      = support/regression support/valdiag

SDCC_PACKIHX    = support/packihx
SDCC_LIBRARIAN  = support/librarian
SDCC_SDBINUTILS = support/sdbinutils

TARGETS         = sdcc-librarian

ifeq ($(OPT_DISABLE_HC08), 0)
SDCC_AS        += sdas/as6808
SDCC_LD        += sdcc-ld6808
endif

ifeq ($(OPT_DISABLE_MCS51), 0)
SDCC_AS        += sdas/as8051
SDCC_LD        += sdcc-ld8051
SDCC_MISC      += debugger/mcs51
endif

ifeq ($(OPT_DISABLE_Z80), 0)
SDCC_AS        += sdas/asz80
SDCC_LD        += sdcc-ldz80
endif

ifeq ($(OPT_DISABLE_R2K), 0)
SDCC_AS        += sdas/asrab
SDCC_LD        += sdcc-ldz80
endif

ifeq ($(OPT_DISABLE_GBZ80), 0)
SDCC_AS        += sdas/asgb
SDCC_LD        += sdcc-ldgb
endif

ifeq ($(OPT_DISABLE_UCSIM), 0)
TARGETS        += sdcc-misc
SDCC_MISC      += sim/ucsim
PKGS           += $(SDCC_MISC)
endif

SDCC_BINUTILS   = 
ifeq ($(OPT_DISABLE_SDBINUTILS), 0)
TARGETS        += sdcc-sdbinutils
PKGS           += $(SDCC_SDBINUTILS)
SDBINUTILS_BINS = sdar$(EXEEXT) sdranlib$(EXEEXT) sdnm$(EXEEXT)
SDCC_BINUTILS   = sdcc-sdbinutils
endif

ifeq ($(OPT_DISABLE_DEVICE_LIB), 0)
TARGETS        += sdcc-device-lib
PKGS           += device/lib device/non-free/lib
endif

ifeq ($(OPT_DISABLE_PACKIHX), 0)
TARGETS        += sdcc-packihx
PKGS           += $(SDCC_PACKIHX)
endif

ifeq ($(OPT_ENABLE_DOC), 1)
TARGETS        += sdcc-doc
endif
# always install docs, which don't need to be built 
PKGS            += $(SDCC_DOC)

ifeq ($(OPT_DISABLE_SDCPP), 0)
SDCC_LIBS      += support/cpp
endif

TARGETS        += sdcc-libs sdcc-cc sdcc-device-inc sdcc-as sdcc-ld sdcc-scripts

PKGS           += $(SDCC_LIBS) src device/include device/non-free/include \
                  $(SDCC_AS) sdas/linksrc $(SDCC_LIBRARIAN) \
                  $(SDCC_SDBINUTILS) $(SDCC_SCRIPTS)

PORTS           = $(shell cat ports.build)
ALLPORTS        = $(shell cat ports.all)

# Compiling entire program or any subproject
# ------------------------------------------
all: checkconf sdcc

tini: checkconf sdcc-tini

sdcc-libs:
	for lib in $(SDCC_LIBS); do $(MAKE) -C $$lib; done

sdcc-cc: sdcc-libs
	$(MAKE) -C src

sdcc-as:
	for as in $(SDCC_AS); do $(MAKE) -C $$as ; done

sdcc-ld:
	$(MAKE) -C sdas/linksrc $(SDCC_LD)

sdcc-misc:
	for misc in $(SDCC_MISC); do $(MAKE) -C $$misc ; done

sdcc-scripts:
	$(MAKE) -C $(SDCC_SCRIPTS)

sdcc-packihx:
	$(MAKE) -C $(SDCC_PACKIHX)

sdcc-librarian:
	$(MAKE) -C $(SDCC_LIBRARIAN)

sdcc-sdbinutils:
	$(MAKE) -C $(SDCC_SDBINUTILS)
	# in some cases (cygwin) the real binaries are in .libs
	for bin in $(SDBINUTILS_BINS); do \
	  if [ -f $(SDCC_SDBINUTILS)/binutils/.libs/$$bin ]; then \
	    cp $(SDCC_SDBINUTILS)/binutils/.libs/$$bin bin; \
	  else \
	    cp $(SDCC_SDBINUTILS)/binutils/$$bin bin; \
	  fi \
	done

sdcc-device-inc:
	$(MAKE) -C device/include
	$(MAKE) -C device/non-free/include

sdcc-device-lib: sdcc-cc sdcc-as sdcc-ld $(SDCC_BINUTILS)
	$(MAKE) -C device/lib
	$(MAKE) -C device/non-free/lib

sdcc-device-tini:
	$(MAKE) -C device/include
	$(MAKE) -C device/non-free/include
	$(MAKE) -C device/lib model-ds390 model-ds400

# doc depends on latex and latex2html
sdcc-doc:
	$(MAKE) -C doc

sdcc: $(TARGETS)

sdcc-tini: sdcc-librarian sdcc-cc sdcc-as sdcc-ld sdcc-device-tini sdcc-packihx
	$(MAKE) -f main.mk all

# Some interesting sub rules
sdcc-bin: sdcc-cc sdcc-as sdcc-ld sdcc-misc

sdcc-base: sdcc-cc sdcc-as sdcc-ld

# Compiling and installing everything and running test
# ----------------------------------------------------
install: checkconf sdcc
	$(MAKE) -f main.mk install
	@for pkg in $(PKGS); do\
	  $(MAKE) -C $$pkg install ;\
	done

# Deleting all the installed files
# --------------------------------
uninstall:
	$(MAKE) -f main.mk uninstall
	@for pkg in $(PKGS); do\
	  $(MAKE) -C $$pkg uninstall ;\
	done

# Deleting all files created by building the program
# --------------------------------------------------
clean:
	@echo "+ Cleaning root of the project..."
	$(MAKE) -f $(srcdir)/clean.mk clean
	@echo "+ Cleaning packages in their directories..."
	for pkg in $(PKGS); do\
	  $(MAKE) -C $$pkg PORTS="$(PORTS)" EXEEXT=$(EXEEXT) clean ;\
	done

# Deleting all files created by configuring or building the program
# -----------------------------------------------------------------
distclean:
	@echo "+ DistCleaning packages using clean.mk..."
	for pkg in $(PKGS); do\
	  $(MAKE) -C $$pkg PORTS="$(PORTS)" EXEEXT=$(EXEEXT) distclean ;\
	done
	for pkg in $(SDCC_EXTRA); do \
	  $(MAKE) -C $$pkg distclean; \
	done
	@echo "+ DistCleaning root of the project..."
	$(MAKE) -f $(srcdir)/clean.mk distclean

# Like clean but some files may still exist
# -----------------------------------------
mostlyclean: clean
	$(MAKE) -f $(srcdir)/clean.mk mostlyclean
	for pkg in $(PKGS); do\
	  $(MAKE) -C $$pkg PORTS="$(PORTS)" EXEEXT=$(EXEEXT) mostlyclean ;\
	done

# Deleting everything that can reconstructed by this Makefile. It deletes
# everything deleted by distclean plus files created by bison, stc.
# -----------------------------------------------------------------------
realclean: distclean
	$(MAKE) -f $(srcdir)/clean.mk realclean
	for pkg in $(PKGS); do\
	  $(MAKE) -C $$pkg PORTS="$(PORTS)" EXEEXT=$(EXEEXT) realclean ;\
	done

# Creating distribution
# ---------------------
dist: distclean
	@if [ -f devel ]; then\
	  rm -f devel; mkdist sdcc; touch devel;\
	else\
	  mkdist sdcc;\
	fi

# Performing self-test
# --------------------
check:

# Performing installation test
# ----------------------------
installcheck:

# Creating dependencies
# ---------------------
dep: $(SDCC_LIBS)
	$(MAKE) -f main.mk dep
	@for pkg in $(PKGS); do\
	  $(MAKE) -C $$pkg dep ;\
	done

# My rules
# --------
newer: distclean
	@if [ -f start ]; then \
	  tar cvf - \
	    `find . -newer start -type f -print` |\
	  gzip -9c >`date '+%m%d%H%M'`.tgz; \
	else \
	  echo "start file not found.\n"; \
	  exit 1; \
	fi

putcopyright:
	'put(c)' -s $(STARTYEAR) *.cc *.h *.y *.l

# Remaking configuration
# ----------------------
configure: configure.in
	$(SHELL) $(AUTOCONF)

main.mk: $(srcdir)/main_in.mk $(srcdir)/configure.in config.status
	$(SHELL) ./config.status

Makefiles: makefiles

makefiles: config.status

config.status: configure
	$(SHELL) ./config.status --recheck

makefiles:
	$(SHELL) ./config.status

freshconf: main.mk

checkconf:
	@if [ -f devel ]; then\
	  $(MAKE) freshconf;\
	fi

# End of Makefile
