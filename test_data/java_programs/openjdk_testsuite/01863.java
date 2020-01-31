



@BarInherited(value = 1)
@BarInherited(value = 2)
class B {}

@ExpectedBase(
        value = BarInherited.class,
        getAnnotation = "@BarInherited(value=3)",
        getAnnotationsByType = {"@BarInherited(value=3)"},
        getAllAnnotationMirrors = {
            "@BarInherited(3)",
            "@BarInheritedContainer({@BarInherited(1), @BarInherited(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "@BarInherited(3)",
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = BarInheritedContainer.class,
        getAnnotation = "@BarInheritedContainer("
        + "value=[@BarInherited(value=1), @BarInherited(value=2)])",
        getAnnotationsByType = {"@BarInheritedContainer("
                + "value=[@BarInherited(value=1), @BarInherited(value=2)])"})
@BarInherited(value = 3)
class RepeatableOverrideATest extends B {}
