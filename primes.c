/** primes.c
  * Reseni: IJC - DU1
  * Autor: Daniel Kamenicky, FIT
  * Login: xkamen21
  * Prelozeno: gcc version 7.3.0
  * Datum odevzdani: 20.3.2019
  *
  * primes.c:	staticky alokuje bitove pole 'string'
  *						volanim funkce 'eratosthenes' eliminuje cisla, ktere nejsou prvocislem
  *						vypise poslednich 10 prvocisel vzestupnym smerem
  **/

#include "bit_array.h"
#include <stdlib.h>
#include <stdio.h>
#include "eratosthenes.c"

int main(void)
{
	bit_array_create(string, 123000000);
	if(bit_array_size(string)<2)
	{
		error_exit("bit_array_size: v rozsahu 0..%lu neni zadne prvocislo", bit_array_size(string));
	}
	eratosthenes(string);
	int count=0;
	for(unsigned long i = bit_array_size(string)-1; i > 1; i--)
	{
		if(!bit_array_getbit(string, i))
			{
					count++;
					if(i==2)
					{
						count=10;
					}
					if (count == 10)
					{
						for(; i<bit_array_size(string); i++)
						{
							if(!bit_array_getbit(string, i))
							{
								printf("%ld\n", i);
							}
						}
						i=1;
					}
			}
	}
	return 0;
}
