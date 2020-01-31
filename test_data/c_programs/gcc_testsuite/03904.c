extern long unsigned int strlen (const char *);
void foo (char *, const char *);
int bar (const char *prefix)
{
    char buff[256];
    foo (buff, prefix);
    return strlen(buff);
}
