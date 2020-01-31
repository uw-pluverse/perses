



public class PrivateLocalConstructor {
    Object Write(final String s)
    {
        class ReadString {
            private String label;
            private ReadString ()
            {
                label = s;
            }
            public String toString()
            {
                return label;
            }
        }
        return new ReadString ();
    }
    public static void main(String args[])
    {
        PrivateLocalConstructor h = new PrivateLocalConstructor();
        if (h.Write("hemant").toString() != "hemant") throw new InternalError();
    }
}
