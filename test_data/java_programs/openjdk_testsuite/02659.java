



public class DefAssignBoolean_3 {

    public static void main(String[] args) {

                boolean b3, b4;
                boolean r = false;
                boolean t = true;

                if ((t && (b3 = r)) == (t && (b3 = t)));
                else
                        r = b3;

    }
}
