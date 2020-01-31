

@Deprecated class A1
{
}

class A2
{
    @Deprecated
        static class A21 { }
}


public class T6241723 {
    
    A1 a1;      
    A2 a2;      
    A2.A21 a21; 

    
    Z1 z1;      
    Z2 z2;      
    Z2.Z21 z21; 
}



@Deprecated class Z1
{
}

class Z2
{
    @Deprecated
        static class Z21 { }
}
