



public enum FauxSpecialEnum1 {
    INFRARED {
        void test() {System.out.println("Concrete test");}
    },
    ULTRAVIOLET {
        abstract void test();
    };
    abstract void test();
}
