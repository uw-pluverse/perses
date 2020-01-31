
class Y extends W {}
class W extends Z {}

class Z {
    void m(Z z) {
        return;
        W w = (W)z;
    }
}
