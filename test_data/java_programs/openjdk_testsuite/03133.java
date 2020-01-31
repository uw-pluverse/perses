


public class MethodReference60 {

    interface ArrayFactory<X> {
        X make(int size);
    }

    interface BadArrayFactory1<X> {
        X make();
    }

    interface BadArrayFactory2<X> {
        X make(int i1, int i2);
    }

    interface BadArrayFactory3<X> {
        X make(String s);
    }

    public static void main(String[] args) {
        BadArrayFactory1<int[]> factory1 = int[]::new; 
        BadArrayFactory2<int[]> factory2 = int[]::new; 
        BadArrayFactory3<int[]> factory3 = int[]::new; 
        ArrayFactory<Integer> factory4 = int[]::new; 
        ArrayFactory<Integer[]> factory5 = int[]::new; 
    }
}
