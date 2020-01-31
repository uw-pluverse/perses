



public class LambdaExpr14 {

    interface SAM {
       SAM invoke();
    }

    static SAM local;

    public static void main(String[] args) {
        local = () -> () -> local.invoke();
        local.invoke().invoke(); 
    }
}
