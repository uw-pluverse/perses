



class T4717181b {
    static class E1 extends Exception {}
    static class E2 extends Exception {}
    static class E3 extends Exception {}
    static abstract class Ta {
        public abstract void m() throws E1, E2;
    }
    interface Tb {
        void m() throws E2, E3;
    }
    static abstract class Tc extends Ta implements Tb {
        {
            try {
                m(); 
            } catch (E2 e2) {
            }
        }
    }
}
