

package p1;

@SuppressWarnings("unchecked")
public class B extends A {
    public void foo1(A... args) { }
    public void foo2(A... args) { }
    public void foo2(Object... args) { }
    public <X extends A> void foo3(X... args) { }
    public <X extends A> void foo4(X... args) { }
    public void foo4(Object... args) { }
}
