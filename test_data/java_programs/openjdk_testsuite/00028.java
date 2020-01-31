

import java.util.List;
import java.io.Serializable;

interface A { int m(); }
interface B { Integer m(); }

interface AB extends A, B {} 

interface C { List<Integer> m(); }
interface D { List<Number> m(); }

interface CD extends C, D {} 

interface E<T> { T m(); }
interface F<T> { T m(); }
interface G { Serializable m(); }

interface BE extends B, E<Number> {} 

interface BE2<T> extends B, E<T> {} 

interface EF<T> extends E<T>, F<T> {} 

interface EF2<U, V extends U> extends E<U>, F<V> {} 

interface EF3<U, V> extends E<U>, F<V> {} 

interface EG<T extends Number> extends E<T>, G {} 

interface EFG<U extends Serializable, V extends Serializable> extends E<U>, F<V>, G {} 
