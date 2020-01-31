



int f (int a) {
 return (a << 31) << 6;
}

unsigned int g (unsigned int a) {
 return (a >> 7) >> 25;
}

int h (int b) {
 return (b >> 30) >> 30;
}

long long j (long long c) {
 return (c >> 35) << 35;
}
