



class DeadInnerClass {
    public String val = "test value";

    void method() {
        if (false) {
            
            class Inner {
                Inner() {
                    System.out.println(val);
                }
            }

            new DeadInnerClass();
        }
    }
}
