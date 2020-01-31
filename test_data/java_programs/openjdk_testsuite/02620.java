



public class Null2DArray {
    public static void main(final String[] args) {
        try {
            float[][] channels = null;
            channels[0] = new float[10];
        } catch (NullPointerException ex) {
            return;
        }
        throw new Error();
    }
}
