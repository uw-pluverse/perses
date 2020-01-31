



@UnofficialInheritedContainer(value = {@FooInherited(value = 1), @FooInherited(value = 2)})
@FooInherited(value = 3)
class G {}

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
            "@FooInherited(0)",
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = UnofficialInheritedContainer.class,
        getAnnotation = "@UnofficialInheritedContainer("
        + "value=[@FooInherited(value=1), @FooInherited(value=2)])",
        getAnnotationsByType = {"@UnofficialInheritedContainer("
                + "value=[@FooInherited(value=1), @FooInherited(value=2)])"})
@FooInherited(value = 0)
class MixSingularAndUnofficialContainerInheritedB2Test extends G{}
