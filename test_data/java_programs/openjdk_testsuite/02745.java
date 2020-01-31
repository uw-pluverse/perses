



public class SwitchScope {
    public static void main(String[] args) {
        switch (args.length) {
        case 0:
            final int k;
            k = 12;
            class Local {
                int j = k;
            }
        case 1:
            
            
            Object o = new Local();
        }
    }
}
