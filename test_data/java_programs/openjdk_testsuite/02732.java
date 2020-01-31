



class ThrowNull {

    void foo() throws Throwable {
        throw(Throwable)  null;
    }


    void bar() {
        Object x = new Object() {
                {
                    if (true) throw null;
                }
            };
    }

}
