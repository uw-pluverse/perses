



import java.lang.annotation.Repeatable;

@Repeatable(BarContainer.class)
@interface Bar {}

@Bar
@Bar
@interface BarContainer {
    Bar[] value();
}

public class ContainerHasRepeatedContained {}
