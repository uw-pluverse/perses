



void *alloca (long unsigned int);
void link_error ();

int main (int argc, char *argv[]) {
 char *foo;
 if ((foo = alloca(argc)) == 0)
   link_error ();
 return 0;
}
