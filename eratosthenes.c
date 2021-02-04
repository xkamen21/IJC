/** eratosthenes.c
  * Reseni: IJC - DU1
  * Autor: Daniel Kamenicky, FIT
  * Login: xkamen21
  * Prelozeno: gcc version 7.3.0
  * Datum odevzdani: 20.3.2019
	*
	* eratosthenes.c:	definuje funkci 'eratosthenes'
	*									funkce vyuziva eratosthenovu eliminacni metodu
	*									eliminuje vsechna cisla v bitovem poli tak, ze nastavi bit na 1, kdyz cislo neni prvocislem
  **/

#include <math.h>

void eratosthenes(bit_array_t string)
{
	double x = sqrt(bit_array_size(string));
	unsigned long n = bit_array_size(string);
	unsigned long i = 0;
	bit_array_setbit(string, i, 1);
	i++;
	bit_array_setbit(string, i, 1);
	for(i = 2; i<x; i++)
	{
			if(!bit_array_getbit(string, i))
			{
				for (unsigned long j = 2; (i*j) < n; j++)
					{
						if(!bit_array_getbit(string, i*j))
							bit_array_setbit(string, (i*j), 1);
					}
			}
	}
}
