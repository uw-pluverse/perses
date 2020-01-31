



@ExpectedBase(
        value = Foo.class,
        getAnnotation = "@Foo(value=0)",
        getAnnotationsByType = {"@Foo(value=0)"},
        getAllAnnotationMirrors = {
            "@Foo(0)",
            "@UnofficialContainer({@Foo(1), @Foo(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "@Foo(0)",
            "@UnofficialContainer({@Foo(1), @Foo(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = UnofficialContainer.class,
        getAnnotation = "@UnofficialContainer("
        + "value=[@Foo(value=1), @Foo(value=2)])",
        getAnnotationsByType = {"@UnofficialContainer("
                + "value=[@Foo(value=1), @Foo(value=2)])"})
@Foo(value = 0)
@UnofficialContainer(value = {@Foo(value = 1), @Foo(value = 2)})
class MixSingularAndUnofficialContainerBasicTest {

    @ExpectedBase(
            value = Foo.class,
            getAnnotation = "@Foo(value=0)",
            getAnnotationsByType = {"@Foo(value=0)"},
            getAllAnnotationMirrors = {
                "@Foo(0)",
                "@UnofficialContainer({@Foo(1), @Foo(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            },
            getAnnotationMirrors = {
                "@Foo(0)",
                "@UnofficialContainer({@Foo(1), @Foo(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            })
    @ExpectedContainer(
            value = UnofficialContainer.class,
            getAnnotation = "@UnofficialContainer("
            + "value=[@Foo(value=1), @Foo(value=2)])",
            getAnnotationsByType = {"@UnofficialContainer("
                    + "value=[@Foo(value=1), @Foo(value=2)])"})
    @Foo(value = 0)
    @UnofficialContainer(value = {@Foo(value = 1), @Foo(value = 2)})
    int testField = 0;

    @ExpectedBase(
            value = Foo.class,
            getAnnotation = "@Foo(value=0)",
            getAnnotationsByType = {"@Foo(value=0)"},
            getAllAnnotationMirrors = {
                "@Foo(0)",
                "@UnofficialContainer({@Foo(1), @Foo(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            },
            getAnnotationMirrors = {
                "@Foo(0)",
                "@UnofficialContainer({@Foo(1), @Foo(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            })
    @ExpectedContainer(
            value = UnofficialContainer.class,
            getAnnotation = "@UnofficialContainer("
            + "value=[@Foo(value=1), @Foo(value=2)])",
            getAnnotationsByType = {"@UnofficialContainer("
                    + "value=[@Foo(value=1), @Foo(value=2)])"})
    @Foo(value = 0)
    @UnofficialContainer(value = {@Foo(value = 1), @Foo(value = 2)})
    void testMethod() {}
}
