




typedef struct bitmap_element_def
{
  unsigned int indx;
} bitmap_element;

typedef struct bitmap_head_def {
    bitmap_element *first;
    int using_obstack;
} bitmap_head;
typedef struct bitmap_head_def *bitmap;

bitmap_element *bitmap_free;

void foo (bitmap head, bitmap_element *elt)
{
  while (1)
    {


      if (head->using_obstack)
 bitmap_free = elt;
    }
}
