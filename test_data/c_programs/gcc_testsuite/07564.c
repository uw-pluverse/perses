


extern void exit (int);

typedef unsigned int uword_t __attribute__ ((mode (__word__)));
struct interrupt_frame
{
  uword_t ip;
  uword_t cs;
  uword_t flags;
  uword_t sp;
  uword_t ss;
};

__attribute__((interrupt, used))
void
fn (struct interrupt_frame *frame, uword_t error)
{
  if (0x12345670 != error)
    __builtin_abort ();
  if (0x12345671 != frame->ip)
    __builtin_abort ();
  if (0x12345672 != frame->cs)
    __builtin_abort ();
  if (0x12345673 != frame->flags)
    __builtin_abort ();
  if (0x12345674 != frame->sp)
    __builtin_abort ();
  if (0x12345675 != frame->ss)
    __builtin_abort ();

  exit (0);
}

int
main ()
{
  asm ("push	$" "0x12345675" ";			push	$" "0x12345674" ";			push	$" "0x12345673" ";			push	$" "0x12345672" ";			push	$" "0x12345671" ";			push	$" "0x12345670" ";			jmp	 " "" "fn");






  return 0;
}
