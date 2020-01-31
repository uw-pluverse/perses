

package two;

interface I {
    int i = 11;
}

public class Child extends one.Parent implements I {
    void method() {
        System.out.println(i);
    }
}
