



class GenObject<T>
{
    public void foo(T obj)
    {
        System.out.println("obj = "+obj);
    }
}

interface TestInterface
{
    void foo(String blah);
}

public class MissingBridge extends GenObject<String> implements TestInterface
{
    public static void main(String[] args)
    {
        MissingBridge test = new MissingBridge();
        TestInterface test2 = test;

        
        test.foo("blah");

        
        test2.foo("blah");
    }
}
