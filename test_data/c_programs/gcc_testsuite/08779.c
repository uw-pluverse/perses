





unsigned int f (unsigned int a) {

 return a % -8;
}

int g (int b) {
 return (b > 0 ? b : -b) % -8;
}

int h (int c) {
 return (c > 0 ? c : -c) % 8;
}

unsigned int k (unsigned int d) {
 return d % 8;
}
