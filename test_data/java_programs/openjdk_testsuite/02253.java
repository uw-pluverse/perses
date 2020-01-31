



import java.io.*;

public class T8004969 implements Serializable {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    static String mm(String s) { return "mref" + s; }

    String aField = "aF";

    public static void main(String[] args) throws Exception {
        (new T8004969()).doit();
    }

    public void doit() throws Exception {
        String aLocal = "aL";
        int anInt = 99;

        try {
            
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            ObjectOutput out = new ObjectOutputStream(baos);

            write(out, z -> "[" + z + "]" );
            write(out, z -> { String x = z + z; return x + x; } );
            write(out, T8004969::mm );
            write(out, z -> (new LSI() { public String convert(String x) { return "*"+x; }} ).convert(z) );
            write(out, z -> aField + z );
            write(out, z -> aLocal + z );
            write(out, z -> z + anInt );
            out.flush();
            out.close();

            
            ByteArrayInputStream bais =
                new ByteArrayInputStream(baos.toByteArray());
            ObjectInputStream in = new ObjectInputStream(bais);
            readAssert(in, "[X]");
            readAssert(in, "XXXX");
            readAssert(in, "mrefX");
            readAssert(in, "*X");
            readAssert(in, "aFX");
            readAssert(in, "aLX");
            readAssert(in, "X99");
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
            throw e;
        }
        assertTrue(assertionCount == 7);
    }

    static void write(ObjectOutput out, LSI lamb) throws IOException {
        out.writeObject(lamb);
    }

    static void readAssert(ObjectInputStream in, String expected)  throws IOException, ClassNotFoundException {
        LSI ls = (LSI) in.readObject();
        String result = ls.convert("X");
        System.out.printf("Result: %s\n", result);
        assertTrue(result.equals(expected));
    }
}

interface LSI extends Serializable {
    String convert(String x);
}
