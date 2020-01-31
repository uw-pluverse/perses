



public @interface AnnoWithClinitFail {
    Foo f = new Foo();

    String foo();
    String bar() default "bar";

    @AnnoWithClinitFail
    static class C {} 
                      

    class Foo {}
}

@AnnoWithClinitFail
class TestAnnoWithClinitFail { }
