



@BarInheritedContainer(value = {@BarInherited(value = 1)})
@BarInheritedContainer(value = {@BarInherited(value = 2)})
class O {}

@ExpectedBase(
        value = BarInheritedContainer.class,
        getAnnotation = "null",
        getAnnotationsByType = {
            "@BarInheritedContainer(value=[@BarInherited(value=1)])",
            "@BarInheritedContainer(value=[@BarInherited(value=2)])"
        },
        getAllAnnotationMirrors = {
            "@BarInheritedContainerContainer("
                + "{@BarInheritedContainer({@BarInherited(1)}),"
                + " @BarInheritedContainer({@BarInherited(2)})})",
                "ExpectedBase",
                "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = BarInheritedContainerContainer.class,
        getAnnotation = "@BarInheritedContainerContainer("
        + "value=[@BarInheritedContainer(value=[@BarInherited(value=1)]),"
        + " @BarInheritedContainer(value=[@BarInherited(value=2)])])",
        getAnnotationsByType = {"@BarInheritedContainerContainer("
                + "value=[@BarInheritedContainer(value=[@BarInherited(value=1)]),"
        + " @BarInheritedContainer(value=[@BarInherited(value=2)])])"})
class RepeatableOfficialContainerInheritedTest extends O {}
