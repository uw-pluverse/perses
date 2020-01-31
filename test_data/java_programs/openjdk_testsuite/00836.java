



public class StringConversion2
{
    public static void main(String[] args) {
        Object o = "Hello ";
        String s = "World!";
        o += s;
        if (!o.equals("Hello World!"))
            throw new Error("test failed");
    }
}
