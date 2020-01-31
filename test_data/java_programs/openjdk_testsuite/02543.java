



import java.lang.annotation.ElementType;
import java.lang.annotation.Target;


class CheckForDeclAnnoNPE {
    void test(String s) {
        test(new @TA String().toString());
    }
}

@Target(ElementType.TYPE_USE)
@interface TA {}
