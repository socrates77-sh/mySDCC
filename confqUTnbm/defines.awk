BEGIN {
D["PACKAGE_NAME"]=" \"\""
D["PACKAGE_TARNAME"]=" \"\""
D["PACKAGE_VERSION"]=" \"\""
D["PACKAGE_STRING"]=" \"\""
D["PACKAGE_BUGREPORT"]=" \"\""
D["PACKAGE_URL"]=" \"\""
D["SDCC_VERSION_LO"]=" 1"
D["SDCC_VERSION_HI"]=" 1"
D["SDCC_VERSION_P"]=" 4"
D["SDCC_VERSION_STR"]=" \"1.1.4\""
D["STDC_HEADERS"]=" 1"
D["HAVE_SYS_TYPES_H"]=" 1"
D["HAVE_SYS_STAT_H"]=" 1"
D["HAVE_STDLIB_H"]=" 1"
D["HAVE_STRING_H"]=" 1"
D["HAVE_MEMORY_H"]=" 1"
D["HAVE_STRINGS_H"]=" 1"
D["HAVE_INTTYPES_H"]=" 1"
D["HAVE_STDINT_H"]=" 1"
D["HAVE_UNISTD_H"]=" 1"
D["HAVE_BOOST_GRAPH_ADJACENCY_LIST_HPP"]=" 1"
D["HAVE_STRERROR"]=" 1"
D["HAVE_VSNPRINTF"]=" 1"
D["HAVE_SNPRINTF"]=" 1"
D["HAVE_VSPRINTF"]=" 1"
D["HAVE_MKSTEMP"]=" 1"
D["UNNAMED_STRUCT_TAG"]=" 1"
D["RETSIGTYPE"]=" void"
D["SIZEOF_CHAR"]=" 1"
D["SIZEOF_SHORT"]=" 2"
D["SIZEOF_INT"]=" 4"
D["SIZEOF_LONG"]=" 4"
D["SIZEOF_LONG_LONG"]=" 8"
D["TYPE_BYTE"]=" char"
D["TYPE_WORD"]=" short"
D["TYPE_DWORD"]=" int"
D["TYPE_QWORD"]=" long long"
D["TYPE_UBYTE"]=" unsigned char"
D["TYPE_UWORD"]=" unsigned short"
D["TYPE_UDWORD"]=" unsigned int"
D["TYPE_UQWORD"]=" unsigned long long"
D["DIR_SEPARATOR_STRING"]=" \"\\\\\""
D["DIR_SEPARATOR_CHAR"]=" '\\\\'"
D["PREFIX"]=" \"\\\\usr\\\\local\""
D["EXEC_PREFIX"]=" \"\\\\usr\\\\local\""
D["BINDIR"]=" \"\\\\usr\\\\local\\\\bin\""
D["DATADIR"]=" \"\\\\usr\\\\local\\\\share\""
D["INCLUDE_DIR_SUFFIX"]=" DIR_SEPARATOR_STRING \"sdcc\\\\include\""
D["NON_FREE_INCLUDE_DIR_SUFFIX"]=" DIR_SEPARATOR_STRING \"sdcc\\\\non-free\\\\include\""
D["LIB_DIR_SUFFIX"]=" DIR_SEPARATOR_STRING \"sdcc\\\\lib\""
D["NON_FREE_LIB_DIR_SUFFIX"]=" DIR_SEPARATOR_STRING \"sdcc\\\\non-free\\\\lib\""
D["BIN2DATA_DIR"]=" DIR_SEPARATOR_STRING \"..\\\\share\""
D["PREFIX2BIN_DIR"]=" DIR_SEPARATOR_STRING \"bin\""
D["PREFIX2DATA_DIR"]=" DIR_SEPARATOR_STRING \"share\""
D["STD_LIB"]=" \"libsdcc\""
D["STD_INT_LIB"]=" \"libint\""
D["STD_LONG_LIB"]=" \"liblong\""
D["STD_FP_LIB"]=" \"libfloat\""
D["STD_DS390_LIB"]=" \"libds390\""
D["STD_DS400_LIB"]=" \"libds400\""
D["STD_XA51_LIB"]=" \"libxa51\""
D["SDCC_DIR_NAME"]=" \"SDCC_HOME\""
D["SDCC_INCLUDE_NAME"]=" \"SDCC_INCLUDE\""
D["SDCC_LIB_NAME"]=" \"SDCC_LIB\""
D["OPT_DISABLE_MCS51"]=" 1"
D["OPT_DISABLE_Z80"]=" 1"
D["OPT_DISABLE_Z180"]=" 1"
D["OPT_DISABLE_R2K"]=" 1"
D["OPT_DISABLE_R3KA"]=" 1"
D["OPT_DISABLE_GBZ80"]=" 1"
D["OPT_DISABLE_DS390"]=" 1"
D["OPT_DISABLE_TININative"]=" 1"
D["OPT_DISABLE_DS400"]=" 1"
D["OPT_DISABLE_MC30"]=" 0"
D["OPT_DISABLE_MC32"]=" 0"
D["OPT_DISABLE_MC35"]=" 0"
D["OPT_DISABLE_PIC14"]=" 1"
D["OPT_DISABLE_PIC16"]=" 1"
D["OPT_DISABLE_HC08"]=" 1"
D["OPT_DISABLE_S08"]=" 1"
D["OPT_DISABLE_AVR"]=" 1"
D["OPT_DISABLE_XA51"]=" 1"
D["OPT_DISABLE_UCSIM"]=" 1"
D["OPT_DISABLE_DEVICE_LIB"]=" 1"
D["OPT_DISABLE_PACKIHX"]=" 1"
D["OPT_DISABLE_SDCPP"]=" 0"
D["OPT_DISABLE_SDCDB"]=" 1"
D["OPT_DISABLE_SDBINUTILS"]=" 1"
D["OPT_ENABLE_DOC"]=" 0"
D["OPT_ENABLE_LIBGC"]=" 0"
  for (key in D) D_is_set[key] = 1
  FS = ""
}
/^[\t ]*#[\t ]*(define|undef)[\t ]+[_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ][_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789]*([\t (]|$)/ {
  line = $ 0
  split(line, arg, " ")
  if (arg[1] == "#") {
    defundef = arg[2]
    mac1 = arg[3]
  } else {
    defundef = substr(arg[1], 2)
    mac1 = arg[2]
  }
  split(mac1, mac2, "(") #)
  macro = mac2[1]
  prefix = substr(line, 1, index(line, defundef) - 1)
  if (D_is_set[macro]) {
    # Preserve the white space surrounding the "#".
    print prefix "define", macro P[macro] D[macro]
    next
  } else {
    # Replace #undef with comments.  This is necessary, for example,
    # in the case of _POSIX_SOURCE, which is predefined and required
    # on some systems where configure will not decide to define it.
    if (defundef == "undef") {
      print "/*", prefix defundef, macro, "*/"
      next
    }
  }
}
{ print }
