



public class ConstBoolAppend {
    public static void main(String[] args) throws Exception {
        if (!("" + true).equals("true")) {
            throw new Exception("append of bools is wrong: 4102672");
        }
    }
}
