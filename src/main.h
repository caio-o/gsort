#ifndef __MAIN_H
#define __MAIN_H

#include "gsconfig.h"

extern struct GlobalConfig globalConf;

/*
 * Configure the globalConfig into the default values. Return 0 if OK.
 */
int gsConfigDefault (void);

#endif
