typedef struct
{
        unsigned char type;
} InternalFPF;
static void SetInternalFPFZero(InternalFPF *dest) {
  dest->type=0;
}
void denormalize(InternalFPF *ptr) {
   SetInternalFPFZero(ptr);
}
