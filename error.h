/** error.h
  * Reseni: IJC - DU1
  * Autor: Daniel Kamenicky, FIT
  * Login: xkamen21
  * Prelozeno: gcc version 7.3.0
  * Datum odevzdani: 20.3.2019
  *
  * error.h:  hlavickovy soubor souboru error.c
  *           Deklaruje funkce warning_msg a error_exit.
  **/

#include "error.c"

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);
