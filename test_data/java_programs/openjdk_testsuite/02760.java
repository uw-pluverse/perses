

package b;

import a.*;

public class B extends A {

    interface Caller {
        void call();
    }

    public void precall() {
        foo();

        Caller caller = new Caller() {
                public void call() {
                    foo();
                }
            };
        caller.call();
    }
}
