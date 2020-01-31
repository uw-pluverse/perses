



@ExpectedBase(
        value = Foo.class,
        getAnnotation = "null",
        getAnnotationsByType = {},
        getAllAnnotationMirrors = {
            "@UnofficialContainer({@Foo(1), @Foo(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "@UnofficialContainer({@Foo(1), @Foo(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = UnofficialContainer.class,
        getAnnotation = "@UnofficialContainer(value=[@Foo(value=1), @Foo(value=2)])",
        getAnnotationsByType = {"@UnofficialContainer(value=[@Foo(value=1), @Foo(value=2)])"})
@UnofficialContainer(value = {@Foo(value = 1), @Foo(value = 2)})
class UnofficialContainerBasicTest {

    @ExpectedBase(
            value = Foo.class,
            getAnnotation = "null",
            getAnnotationsByType = {},
            getAllAnnotationMirrors = {
                "@UnofficialContainer({@Foo(1), @Foo(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            },
            getAnnotationMirrors = {
                "@UnofficialContainer({@Foo(1), @Foo(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            })
    @ExpectedContainer(
            value = UnofficialContainer.class,
            getAnnotation = "@UnofficialContainer(value=[@Foo(value=1), @Foo(value=2)])",
            getAnnotationsByType = {"@UnofficialContainer(value=[@Foo(value=1), @Foo(value=2)])"})
    @UnofficialContainer(value = {@Foo(value = 1), @Foo(value = 2)})
    int testField = 0;

    @ExpectedBase(
            value = Foo.class,
            getAnnotation = "null",
            getAnnotationsByType = {},
            getAllAnnotationMirrors = {
                "@UnofficialContainer({@Foo(1), @Foo(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            },
            getAnnotationMirrors = {
                "@UnofficialContainer({@Foo(1), @Foo(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            })
    @ExpectedContainer(
            value = UnofficialContainer.class,
            getAnnotation = "@UnofficialContainer(value=[@Foo(value=1), @Foo(value=2)])",
            getAnnotationsByType = {"@UnofficialContainer(value=[@Foo(value=1), @Foo(value=2)])"})
    @UnofficialContainer(value = {@Foo(value = 1), @Foo(value = 2)})
    void testMethod() {}
}
