



public class MethodReference36 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SamC { void m(char[] a); }
    interface SamZ { void m(boolean[] a); }
    interface SamB { void m(byte[] a); }
    interface SamS { void m(short[] a); }
    interface SamI { void m(int[] a); }
    interface SamL { void m(long[] a); }
    interface SamF { void m(float[] a); }
    interface SamD { void m(double[] a); }
    interface SamO { void m(Object[] a); }


    static void m(Object... vi) {
        assertTrue(true);
    }

    public void test() {

        SamC sc = MethodReference36::m;
        sc.m(new char[] { 'a', 'b' } );

        SamZ sz = MethodReference36::m;
        sz.m(new boolean[] { true, false } );

        SamB sb = MethodReference36::m;
        sb.m(new byte[] { 0, 1 } );

        SamS ss = MethodReference36::m;
        ss.m(new short[] { 0, 1 } );

        SamI si = MethodReference36::m;
        si.m(new int[] { 0, 1 } );

        SamL sl = MethodReference36::m;
        sl.m(new long[] { 0, 1 } );

        SamF sf = MethodReference36::m;
        sf.m(new float[] { 0, 1 } );

        SamD sd = MethodReference36::m;
        sd.m(new double[] { 0, 1 } );

        SamO so = MethodReference36::m;
        so.m(new Object[] { null, null } );
    }

    public static void main(String[] args) {
       new MethodReference36().test();
       assertTrue(assertionCount == 9);
    }
}
