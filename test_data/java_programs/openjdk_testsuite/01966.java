



import java.util.List;

@Anno("TYPE")
public class Source {
    @Anno("TYPE")
    class Inner {
        class InnerInner {
            public @Anno("CONSTRUCTOR") InnerInner(@Anno("TYPE_USE") Source. @Anno("TYPE_USE") Inner Inner.this,
                                                   @Anno("PARAMETER") java.lang. @Anno("TYPE_USE") Runnable p) {
                Runnable r = () -> {
                    @Anno("TYPE_USE") Object tested = null;
                    @Anno("TYPE_USE") boolean isAnnotated = tested instanceof @Anno("TYPE_USE") String;
                };

                @Anno("TYPE_USE") Object tested = (@Anno("TYPE_USE") String @Anno("TYPE_USE") []) null;
                @Anno("TYPE_USE") boolean isAnnotated = tested instanceof@Anno("TYPE_USE") String;

                tested = new java.lang. @Anno("TYPE_USE") Object();
                tested = new @Anno("TYPE_USE") Object();
            }
        }
    }

    {
        Runnable r = () -> {
            @Anno("TYPE_USE") Object tested = null;
            @Anno("TYPE_USE") boolean isAnnotated = tested instanceof @Anno("TYPE_USE") String;
        };

        @Anno("TYPE_USE") Object tested = (@Anno("TYPE_USE") String @Anno("TYPE_USE") []) null;
        @Anno("TYPE_USE") boolean isAnnotated = tested instanceof@Anno("TYPE_USE") String;

        tested = new java.lang. @Anno("TYPE_USE") Object();
        tested = new @Anno("TYPE_USE") Object();
    }

    @Anno("TYPE")
    @Anno("ANNOTATION_TYPE")
    @interface A { }
    abstract class Parameterized<@Anno("TYPE_PARAMETER") T extends @Anno("TYPE_USE") CharSequence &
                                                                   @Anno("TYPE_USE") Runnable>
        implements @Anno("TYPE_USE") List<@Anno("TYPE_USE") Runnable> { }
}
