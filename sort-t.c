/********************************************************************/
/** FACULDADE DE COMPUTACAO (FACOM) UFMS                            */
/** ALGORITMOS E PROGRAMACAO 2                                      */
/** PROFESSOR: DR. ANDERSON BESSA DA COSTA                          */
/**                                                                 */
/** ATIVIDADE EAD 1 VALENDO PRESENCA PARA 09/09/2025                */
/** BUBBLE SORT GENERICO, usando ponteiro para funcao               */
/**                                                                 */
/** ALUNO    : CAIO E SILVA BARBIERI                                */
/** RGA ALUNO: 202519040146                                         */
/** DATA     : 10 set 2025                                          */
/**                                                                 */
/** CONTEUDO : Funcao requisitada bubble_sort,                      */
/**            Funcao auxiliar swap,                                */
/**                                                                 */
/********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include <sort-t.h>

/**
 * bubble_sort function implementation.
 * requested by the Professor.
 * Requisitado pelo professor.
 */
void bubble_sort (void* base,      // Vector to be sorted 
		  size_t n_items,  // Amount of vector elements
		  size_t size,     // Size of vector elements
		  int (*compare) (const void*, const void*)) // Ordering relation
{
	size_t i, j, aux;
	char* cBase = (char*) base;	

	for (i = 0; i < n_items-1; i++)
	{
		for (j = 0; j < n_items - i - 1; j++)
		{
			if (compare (&(cBase[j*size]), &(cBase[(j+1)*size])) > 0)
			{
				swap (&(cBase[j*size]), &(cBase[(j+1)*size]), size);	
			}
		}
	}
}

void swap (void *a, void *b, size_t size) 
{
	void *tmp = malloc(sizeof(char) * size);
	
	memcpy (tmp, a,   size); // *tmp = *a
	memcpy (a,   b,   size); // *a   = *b
	memcpy (b,   tmp, size); // *b   = *tmp

	free (tmp);
}
