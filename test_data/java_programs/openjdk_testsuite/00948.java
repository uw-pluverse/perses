



public class BinaryLiterals {
    public static void main(String... args) throws Exception {
        new BinaryLiterals().run();
    }

    public void run() throws Exception {
        test(0,  0B0);
        test(1,  0B1);
        test(2, 0B10);
        test(3, 0B11);

        test(0,  0b0);
        test(1,  0b1);
        test(2, 0b10);
        test(3, 0b11);

        test(-0,  -0b0);
        test(-1,  -0b1);
        test(-2, -0b10);
        test(-3, -0b11);

        test(-1,  0b11111111111111111111111111111111);
        test(-2,  0b11111111111111111111111111111110);
        test(-3,  0b11111111111111111111111111111101);

        test( 1, -0b11111111111111111111111111111111);
        test( 2, -0b11111111111111111111111111111110);
        test( 3, -0b11111111111111111111111111111101);

        test(0,     0b00);
        test(1,    0b001);
        test(2,  0b00010);
        test(3, 0b000011);

        
        test(      0x10,                            0b10000);
        test(     0x100,                        0b100000000);
        test(   0x10000,                0b10000000000000000);
        test(0x80000000, 0b10000000000000000000000000000000);
        test(0xffffffff, 0b11111111111111111111111111111111);

        test(0L,  0b0L);
        test(1L,  0b1L);
        test(2L, 0b10L);
        test(3L, 0b11L);

        test(0,     0b00L);
        test(1,    0b001L);
        test(2,  0b00010L);
        test(3, 0b000011L);

        
        test(              0x10L,                                                            0b10000L);
        test(             0x100L,                                                        0b100000000L);
        test(           0x10000L,                                                0b10000000000000000L);
        test(        0x80000000L,                                 0b10000000000000000000000000000000L);
        test(        0xffffffffL,                                 0b11111111111111111111111111111111L);
        test(0x8000000000000000L, 0b1000000000000000000000000000000000000000000000000000000000000000L);
        test(0xffffffffffffffffL, 0b1111111111111111111111111111111111111111111111111111111111111111L);

        test(0l,  0b0l);
        test(1l,  0b1l);
        test(2l, 0b10l);
        test(3l, 0b11l);

        test(0,     0b00l);
        test(1,    0b001l);
        test(2,  0b00010l);
        test(3, 0b000011l);

        
        test(              0x10l,                                                            0b10000l);
        test(             0x100l,                                                        0b100000000l);
        test(           0x10000l,                                                0b10000000000000000l);
        test(        0x80000000l,                                 0b10000000000000000000000000000000l);
        test(        0xffffffffl,                                 0b11111111111111111111111111111111l);
        test(0x8000000000000000l, 0b1000000000000000000000000000000000000000000000000000000000000000l);
        test(0xffffffffffffffffl, 0b1111111111111111111111111111111111111111111111111111111111111111l);

        if (errors > 0)
             throw new Exception(errors + " errors found");
    }

    void test(int expect, int found) {
        count++;
        if (found != expect)
            error("test " + count + "\nexpected: 0x" + Integer.toHexString(expect) + "\n   found: 0x" + Integer.toHexString(found));
    }

    void test(long expect, long found) {
        count++;
        if (found != expect)
            error("test " + count + "\nexpected: 0x" + Long.toHexString(expect) + "\n   found: 0x" + Long.toHexString(found));
    }

    void error(String message) {
        System.out.println(message);
        errors++;
    }

    int count;
    int errors;
}
