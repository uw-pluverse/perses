float madd_s (float f, float g, float h)
{
  return (f * g) + h;
}
float msub_s (float f, float g, float h)
{
  return (f * g) - h;
}
double madd_d (double f, double g, double h)
{
  return (f * g) + h;
}
double msub_d (double f, double g, double h)
{
  return (f * g) - h;
}
float nmadd_s (float f, float g, float h)
{
  return 0-((f * g) + h);
}
float nmsub_s (float f, float g, float h)
{
  return 0-((f * g) - h);
}
double nmadd_d (double f, double g, double h)
{
  return 0-((f * g) + h);
}
double nmsub_d (double f, double g, double h)
{
  return 0-((f * g) - h);
}
