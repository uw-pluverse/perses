

class MethodReference50 {

    interface SAM1 {
        void m();
    }

    interface SAM2 {
        void m();
    }

    void call(SAM1 s) {}
    void call(SAM2 s) {}

    {
        call(NonExistentType::m);
    }
}
