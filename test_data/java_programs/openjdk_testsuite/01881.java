



@BarInheritedContainer(value = {@BarInherited(value = 1), @BarInherited(value = 2)})
@BarInherited(value = 3)
class H {}

@ExpectedBase(
        value = BarInherited.class,
        getAnnotation = "@BarInherited(value=0)",
        getAnnotationsByType = {"@BarInherited(value=0)"},
        getAllAnnotationMirrors = {
            "@BarInherited(0)",
            "@BarInheritedContainer({@BarInherited(1), @BarInherited(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "@BarInherited(0)",
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = BarInheritedContainer.class,
        getAnnotation = "@BarInheritedContainer("
        + "value=[@BarInherited(value=1), @BarInherited(value=2)])",
        getAnnotationsByType = {"@BarInheritedContainer("
                + "value=[@BarInherited(value=1), @BarInherited(value=2)])"})
@BarInherited(value = 0)
class MixRepeatableAndOfficialContainerInheritedB2Test extends H {}
