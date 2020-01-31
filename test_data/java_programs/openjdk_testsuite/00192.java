

import java.util.List;

class T6985719g {
    interface A<X> { void f(List<X> ls); }
    interface B extends A<String> { void f(List<Integer> ls); }
}
