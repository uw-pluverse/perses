







int outbuf[100];
int outcnt;
int bi_buf;
void send_bits(void)
{
    bi_buf = 0;
    outbuf[outcnt++] = 8;
    outbuf[outcnt++] = 8;
    if (outcnt)
        bi_buf = 1;
}
