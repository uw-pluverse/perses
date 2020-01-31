struct str {
  int head;
  signed char data[8];
};

int foo(struct str t)
{
  return t.data[0] || (unsigned char) t.data[2] != 130;
}
