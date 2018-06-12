BEGIN {
S["LTLIBOBJS"]=""
S["LIBOBJS"]=""
S["subdirs"]=" support/cpp"
S["OPT_ENABLE_LIBGC"]="0"
S["MAKEINDEX"]=":"
S["PDFOPT"]=":"
S["PDFLATEX"]=":"
S["LATEX2HTML"]=":"
S["LYX"]=":"
S["OPT_ENABLE_DOC"]="0"
S["OPT_DISABLE_SDBINUTILS"]="1"
S["OPT_DISABLE_SDCDB"]="1"
S["OPT_DISABLE_SDCPP"]="0"
S["OPT_DISABLE_PACKIHX"]="1"
S["OPT_DISABLE_DEVICE_LIB"]="1"
S["OPT_DISABLE_UCSIM"]="1"
S["OPT_DISABLE_XA51"]="1"
S["OPT_DISABLE_AVR"]="1"
S["OPT_DISABLE_S08"]="1"
S["OPT_DISABLE_HC08"]="1"
S["OPT_DISABLE_PIC16"]="1"
S["OPT_DISABLE_PIC14"]="1"
S["OPT_DISABLE_DS400"]="1"
S["OPT_DISABLE_DS390"]="1"
S["OPT_DISABLE_GBZ80"]="1"
S["OPT_DISABLE_R3KA"]="1"
S["OPT_DISABLE_R2K"]="1"
S["OPT_DISABLE_Z180"]="1"
S["OPT_DISABLE_Z80"]="1"
S["OPT_DISABLE_MCS51"]="1"
S["non_free_lib_dir_suffix"]="sdcc/non-free/lib"
S["lib_dir_suffix"]="sdcc/lib"
S["non_free_include_dir_suffix"]="sdcc/non-free/include"
S["include_dir_suffix"]="sdcc/include"
S["LIB_TYPE"]="RANLIB"
S["sdccconf_h_dir_separator"]="\\\\"
S["C99_FLAG"]="--std=c99"
S["WALL_FLAG"]="-Wall -Wno-parentheses"
S["MAKEDEP"]="gcc -MM"
S["CCACHE"]=""
S["CXXCPP"]="g++ -E"
S["EGREP"]="/bin/grep -E"
S["GREP"]="/bin/grep"
S["YACC"]="bison -y"
S["LEX"]="flex"
S["AR"]="ar"
S["CP"]="cp"
S["AS"]="as"
S["STRIP"]="strip"
S["AUTOCONF"]="autoconf"
S["RANLIB"]="ranlib"
S["INSTALL_DATA"]="${INSTALL} -m 644"
S["INSTALL_SCRIPT"]="${INSTALL}"
S["INSTALL_PROGRAM"]="${INSTALL}"
S["ac_ct_CXX"]="g++"
S["CXXFLAGS"]="-pipe -ggdb -g"
S["CXX"]="g++"
S["CPP"]="gcc -E"
S["OBJEXT"]="o"
S["EXEEXT"]=".exe"
S["ac_ct_CC"]="gcc"
S["CPPFLAGS"]=""
S["LDFLAGS"]=""
S["CFLAGS"]="-fms-extensions -pipe -ggdb -g"
S["CC"]="gcc"
S["VERSIONP"]="4"
S["VERSIONLO"]="1"
S["VERSIONHI"]="1"
S["VERSION"]="1.1.4"
S["PACKAGE"]="sdcc"
S["AWK"]="gawk"
S["host_os"]="mingw32"
S["host_vendor"]="pc"
S["host_cpu"]="i686"
S["host"]="i686-pc-mingw32"
S["build_os"]="mingw32"
S["build_vendor"]="pc"
S["build_cpu"]="i686"
S["build"]="i686-pc-mingw32"
S["target_alias"]=""
S["host_alias"]=""
S["build_alias"]=""
S["LIBS"]=""
S["ECHO_T"]=""
S["ECHO_N"]="-n"
S["ECHO_C"]=""
S["DEFS"]="-DHAVE_CONFIG_H"
S["mandir"]="${datarootdir}/man"
S["localedir"]="${datarootdir}/locale"
S["libdir"]="${exec_prefix}/lib"
S["psdir"]="${docdir}"
S["pdfdir"]="${docdir}"
S["dvidir"]="${docdir}"
S["htmldir"]="${docdir}"
S["infodir"]="${datarootdir}/info"
S["docdir"]="${datarootdir}/doc/${PACKAGE}"
S["oldincludedir"]="/usr/include"
S["includedir"]="${prefix}/include"
S["localstatedir"]="${prefix}/var"
S["sharedstatedir"]="${prefix}/com"
S["sysconfdir"]="${prefix}/etc"
S["datadir"]="${datarootdir}"
S["datarootdir"]="${prefix}/share"
S["libexecdir"]="${exec_prefix}/libexec"
S["sbindir"]="${exec_prefix}/sbin"
S["bindir"]="${exec_prefix}/bin"
S["program_transform_name"]="s,x,x,"
S["prefix"]="/usr/local"
S["exec_prefix"]="${prefix}"
S["PACKAGE_URL"]=""
S["PACKAGE_BUGREPORT"]=""
S["PACKAGE_STRING"]=""
S["PACKAGE_VERSION"]=""
S["PACKAGE_TARNAME"]=""
S["PACKAGE_NAME"]=""
S["PATH_SEPARATOR"]=":"
S["SHELL"]="/bin/sh"
  for (key in S) S_is_set[key] = 1
  FS = ""

}
{
  line = $ 0
  nfields = split(line, field, "@")
  substed = 0
  len = length(field[1])
  for (i = 2; i < nfields; i++) {
    key = field[i]
    keylen = length(key)
    if (S_is_set[key]) {
      value = S[key]
      line = substr(line, 1, len) "" value "" substr(line, len + keylen + 3)
      len += length(value) + length(field[++i])
      substed = 1
    } else
      len += 1 + keylen
  }

  print line
}
