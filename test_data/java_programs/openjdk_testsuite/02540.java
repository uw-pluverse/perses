
import java.lang.annotation.*;

@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.TYPE)
@interface X {}
interface Foo {}
class TypeOnAnonClass { void m() { new @X Foo() {}; } }
