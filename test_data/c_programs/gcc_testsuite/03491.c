

extern volatile unsigned char x[];
void foo (void)
{
  unsigned char orig0, inc0, orig1, inc1, orig2, inc2, orig3, inc3, orig4, inc4, orig5, inc5, orig6, inc6, orig7, inc7, orig8, inc8;
  orig0 = x[0], orig1 = x[1], orig2 = x[2], orig3 = x[3], orig4 = x[4], orig5 = x[5], orig6 = x[6], orig7 = x[7], orig8 = x[8];
  inc0 = orig0 + 1, inc1 = orig1 + 1, inc2 = orig2 + 1, inc3 = orig3 + 1, inc4 = orig4 + 1, inc5 = orig5 + 1, inc6 = orig6 + 1, inc7 = orig7 + 1, inc8 = orig8 + 1;
  x[0] = orig0, x[1] = orig1, x[2] = orig2, x[3] = orig3, x[4] = orig4, x[5] = orig5, x[6] = orig6, x[7] = orig7, x[8] = orig8;
  x[0] = inc0, x[1] = inc1, x[2] = inc2, x[3] = inc3, x[4] = inc4, x[5] = inc5, x[6] = inc6, x[7] = inc7, x[8] = inc8;
}
