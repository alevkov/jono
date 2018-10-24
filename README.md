  Implementation of dynamic strings in C.
  
  ```C
  char s[] = "test";
  // typedef "str" used to mark dynamic string
  str j = str_new(s);
  
  // get length of string (stored in int-sized header appended to char pointer)
  int len = str_len(j);
  
  // copy string
  str cpy = str_cpy(j);
  
  // concatenate string
  str j1 = str_new("test");
  // must reassign pointer
  j = str_cat(j, j1);
  
  printf("The new string is \"%s\"\n", j); // will print "testtest"
  
  // erase characters between [0..3] inclusive
  j = str_cut(j, 0, 4);
  
  // get substring between [4..7] inclusive
  str sub = str_sub(j, 4, 8);
  ```
