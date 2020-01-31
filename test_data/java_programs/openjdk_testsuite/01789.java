



public class ArrayCloneCodeGen {

    public static void main(String[] args) {}

    private String[] args = null;

    public String[] getArgs() {
        return (String []) (args.clone());
    }
}
