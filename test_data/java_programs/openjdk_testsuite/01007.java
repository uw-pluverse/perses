



package capture1;

import java.util.List;

class C {
    public static <T> void copy1(List<? super T> dest, List<? extends T> src) {
        copy1(dest, src);
        copy2(dest, src); 
        copy3(dest, src); 
    }
    public static <T> void copy2(List<T> dest, List<? extends T> src) {
        copy1(dest, src);
        copy2(dest, src);
        copy3(dest, src); 
    }
    public static <T> void copy3(List<? super T> dest, List<T> src) {
        copy1(dest, src);
        copy2(dest, src); 
        copy3(dest, src);
    }
}
