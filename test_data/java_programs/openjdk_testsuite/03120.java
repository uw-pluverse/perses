


import java.util.List;

class TargetType19 {

    interface SAM<X> {
        void f(List<? extends X> i);
    }

    <Z> void call(SAM<? extends Z> s, Z z) {  }

   { call((List<? extends String> p) -> { }, 1); }
}
