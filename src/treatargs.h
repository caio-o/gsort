#ifndef __TREATARGS_H
#define __TREATARGS_H


#define OPT_FILEPATH   'F'
#define OPT_NUMS       'N'
#define OPT_TEST       't'
#define OPT_LIST_TYPE  "acdif"
#define OPT_LIST_ALL   "F:N:acdift"

/*
 * treatArgs shall take the chars, and parse them (1) to set the settings and
 * (2) to make the list of operations. A list, because many input files may be
 * chosen.
 */
int treatArgs (int argc, char** argv);

#endif
