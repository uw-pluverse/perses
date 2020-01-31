







extern const char flags [256];

unsigned char * f (unsigned char * s) {
  while (flags[*++s]);
  while (!flags[*++s]);
  return s;
}
