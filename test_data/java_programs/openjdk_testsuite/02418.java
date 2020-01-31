



public @interface AnnoWithClinit1 {
    Foo f = new Foo();

    @AnnoWithClinit1
    static class C {} 
                      

    class Foo {}
}


@AnnoWithClinit1
class BarAnnoClinit1 {}

@interface AAnnoClinit1 {
    Runnable r2 = new Runnable() { public void run() { }};
    String str1();
    String str2withdefault() default "bar";
}

@AAnnoClinit1(str1="value")
class TestAnnoClinit1 { }
