


class Y extends W {}
class W extends Z {}

class Z {
    void m(Z z) {
        W w = (W)z;
    }
}
