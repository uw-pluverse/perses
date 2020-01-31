



@ExpectedBase(
        value = Foo.class,
        getAnnotation = "@Foo(value=0)",
        getAnnotationsByType = {"@Foo(value=0)"},
        getAllAnnotationMirrors = {
            "@Foo(0)",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "@Foo(0)",
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer
@Foo(value = 0)
public class SingularBasicTest {

    @ExpectedBase(
            value = Foo.class,
            getAnnotation = "@Foo(value=0)",
            getAnnotationsByType = {"@Foo(value=0)"},
            getAllAnnotationMirrors = {
                "@Foo(0)",
                "ExpectedBase",
                "ExpectedContainer"
            },
            getAnnotationMirrors = {
                "@Foo(0)",
                "ExpectedBase",
                "ExpectedContainer"
            })
    @ExpectedContainer
    @Foo(value = 0)
    int testField = 0;

    @ExpectedBase(
            value = Foo.class,
            getAnnotation = "@Foo(value=0)",
            getAnnotationsByType = {"@Foo(value=0)"},
            getAllAnnotationMirrors = {
                "@Foo(0)",
                "ExpectedBase",
                "ExpectedContainer"
            },
            getAnnotationMirrors = {
                "@Foo(0)",
                "ExpectedBase",
                "ExpectedContainer"
            })
    @ExpectedContainer
    @Foo(value = 0)
    void testMethod() {
    }
}
