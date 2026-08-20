package javax.annotation.concurrent;

@java.lang.annotation.Target({ java.lang.annotation.ElementType.METHOD, java.lang.annotation.ElementType.TYPE_USE })
public @interface GuardedBy {

    public String value();
}
