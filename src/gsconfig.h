#ifndef __GSCONFIG_H
#define __GSCONFIG_H

#define BIT(x) unsigned int x:1

struct GlobalConfig
{
	BIT(silent);
};

#endif
