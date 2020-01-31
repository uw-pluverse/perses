



public class T7164542 {
    public static <S extends Readable & AutoCloseable,
                       T extends Appendable & AutoCloseable>
    void copy(S s, T t, int size) throws Exception {
        
        try (S src = s; T trg = t) {
        }
    }
}
