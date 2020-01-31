



import java.lang.annotation.*;

class ClassA {
    Object o = ClassB.lcv;
}

class ClassB {
    static final String[] lcv = new @TA String[0];
}

class ClassC {
    static final Object o = (@TA Object) null;
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface TA {}
