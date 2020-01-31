



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import static javax.lang.model.SourceVersion.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.lang.model.util.ElementFilter.*;
import static javax.tools.Diagnostic.Kind.*;
import static javax.tools.StandardLocation.*;
import java.io.*;


public class TestIsFunctionalInterface extends JavacTestingAbstractProcessor {
    private int count = 0;
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        if (!roundEnv.processingOver()) {
            for(TypeElement type : typesIn(roundEnv.getElementsAnnotatedWith(ExpectedIsFunInt.class))) {
                count++;
                System.out.println(type);
                if (elements.isFunctionalInterface(type) !=
                    type.getAnnotation(ExpectedIsFunInt.class).value()) {
                    messager.printMessage(ERROR,
                                          "Mismatch between expected and computed isFunctionalInterface",
                                          type);
                }
            }
        } else {
            if (count <= 0)
                messager.printMessage(ERROR, "No types with ExpectedIsFunInt processed.");
            }
    return true;
    }
}

@interface ExpectedIsFunInt {
    boolean value();
}



@ExpectedIsFunInt(false) 
interface Foo1 { boolean equals(Object obj); }

@ExpectedIsFunInt(true) 
interface Bar1 extends Foo1 { int compare(String o1, String o2); }


@ExpectedIsFunInt(true) 
interface LocalComparator<T> {
 boolean equals(Object obj);
 int compare(T o1, T o2);
}

@ExpectedIsFunInt(false) 
interface Foo2 {
  int m();
  Object clone();
}

interface X1 { int m(Iterable<String> arg); }
interface Y1 { int m(Iterable<String> arg); }
@ExpectedIsFunInt(true) 
interface Z1 extends X1, Y1 {}

interface X2 { Iterable m(Iterable<String> arg); }
interface Y2 { Iterable<String> m(Iterable arg); }
@ExpectedIsFunInt(true) 
interface Z2 extends X2, Y2 {}

interface Action<T> {
    T doit();
}
@ExpectedIsFunInt(true)
interface LocalExecutor { <T> T execute(Action<T> a); }

interface X5 { <T> T execute(Action<T> a); }
interface Y5 { <S> S execute(Action<S> a); }
@ExpectedIsFunInt(true) 
interface Exec5 extends X5, Y5 {}
