



@ExpectedBase(
        value = Bar.class,
        getAnnotation = "null",
        getAnnotationsByType = {},
        getAllAnnotationMirrors = {
            "@BarContainerContainer({@BarContainer({@Bar(1)}), @BarContainer({@Bar(2)})})",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "@BarContainerContainer({@BarContainer({@Bar(1)}), @BarContainer({@Bar(2)})})",
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = BarContainer.class,
        getAnnotation = "null",
        getAnnotationsByType = {
            "@BarContainer(value=[@Bar(value=1)])",
            "@BarContainer(value=[@Bar(value=2)])"})
@BarContainer(value = {@Bar(value = 1)})
@BarContainer(value = {@Bar(value = 2)})
class RepeatableOfficialContainerBasicTest {

    @ExpectedBase(
            value = Bar.class,
            getAnnotation = "null",
            getAnnotationsByType = {},
            getAllAnnotationMirrors = {
                "@BarContainerContainer({@BarContainer({@Bar(1)}), @BarContainer({@Bar(2)})})",
                "ExpectedBase",
                "ExpectedContainer"
            },
            getAnnotationMirrors = {
                "@BarContainerContainer({@BarContainer({@Bar(1)}), @BarContainer({@Bar(2)})})",
                "ExpectedBase",
                "ExpectedContainer"
            })
    @ExpectedContainer(
            value = BarContainer.class,
            getAnnotation = "null",
            getAnnotationsByType = {
                "@BarContainer(value=[@Bar(value=1)])",
                "@BarContainer(value=[@Bar(value=2)])"})
    @BarContainer(value = {@Bar(value = 1)})
    @BarContainer(value = {@Bar(value = 2)})
    int testField = 0;

    @ExpectedBase(
            value = Bar.class,
            getAnnotation = "null",
            getAnnotationsByType = {},
            getAllAnnotationMirrors = {
                "@BarContainerContainer({@BarContainer({@Bar(1)}), @BarContainer({@Bar(2)})})",
                "ExpectedBase",
                "ExpectedContainer"
            },
            getAnnotationMirrors = {
                "@BarContainerContainer({@BarContainer({@Bar(1)}), @BarContainer({@Bar(2)})})",
                "ExpectedBase",
                "ExpectedContainer"
            })
    @ExpectedContainer(
            value = BarContainer.class,
            getAnnotation = "null",
            getAnnotationsByType = {
                "@BarContainer(value=[@Bar(value=1)])",
                "@BarContainer(value=[@Bar(value=2)])"})
    @BarContainer(value = {@Bar(value = 1)})
    @BarContainer(value = {@Bar(value = 2)})
    void testMethod() {}
}
