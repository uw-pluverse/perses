



@interface TestM2 {
    String message() default "MyMessage";
    Class myClass() default Integer.class;
}

@interface TestM3 {
    String message() default "MyMessage";
    Class myClass() default Integer.class;

}

@interface X {
    TestM2 value();
}

@X(@TestM3())
class Foo {
}
