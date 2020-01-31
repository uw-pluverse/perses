


long last_data_offset;
int store;
char *data;
void g (long);

void
f ()
{

  long data_offset = last_data_offset;
  char *p;

  for (p = data; *p; p++)
    {
      data_offset++;
      g (data_offset);
      store = data_offset + 1;
    }
}
