




class StaticBoundMref {

    interface SAM {
        void m(StaticBoundMref m);
    }

    SAM s = StaticBoundMref::m;

    static void m() { }
}
