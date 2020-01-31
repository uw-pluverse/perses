






typedef long unsigned int size_t;
extern void * memcpy (void * a1, const void * a2, size_t a3); void * test1a (void * a1, const void * a2, size_t a3) { return memcpy (a1, a2, a3); }
extern void * memcpy (void * a1, const void * a2, size_t a3); void * test1b (void * a1, const void * a2, size_t a3) { return memcpy (a1, a2, 10); }
extern void * mempcpy (void * a1, const void * a2, size_t a3); void * test2a (void * a1, const void * a2, size_t a3) { return mempcpy (a1, a2, a3); }
extern void * mempcpy (void * a1, const void * a2, size_t a3); void * test2b (void * a1, const void * a2, size_t a3) { return mempcpy (a1, a2, 10); }
extern void * memmove (void * a1, const void * a2, size_t a3); void * test3a (void * a1, const void * a2, size_t a3) { return memmove (a1, a2, a3); }
extern void * memmove (void * a1, const void * a2, size_t a3); void * test3b (void * a1, const void * a2, size_t a3) { return memmove (a1, "abcdefghijklmno", a3); }
extern void * memset (void * a1, int a2, size_t a3); void * test4a (void * a1, int a2, size_t a3) { return memset (a1, a2, a3); }
extern void * memset (void * a1, int a2, size_t a3); void * test4b (void * a1, int a2, size_t a3) { return memset (a1, a2, 156); }
extern void * memset (void * a1, int a2, size_t a3); void * test4c (void * a1, int a2, size_t a3) { return memset (a1, 0, a3); }
extern void * memset (void * a1, int a2, size_t a3); void * test4d (void * a1, int a2, size_t a3) { return memset (a1, 0, 10000); }
extern int memcmp (const void * a1, const void * a2, size_t a3); int test5a (const void * a1, const void * a2, size_t a3) { return memcmp (a1, a2, a3); }
extern int memcmp (const void * a1, const void * a2, size_t a3); int test5b (const void * a1, const void * a2, size_t a3) { return memcmp (a1, "abcdefghijkl", a3); }
extern char * strcpy (char * a1, const char * a2); char * test6 (char * a1, const char * a2) { return strcpy (a1, a2); }
extern char * stpcpy (char * a1, const char * a2); char * test7 (char * a1, const char * a2) { return stpcpy (a1, a2); }
extern char * strncpy (char * a1, const char * a2, size_t a3); char * test8 (char * a1, const char * a2, size_t a3) { return strncpy (a1, a2, a3); }
extern char * stpncpy (char * a1, const char * a2, size_t a3); char * test9 (char * a1, const char * a2, size_t a3) { return stpncpy (a1, a2, a3); }
extern char * strcat (char * a1, const char * a2); char * test10 (char * a1, const char * a2) { return strcat (a1, a2); }
extern char * strncat (char * a1, const char * a2, size_t a3); char * test11 (char * a1, const char * a2, size_t a3) { return strncat (a1, a2, a3); }
extern size_t strlen (const char * a1); size_t test12a (const char * a1) { return strlen (a1); }
extern size_t strlen (const char * a1); size_t test12b (const char * a1) { return strlen ("foobar"); }
extern int strcmp (const char * a1, const char * a2); int test13a (const char * a1, const char * a2) { return strcmp (a1, a2); }
extern int strcmp (const char * a1, const char * a2); int test13b (const char * a1, const char * a2) { return strcmp (a1, "abcdefghijklm"); }
extern int strncmp (const char * a1, const char * a2, size_t a3); int test14a (const char * a1, const char * a2, size_t a3) { return strncmp (a1, a2, a3); }
extern int strncmp (const char * a1, const char * a2, size_t a3); int test14b (const char * a1, const char * a2, size_t a3) { return strncmp (a1, "abcdefghijklm", 10); }
extern char * strchr (const char * a1, int a2); char * test15 (const char * a1, int a2) { return strchr (a1, a2); }
