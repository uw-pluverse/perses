



@FooInherited(value = 1)
class P {}

@ExpectedBase(
        value = FooInherited.class,
        getAnnotation = "@FooInherited(value=2)",
        getAnnotationsByType = {"@FooInherited(value=2)"},
        getAllAnnotationMirrors = {
            "@FooInherited(2)",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "@FooInherited(2)",
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer(
        value = UnofficialInheritedContainer.class,
        getAnnotation = "null",
        getAnnotationsByType = {})
@FooInherited(value = 2)
class SingularInheritedBTest extends P {}
