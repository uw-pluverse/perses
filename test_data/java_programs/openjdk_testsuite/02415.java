



import java.lang.annotation.Repeatable;

public class RepMemberAnno {
    @Bar("Apa") @Bar("Banan")
    public void meh() {}
}

@Repeatable(BarContainer.class)
@interface Bar {
    String value();
}

@interface BarContainer {
    Bar[] value();
}
