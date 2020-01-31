



public class QualifiedOuterThis {
    static StringBuffer sb = new StringBuffer();
    public String toString() { sb.append('X'); return "X"; }
    void test() {
        class Y {
            public String toString() { sb.append('Y'); return "Y"; }
            class Z {
                public String toString() { sb.append('Z'); return "Z"; }
                void test() {
                    System.out.println(this.toString());
                    System.out.println(Y.this.toString());
                    System.out.println(QualifiedOuterThis.this.toString());
                }
            }
            void test() {
                new Z().test();
            }
        }
        new Y().test();
    }
    public static void main(String[] s) throws Exception {
        QualifiedOuterThis x = new QualifiedOuterThis();
        x.test();  
        System.out.println(sb.toString());
        if (!sb.toString().equals("ZYX")) {
            throw new Exception("incorrect outer instance method called!");
        }
    }
}
