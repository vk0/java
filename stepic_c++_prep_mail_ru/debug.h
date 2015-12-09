// Реализация журналирования

#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#define PDEBUG(level,fmt,args,...)
#ifdef DEBUG
#undef PDEBUG
#define PDEBUG(level,fmt,args,...)\
    if(level <= DEBUG)
        printf("%s:%d: " fmt "\n", __FUNCTION__, __LINE__, ##args)
#endif
#endif