



import java.io.PrintStream;

public class SynthName1 {
    public static void main(String args[]) {
        run(args, System.out);
    }
    public static void run(String args[],PrintStream out) {
        int  res1, res2;
        Intf ob = meth(1, 2);

        res1 = ob.getFirst();
        res2 = ob.getSecond();

        if ( res1 == 1 && res2 == 2 )
            return;
        out.println("Failed:  res1=" + res1 + ", res2=" + res2);
        throw new Error("test failed!");
    }
    interface Intf {
        int getFirst();
        int getSecond();
    }
    static Intf meth(final int prm1, final int zzz) {
        class InnClass implements Intf {
            Object val$prm1 = null;
            
            Object locVar;
            public int getFirst() {
                locVar = val$prm1;
                return prm1;
            }
            public int getSecond() {
                return zzz;
            }
        }
        return new InnClass();
    }
}
