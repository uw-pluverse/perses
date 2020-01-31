void foo(char *a, char *b) { }

void showinfo()
{
    char uname[33] = "", tty[38] = "/dev/";
    foo(uname, tty);
}

int main()
{
  showinfo ();
  exit (0);
}
