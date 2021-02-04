/** steg-decode.c
  * Reseni: IJC - DU1
  * Autor: Daniel Kamenicky, FIT
  * Login: xkamen21
  * Prelozeno: gcc version 7.3.0
  * Datum odevzdani: 20.3.2019
  *
  * steg-decode.c:  Pomoci funkce 'ppm_read', definovane v zdrojovem souboru ppm.c, nam .ppm soubor zapise do struktury.
  *                 Dynamicky alokuje pomocne bitove pole, ktere dale eliminuje vsechna cisla, ktere nejsou prvocislem
  *                 Obrazek dale prochazi a zjistuje LSB bity na kazdem prvocisle(porovnavanim s bitovym polem), ktere zapisuje do externi promenne char.
  *                 Po dosazeni 8 bitu (velikosti znaku char) znak vypise
  *                 Dale znaky vypisuje az po ukoncujici znak '\0'
  **/

#include <stdlib.h>
#include <stdio.h>
#include "bit_array.h"
#include "eratosthenes.c"
#include "ppm.c"
#include <limits.h>

int main(int argc, char const *argv[]) {
  int znak=0, counter=0;
  if(argc!=2)
  {
    error_exit("steg-decode.c\nzadejte nasledovne: ./steg-decode du1-obrazek.ppm");
  }

  struct ppm* obrazek = ppm_read(argv[1]);

  if(obrazek==NULL)
  {
    error_exit("steg-decode.c\nspatne nacteny obrazek");
  }
  unsigned long size = (3*sizeof(char)*obrazek->xsize*obrazek->ysize);

  bit_array_alloc(pole_ppm,size);

  eratosthenes(pole_ppm);

  for(int i=18; i<size; i++)
  {
    if(!bit_array_getbit(pole_ppm, i))
    {
      if((obrazek->data[i]&1)==1)
      {
        znak|=1<<counter;
      }
      else
      {
        znak&= ~(1<<counter);
      }
      counter++;
      if(counter==CHAR_BIT)
      {
        if(znak==0)
        {
          counter= -1;
          break;
        }
        if(znak>0&&znak<=255)
        {
        printf("%c", znak);
        }
        else
        {
          warning_msg("steg-decode.c\nnetisknutelny znak, znak musi byt v intervalu <0, 255> a je %d", znak);
        }
        counter=0;
      }
    }
  }
  if(counter!=-1)
  {
    error_exit("steg-decode.c\nnenacten ukoncujici znak");
  }
  ppm_free(obrazek);
  bit_array_free(pole_ppm);
  printf("\n");
  return 0;
}
