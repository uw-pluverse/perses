



import java.util.List;

class T6995200 {
    static <T> T getValue() {
        return null;
    }

    <X> void test() {
        byte v1 = getValue();
        short v2 = getValue();
        int v3 = getValue();
        long v4 = getValue();
        float v5 = getValue();
        double v6 = getValue();
        String v7 = getValue();
        String[] v8 = getValue();
        List<String> v9 = getValue();
        List<String>[] v10 = getValue();
        List<? extends String> v11 = getValue();
        List<? extends String>[] v12 = getValue();
        List<? super String> v13 = getValue();
        List<? super String>[] v14 = getValue();
        List<?> v15 = getValue();
        List<?>[] v16 = getValue();
        X v17 = getValue();
        X[] v18 = getValue();
        List<X> v19 = getValue();
        List<X>[] v20 = getValue();
        List<? extends X> v21 = getValue();
        List<? extends X>[] v22 = getValue();
        List<? super X> v23 = getValue();
        List<? super X>[] v24 = getValue();
    }
}
