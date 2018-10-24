#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "str.h"

int main(int argc, const char * argv[]) {
  char s[] = "testtesttesttesttest";
  str j = str_new(s);
  
  assert(str_len(j) == 20);
  
  printf("The string is \"%s\"\n", j);
  printf("The length is \"%d\"\n", str_len(j));
  
  str cpy = str_cpy(j);
  assert(str_len(cpy) == 20);
  assert(strcmp(j, cpy) == 0);
  
  printf("The copied string is \"%s\"\n", cpy);
  printf("The length is \"%d\"\n", str_len(cpy));
  
  char s1[] = "cat";
  str j1 = str_new(s1);
  j = str_cat(j, j1);
  j = str_cat(j, j1);
  j = str_cat(j, j1);
  assert(str_len(j) == 29);
  
  printf("The cat string is \"%s\"\n", j);
  printf("The cat length is \"%d\"\n", str_len(j));
  
  str del = str_cut(j, 0, 4);
  del = str_cut(del, 8, 12);
  assert(str_len(del) == 21);
  assert(strcmp("testtestcatcatcat", del) == 0);
  
  printf("The cut string is \"%s\"\n", del);
  
  str sub = str_sub(del, 4, 8);
  assert(str_len(sub) == 4);
  assert(strcmp("test", sub) == 0);
  
  printf("The sub string is \"%s\"\n", sub);
  
  str j3 = str_new("23niud3iunq3iun4fiuq34nufqiu34filunq34f");
  assert(str_len(j3) == 39);
  
  j3 = str_cat(j3, str_new("abc"));
  j3 = str_cut(j3, 3, 13);
  
  int i = str_toi(str_new("23423412"));
  assert(i == 23423412);
  
  return 0;
}

