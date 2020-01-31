



public class EagerReturnTypeResolutionTesta {

    abstract class Test1<T>{
        abstract <S> S foo(S x, S y);
        <S extends Number & Comparable<? extends Number>> void baz(Test1<S> a){}

        void bar(Test1<Long> x, Test1<Integer> y){
            baz(foo(x, y));
        }
    }

    abstract class Test2<T>{
        abstract <S> S foo(S x, S y);
        abstract <S1> void baz(Test2<S1> a);

        void bar(Test2<Integer> y, Test2<Long> x){
             baz(foo(x, y));
        }
    }

    abstract class Test3<T>{
        abstract <S> S foo(S x, S y);
        <T extends Number & Comparable<?>,
                S extends Number & Comparable<? extends T>> void baz(Test3<S> a){}

        void bar(Test3<Long> x, Test3<Integer> y){
            baz(foo(x, y));
        }
    }

    abstract class Test4 {
        abstract class A0<T> {}

        abstract class A1<T> extends A0<T> {}

        abstract class A2<T> extends A0<T> {}

        abstract <S> S foo(S x, S y);
        abstract <S1> void baz(A0<S1> a);

        void bar(A2<Integer> y, A1<Long> x){
             baz(foo(x, y));
        }
    }

}
