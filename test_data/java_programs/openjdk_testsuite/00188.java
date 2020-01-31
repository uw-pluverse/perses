

import java.util.List;

class T6985719a {
    interface A { void f(List<String> ls); }
    interface B { void f(List<Integer> ls); }
    interface C extends A,B {}
}
