




class StaticBoundMref {

    Runnable r = new StaticBoundMref()::m;

    static void m() { }
}
