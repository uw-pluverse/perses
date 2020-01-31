

class CovariantCompat2 {
    static {
        CovariantCompat1.B x = new CovariantCompat1.B();
        CovariantCompat1.B o = x.foo();
    }
}
