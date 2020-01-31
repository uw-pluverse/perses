typedef long unsigned int size_t;
void *memset(void*, int, size_t);
typedef struct __incomplete *incomplete;
void mt_query_for_domain(const char *domain)
{
 incomplete query = 0;
 memset(query, 0, sizeof(query));
}
