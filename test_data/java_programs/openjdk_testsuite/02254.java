



public class ConstCharAppend {
    public static void main(String[] args) throws Exception {
        if (!("" + 'a' + 'b').equals("ab")) {
            throw new Exception("append of chars is wrong: 4103959");
        }
    }
}
