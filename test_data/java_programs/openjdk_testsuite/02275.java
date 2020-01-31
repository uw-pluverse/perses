





class R extends Q {
    @Deprecated public void pDep_qDep_rDep() { }
                public void pDep_qDep_rUnd() { } 
    
    @Deprecated public void pDep_qUnd_rDep() { }
                public void pDep_qUnd_rUnd() { }
    
    @Deprecated public void pDep_qInh_rDep() { }
                public void pDep_qInh_rUnd() { } 
    
    @Deprecated public void pUnd_qDep_rDep() { }
                public void pUnd_qDep_rUnd() { } 
    
    @Deprecated public void pUnd_qUnd_rDep() { }
                public void pUnd_qUnd_rUnd() { }
    
    @Deprecated public void pUnd_qInh_rDep() { }
                public void pUnd_qInh_rUnd() { }
    
}
