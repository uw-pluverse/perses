



class PrivateUplevelConstant {

  private static final int C1 = 1;

    void test () {
        Object bug = new Object() {
            public int hashCode() {
                switch (1+1) {
                  case C1: return 1;
                  default: return 3;
                }
            }
        };
    }

}
