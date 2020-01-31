



typedef unsigned char uint8_t;
typedef unsigned int uint16_t;

uint8_t
_xtime (const uint8_t byte, const uint16_t generator)
{
  if (byte & 0x80)
    return byte ^ generator;
  else
    return byte << 1;
}
