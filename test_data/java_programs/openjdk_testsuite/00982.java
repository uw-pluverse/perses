



import pkg.SuperClass;

class ProtectedMemberAccess3 {

  
  

  pkg.SuperClass x = new pkg.SuperClass();

  static pkg.SuperClass sx = new pkg.SuperClass();

  class Inner {

    int i = x.pi;                               
    int j = x.spi;                              

    int n = sx.pi;                              
    int m = sx.spi;                             

    
    

    int w = x.pm();                             
    int y = x.spm();                            

    int u = sx.pm();                            
    int v = sx.spm();                           

    pkg.SuperClass.pC  obj1;                    
    pkg.SuperClass.spC obj2;                    

    pkg.SuperClass.pI  obj3;                    
    pkg.SuperClass.spI obj4;                    

    Object o1 = (pkg.SuperClass.pC) null;       
    Object o2 = (pkg.SuperClass.spC) null;      

    Object o3 = (pkg.SuperClass.pI) null;       
    Object o4 = (pkg.SuperClass.spI) null;      

    class C1 extends pkg.SuperClass.pC {}       
    class C2 extends pkg.SuperClass.spC {}      

    
    

    
    

    void m() {

      pkg.SuperClass lx = new pkg.SuperClass();

      x.pi  = 1;                                
      x.spi = 2;                                

      sx.pi  = 1;                               
      sx.spi = 2;                               

      lx.pi  = 1;                               
      lx.spi = 2;                               

      int t = x.pm();                           
      int y = x.spm();                          

      int u = sx.pm();                          
      int v = sx.spm();                         

      int w = lx.pm();                          
      int z = lx.spm();                         

      int i = x.pi;                             
      int j = x.spi;                            

      int n = sx.pi;                            
      int m = sx.spi;                           

      int k = lx.pi;                            
      int l = lx.spi;                           

      pkg.SuperClass.pC  obj1;                  
      pkg.SuperClass.spC obj2;                  

      pkg.SuperClass.pI  obj3;                  
      pkg.SuperClass.spI obj4;                  

      Object o1 = (pkg.SuperClass.pC) null;     
      Object o2 = (pkg.SuperClass.spC) null;    

      Object o3 = (pkg.SuperClass.pI) null;     
      Object o4 = (pkg.SuperClass.spI) null;    

      class C1 extends pkg.SuperClass.pC {}     
      class C2 extends pkg.SuperClass.spC {}    

      
      

    }

  }

}
