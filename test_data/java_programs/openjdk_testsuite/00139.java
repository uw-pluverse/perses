



class C {}
interface I {}
interface I1 {}
interface I2 {}
class CT extends C implements I, I1, I2 {}

public class T6569789 {
    public static void m() {
        CT ct = new CT();
        testMethod(ct);
    }

    static <W extends C & I & I1 & I2, T extends W> void testMethod(T t) {}
}
