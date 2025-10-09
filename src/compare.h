#include <time.h>

#ifndef __COMPARE_H_DEFINED
#define __COMPARE_H_DEFINED

/**********************************************/
/** Comparison functions for different types  */
/**********************************************/

int   intcmp        (const void*   a,   const void*   b); // integers
int   charcmp       (const void*   a,   const void*   b); // characters / bytes
int   alphacmp      (const void*   a,   const void*   b); // case ignoreing charcmp
int   floatcmp      (const void*   a,   const void*   b); // floating point nums
int   dblcmp        (const void*   a,   const void*   b); // doubles / long floats

int   timecmp       (const void*   a,   const void*   b);

#endif
