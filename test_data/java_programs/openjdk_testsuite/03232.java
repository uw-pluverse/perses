



import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

import static java.util.stream.Collectors.toList;

public class MethodReferenceIntersection1 {

    public static void main(String[] args) {
        MethodReferenceIntersection1 main = new MethodReferenceIntersection1();
        List<Info_MRI1> list = main.toInfoListError(Arrays.asList(new Base_MRI1()));
        System.out.printf("result %d\n", list.size());
    }

    public <H extends B_MRI1 & A_MRI1> List<Info_MRI1> toInfoListError(List<H> list) {
        Comparator<B_MRI1> byNameComparator =
                    (B_MRI1 b1, B_MRI1 b2) -> b1.getB().compareToIgnoreCase(b2.getB());
        return list.stream().sorted(byNameComparator).map(Info_MRI1::new).collect(toList());
    }

    public <H extends B_MRI1 & A_MRI1> List<Info_MRI1> toInfoListWorks(List<H> list) {
        Comparator<B_MRI1> byNameComparator =
                    (B_MRI1 b1, B_MRI1 b2) -> b1.getB().compareToIgnoreCase(b2.getB());
        return list.stream().sorted(byNameComparator).map(s -> new Info_MRI1(s)).collect(toList());
    }
}

interface B_MRI1 {
    public String getB();
}

interface A_MRI1 {
    public long getA();
}

class Info_MRI1 {
    private final long a;
    private final String b;

    <H extends A_MRI1 & B_MRI1> Info_MRI1(H h) {
        a = h.getA();
        b = h.getB();
    }
}

class Base_MRI1 implements A_MRI1, B_MRI1 {

    @Override
    public long getA() {
        return 7L;
    }

    @Override
    public String getB() {
        return "hello";
    }
}
