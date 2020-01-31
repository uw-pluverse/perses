




class StaticMrefWithTargs<X> {

    Runnable r = StaticMrefWithTargs<String>::m;

    static void m() { }
}
