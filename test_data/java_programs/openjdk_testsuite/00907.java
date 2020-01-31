






abstract class BaseClass
{
    protected BaseClass()
    {
        x();
    }
    protected abstract void x();
}

public class Closure3
{
    public static void main(String[] args)
    {
        callingMethod("12345678");
    }

    protected static void callingMethod(final String parameter)
    {
        String t = "12345";
        final String local_var = t;
        BaseClass enum_ = new BaseClass() {
            public void x()
                {
                    int i = parameter.length() + local_var.length();
                    if (i != 13) throw new Error();
                }
        };
    }
}
