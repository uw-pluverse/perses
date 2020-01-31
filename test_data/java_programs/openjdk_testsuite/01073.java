



public class InstanceInitException_2 {

    int x = 1;

    class Exn1 extends Exception {}
    class Exn2 extends Exception {}

    class Inner {

        Inner() throws Exn1 {}

        Inner(int x) throws Exn1, Exn2 {}

        {
            if (x > 0) throw new Exn1();
            if (x > 0) throw new Exn2();  
        }

    }

}
