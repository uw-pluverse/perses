

main(){

 __attribute__((vector_size(8))) int c;
__attribute__((vector_size(8))) int a = {1, -1};
__attribute__((vector_size(8))) int b = {2, -2};
c = -a + b*b*(-1LL);


 printf("result is %llx\n", (long long)c);
}
