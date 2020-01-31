



import java.lang.annotation.*;

public class DelayRepeatedContainer {
    @Bar("apa") @Bar("banan")
    String meh() { return "meh"; }
}

@Bar("katt")
@Bar("lol")
@Repeatable(BarContainer.class)
@interface Bar {
    String value();
}

@interface BarContainer {
    Bar[] value();
}
