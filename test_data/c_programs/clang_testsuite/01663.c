void* allocate(long size);
void* main(void* context, long size) {
  if (context) return allocate(size);
}
