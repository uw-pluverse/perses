

package pkg;
class A {
    public static void m() {
        B.result += "A.m()";
    }
}

public class B extends A {
    public static String result = "";
}
