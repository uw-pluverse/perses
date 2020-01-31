




extern void fn2();
struct {
    unsigned qp_num;
    unsigned starting_psn;
    void *private_data;
} a;
struct {
    unsigned id;
    unsigned qpn;
    unsigned psn;
} b;
void fn1() {
    a.qp_num = b.qpn;
    a.starting_psn = b.psn;
    fn2(b.id);
}
