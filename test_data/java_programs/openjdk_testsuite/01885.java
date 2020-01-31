



@UnofficialInheritedContainer(value = {@FooInherited(value = 1),@FooInherited(value = 2)})
class F {}

@ExpectedBase(
        value = FooInherited.class,
        getAnnotation = "null",
        getAnnotationsByType = {},
        getAllAnnotationMirrors = {
            "@UnofficialInheritedContainer({@FooInherited(1), @FooInherited(2)})",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = UnofficialInheritedContainer.class,
        getAnnotation = "@UnofficialInheritedContainer("
        + "value=[@FooInherited(value=1), @FooInherited(value=2)])",
        getAnnotationsByType = {"@UnofficialInheritedContainer("
                + "value=[@FooInherited(value=1), @FooInherited(value=2)])"})
class UnofficialContainerInheritedTest extends F {}
