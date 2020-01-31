



public class ObjectMethodRefFromInterface {

    public interface JunkInterface {
        public void blahBlahBlah(int j);
    }

    public static class JunkClass implements JunkInterface {
        public void blahBlahBlah(int j) {
            return;
        }
    }

    public void doReference(JunkInterface o) {
        Class c = o.getClass();
    }

    public static void main(String args[]) {
        JunkInterface o = new JunkClass();
        ObjectMethodRefFromInterface cnt = new ObjectMethodRefFromInterface();
        cnt.doReference(o);
    }
}
