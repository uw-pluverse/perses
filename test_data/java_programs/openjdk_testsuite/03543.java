

public class BadTwr implements AutoCloseable {
    public static void main(String... args) {
        
        try(BadTwr r1 = new BadTwr(); BadTwr r1 = new BadTwr()) {
            System.out.println(r1.toString());
        }

        
        try(BadTwr args = new BadTwr()) {
            System.out.println(args.toString());
            final BadTwr thatsIt = new BadTwr();
            thatsIt = null;
        }

        try(BadTwr name = new BadTwr()) {
            
            try(BadTwr name = new BadTwr()) {
                System.out.println(name.toString());
            }
        }

    }

    public void close() {
        ;
    }
}
