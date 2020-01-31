

import java.util.List;
import java.io.*;

class Test {
    void m1(int m1_arg) {
        String x = "x, m1_arg, super, this; List, Test2, Test; java.io.*, java.lang.*";
        String y = "y, x, m1_arg, super, this; List, Test2, Test; java.io.*, java.lang.*";
        String z = "z, y, x, m1_arg, super, this; List, Test2, Test; java.io.*, java.lang.*";
        Object o = new Object() {
            public boolean equals(Object other) {
                String p = "p, other, super, this; -, o, z, y, x, m1_arg, super, this; List, Test2, Test; java.io.*, java.lang.*";
                String q = "q, p, other, super, this; -, o, z, y, x, m1_arg, super, this; List, Test2, Test; java.io.*, java.lang.*";
                String r = "r, q, p, other, super, this; -, o, z, y, x, m1_arg, super, this; List, Test2, Test; java.io.*, java.lang.*";
                return (this == other);
            }
        };
    }

    String s = "super, this; List, Test2, Test; java.io.*, java.lang.*";

    boolean b = new Object() {
            public boolean equals(Object other) {
                String p = "p, other, super, this; -, super, this; List, Test2, Test; java.io.*, java.lang.*";
                String q = "q, p, other, super, this; -, super, this; List, Test2, Test; java.io.*, java.lang.*";
                String r = "r, q, p, other, super, this; -, super, this; List, Test2, Test; java.io.*, java.lang.*";
                return (this == other);
            }

    }.equals(null);
}

class Test2 { }
