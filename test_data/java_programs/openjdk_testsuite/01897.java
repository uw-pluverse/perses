



@FooInherited(value = 0)
class L {}

@ExpectedBase(
        value = FooInherited.class,
        getAnnotation = "@FooInherited(value=0)",
        getAnnotationsByType = {"@FooInherited(value=0)"},
        getAllAnnotationMirrors = {
            "@FooInherited(0)",
            "@UnofficialInheritedContainer({@FooInherited(1), @FooInherited(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "@UnofficialInheritedContainer({@FooInherited(1), @FooInherited(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = UnofficialInheritedContainer.class,
        getAnnotation = "@UnofficialInheritedContainer("
        + "value=[@FooInherited(value=1), @FooInherited(value=2)])",
        getAnnotationsByType = {"@UnofficialInheritedContainer("
                + "value=[@FooInherited(value=1), @FooInherited(value=2)])"})
@UnofficialInheritedContainer(value = {@FooInherited(value = 1), @FooInherited(value = 2)})
class MixSingularAndUnofficialContainerInheritedA1Test extends L {}
