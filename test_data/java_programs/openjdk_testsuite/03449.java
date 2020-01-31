


package p1.p2;
import java.util.ArrayList;

public class T6304128 {
    private void testme( boolean check ) {
        ArrayList<Integer> aList = new ArrayList<Integer>();

        for( @Ann(Color.red) Integer i : aList ) {
            System.out.println( "checking" );
        }
    }
}

enum Color { red, green, blue };

@interface Ann {
    Color value();
}
