



package PermuteBound;

class C<X, Y> {}

class D<X, Y> extends C<X, Y>
{
    void f(C<X, Y> c)
    {
        D<X, Y> d = (D<X, Y>) c;
    }

    void g(C<Y, X> c)
    {
        D<Y, X> d = (D<Y, X>) c;
        
        
        
        
    }
    
}
