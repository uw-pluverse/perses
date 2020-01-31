


union loc {
    unsigned reg;
    signed offset;
};
void __frame_state_for2 (volatile char *state_in)
{
    union loc fs;
    {
 *state_in = fs.reg;
 *state_in = fs.offset;
    }
}
void __frame_state_for1 (volatile char *state_in)
{
    union loc fs;
    for (;;)
    {
 *state_in = fs.offset;
 *state_in = fs.reg;
    }
}
