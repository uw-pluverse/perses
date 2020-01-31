extern void abort(void);

struct one_gcc {
  int d;
  unsigned char a;
  unsigned short b:7;
  char c;
} __attribute__((__gcc_struct__)) ;


struct one_ms {
  int d;
  unsigned char a;
  unsigned short b:7;
  char c;
} __attribute__((__ms_struct__));


main()
  {



    if (sizeof(struct one_ms) != 8)
 abort();
    if (sizeof(struct one_gcc) != 8)
 abort();
    return 0;
  }
