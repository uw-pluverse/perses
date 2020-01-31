


class Static02 {

    interface I {
        public static void test() { }
    }

    public static void main(String[] args) {
        I.test(); 
        I i = new I() {};
        i.test(); 
    }
}
