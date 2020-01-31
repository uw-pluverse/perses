typedef struct added_obj_st {
  int type;
} ADDED_OBJ;
void f() {
  ADDED_OBJ *ao[4]={((void*)0),((void*)0),((void*)0),((void*)0)};
  if (ao[0] != ((void*)0)) {
    ao[0]->type=0;
  }
}
