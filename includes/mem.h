#ifndef MEM_H

#include "libal.h"

void	al_memdel(void *mem, size_t n);

void 	*al_memalloc(size_t n);
void	*al_memcpy(void *dest, const void *src, size_t n);


#endif
