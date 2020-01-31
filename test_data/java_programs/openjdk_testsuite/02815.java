
import java.lang.annotation.*;

@Repeatable(AliveRanges.class)
@Target({ElementType.METHOD})
@interface AliveRange {
    String varName();
    int bytecodeStart();
    int bytecodeLength();
}

@Target({ElementType.METHOD})
@interface AliveRanges {AliveRange[] value();}
