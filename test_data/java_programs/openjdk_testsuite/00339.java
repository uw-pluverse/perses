



import java.util.Stack;
public class T4684378 {
    public static void main(String[] argv) {
        Stack<String> bar = new Stack<String>();
        String foo;

        
        foo=(bar.empty()?"":bar.peek()).intern();

        
        foo = (bar.empty()?"":bar.peek().intern());
        foo = (bar.empty()?"":(String)bar.peek()).intern();
    }
}
