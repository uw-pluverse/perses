



package enumswitch2;

enum E1 { a, b, c, d, e }

class EnumSwitch2 {
    void f(E1 e1) {
        switch (e1) {
        case E1.a:
        case E1.d:
        default:
            break;
        }
    }
}
