







short k;

int main (int argc, char *argv[]) {
   k = argc;
   __attribute__((vector_size((8)*sizeof(short)))) short v0 = {argc,1,2,3,4,5,6,7};
   __attribute__((vector_size((8)*sizeof(short)))) short v2 = {k, k,k,k,k,k,k,k};
   __attribute__((vector_size((8)*sizeof(short)))) short r1;

   r1 = v0 >> v2;

   return (*((short *) &(r1) + 0));
}
