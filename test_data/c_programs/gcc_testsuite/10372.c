


struct os { struct o *o; };
struct o { struct o *next; struct os *se; };
void f(struct o *o){
  struct os *s;
  if(o) s = o->se;
  while(o && s == o->se){
    s++;
    s == o->se
      ? (o = o->next, o ? s = o->se : 0)
      : 0;
  }
}
