extern void abort (void);
const char *dont_optimize_function_away;

const char *use(const char *str)
{
 dont_optimize_function_away = str;
 if (str[0] != 'v')
  abort();
 if (str[1] < '1' || str[1] > '6')
  abort();
 if (str[2])
  abort();
 return str[2] ? "notused" : "v6";
}

const char *func(char *a, char *b)
{
 char buf[128];
 unsigned char i;
 const char *result;

 char *item[] = {
  "v1",
  "v2",
 };

 buf[0] = 'v';
 buf[1] = '3';
 buf[2] = 0;

 for (i = 0; i < 2; i++) {

  result = use(item[i]);

  use(buf);
  use(a);
  use(b);
  result = use(result);
 }
 return result;
}

int main()
{
 func("v4", "v5");
 return 0;
}
