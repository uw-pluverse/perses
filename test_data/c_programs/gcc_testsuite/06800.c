volatile int gv[30];
void *volatile data;

int
main (void)
{
  __label__ foo;

  if (gv[0] == 1)
    goto foo;
  data = &&foo;
  do
    {
      int i0 = gv[0], i1 = gv[1], i2 = gv[2], i3 = gv[3], i4 = gv[4], i5 = gv[5], i6 = gv[6], i7 = gv[7], i8 = gv[8], i9 = gv[9], i10 = gv[10], i11 = gv[11], i12 = gv[12], i13 = gv[13], i14 = gv[14], i15 = gv[15], i16 = gv[16], i17 = gv[17], i18 = gv[18], i19 = gv[19], i20 = gv[20], i21 = gv[21], i22 = gv[22], i23 = gv[23], i24 = gv[24], i25 = gv[25], i26 = gv[26], i27 = gv[27], i28 = gv[28], i29 = gv[29];
      gv[0] = i0, gv[1] = i1, gv[2] = i2, gv[3] = i3, gv[4] = i4, gv[5] = i5, gv[6] = i6, gv[7] = i7, gv[8] = i8, gv[9] = i9, gv[10] = i10, gv[11] = i11, gv[12] = i12, gv[13] = i13, gv[14] = i14, gv[15] = i15, gv[16] = i16, gv[17] = i17, gv[18] = i18, gv[19] = i19, gv[20] = i20, gv[21] = i21, gv[22] = i22, gv[23] = i23, gv[24] = i24, gv[25] = i25, gv[26] = i26, gv[27] = i27, gv[28] = i28, gv[29] = i29;
      gv[0] = i0, gv[1] = i1, gv[2] = i2, gv[3] = i3, gv[4] = i4, gv[5] = i5, gv[6] = i6, gv[7] = i7, gv[8] = i8, gv[9] = i9, gv[10] = i10, gv[11] = i11, gv[12] = i12, gv[13] = i13, gv[14] = i14, gv[15] = i15, gv[16] = i16, gv[17] = i17, gv[18] = i18, gv[19] = i19, gv[20] = i20, gv[21] = i21, gv[22] = i22, gv[23] = i23, gv[24] = i24, gv[25] = i25, gv[26] = i26, gv[27] = i27, gv[28] = i28, gv[29] = i29;
      gv[0] = i0, gv[1] = i1, gv[2] = i2, gv[3] = i3, gv[4] = i4, gv[5] = i5, gv[6] = i6, gv[7] = i7, gv[8] = i8, gv[9] = i9, gv[10] = i10, gv[11] = i11, gv[12] = i12, gv[13] = i13, gv[14] = i14, gv[15] = i15, gv[16] = i16, gv[17] = i17, gv[18] = i18, gv[19] = i19, gv[20] = i20, gv[21] = i21, gv[22] = i22, gv[23] = i23, gv[24] = i24, gv[25] = i25, gv[26] = i26, gv[27] = i27, gv[28] = i28, gv[29] = i29;
      if (data != &&foo)
 gv[0] = 1;
      else
 gv[1] = 2;
    }
  while (gv[0] > 0);
 foo:
  return 0;
}
