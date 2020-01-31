



package enumswitch1;

enum E1 { a, b, c, d, e }

class EnumSwitch1 {
    void f(E1 e1) {
        switch (e1) {
        case a:
        case d:
        default:
            break;
        }
    }
}
