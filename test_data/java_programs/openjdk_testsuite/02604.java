



public class InstanceInitException_1 {

    int i = 1;

    InstanceInitException_1() throws Throwable {}

    {
        if (i > 0) throw new Throwable();
    }

    class Inner1 {

        Inner1() throws Throwable {}

        {
            if (i > 0) throw new Throwable();
        }

    }

    class Exn1 extends Throwable {}
    class Exn2 extends Exception {}

    class Inner2 {

        Inner2() throws Exn1, Exn2 {}

        {
            if (i > 0) throw new Exn1();
            if (i > 0) throw new Exn2();
        }

    }

    void test() throws Throwable {

        new Object() {
            {
                if (i > 0) throw new Throwable();
            }
        };

    }

}
