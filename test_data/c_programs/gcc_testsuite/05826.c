



typedef int vec __attribute__((vector_size(16)));
vec f(vec x,vec y){
  return x<y|x==y;
}
