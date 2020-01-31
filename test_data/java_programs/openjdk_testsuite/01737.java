

package pkg1;

public class A {
    public interface I {
        default void m() { A.m(this); }
    }

    public static void m(Object o) {}
}
