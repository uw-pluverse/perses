



public class Switch2
{
    private boolean isZero( int d ) {
        switch (d) {
        case 0:
            return true;
        default:
            return false;
        }
    }

    void useSecondArgument( String a, int b ) {
        if ( !isZero( b ) )
            throw new RuntimeException("isZero(0) returns false?!");
    }

    public static void main( String[] args ) {
        Switch2 object = new Switch2();
        object.useSecondArgument( "42", 0 );
    }
}
