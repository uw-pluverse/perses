



@BarInherited(value = 0)
class C {}

@ExpectedBase(
        value = BarInherited.class,
        getAnnotation = "@BarInherited(value=0)",
        getAnnotationsByType = {
            "@BarInherited(value=1)",
            "@BarInherited(value=2)"
        },
        getAllAnnotationMirrors = {
            "@BarInherited(0)",
            "@BarInheritedContainer({@BarInherited(1), @BarInherited(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "@BarInheritedContainer({@BarInherited(1), @BarInherited(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = BarInheritedContainer.class,
        getAnnotation = "@BarInheritedContainer("
        + "value=[@BarInherited(value=1), @BarInherited(value=2)])",
        getAnnotationsByType = {"@BarInheritedContainer("
                + "value=[@BarInherited(value=1), @BarInherited(value=2)])"})
@BarInherited(value = 1)
@BarInherited(value = 2)
class RepeatableOverrideBTest extends C {}
