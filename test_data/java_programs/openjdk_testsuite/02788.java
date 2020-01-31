



interface I {
    Class getClass(); 
    static class T {
        static void f(I i) {
            if (i == null) {
                Integer x = new Integer(2);
            } else {
                I x = i;
                x.getClass();
            }
        }
        public static void main(String[] args) {
            f(null);
        }
    }
}
