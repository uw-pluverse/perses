


typedef double v2df __attribute__ ((__vector_size__ (16)));

v2df f(double d,double e){
  v2df x={-d,d};
  v2df y={-e,e};
  return __builtin_ia32_shufpd(x,y,1);
}
