

import java.util.List;

interface Foo1 { int getAge(String s);}
interface Bar1 { Integer getAge(String s);}
interface Foo1Bar1 extends Foo1, Bar1 {} 

interface AC extends A, C {} 
interface ABC extends A, B, C {} 
interface AD extends A, D {} 

interface Foo2<T> { void m(T arg);}
interface Bar2<S> { void m(S arg);}
interface Foo2Bar2<T1, T2> extends Foo2<T1>, Bar2<T2> {} 
