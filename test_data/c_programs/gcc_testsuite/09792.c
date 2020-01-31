






int a = 1.7976931348623157e+308;

int b = (int) 1.7976931348623157e+308;
unsigned int c = -1.0;

unsigned int d = (unsigned)-1.0;

int e = 0 << 1000;

int f = 0 << -1;

int g = 0 >> 1000;

int h = 0 >> -1;


int b1 = (0 ? (int) 1.7976931348623157e+308 : 0);
unsigned int d1 = (0 ? (unsigned int)-1.0 : 0);
int e1 = (0 ? 0 << 1000 : 0);
int f1 = (0 ? 0 << -1 : 0);
int g1 = (0 ? 0 >> 1000 : 0);
int h1 = (0 ? 0 >> -1: 0);

int i = -1 << 0;


int j[1] = { 1.7976931348623157e+308 };


int array[2] = { [0 * (2147483647 + 1)] = 0 };


_Bool k = 2147483647 + 1;
