





import p.SuperClass;

class ProtectedAccess_1 extends SuperClass {
    {
        SuperClass.i = 5;        
        new SuperClass().i = 5;  
    }
}
