



public class SwitchFence {
    public static final int MEMENTO_NULL = 0x7FFFFFFD;
    public static final int MEMENTO_ALLE = 0x7FFFFFFE;
    public static final int MEMENTO_LEER = 0x7FFFFFFF;

    public static void main(String[] args) throws Exception {
        int i = MEMENTO_LEER;
        switch (i) {
        case MEMENTO_NULL:
            throw new Exception("fail");

        case MEMENTO_ALLE:
            throw new Exception("fail");

        case MEMENTO_LEER:
            break;
        }
    }
}
