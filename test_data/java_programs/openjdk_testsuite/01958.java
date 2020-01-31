

package p;

public class NestedExamples {
    static class MemberClass1 { }

    class MemberClass2 { }

    class Win$$AtVegas { } 

    public Class<?>[] getClasses() {
        class LocalClass { }

        Object o = new Object() { 
            @Override
            public String toString() {
                return "I have no name!";
            }
        };

        return new Class<?>[] {
            NestedExamples.class,
            MemberClass1.class,
            MemberClass2.class,
            Win$$AtVegas.class,
            LocalClass.class,
            o.getClass()
        };
    }

    public String[] getClassNames() {
        return new String[] {
            "p.NestedExamples",
            "p.NestedExamples.MemberClass1",
            "p.NestedExamples.MemberClass2",
            "p.NestedExamples.Win$$AtVegas"
        };
    }
}


