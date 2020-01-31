





class DepAnn
{
    
    void m1(int i) {
    }
}


@SuppressWarnings("dep-ann")

class DepAnn1
{
    
    void m1(int i) {
        
        int x = 3;
    }
}

class DepAnn2
{
    @SuppressWarnings("dep-ann")
    
    class Bar {
        
        void m1(int i) {
        }
    }

    @SuppressWarnings("dep-ann")
    
    void m2(int i) {
    }


    @SuppressWarnings("dep-ann")
    static int x = new DepAnn2() {
            
            int m1(int i) {
                return 0;
            }
        }.m1(0);

}



class DepAnn3 extends DepAnn1
{
    
    void m1(int i) {
    }
}
