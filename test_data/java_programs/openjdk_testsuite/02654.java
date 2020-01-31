



public class DefAssignBoolean_2 {

    public static void main(String[] args) {

                boolean b3, b4;
                boolean r = false;
                boolean t = true;

                if ((r || (b4 = t)) == (t && (b4 = true)))
                        r = b4;
    }
}
