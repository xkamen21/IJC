/** ppm.h
  * Reseni: IJC - DU1
  * Autor: Daniel Kamenicky, FIT
  * Login: xkamen21
  * Prelozeno: gcc version 7.3.0
  * Datum odevzdani: 20.3.2019
  *
  * ppm.h:  Hlavickovy soubor k soubrou ppm.c
  *         Deklarace funkci.
  **/

struct ppm{
  unsigned xsize;
  unsigned ysize;
  char data[];      //RGB bajty celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);

void ppm_free(struct ppm *p);
