



public class T6219964 {
    interface I { }
    void foo() {
        new Object() {
            I bar() {
                return (I)this;
            }
        };
    }
}
