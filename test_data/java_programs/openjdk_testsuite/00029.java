

import java.util.Set;
import java.util.HashSet;

interface A { void m(Set<Integer> s); }
interface B { void m(Set<String> s); }
interface C { void m(Set<?> s); }

interface AB extends A, B {} 

interface AC extends A, C {} 

interface D<T> { void m(Set<T> s); }

interface AD extends A, D<Integer> {} 

interface AD2 extends A, D<Number> {} 

interface CD<T> extends C, D<T> {} 

interface E { <T> void m(Set<T> s); }

interface DE<T> extends D<T>, E {} 
