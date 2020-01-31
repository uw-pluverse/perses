

import pack1.P1;

class CMain {

    class Foo {
        class Bar {}
    }

    static class Baz {
        private static class Quux {
            static class Quem {}
        }
    }

    
    CMain z = new CMain();
    Foo x = z.new Foo();
    Foo.Bar y = x.new Bar();

    void test() {
        P1 p1 = new P1();

        
        

        P1.Foo.Bar x = null;            
        int i = p1.a.length;            
        
        
        p1.p2.privatei = 3;             
        System.out.println (p1.p2.privatei);    
    }

}
