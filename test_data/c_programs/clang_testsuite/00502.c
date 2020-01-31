typedef struct _LIST_ENTRY {
  struct _LIST_ENTRY *ForwardLink;
  struct _LIST_ENTRY *BackLink;
} LIST_ENTRY;
typedef struct {
  unsigned long long Signature;
  LIST_ENTRY Link;
} MEMORY_MAP;
int test(unsigned long long param)
{
  LIST_ENTRY *Link;
  MEMORY_MAP *Entry;
  Link = (LIST_ENTRY *) param;
  Entry = ((MEMORY_MAP *) ((unsigned char *) (Link) - (unsigned char *) &(((MEMORY_MAP *) 0)->Link)));
  return (int) Entry->Signature;
}
