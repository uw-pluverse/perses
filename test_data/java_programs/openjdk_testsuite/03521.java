

class TwrOnNonResource {
    public static void main(String... args) {
        try(TwrOnNonResource aonr = new TwrOnNonResource()) {
            System.out.println(aonr.toString());
        }
        try(TwrOnNonResource aonr = new TwrOnNonResource()) {
            System.out.println(aonr.toString());
        } finally {;}
        try(TwrOnNonResource aonr = new TwrOnNonResource()) {
            System.out.println(aonr.toString());
        } catch (Exception e) {;}
    }

    
    public void close() {
        throw new AssertionError("I'm not Closable!");
    }
}
