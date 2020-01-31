

package test.core;

import test.annotation.TestAnnotation;

public class TestCore
{
    @TestAnnotation(test = 1)
    public static void main( String[] args )  { }

    public void test()
    {
        System.out.println("test");
    }
}
