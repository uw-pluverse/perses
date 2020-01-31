



public class FinalStringInNested {

    public void f() {
        Object o = new Object() {
            @FinalStringInNested.Annotation(Nested.ID)
            class Nested {
                static final String ID = "B";
            }
        };
    }

    @interface Annotation {
        String value();
    }
}
