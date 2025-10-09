#ifndef __SORT_H_DEFINED
#define __SORT_H_DEFINED

/**
 * Swaps generic elements <a> and <b>.
 * size: size_t size of a and b in bytes.
 */
void  swap      (void *a, void *b, size_t size);

/*******************************************************/
/** Funcao bubble sort, requisitada pelo Professor.    */
/** Bubble sort function, requested by the Professor.  */
/*******************************************************/
/**
 * Sorts base vector according to bubble sort algorithm,
 * using provided compare function.
 *
 * base:    void* vector to be ordered
 * n_items: size_t ammount of vector elements
 * size:    size_t size of each element, in bytes
 * compare: pointer to generic compare function, for ordering
 */
void bubble_sort (void* base,
                  size_t n_items,
                  size_t size,
                  int (*compare) (const void*, const void*));

#endif

