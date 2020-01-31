



public class BitwiseAssignment {
    private static class Inner {
        private int data = 4711;
    }

    public static void main(String[] args) {
        {
            Inner inner1 = new Inner();
            inner1.data ^= 42;

            Inner inner2 = new Inner();
            inner2.data = inner2.data ^ 42;
            if (inner1.data != inner2.data) throw new Error("Failed inner ^=");
        }

        {
            Inner inner1 = new Inner();
            inner1.data |= 42;

            Inner inner2 = new Inner();
            inner2.data = inner2.data | 42;
            if (inner1.data != inner2.data) throw new Error("Failed inner |=");
        }

        {
            Inner inner1 = new Inner();
            inner1.data &= 4211;

            Inner inner2 = new Inner();
            inner2.data = inner2.data & 4211;
            if (inner1.data != inner2.data) throw new Error("Failed inner &=");
        }
    }
}
