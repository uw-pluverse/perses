

import java.util.List;

class T6985719c {
    interface A { void f(List<String> ls); }
    interface B<X> { void f(List<X> ls); }
    interface C extends A,B<Integer> {}
}
