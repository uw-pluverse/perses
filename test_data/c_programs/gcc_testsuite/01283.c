



typedef union
{
  unsigned long int u_32_value;
  struct
  {
    unsigned short int u_16_value_0;
    unsigned short int u_16_value_1;
  } u_16_values;
} my_union;


unsigned long int Test(const unsigned short int wXe)
{
  my_union dwCalcVal;

  dwCalcVal.u_16_values.u_16_value_0=wXe;
  dwCalcVal.u_16_values.u_16_value_1=0x8000u;

  dwCalcVal.u_32_value /=3;

  return (dwCalcVal.u_32_value);
}
