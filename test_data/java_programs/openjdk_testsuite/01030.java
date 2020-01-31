






public class DeadCode5
{
    int fld;

    static public void main(String args[]) {
        DeadCode5 t = null;
        try {
            int dummy = t.fld;
            
            throw new RuntimeException("accidental removal of live code");
        } catch (NullPointerException e) {
            System.out.println("NullPointerException correctly thrown");
            e.printStackTrace();
        }
    }
}
