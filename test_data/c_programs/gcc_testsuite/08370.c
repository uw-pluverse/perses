typedef int wchar_t;

extern int strcmp (const char *, const char *);





extern void abort (void);



const char *str1 = "str  1";





const char x = 'b';




const char *term = "\"\\\"\\";
const char termc = '\'';
const char *terms = "'";


const wchar_t wchar = L'w';
const wchar_t* wstring = L"wide string";




const char *t = "\\{}#]??([|^~?#??-";



int main (int argc, char *argv[])
{
  if (strcmp (str1, "str  1"))
    do { ; abort(); } while (0);

  if (x != 'b')
    do { ; abort(); } while (0);




  if (strcmp (t, "\\{}#]?" "?([|^~?#??" "-"))
    do { ; abort(); } while (0);

  if (term[0] != '"' || term[1] != '\\' || term[2] != '"'
      || term[3] != '\\' || term[4] != '\0')
    do { ; abort(); } while (0);

  if (termc != terms[0])
    do { ; abort(); } while (0);

  return 0;
}
