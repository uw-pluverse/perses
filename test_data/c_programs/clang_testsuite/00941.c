typedef float float4 __attribute__((vector_size(16)));
int main(){
  volatile float4 x = (float4) { 0.0f, 1.0f, 2.0f, 3.0f };
  x += x;
  return 0;
}
