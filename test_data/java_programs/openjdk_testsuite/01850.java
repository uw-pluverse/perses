



import javax.lang.model.type.*;

public class NpeTest  {
    public static void main(String... args) {
        try {
            MirroredTypeException mte = new MirroredTypeException(null);
            throw new RuntimeException("Expected NPE not thrown.");
        } catch (NullPointerException npe) {
            ; 
        }
    }
}
