



@ExpectedBase(
        value = Bar.class,
        getAnnotation = "@Bar(value=0)",
        getAnnotationsByType = {
            "@Bar(value=0)",
            "@Bar(value=1)",
            "@Bar(value=2)"
        },
        getAllAnnotationMirrors = {
            "@Bar(0)",
            "@BarContainer({@Bar(1), @Bar(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "@Bar(0)",
            "@BarContainer({@Bar(1), @Bar(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = BarContainer.class,
        getAnnotation = "@BarContainer(value=[@Bar(value=1), @Bar(value=2)])",
        getAnnotationsByType = {"@BarContainer(value=[@Bar(value=1), @Bar(value=2)])"})
@Bar(value = 0)
@BarContainer(value = {@Bar(value = 1), @Bar(value = 2)})
class MixRepeatableAndOfficialContainerBasicTest {

    @ExpectedBase(
            value = Bar.class,
            getAnnotation = "@Bar(value=0)",
            getAnnotationsByType = {
                "@Bar(value=0)",
                "@Bar(value=1)",
                "@Bar(value=2)"
            },
            getAllAnnotationMirrors = {
                "@Bar(0)",
                "@BarContainer({@Bar(1), @Bar(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            },
            getAnnotationMirrors = {
                "@Bar(0)",
                "@BarContainer({@Bar(1), @Bar(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            })
    @ExpectedContainer(
            value = BarContainer.class,
            getAnnotation = "@BarContainer(value=[@Bar(value=1), @Bar(value=2)])",
            getAnnotationsByType = {"@BarContainer(value=[@Bar(value=1), @Bar(value=2)])"})
    @Bar(value = 0)
    @BarContainer(value = {@Bar(value = 1), @Bar(value = 2)})
    int testField = 0;

    @ExpectedBase(
            value = Bar.class,
            getAnnotation = "@Bar(value=0)",
            getAnnotationsByType = {
                "@Bar(value=0)",
                "@Bar(value=1)",
                "@Bar(value=2)"
            },
            getAllAnnotationMirrors = {
                "@Bar(0)",
                "@BarContainer({@Bar(1), @Bar(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            },
            getAnnotationMirrors = {
                "@Bar(0)",
                "@BarContainer({@Bar(1), @Bar(2)})",
                "ExpectedBase",
                "ExpectedContainer"
            })
    @ExpectedContainer(
            value = BarContainer.class,
            getAnnotation = "@BarContainer(value=[@Bar(value=1), @Bar(value=2)])",
            getAnnotationsByType = {"@BarContainer(value=[@Bar(value=1), @Bar(value=2)])"})
    @Bar(value = 0)
    @BarContainer(value = {@Bar(value = 1), @Bar(value = 2)})
    void testMethod() {}
   }
