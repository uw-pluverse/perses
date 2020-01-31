





abstract class B2 extends A implements I {
    @Deprecated public void iDep_aDep_bDep() { }
                public void iDep_aDep_bUnd() { } 
    
    @Deprecated public void iDep_aUnd_bDep() { }
                public void iDep_aUnd_bUnd() { } 
    
    @Deprecated public void iDep_aInh_bDep() { }
                public void iDep_aInh_bUnd() { } 
    
    @Deprecated public void iUnd_aDep_bDep() { }
                public void iUnd_aDep_bUnd() { } 
    
    @Deprecated public void iUnd_aUnd_bDep() { }
                public void iUnd_aUnd_bUnd() { }
    
    @Deprecated public void iUnd_aInh_bDep() { }
                public void iUnd_aInh_bUnd() { }
    
}
