

import java.util.List;

class T6985719e {
    interface A { void f(List<String> ls); }
    interface B extends A { void f(List<Integer> ls); }
}
