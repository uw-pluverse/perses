




typedef struct gfc_se { int pre; } gfc_se;
typedef struct gfc_ss_info { int dim[7]; } gfc_ss_info;
int gfc_rank_cst[7 + 1];
int a (int, int, int);
int b (int, int);
int c (int, int);
void
gfc_conv_array_transpose (gfc_se * se) {
  int dest, src, dest_index, src_index;
  gfc_ss_info *dest_info;
  int n;
  for (n = 0; n < 2; n++) {
    dest_info->dim[n] = n;
    src_index = gfc_rank_cst[1 - n];
    a (se->pre, b (dest, dest_index), c (src, src_index));
  }
}
