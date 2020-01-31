


import javax.annotation.processing.Completion;
import static javax.annotation.processing.Completions.*;

public class TestCompletions {
    public static void main(String... argv) {
        String value = "value";
        String message = "message";

        Completion c = of(value, message);
        if (!value.equals(c.getValue()) ||
            !message.equals(c.getMessage()))
            throw new RuntimeException("Bad full completion" + c);

        c = of(value);
        if (!value.equals(c.getValue()) ||
            !"".equals(c.getMessage()))
            throw new RuntimeException("Bad value completion" + c);
    }
}
