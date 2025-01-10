







const char* const ap[32] = { "1", "12", "123" };

char d4[4];
char d7[7];

void nowarn_range_ptr_var_1 (int i)
{
  __builtin_sprintf (d4, "%s", ap[i]);
}

void nowarn_range_ptr_var_2 (int i, int j)
{
  __builtin_sprintf (d7, "%s%s", ap[i], ap[j]);
}
