



@ExpectedBase(
        value = Bar.class,
        getAnnotation = "null",
        getAnnotationsByType = {
            "@Bar(value=1)",
            "@Bar(value=2)"
        },
        getAllAnnotationMirrors = {
            "@BarContainer({@Bar(1), @Bar(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "@BarContainer({@Bar(1), @Bar(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = BarContainer.class,
        getAnnotation = "@BarContainer(value=[@Bar(value=1), @Bar(value=2)])",
        getAnnotationsByType = {"@BarContainer(value=[@Bar(value=1), @Bar(value=2)])"})
@Bar(value = 1)
@Bar(value = 2)
class RepeatableBasicTest {

    @ExpectedBase(
            value = Bar.class,
            getAnnotation = "null",
            getAnnotationsByType = {
                "@Bar(value=1)",
                "@Bar(value=2)"
            },
            getAllAnnotationMirrors = {
                "@BarContainer({@Bar(1), @Bar(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            },
            getAnnotationMirrors = {
                "@BarContainer({@Bar(1), @Bar(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            })
    @ExpectedContainer(
            value = BarContainer.class,
            getAnnotation = "@BarContainer(value=[@Bar(value=1), @Bar(value=2)])",
            getAnnotationsByType = {"@BarContainer(value=[@Bar(value=1), @Bar(value=2)])"})
    @Bar(value = 1)
    @Bar(value = 2)
    int testField = 0;

    @ExpectedBase(
            value = Bar.class,
            getAnnotation = "null",
            getAnnotationsByType = {
                "@Bar(value=1)",
                "@Bar(value=2)"
            },
            getAllAnnotationMirrors = {
                "@BarContainer({@Bar(1), @Bar(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            },
            getAnnotationMirrors = {
                "@BarContainer({@Bar(1), @Bar(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            })
    @ExpectedContainer(
            value = BarContainer.class,
            getAnnotation = "@BarContainer(value=[@Bar(value=1), @Bar(value=2)])",
            getAnnotationsByType = {"@BarContainer(value=[@Bar(value=1), @Bar(value=2)])"})
    @Bar(value = 1)
    @Bar(value = 2)
    void testMethod() {}
}
