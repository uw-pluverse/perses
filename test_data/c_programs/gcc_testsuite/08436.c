



extern void abort (void);
enum { i = 44 };
enum { j = 90 };

char array1[i == 44 ? 1 : -1];
char array2[j == 90 ? 1 : -1];
char array3[19 == 19 ? 1 : -1];
