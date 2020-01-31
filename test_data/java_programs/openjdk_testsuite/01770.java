
class Neg14 {
    interface IA { int m(); }
    interface IB { default int m() { return 1; } }

    abstract class AB implements IA, IB {}
}
