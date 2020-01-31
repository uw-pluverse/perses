




class Test {
    void m1(int m1_arg) {
        String x = "Test; 0; 0";
        String y = "Test; 0; 0";
        String z = "Test; 0; 0";
        Object o = new Object() {
            public boolean equals(Object other) {
                String p = "-; Test; 0; 0";
                String q = "-; Test; 0; 0";
                String r = "-; Test; 0; 0";
                return (this == other);
            }
        };
    }

    String s = "Test; 0; 0";

    boolean b = new Object() {
            public boolean equals(Object other) {
                String p = "-; Test; 0; 0";
                String q = "-; Test; 0; 0";
                String r = "-; Test; 0; 0";
                return (this == other);
            }

    }.equals(null);

    class Test2 {
        String s = "Test.Test2; Test; 0; 0";
    }
}
