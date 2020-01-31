



package NameOrder;

interface a {}
interface b {}
interface c {}

class AB implements a, b {}
class CA implements c, a {}


abstract class X {
    <T> T f(T t1, T t2) { return null; }
    void g() {
        a x = f( new AB(), new CA() );
    }
}
