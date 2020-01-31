


extern void abort (void);
struct rtx_def;
typedef struct rtx_def *rtx;


struct rtx_def
{

  int code;
  unsigned int unchanging:1;

};
rtx current_sym_addr;

int
foo ()
{
  if (current_sym_addr->code == 42
      && (({
        rtx _rtx = current_sym_addr;
        if (((_rtx)->code) != 42)
          abort ();
        _rtx;}
    )->unchanging))
    return 0;
}
