



@BarInheritedContainer(value = {@BarInherited(value = 1), @BarInherited(value = 2)})
class D {}

@ExpectedBase(
        value = BarInherited.class,
        getAnnotation = "null",
        getAnnotationsByType = {
            "@BarInherited(value=1)",
            "@BarInherited(value=2)"
        },
        getAllAnnotationMirrors = {
            "@BarInheritedContainer({@BarInherited(1), @BarInherited(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = BarInheritedContainer.class,
        getAnnotation = "@BarInheritedContainer("
        + "value=[@BarInherited(value=1), @BarInherited(value=2)])",
        getAnnotationsByType = {"@BarInheritedContainer("
                + "value=[@BarInherited(value=1), @BarInherited(value=2)])"})
class OfficialContainerInheritedTest extends D {}
