



package enumswitch3;

class Test
{
    public static void main(String[] args)
    {
        TestEnum e = TestEnum.A;
        switch (e)
        {
            case A: System.out.println("A = A"); break;
            case B: System.out.println("B = B"); break;
            default: System.out.println("C = C"); break;
        }
    }
}
enum TestEnum
{
    A, B, C;
}
