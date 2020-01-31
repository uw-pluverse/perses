typedef short int16_t;

int round_sample(int *sum);
void foo(int *dither_state, int *samples)
{
  int16_t *synth_buf;
  const int16_t *w, *p;
  int sum;

  sum = *dither_state;
  p = synth_buf + 16;
  { sum += (((w)[0 * 64]) * (p[0 * 64])); sum += (((w)[1 * 64]) * (p[1 * 64])); sum += (((w)[2 * 64]) * (p[2 * 64])); sum += (((w)[3 * 64]) * (p[3 * 64])); sum += (((w)[4 * 64]) * (p[4 * 64])); sum += (((w)[5 * 64]) * (p[5 * 64])); sum += (((w)[6 * 64]) * (p[6 * 64])); sum += (((w)[7 * 64]) * (p[7 * 64])); };
  p = synth_buf + 48;
  { sum -= (((w + 32)[0 * 64]) * (p[0 * 64])); sum -= (((w + 32)[1 * 64]) * (p[1 * 64])); sum -= (((w + 32)[2 * 64]) * (p[2 * 64])); sum -= (((w + 32)[3 * 64]) * (p[3 * 64])); sum -= (((w + 32)[4 * 64]) * (p[4 * 64])); sum -= (((w + 32)[5 * 64]) * (p[5 * 64])); sum -= (((w + 32)[6 * 64]) * (p[6 * 64])); sum -= (((w + 32)[7 * 64]) * (p[7 * 64])); };
  *samples = round_sample(&sum);
}
