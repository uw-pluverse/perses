void
f (void)
{
  unsigned char c, ca[15], caa[20][30];

 {
    c = 5;
    ca[3] = c;
    caa[3][12] = ca[3] + caa[3][12];

 {
      c = 6;
      ca[4] = c;
      caa[3][12] = ca[3] + caa[3][12];
    }

 {
      c = 7;
      ca[5] = c;
      caa[3][12] = ca[3] + caa[3][12];
    }

 {
      c = 8;
      ca[6] = c;
      caa[3][12] = ca[3] + caa[3][12];
    }

 {
      c = 15;
      ca[7] = c;
      caa[3][12] = ca[3] + caa[3][12];

 {
 c = 16;
 ca[8] = c;
 caa[3][12] = ca[3] + caa[3][12];
      }

 {
 c = 17;
 ca[9] = c;
 caa[3][12] = ca[3] + caa[3][12];
      }

 {
 c = 18;
 ca[10] = c;
 caa[3][12] = ca[3] + caa[3][12];
      }
    }
  }
}
