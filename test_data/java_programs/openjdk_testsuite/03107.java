

class TargetType26 {
    interface SAM {
       void m();
    }

    <Z> void call(Z z) { }

    { call(() -> { }); }
}
