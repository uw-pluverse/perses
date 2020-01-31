



class cls
{
   int [] ai = null;
}

public class DeadCode2 extends cls
{
    int [] bi = null;

    static int[] func()  {  return (int[])null; }

    public static void main(String argv[]) {
        int [] ci = null;
        int m = 0;
        int errcnt = 0;

        try { int i = func()[m = 7]; }
        catch(Exception e) {  System.out.println(e + " found "); errcnt++; }
        try { DeadCode2 ox = new DeadCode2(); int i = ox.ai[m = 7]; }
        catch(Exception e) {  System.out.println(e + " found "); errcnt++; }
        try { DeadCode2 ox = new DeadCode2(); int i = ox.bi[m = 7]; }
        catch(Exception e) {  System.out.println(e + " found "); errcnt++; }
        try { int i = ci[m = 7]; }
        catch(Exception e) {  System.out.println(e + " found "); errcnt++; }
        try { int i = ((int[])null)[0]; }
        catch(Exception e) {  System.out.println(e + " found "); errcnt++; }

        if (errcnt != 5)
            throw new RuntimeException("live code accidentally removed");
    }
}
