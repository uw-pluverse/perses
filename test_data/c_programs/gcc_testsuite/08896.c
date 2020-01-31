


unsigned int
apply_frontend_param (unsigned int spi_bias)
{
  static const int ppm = 8000;
  spi_bias /= 1000ULL + ppm/1000;
  return spi_bias;
}
