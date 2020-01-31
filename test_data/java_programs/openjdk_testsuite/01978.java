



import java.lang.annotation.ElementType;
import java.lang.annotation.Target;

@OnMethod
@OnField
class Class<@OnType @OnMethod @OnField T extends @OnType @OnMethod @OnField CharSequence & @OnType @OnMethod @OnField Runnable> extends @OnType @OnMethod @OnField Object {

    @OnType
    @OnTypeUse
    @OnField
    private void testMethod(@OnType @OnField @OnMethod int i) { }

    @OnType
    @OnMethod
    private java.lang.@OnType @OnMethod @OnField String testField;
}

@Target(ElementType.TYPE)
@interface OnType {}

@Target(ElementType.METHOD)
@interface OnMethod {}

@Target(ElementType.TYPE_USE)
@interface OnTypeUse {}

@Target(ElementType.FIELD)
@interface OnField {}
