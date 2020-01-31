



import java.lang.annotation.*;

@interface Foos {
    UseWrongRepeatable[] value();
}

@Repeatable(Target.class)
public @interface UseWrongRepeatable {}

@UseWrongRepeatable @UseWrongRepeatable
@interface Foo {}
