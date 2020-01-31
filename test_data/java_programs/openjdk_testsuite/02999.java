


import java.io.IOException;
import java.util.concurrent.Callable;

class TargetType72 {

    Callable<Number> c = id(id(()->{ if (true) throw new java.io.IOException(); return 0; }));

    <Z> Z id(Z z) { return null; }

}
