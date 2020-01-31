



package PrimitiveVariant;

interface I {
    double m();
}

abstract class J {
    int m() { return 2; }
}

class Main extends J implements I {
    public short m() { return 1; }
}
