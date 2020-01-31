





abstract class A implements I {
    @Deprecated public void iDep_aDep_bDep() { }
    @Deprecated public void iDep_aDep_bUnd() { }
    @Deprecated public void iDep_aDep_bInh() { }
                public void iDep_aUnd_bDep() { } 
                public void iDep_aUnd_bUnd() { } 
                public void iDep_aUnd_bInh() { } 
    
    
    
    @Deprecated public void iUnd_aDep_bDep() { }
    @Deprecated public void iUnd_aDep_bUnd() { }
    @Deprecated public void iUnd_aDep_bInh() { }
                public void iUnd_aUnd_bDep() { }
                public void iUnd_aUnd_bUnd() { }
                public void iUnd_aUnd_bInh() { }
    
    
    
}
