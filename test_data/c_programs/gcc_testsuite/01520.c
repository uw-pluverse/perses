





struct st_a {
   int data;
};

struct st_b {
   struct st_a *p_a;
    struct st_b *next;
};

extern struct st_b gObj;
extern void foo(int, struct st_b*);

int goo(struct st_b * obj) {
   struct st_a *pa;
   if (gObj.p_a->data != 0) {
     foo(gObj.p_a->data, obj);
   }
   pa = obj->p_a;
   if (pa == 0) {
     return 0;
   } else if (pa == gObj.p_a) {
     return 0;
   }
   return pa->data;
}
