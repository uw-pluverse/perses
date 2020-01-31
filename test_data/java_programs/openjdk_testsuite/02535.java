



import java.lang.annotation.*;

class TypeVariableCycleTest<CTV> {
    <MTV extends  @TA CTV> MTV cast(CTV p) {
        return (@TB MTV) p;
    }
}

@Target(ElementType.TYPE_USE)
@interface TA {}

@Target(ElementType.TYPE_USE)
@interface TB {}
