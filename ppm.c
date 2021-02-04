/** ppm.c
  * Reseni: IJC - DU1
  * Autor: Daniel Kamenicky, FIT
  * Login: xkamen21
  * Prelozeno: gcc version 7.3.0
  * Datum odevzdani: 20.3.2019
  *
  * ppm.c:  Definuje funkce ppm_free a ppm_read
  *         Otevira soubor .ppm a cte ho do struktury.
  *         Kontroluje vsechny vstupy a dale vraci nactenou strukturu.
  **/

#include "ppm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ppm_free(struct ppm *p)
{
  free(p);
}

struct ppm * ppm_read(const char * filename)
{
  int colors;
  unsigned xsizetxt;
  unsigned ysizetxt;
  FILE *f1 = fopen(filename, "r");
  if(f1==NULL)
  {
    warning_msg("ppm.c\nNepodarilo se otevrit soubor");
    return NULL;
  }

   if(fscanf(f1, "P6 %u %u %d ", &xsizetxt, &ysizetxt, &colors)!=3)
   {
     warning_msg("ppm.c\nchybny soubor .ppm");
     fclose(f1);
     return NULL;
   }

   if(xsizetxt<=0||ysizetxt<=0||colors!=255)
   {
     warning_msg("ppm.c\ndata v hlavicce souboru .ppm neodpovidaji\nOCEKAVANA DATA:\n\txsize>0, nacteno: %u\n\tysize>0, nacteno: %u\n\tcolors=255, nacteno: %d", xsizetxt, ysizetxt, colors);
     fclose(f1);
     return NULL;
   }

     struct ppm* obrazek = malloc((3*xsizetxt*ysizetxt*sizeof(char))+sizeof(struct ppm));
     if(obrazek==NULL)
     {
       warning_msg("ppm.c\nchyba alokace struktury");
       fclose(f1);
       return NULL;
     }

     if(fread(&obrazek->data, sizeof(char), (3*xsizetxt*ysizetxt*sizeof(char)), f1)!=(3*xsizetxt*ysizetxt*sizeof(char)))
     {
       warning_msg("ppm.c\nchyba nacitani souboru do struktury");
       ppm_free(obrazek);
       fclose(f1);
       return NULL;
     }

     obrazek->xsize=xsizetxt;
     obrazek->ysize=ysizetxt;

     fclose(f1);
     return obrazek;
}
