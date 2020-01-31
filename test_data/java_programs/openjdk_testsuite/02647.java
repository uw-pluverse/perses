



public class DefAssignBoolean_4 {

    public static void main(String[] args) {

                boolean b3, b4;
                boolean r = false;
                boolean t = true;

                if ((r || (b4 = r)) == (r || (b4 = t)));
                else
                        r = b4;
    }
}
