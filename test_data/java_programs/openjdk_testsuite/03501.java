

import java.lang.annotation.Native;

public class TestClass5 {
    @Native
    public static final int tc5 = 1;

    public class Inner1 {
        @Native
        public static final int tc5i1 = 2;

        public class Inner1A {
            @Native
            public static final int tc5i1i1a = 3;
        }

        public class Inner1B {
            @Native
            public static final int tc5i1i1b = 4;
        }
    }

    public class Inner2 {
        @Native
        public static final int tc521 = 5;

        public class Inner2A {
            @Native
            public static final int tc5i2i2a = 6;
        }

        public class Inner2B {
            @Native
            public static final int tc5i2i2b = 7;
        }
    }
}

