

void exit (int);
void abort ();

int f (int a) {
 if ((a > 0 ? a : -a) >= 0) return 1;
 else return 0;
}

int main (int argc, char *argv[]) {
 if (f((-2147483647 -1)))
   abort ();
 else
   exit (0);
}
