





class Base {
    <T extends Exception> void m() throws T { }
}

class OverrideUncheckedThrown extends Base {
     void m() throws Exception { }
}
