
public class T6723444 {

    static class Foo<X extends Throwable> {
        Foo() throws X {}
    }

    <X extends Throwable> T6723444()
        throws X {}

    <X extends Throwable> T6723444(Foo<X> foo)
        throws X {}

    <X1 extends Throwable, X2 extends Throwable> T6723444(Foo<X1> foo, int i)
        throws X1, X2 {}

    public static void main(String[] args) throws Exception {

        

        Foo<Exception> exFoo = new Foo<Exception>();
        exFoo = new Foo<Exception>() {};

        new<Exception> T6723444();
        new<Exception> T6723444() {};
        new T6723444(exFoo);
        new T6723444(exFoo) {};
        new<Exception, Exception> T6723444(exFoo, 1);
        new<Exception, Exception> T6723444(exFoo, 1) {};

        
        

        new T6723444(exFoo, 1);
        new T6723444(exFoo, 1) {};

        Foo<Throwable> thFoo = new Foo<Throwable>();
        thFoo = new Foo<Throwable>() {};

        new<Throwable> T6723444();
        new<Throwable> T6723444() {};
        new T6723444(thFoo);
        new T6723444(thFoo) {};
        new T6723444(thFoo, 1);
        new T6723444(thFoo, 1) {};
        new<Throwable, Throwable> T6723444(thFoo, 1);
        new<Throwable, Throwable> T6723444(thFoo, 1) {};
    }
}
