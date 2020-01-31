

@CompilerAnnotationTest(@CompilerAnnotationTest2(name="test"))
@interface CompilerAnnotationTest2
{
   String name();
   String name2() default "test"; 
}
