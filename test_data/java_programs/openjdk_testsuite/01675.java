



package bad.covar;

import java.util.*;

interface A{
        List<? extends A> f();
}

interface B{
        List<? extends B> f();
}

abstract class C implements A, B {} 
