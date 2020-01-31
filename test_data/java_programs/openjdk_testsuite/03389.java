
abstract class T8010387<X> {

    interface F<X> { }

    <P> void test() {
        m(new F<P>() { });
    }


    abstract <T> T8010387<?> m(F<? extends X> fx);
}
