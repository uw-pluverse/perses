






interface I {
    @Deprecated public void iDep_aDep_bDep();
    @Deprecated public void iDep_aDep_bUnd();
    @Deprecated public void iDep_aDep_bInh();
    @Deprecated public void iDep_aUnd_bDep();
    @Deprecated public void iDep_aUnd_bUnd();
    @Deprecated public void iDep_aUnd_bInh();
    @Deprecated public void iDep_aInh_bDep();
    @Deprecated public void iDep_aInh_bUnd();
    
                public void iUnd_aDep_bDep();
                public void iUnd_aDep_bUnd();
                public void iUnd_aDep_bInh();
                public void iUnd_aUnd_bDep();
                public void iUnd_aUnd_bUnd();
                public void iUnd_aUnd_bInh();
                public void iUnd_aInh_bDep();
                public void iUnd_aInh_bUnd();
    
}
