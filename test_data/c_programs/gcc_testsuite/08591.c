




typedef unsigned char u8;
typedef unsigned int u32;
union __anonunion
{
  u32 value;
  u8 bytes[4];
};

u32
acpi_ut_dword_byte_swap (u32 value)
{
  union __anonunion in;
  in.value = value;

  return ((in.bytes[0] << 24) | (in.bytes[1] << 16)
   | (in.bytes[2] << 8) | in.bytes[3]);




}
