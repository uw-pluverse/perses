typedef struct {
    char I[4];
    int S;
} Hdr;
typedef struct {
    short w;
} Hdr2;
typedef struct {
    Hdr2 usedtobeundef;
} Info;
typedef struct {
    const unsigned char *ib;
    int cur;
    int end;
} IB;
unsigned long gl(IB *input);
inline void gbs(IB *input, unsigned char *buf, int count);
void getB(IB *st, Hdr2 *usedtobeundef);
inline unsigned char gb(IB *input) {
    if (input->cur + 1 > input->end)
      ;
    return input->ib[(input->cur)++];
}
static void getID(IB *st, char str[4]) {
    str[0] = gb(st);
    str[1] = gb(st);
    str[2] = gb(st);
    str[3] = gb(st);
}
static void getH(IB *st, Hdr *header) {
    getID (st, header->I);
    header->S = gl(st);
}
static void readILBM(IB *st, Info *pic) {
    pic->usedtobeundef.w = 5;
    Hdr header;
    getH (st, &header);
    getID(st, header.I);
    int i = 0;
    while (st->cur < st->end && i < 4) {
      i++;
      getH (st, &header);
    }
}
int bitmapImageRepFromIFF(IB st, const unsigned char *ib, int il) {
    Info pic;
    st.ib = ib;
    st.cur = 0;
    st.end = il;
    readILBM(&st,&pic);
    return pic.usedtobeundef.w;
}
