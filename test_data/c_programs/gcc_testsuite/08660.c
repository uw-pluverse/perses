


extern int use_data (void *p_01, void *p_02, void *p_03, void *p_04, void *p_05,
       void *p_06, void *p_07, void *p_08, void *p_09, void *p_10,
       void *p_11, void *p_12, void *p_13, void *p_14, void *p_15,
       void *p_16, void *p_17, void *p_18, void *p_19, void *p_20,
       void *p_21, void *p_22, void *p_23, void *p_24, void *p_25,
       void *p_26, void *p_27, void *p_28, void *p_29,
       void *p_30);

extern int idx (int i, int j, int n);

struct stuff
{
  int decision;
  int *a, *b, *c;
  int res;
};
void
foo (struct stuff *stuff,
     int iter,
     void *p_01, void *p_02, void *p_03, void *p_04, void *p_05,
     void *p_06, void *p_07, void *p_08, void *p_09, void *p_10,
     void *p_11, void *p_12, void *p_13, void *p_14, void *p_15,
     void *p_16, void *p_17, void *p_18, void *p_19, void *p_20,
     void *p_21, void *p_22, void *p_23, void *p_24, void *p_25,
     void *p_26, void *p_27, void *p_28, void *p_29, void *p_30)
{
 switch (stuff->decision)
   {
   case 0:
     { int i, j, k; for (i = 0; i < 83; i++) for (j = 0; j < 83; j++) { int v = stuff->c[idx(i, j, 83)]; for (k = 0; k < 83; k++) v += stuff->a[idx(i, k, 83)] * stuff->b[idx(k,j,83)]; stuff->c[idx(i, j, 83)] = v; } };
     stuff->res =
       use_data (p_01, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10,
   p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20,
   p_21, p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29, p_30);
     if (iter > 0) foo (stuff, iter - 1, (void *) -1, p_01, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20, p_21, p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29); else foo (stuff, iter, p_01, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20, p_21,p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29, p_30);
     break;

   case 1:
     { int i, j, k; for (i = 0; i < 25; i++) for (j = 0; j < 25; j++) { int v = stuff->c[idx(i, j, 25)]; for (k = 0; k < 25; k++) v += stuff->a[idx(i, k, 25)] * stuff->b[idx(k,j,25)]; stuff->c[idx(i, j, 25)] = v; } };
     stuff->res =
       use_data (p_11, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10,
   p_21, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20,
   p_01, p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29, p_30);
     if (iter > 0) foo (stuff, iter - 1, (void *) -1, p_01, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20, p_21, p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29); else foo (stuff, iter, p_01, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20, p_21,p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29, p_30);
     break;

   case 3:
     { int i, j, k; for (i = 0; i < 139; i++) for (j = 0; j < 139; j++) { int v = stuff->c[idx(i, j, 139)]; for (k = 0; k < 139; k++) v += stuff->a[idx(i, k, 139)] * stuff->b[idx(k,j,139)]; stuff->c[idx(i, j, 139)] = v; } };
     stuff->res =
       use_data (p_01, p_12, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10,
   p_11, p_22, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20,
   p_21, p_02, p_23, p_24, p_25, p_26, p_27, p_28, p_29, p_30);
     if (iter > 0) foo (stuff, iter - 1, (void *) -1, p_01, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20, p_21, p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29); else foo (stuff, iter, p_01, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20, p_21,p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29, p_30);
     break;

   case 4:
     { int i, j, k; for (i = 0; i < 32; i++) for (j = 0; j < 32; j++) { int v = stuff->c[idx(i, j, 32)]; for (k = 0; k < 32; k++) v += stuff->a[idx(i, k, 32)] * stuff->b[idx(k,j,32)]; stuff->c[idx(i, j, 32)] = v; } };
     stuff->res =
       use_data (p_01, p_02, p_13, p_04, p_05, p_06, p_07, p_08, p_09, p_10,
   p_11, p_12, p_23, p_14, p_15, p_16, p_17, p_18, p_19, p_20,
   p_21, p_22, p_03, p_24, p_25, p_26, p_27, p_28, p_29, p_30);
     if (iter > 0) foo (stuff, iter - 1, (void *) -1, p_01, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20, p_21, p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29); else foo (stuff, iter, p_01, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20, p_21,p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29, p_30);
     break;

   case 5:
     { int i, j, k; for (i = 0; i < 205; i++) for (j = 0; j < 205; j++) { int v = stuff->c[idx(i, j, 205)]; for (k = 0; k < 205; k++) v += stuff->a[idx(i, k, 205)] * stuff->b[idx(k,j,205)]; stuff->c[idx(i, j, 205)] = v; } };
     stuff->res =
       use_data (p_01, p_02, p_03, p_04, p_15, p_06, p_07, p_08, p_09, p_10,
   p_11, p_12, p_13, p_14, p_25, p_16, p_17, p_18, p_19, p_20,
   p_21, p_22, p_23, p_24, p_05, p_26, p_27, p_28, p_29, p_30);
     if (iter > 0) foo (stuff, iter - 1, (void *) -1, p_01, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20, p_21, p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29); else foo (stuff, iter, p_01, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20, p_21,p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29, p_30);
     break;

   case 6:
     { int i, j, k; for (i = 0; i < 64; i++) for (j = 0; j < 64; j++) { int v = stuff->c[idx(i, j, 64)]; for (k = 0; k < 64; k++) v += stuff->a[idx(i, k, 64)] * stuff->b[idx(k,j,64)]; stuff->c[idx(i, j, 64)] = v; } };
     stuff->res =
       use_data (p_01, p_02, p_03, p_04, p_05, p_16, p_07, p_08, p_09, p_10,
   p_11, p_12, p_13, p_14, p_15, p_26, p_17, p_18, p_19, p_20,
   p_21, p_22, p_23, p_24, p_25, p_06, p_27, p_28, p_29, p_30);
     if (iter > 0) foo (stuff, iter - 1, (void *) -1, p_01, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20, p_21, p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29); else foo (stuff, iter, p_01, p_02, p_03, p_04, p_05, p_06, p_07, p_08, p_09, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20, p_21,p_22, p_23, p_24, p_25, p_26, p_27, p_28, p_29, p_30);
     break;
   }
}



void
bar (struct stuff *stuff, int iter)
{
  foo (stuff, iter, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0,
       (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0,
       (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
}
