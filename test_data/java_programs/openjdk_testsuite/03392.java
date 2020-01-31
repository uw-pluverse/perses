



public class T6211853 {
    static class StringList extends java.util.LinkedList<String> {
    }

    static class Test {
        public static void main(String[] args) {
            java.util.List<? extends String> a = new StringList();
            java.util.List<String> b = (StringList) a;      
        }
    }
}
