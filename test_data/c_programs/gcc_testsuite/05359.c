



extern void link_error (void);
void f1 (unsigned char s) { if ((unsigned char) s == 0) return; if (s == 0) link_error (); }
void f2 (unsigned short s) { if ((unsigned char) s == 0) return; if (s == 0) link_error (); }
void f3 (unsigned int s) { if ((unsigned char) s == 0) return; if (s == 0) link_error (); }
void f4 (unsigned long int s) { if ((unsigned char) s == 0) return; if (s == 0) link_error (); }
void f5 (unsigned long long int s) { if ((unsigned char) s == 0) return; if (s == 0) link_error (); }
void f6 (unsigned short int s) { if ((unsigned short int) s == 0) return; if (s == 0) link_error (); }
void f7 (unsigned int s) { if ((unsigned short int) s == 0) return; if (s == 0) link_error (); }
void f8 (unsigned long int s) { if ((unsigned short int) s == 0) return; if (s == 0) link_error (); }
void f9 (unsigned long long int s) { if ((unsigned short int) s == 0) return; if (s == 0) link_error (); }
void f10 (unsigned int s) { if ((unsigned int) s == 0) return; if (s == 0) link_error (); }
void f11 (unsigned long int s) { if ((unsigned int) s == 0) return; if (s == 0) link_error (); }
void f12 (unsigned long long int s) { if ((unsigned int) s == 0) return; if (s == 0) link_error (); }
void f13 (unsigned long int s) { if ((unsigned long int) s == 0) return; if (s == 0) link_error (); }
void f14 (unsigned long long int s) { if ((unsigned long int) s == 0) return; if (s == 0) link_error (); }
void f15 (unsigned long long int s) { if ((unsigned long long int) s == 0) return; if (s == 0) link_error (); }

int
main ()
{
  return 0;
}
