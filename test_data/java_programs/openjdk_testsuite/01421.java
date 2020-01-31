




class MrefStat1 {

    void m() { }

    static class Sub extends MrefStat1 {
        Runnable r = super::m;
    }
}
