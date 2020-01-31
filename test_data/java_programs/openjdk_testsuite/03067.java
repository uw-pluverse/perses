

class MethodReference21 {

    interface SAM {
        void m();
    }

    void call(SAM s) {}

    SAM s = NonExistentType::m;

    {
        call(NonExistentType::m);
    }
}
