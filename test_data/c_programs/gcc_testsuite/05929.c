



typedef int TItype __attribute__ ((mode (TI)));




TItype last_data_offset ;
int store;
char *data;

f ()
{

  TItype data_offset = last_data_offset;
  char *p;

  for (p = data; *p; p++)
    {
      data_offset++;
      g (data_offset);
      store = data_offset + 1;
    }
}
