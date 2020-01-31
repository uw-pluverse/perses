


class Q extends Q2
{
    @Deprecated void foo() {  }
    void bar() { }  
}

class Q2 {
    @Deprecated void bar() { }
}



class Q3 {
    void baz() { new Q().foo(); } 
}
