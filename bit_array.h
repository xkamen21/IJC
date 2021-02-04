/** bit_array.h
  * Reseni: IJC - DU1
  * Autor: Daniel Kamenicky, FIT
  * Login: xkamen21
  * Prelozeno: gcc version 7.3.0
  * Datum odevzdani: 20.3.2019
  *
  * bit_array.h:  deklaruje makra a inline funkce
  *               podel typu prekladu dale predava makra ci inline funkce
  **/

#include "error.h"
#include <limits.h>

unsigned long jedna = 1;

typedef unsigned long* bit_array_t;

#define bit_array_create(jmeno_pole, velikost) unsigned long jmeno_pole[(velikost/sizeof(unsigned long)/CHAR_BIT)+(velikost%(sizeof(unsigned long)*CHAR_BIT)==0 ? 1 : 2)] = {velikost, 0, }

#define bit_array_alloc(jmeno_pole, velikost) unsigned long *jmeno_pole=calloc(((velikost/sizeof(unsigned long)/CHAR_BIT)+(velikost%(sizeof(unsigned long)*CHAR_BIT)==0 ? 1 : 2)),sizeof(unsigned long));\
jmeno_pole[0] = velikost\

#ifndef USE_INLINE //pouzivaji se makra

#define bit_array_free(jmeno_pole) free(jmeno_pole)

#define bit_array_size(jmeno_pole) (jmeno_pole[0]==0||jmeno_pole[0]<0?8:jmeno_pole[0])

#define bit_array_setbit(jmeno_pole, index, vyraz) (index>=0&&index<=(bit_array_size(jmeno_pole)))?\
jmeno_pole[1+(index/sizeof(unsigned long)/CHAR_BIT)]=(vyraz==0?jmeno_pole[1+(index/sizeof(unsigned long)/CHAR_BIT)]&= ~(jedna<<(index%(sizeof(unsigned long)*CHAR_BIT))):(jmeno_pole[1+(index/sizeof(unsigned long)/CHAR_BIT)]|=jedna<<(index%(sizeof(unsigned long)*CHAR_BIT))))\
:\
(error_exit("bit_array_setbit: index neni v rozahu 0..%lu", bit_array_size(jmeno_pole)),0)\

#define bit_array_getbit(jmeno_pole, index) ((index>=0&&index<=(bit_array_size(jmeno_pole)))?\
((jmeno_pole[1+(index/sizeof(unsigned long)/CHAR_BIT)]&(jedna<<(index%(sizeof(unsigned long)*CHAR_BIT))))!=0)\
:\
(error_exit("bit_array_getbit: index neni v rozahu 0..%lu", bit_array_size(jmeno_pole)),2))\

#else //pouzivaji se inline funkce

extern inline void bit_array_free(bit_array_t jmeno_pole)
{
  free(jmeno_pole);
}

extern inline unsigned long bit_array_size(bit_array_t jmeno_pole)
{
  return jmeno_pole[0];
}

extern inline void bit_array_setbit(bit_array_t jmeno_pole, unsigned long index, unsigned long vyraz)
{
  if(index>=0&&index<=(bit_array_size(jmeno_pole)))
  {
    if(vyraz==0)
    {
      jmeno_pole[1+(index/sizeof(unsigned long)/CHAR_BIT)]=jmeno_pole[1+(index/sizeof(unsigned long)/CHAR_BIT)]&= ~(jedna<<(index%(sizeof(unsigned long)*CHAR_BIT)));
    }
    else
    {
      jmeno_pole[1+(index/sizeof(unsigned long)/CHAR_BIT)]=(jmeno_pole[1+(index/sizeof(unsigned long)/CHAR_BIT)]|=jedna<<(index%(sizeof(unsigned long)*CHAR_BIT)));
    }
  }
  else
  {
    error_exit("bit_array_setbit: index neni v rozahu 0..%lu", bit_array_size(jmeno_pole));
  }
}

extern inline unsigned long bit_array_getbit(bit_array_t jmeno_pole, unsigned long index)
{
  if(index>=0&&index<=(bit_array_size(jmeno_pole)))
  {
    if((((jmeno_pole[1+(index/sizeof(unsigned long)/CHAR_BIT)]>>(index%(sizeof(unsigned long)*CHAR_BIT))) & jedna) > 0)==1)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    error_exit("bit_array_getbit: index neni v rozahu 0..%lu", bit_array_size(jmeno_pole));
  }
  return 0;
}

#endif //ukonceni podminky if pro inline funkce
