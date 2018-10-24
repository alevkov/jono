#ifndef str_h
#define str_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* str;
static const int HDR_SIZE = 4;

// assume any ptr passed to public function is at base 0 relative to HDR
str  str_new(const char *s);
int  str_len(str s);
str  str_cpy(str s);
str  str_cat(str a, str b);
str  str_cut(str s, int r1, int r2);
str  str_sub(str a, int r1, int r2);
void str_del(str a);
int  str_toi(str a);

#endif /* str_h */
