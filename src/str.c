#include "str.h"

// assume any ptr passed to public function is at base 0 relative to HDR
static inline void update_len(str _s, size_t len)
{
  for (int i = 0, j = 24; i < HDR_SIZE; i++) {
    _s[i] = (len >> j) & 0xFF; j = j - 8;
  }
}

str str_new(const char *s)
{
  if (s == NULL)
    return NULL;
  size_t len = strlen(s);
  char *_s = (char *)malloc((len + HDR_SIZE) * sizeof(char));
  memmove(_s + HDR_SIZE, s, len);
  _s[len + HDR_SIZE] = '\0';
  update_len(_s, len);
  
  return _s + HDR_SIZE;
}

int str_len(str s)
{
  char *_s = s - HDR_SIZE;
  int len = 0;
  for (int i = 0, j = 24; i < HDR_SIZE; i++) {
    len |= ((int)_s[i] << j);
    j = j - 8;
  }
  return len;
}

str str_cpy(str s)
{
  int len = str_len(s);
  str _s = (char *)malloc((HDR_SIZE + len) * sizeof(char));
  memmove(_s, s - HDR_SIZE, len + HDR_SIZE);
  _s[len + HDR_SIZE] = '\0';
  
  return _s + HDR_SIZE;
}

str str_cat(str a, str b)
{
  int la = str_len(a);
  int lb = str_len(b);
  char *_s = a - HDR_SIZE;
  _s = (char *)realloc(_s, (la + lb + HDR_SIZE) * sizeof(char));
  memmove(_s + la, b, lb);
  _s[la + lb] = '\0';
  update_len(_s, la + lb);
  
  return _s + HDR_SIZE;
}

str str_cut(str s, int r1, int r2)
{
  int range = r2 - r1, orig_len = str_len(s);
  if (range > orig_len || range < 1) return s;
  memmove(s + r1, s + r2, orig_len - r2);
  s[orig_len - range] = '\0';
  char *_s = s - HDR_SIZE;
  update_len(_s, orig_len - range);
  
  return _s + HDR_SIZE;
}

str str_sub(str s, int r1, int r2)
{
  int range = r2 - r1;
  if (range > str_len(s) || range < 1) return s;
  char *_r = (char *)malloc((HDR_SIZE + range) * sizeof(char));
  memmove(_r + HDR_SIZE, s + r1, range);
  _r[HDR_SIZE + range] = '\0';
  update_len(_r, range);
  
  return _r + HDR_SIZE;
}

void str_del(str s)
{
  free(s - HDR_SIZE);
}

int str_toi(char *s)
{
  int num = 0;
  while(*s >= '0' && *s <= '9') {
    num = (*s - '0') + num * 10; s++;
  }
  return num;
}
