






class C1 extends C1 {}                  

class C11 extends C12 {}                
class C12 extends C11 {}                

interface I1 extends I1 {}              

interface I11 extends I12 {}            
interface I12 extends I11 {}            



class C211 implements C211.I {          
        interface I {};                 
}

class C212 extends C212.C {             
        static class C {};              
}


class C221 implements C221.I {          
        private interface I {};         
}

class C222 extends C222.C {             
        private static class C {};      
}



class C3 {
    class A {
        class B extends A {}
    }
}

class C4 {
    class A extends B {}
    class B {
        class C extends A {}
    }
}
