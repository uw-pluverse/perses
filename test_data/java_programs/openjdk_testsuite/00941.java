

import pack1.P1;

public class QualifiedAccess_1 {

    
    
    
    
    

    P1 foo;
    P1.P3 bar;                                  
    P1.P3.P4 baz;                               
    P1.P3.P4.P5 quux;                           

    P1 m11() {return null;}
    P1.P3 m12() {return null;}                  
    P1.P3.P4 m13() {return null;}               
    P1.P3.P4.P5 m14() {return null;}            

    void m21(P1 x) {}
    void m22(P1.P3 x) {}                        
    void m23(P1.P3.P4 x) {}                     
    void m24(P1.P3.P4.P5 x) {}                  

    void test1() {

        
        
        
        

        P1 foo = null;
        P1.P3 bar = null;                       
        P1.P3.P4 baz = null;                    
        P1.P3.P4.P5 quux = null;                
    }

    void test2() {

        
        
        
        

        Object foo = (P1)null;
        Object bar = (P1.P3)null;               
        Object baz = (P1.P3.P4)null;            
        Object quux = (P1.P3.P4.P5)null;        
    }

    void test3() {

        
        
        
        

        boolean foo = null instanceof P1;
        boolean bar = null instanceof P1.P3;            
        boolean baz = null instanceof P1.P3.P4;         
        boolean quux = null instanceof P1.P3.P4.P5;     
    }

}
