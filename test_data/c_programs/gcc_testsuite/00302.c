







int fusion_float_read (float *p){ return p[0x12345]; }
int fusion_double_read (double *p){ return p[0x12345]; }

void fusion_float_write (float *p, float f){ p[0x12345] = f; }
void fusion_double_write (double *p, double d){ p[0x12345] = d; }
