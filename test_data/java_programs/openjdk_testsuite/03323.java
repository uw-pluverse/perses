



import java.util.List;
import java.util.Collection;
import java.sql.SQLException;
import java.sql.SQLTransientException;
import java.util.concurrent.TimeoutException;
import java.io.*;

interface A {int getOldest(List<Number> list);}
interface B {int getOldest(List list);}
interface C {int getOldest(List<?> list);}
interface D {int getOldest(List<Integer> list);}
interface E {int getOldest(Collection<?> collection);}

interface DE extends D, E {}

interface Foo {int getAge(Number n);}
interface Bar {int getAge(Integer i);}

interface FooBar extends Foo, Bar {}


interface Planet {boolean equals(Object o);}




interface Mars<T> extends Planet {int getAge(T t);}

interface Jupiter {
    boolean equals(Object o);
    String toString();
    int increment(int i);
}


interface X {int getTotal(List<String> arg);}
interface Y {int getTotal(List<String> strs);}

interface XY extends X, Y {}

interface XYZ extends X, Y, XY {}



interface AB extends A, B {}


interface F {Number getValue(String str);}
interface G {Integer getValue(String str);}
interface H {Serializable getValue(String str);}
interface I {Object getValue(String str);}

interface FGHI extends F, G, H, I {}

interface J {List<Number> getAll(String str);}
interface K {List<?> getAll(String str);}
interface L {List getAll(String str);}
interface M {Collection getAll(String str);}

interface JK extends J, K {}

interface JL extends J, L {}

interface JKL extends J, K, L {}

interface JKLM extends J, K, L, M {}


interface N {String getText(File f) throws IOException;}
interface O {String getText(File f) throws FileNotFoundException;}
interface P {String getText(File f) throws NullPointerException;}

interface NO extends N, O {}

interface NOP extends N, O, P {}

interface Boo {int getAge(String s) throws IOException;}
interface Doo {int getAge(String s) throws SQLException;}

interface BooDoo extends Boo, Doo {}


interface Q {Iterable m(Iterable<String> arg);}
interface R {Iterable<String> m(Iterable arg);}

interface QR extends Q, R {}

interface U {Collection foo(List<String> arg) throws IOException, SQLTransientException;}
interface V {List<?> foo(List<String> arg) throws EOFException, SQLException, TimeoutException;}
interface W {List<String> foo(List arg) throws Exception;}

interface UV extends U, V {}

interface UVW extends U, V, W {}



interface Qoo<T> {void m(T arg);}
interface Roo<S extends Number> {void m(S arg);}
interface QooRoo<T1, T2 extends Number, T3> extends Qoo<T1>, Roo<T2> {}
