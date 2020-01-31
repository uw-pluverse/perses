






extern int strcmp (const char *, const char *);
extern int puts (const char *);
extern void abort (void);
int main (int argc, char *argv[])
{
  "";
  "\\";
  "\\";


  if (strcmp ("0", "0"))
    do { puts("macro expansion"); abort(); } while (0);

  if (strcmp("__INCLUDE_LEVEL__", "__INCLUDE_LEVEL__"))
    do { puts("macro name"); abort(); } while (0);

  if (strcmp("", "") || strcmp("", ""))
    do { puts("empty string"); abort(); } while (0);

  if (strcmp("\"s\\n\"", "\"s\\n\""))
    do { puts("quoted string"); abort(); } while (0);

  if (strcmp ("a � b", "a \200 b"))
    do { puts("unprintable char"); abort(); } while (0);

  if (strcmp ("a b@ c", "a b@ c"))
    do { puts("internal whitespace"); abort(); } while (0);

  if (strcmp ("a \n", "a \n"))
    do { puts("backslash token"); abort(); } while (0);

  if (strcmp ("foo, bar", "foo, bar"))
    do { puts("variable arguments"); abort(); } while (0);

  if (strcmp ("GLIBC_2.2", "GLIBC_2.2"))
    do { puts("whitespace"); abort(); } while (0);

  return 0;
}
