


typedef long unsigned int size_t;




extern int snprintf (char *, size_t, const char *, ...);
const char a[] = "";
int b;
void
get_bar ()
{
  snprintf (0, 0, "%s", &a[b]);
}
