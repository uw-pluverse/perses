









public class EmptyDocComments
{
    public static void Main(String [] args)
    {
    }

    

    
    public static void emptyDocComment0()
    {
        System.out.println("javadoc comment");
        System.out.println("- contains whitespace");
        System.out.println("- ends on same line as potential comment");
    }

    
    public static void emptyDocComment1()
    {
        System.out.println("javadoc comment");
        System.out.println("- contains nothing");
        System.out.println("- ends on same line as potential comment");
    }

    
    public static void emptyDocComment2()
    {
        System.out.println("javadoc comment");
        System.out.println("- contains whitespace");
        System.out.println("- ends on same line as comment start");
    }

    
    public static void emptyDocComment3()
    {
        System.out.println("javadoc comment");
        System.out.println("- contains whitespace");
        System.out.println("- ends on new line ");
    }

    
    public static void emptyDocComment4()
    {
        System.out.println("minimal javadoc comment");
        System.out.println("- contains nothing");
        System.out.println("- ends on same line as comment start");
    }

    
    public static void emptyDocComment5()
    {
        System.out.println("minimal _java_ comment");
        System.out.println("- contains nothing");
        System.out.println("- ends on same line as comment start");
    }

    
    public static void emptyDocComment6()
    {
        System.out.println("javadoc comment");
        System.out.println("- contains \"*\"");
        System.out.println("- ends on same line as comment start");
    }

    

    
    public static void singleChar0()
    {
        System.out.println("javadoc comment");
        System.out.println("- contains a single character");
        System.out.println("- ends on same line as comment start");
    }

    
    public static void singleChar1()
    {
        System.out.println("javadoc comment");
        System.out.println("- contains a single character and trailing whitespace");
        System.out.println("- ends on same line as potential comment");
    }

    
    public static void singleChar2()
    {
        System.out.println("javadoc comment");
        System.out.println("- contains a single character, no trailing whitespace");
        System.out.println("- ends on new line ");
    }

    
    public static void singleChar3()
    {
        System.out.println("javadoc comment");
        System.out.println("- contains a single character and trailing whitespace");
        System.out.println("- ends on new line ");
    }
}
