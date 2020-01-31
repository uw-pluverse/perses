







struct s { char c[1]; };
struct s a, b, c;
int d;
int e;

void
bar (void)
{



  (e ? (d ? b : c).c : (e ? b : c).c);
}
