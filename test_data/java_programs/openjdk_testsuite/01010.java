

public interface InterfaceMemberClassModifiers {

    Object nullWriter = null;

    class SomeClass1 implements InterfaceMemberClassModifiers {                 
        public Object getOut() {
            return nullWriter;
        }
    }

    public class SomeClass2 implements InterfaceMemberClassModifiers {          
        public Object getOut() {
            return nullWriter;
        }
    }

    

    protected class SomeClass3 implements InterfaceMemberClassModifiers {       
        public Object getOut() {
            return nullWriter;
        }
    }

    private class SomeClass4 implements InterfaceMemberClassModifiers {         
        public Object getOut() {
            return nullWriter;
        }
    }

}
