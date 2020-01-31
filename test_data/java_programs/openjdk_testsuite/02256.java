





abstract class B extends A {
     public void iDep_aDep_bDep() { }
                       public void iDep_aDep_bUnd() { } 
    
     public void iDep_aUnd_bDep() { }
                       public void iDep_aUnd_bUnd() { }
    
     public void iDep_aInh_bDep() { }
                       public void iDep_aInh_bUnd() { } 
    
     public void iUnd_aDep_bDep() { }
                       public void iUnd_aDep_bUnd() { } 
    
     public void iUnd_aUnd_bDep() { }
                       public void iUnd_aUnd_bUnd() { }
    
     public void iUnd_aInh_bDep() { }
                       public void iUnd_aInh_bUnd() { }
    
}
