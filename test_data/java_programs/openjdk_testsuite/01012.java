



class InnerMemberRegression {
    void  test() {
        class Z {
            class Y {
                void test() {
                }
            }
            Y y = new Y();
            int m=100;

            void test() {
                y.test();
            }
        }  
        Z z = new Z();
        z.test();
    }

    public  static  void  main(String[]  s) {
        InnerMemberRegression x  =  new InnerMemberRegression();
        x.test();
    }
}
