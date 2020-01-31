



class Test {
    void m1(int m1_arg) {
        String x = "m1; 0; 0";
        String y = "m1; 0; 0";
        String z = "m1; 0; 0";
        Object o = new Object() {
            public boolean equals(Object other) {
                String p = "equals; m1; 0; 0";
                String q = "equals; m1; 0; 0";
                String r = "equals; m1; 0; 0";
                return (this == other);
            }
        };
    }

    String s = "0; 0; 0";

    boolean b = new Object() {
            public boolean equals(Object other) {
                String p = "equals; 0; 0; 0";
                String q = "equals; 0; 0; 0";
                String r = "equals; 0; 0; 0";
                return (this == other);
            }

    }.equals(null);

    class Test2 {
        String s = "0; 0; 0; 0";
    }
}
