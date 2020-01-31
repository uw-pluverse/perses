



class LambdaWithInterfaceSuper {

    interface Sup {
        default void m() {}
    }

    interface I extends Sup {
        default void m() {
            Runnable r = ()-> { Sup.super.m(); };
            r.run();
       }
    }
}
