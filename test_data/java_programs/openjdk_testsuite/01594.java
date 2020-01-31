





public class NonStaticFinalVar {
    
    final int constant = 0; 

    
    final int [] intArray = {constant};

    
    NonStaticFinalVar(int i) {
        switch(i) {
        case constant:
            System.out.println("constructor ok " + constant);
            break;
        }
    }

    
    void methodA() {
        class Inner {
            final int constant = 0; 

            public void otherMethod(int i) {
                switch (i) {
                case constant:
                    System.out.println("method ok " + constant);
                    break;
                }
            }
        }
    }
}
