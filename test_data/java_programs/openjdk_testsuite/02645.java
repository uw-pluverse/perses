



public class DefAssignBoolean_7 {

    public static void main(String[] args) {

                boolean b3, b4;
                boolean r = false;
                boolean t = true;

                if ((t && (b3 = r)) != (r || (b3 = false)));
                else
                    r = b3;
    }
}
