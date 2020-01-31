


@ExpectedDeprecation(false)
public class Dep1 {
    
    @ExpectedDeprecation(true)
    public void method1() {}

    @Deprecated
    @ExpectedDeprecation(true)
    public void method2() {}


    
    public void method3(
                        @ExpectedDeprecation(false)
                        Object method3_param0) {}

    public void method4(
                        @ExpectedDeprecation(false)
                        Object method4_param0, Object method4_param1) {}

    @ExpectedDeprecation(false)
    public void methodn() {}

    @ExpectedDeprecation(false)
    private Object field0;

    @Deprecated
    @ExpectedDeprecation(true)
    private Object field1;


    
    @ExpectedDeprecation(true)
    private Object field3;

    @ExpectedDeprecation(true)
    @Deprecated
    class NestedClass {}
}
