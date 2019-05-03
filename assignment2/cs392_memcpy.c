//I pledge my honor that I have abided by the Stevens Honor System - atartagl

#include "cs392_string.h"

void * cs392_memcpy(void *dst, void *src, unsigned num) {
	//copies “num” bytes of data from the memory pointed to by “src” to the memory pointed to by “dst”
	char *pszDest = (char *) dst;
 
	char *pszSource = (char*) src;
 
	 while(num) { 
	     *(pszDest++)= *(pszSource++); 
	     --num;
	  }
	  return dst;
}