void make_file_symbol_completion_list (char *);




void location_completer (char *text)
{
 char *p, *symbol_start = text;
 for (p = text; *p != '\0'; ++p) {
  if (*p == '\\' && p[1] == '\'')
   p++;
  else if (*p == ':')
   symbol_start = p + 1;
  else
   symbol_start = p + 1;
  make_file_symbol_completion_list(symbol_start);
 }
}
