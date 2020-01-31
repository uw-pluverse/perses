





class UplevelPrivateConstants {

    class Inner {

        private String value;

        Inner(int code) {
            switch(code) {
              case VAL1: value = "value1"; break;
              case VAL2: value = "value2"; break;
              case VAL3: value = "value3"; break;
            }
        }
    }

    private static final int VAL1 = 1;
    private static final int VAL2 = 2;
    private static final int VAL3 = 3;
}
