





void
_op_blend_p_caa_dp(unsigned *s, unsigned* e, unsigned *d, unsigned c) {
  while (d < e) {
    *d = ( (((((*s) >> 8) & 0x00ff00ff) * (c)) & 0xff00ff00) + (((((*s) & 0x00ff00ff) * (c)) >> 8) & 0x00ff00ff) );
    d++;
    s++;
  }
}
