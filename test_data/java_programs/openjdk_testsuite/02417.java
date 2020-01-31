
public class TestCrashNestedAnnos {
    
    @A(@A1()) int foo() {}
    @B(@B1()) int bar() {}
}

class B {}
class B1 {}
