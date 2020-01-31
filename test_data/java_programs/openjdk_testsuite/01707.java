



public class SuperNew3 {
    SuperNew3() {}
    SuperNew3(Object o) {}
    void foo() {
        class One extends SuperNew3 {}
        class Two extends SuperNew3 {
            Two() {
                super(new One() {
                        { new One(); }
                    });
            }
        }
    }
}
