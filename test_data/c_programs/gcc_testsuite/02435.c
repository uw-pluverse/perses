






extern void abort (void);
typedef long unsigned int size_t;
extern int strncmp (const char *, const char *, size_t);

void
main_test (void)
{



  const char *const s1 = "hello world";
  const char *s2;
  int n = 6, x;

  s2 = s1;
  if (strncmp (++s2, "ello", 3) != 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp ("ello", ++s2, 3) != 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp (++s2, "ello", 4) != 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp ("ello", ++s2, 4) != 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp (++s2, "ello", 5) <= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp ("ello", ++s2, 5) >= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp (++s2, "ello", 6) <= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp ("ello", ++s2, 6) >= 0 || s2 != s1+1)
    abort();

  s2 = s1;
  if (strncmp (++s2, "zllo", 3) >= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp ("zllo", ++s2, 3) <= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp (++s2, "zllo", 4) >= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp ("zllo", ++s2, 4) <= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp (++s2, "zllo", 5) >= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp ("zllo", ++s2, 5) <= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp (++s2, "zllo", 6) >= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp ("zllo", ++s2, 6) <= 0 || s2 != s1+1)
    abort();

  s2 = s1;
  if (strncmp (++s2, "allo", 3) <= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp ("allo", ++s2, 3) >= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp (++s2, "allo", 4) <= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp ("allo", ++s2, 4) >= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp (++s2, "allo", 5) <= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp ("allo", ++s2, 5) >= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp (++s2, "allo", 6) <= 0 || s2 != s1+1)
    abort();
  s2 = s1;
  if (strncmp ("allo", ++s2, 6) >= 0 || s2 != s1+1)
    abort();

  s2 = s1; n = 2; x = 1;
  if (strncmp (++s2, s1+(x&3), ++n) != 0 || s2 != s1+1 || n != 3)
    abort();
  s2 = s1; n = 2; x = 1;
  if (strncmp (s1+(x&3), ++s2, ++n) != 0 || s2 != s1+1 || n != 3)
    abort();
  s2 = s1; n = 3; x = 1;
  if (strncmp (++s2, s1+(x&3), ++n) != 0 || s2 != s1+1 || n != 4)
    abort();
  s2 = s1; n = 3; x = 1;
  if (strncmp (s1+(x&3), ++s2, ++n) != 0 || s2 != s1+1 || n != 4)
    abort();
  s2 = s1; n = 4; x = 1;
  if (strncmp (++s2, s1+(x&3), ++n) != 0 || s2 != s1+1 || n != 5)
    abort();
  s2 = s1; n = 4; x = 1;
  if (strncmp (s1+(x&3), ++s2, ++n) != 0 || s2 != s1+1 || n != 5)
    abort();
  s2 = s1; n = 5; x = 1;
  if (strncmp (++s2, s1+(x&3), ++n) != 0 || s2 != s1+1 || n != 6)
    abort();
  s2 = s1; n = 5; x = 1;
  if (strncmp (s1+(x&3), ++s2, ++n) != 0 || s2 != s1+1 || n != 6)
    abort();

  s2 = s1; n = 2;
  if (strncmp (++s2, "zllo", ++n) >= 0 || s2 != s1+1 || n != 3)
    abort();
  s2 = s1; n = 2; x = 1;
  if (strncmp ("zllo", ++s2, ++n) <= 0 || s2 != s1+1 || n != 3)
    abort();
  s2 = s1; n = 3; x = 1;
  if (strncmp (++s2, "zllo", ++n) >= 0 || s2 != s1+1 || n != 4)
    abort();
  s2 = s1; n = 3; x = 1;
  if (strncmp ("zllo", ++s2, ++n) <= 0 || s2 != s1+1 || n != 4)
    abort();
  s2 = s1; n = 4; x = 1;
  if (strncmp (++s2, "zllo", ++n) >= 0 || s2 != s1+1 || n != 5)
    abort();
  s2 = s1; n = 4; x = 1;
  if (strncmp ("zllo", ++s2, ++n) <= 0 || s2 != s1+1 || n != 5)
    abort();
  s2 = s1; n = 5; x = 1;
  if (strncmp (++s2, "zllo", ++n) >= 0 || s2 != s1+1 || n != 6)
    abort();
  s2 = s1; n = 5; x = 1;
  if (strncmp ("zllo", ++s2, ++n) <= 0 || s2 != s1+1 || n != 6)
    abort();

  s2 = s1; n = 2;
  if (strncmp (++s2, "allo", ++n) <= 0 || s2 != s1+1 || n != 3)
    abort();
  s2 = s1; n = 2; x = 1;
  if (strncmp ("allo", ++s2, ++n) >= 0 || s2 != s1+1 || n != 3)
    abort();
  s2 = s1; n = 3; x = 1;
  if (strncmp (++s2, "allo", ++n) <= 0 || s2 != s1+1 || n != 4)
    abort();
  s2 = s1; n = 3; x = 1;
  if (strncmp ("allo", ++s2, ++n) >= 0 || s2 != s1+1 || n != 4)
    abort();
  s2 = s1; n = 4; x = 1;
  if (strncmp (++s2, "allo", ++n) <= 0 || s2 != s1+1 || n != 5)
    abort();
  s2 = s1; n = 4; x = 1;
  if (strncmp ("allo", ++s2, ++n) >= 0 || s2 != s1+1 || n != 5)
    abort();
  s2 = s1; n = 5; x = 1;
  if (strncmp (++s2, "allo", ++n) <= 0 || s2 != s1+1 || n != 6)
    abort();
  s2 = s1; n = 5; x = 1;
  if (strncmp ("allo", ++s2, ++n) >= 0 || s2 != s1+1 || n != 6)
    abort();


}
