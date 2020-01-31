

public class InnerNamedConstant_2 {

    static class Inner1 {
        static int x = 1;                  
        static final int y = x * 5;        
        static final String z;             
        static {
            z = "foobar";
        }
    }

    class Inner2 {
        static int x = 1;                  
        static final String z;             
        {
            z = "foobar";                  
        }
    }

    
    
    

    class Inner3 {
        static final int y = Inner1.x * 5; 
    }

}
