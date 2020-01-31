

typedef long unsigned int size_t;



void *memcpy (void *__restrict, const void *__restrict, size_t);

__attribute__((transaction_safe))
void *wmemcpy(void *dest, const void *src, size_t n)
{
    return memcpy(dest, src, n);
}
