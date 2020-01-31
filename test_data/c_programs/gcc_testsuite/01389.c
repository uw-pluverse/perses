



int foo(char ch)
{
  switch (ch) {
    case '-':
    case '?':
    case '/':
    case 99:
        return 1;
    default:
        return 0;
  }
}
