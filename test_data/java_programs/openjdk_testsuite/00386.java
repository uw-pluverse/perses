



class BoundBug {
    class C {}

    class B<T extends C>
    {
        void foo() {
            B<? super T> con = null;   
            B<? extends T> cov = null; 
            B<?>  biv = null;          
            B<T>  inv = null;
        }
    }

    static
    {
        B<? super C> con = null;    
        B<? extends C> cov = null;  
        B<?>  biv = null;           
        B<C>  inv = null;
    }
}
