



@FooInherited(value = 0)
class K {}

@ExpectedBase(
        value = FooInherited.class,
        getAnnotation = "@FooInherited(value=3)",
        getAnnotationsByType = {"@FooInherited(value=3)"},
        getAllAnnotationMirrors = {
            "@FooInherited(3)",
            "@UnofficialInheritedContainer({@FooInherited(1), @FooInherited(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "@UnofficialInheritedContainer({@FooInherited(1), @FooInherited(2)})",
            "@FooInherited(3)",
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
@FooInherited(value = 3)
class MixSingularAndUnofficialContainerInheritedA2Test extends K {}
