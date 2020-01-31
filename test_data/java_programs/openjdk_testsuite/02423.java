

@CompilerAnnotationTest(@CompilerAnnotationTest2(name="test",name2="test2"))
public @interface CompilerAnnotationTest
{
   CompilerAnnotationTest2[] value();
}
