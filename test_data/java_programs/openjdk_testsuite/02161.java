
import p1.*;

class T6313164 {
    {
        B b = new B();
        b.foo1(new B(), new B()); 
        
        b.foo2(new B(), new B());
        b.foo3(null, null); 
        b.foo4(null, null); 
        
        b.foo4(new B(), new C());
    }
}
