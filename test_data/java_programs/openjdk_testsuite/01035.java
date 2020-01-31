



public class Switch1
{
    public static void main (String argc[])
    {
        for (int i = 0; i < 2; i++) {
            String ret;

            ret = test(0);
            if (ret.equals("Error"))
                throw new RuntimeException("test(0) = Error");
            System.out.println("test(0) = " + ret);

            ret = test(1);
            if (ret.equals("Error"))
                throw new RuntimeException("test(1) = Error");
            System.out.println("test(1) = " + ret);
        }
    }

    private static String test (int i)
    {
        switch (i) {
        case 0:
            return ("found 0");
        case 1:
            return ("found 1");
        }
        return ("Error");
    }
}
