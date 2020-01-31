



@FooInherited(value = 0)
class A {}

@ExpectedBase(
        value = FooInherited.class,
        getAnnotation = "@FooInherited(value=0)",
        getAnnotationsByType = {"@FooInherited(value=0)"},
        getAllAnnotationMirrors = {
            "@FooInherited(0)",
            "ExpectedBase",
            "ExpectedContainer"
        },
        getAnnotationMirrors = {
            "ExpectedBase",
            "ExpectedContainer"
        })
@ExpectedContainer
class SingularInheritedATest extends A {}
