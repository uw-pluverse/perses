



public interface InterfaceAndInnerClsCtor
{
    
    
    public static class Inner {
        
        public Inner(boolean b) {}
        Inner(char c) {}
        protected Inner(int i) {}
        private Inner() {}
    }

    
    public final static Inner i0 = new Inner(true);
    public final static Inner i1 = new Inner('a');
    public final static Inner i2 = new Inner(7);
    public final static Inner i3 = new Inner();
}
