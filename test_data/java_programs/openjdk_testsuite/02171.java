

class T6885255 {

    static class Test<X, Y> {}

    Class<Test> ct; 
    Class<Test<Test, Test>> ctt; 

    Class<Class<Test>> cct; 
    Class<Class<Test<Test, Test>>> cctt; 

    Object o1 = (Test)null; 
    Object o2 = (Test<Test, Test>)null; 

    Object o3 = (Class)null; 
    Object o4 = (Class<Test>)null; 

    Object o5 = (Class<Test<Test, Test>>)null; 
    Object o6 = (Class<Class<Test<Test, Test>>>)null; 

    Object o7 = (Test<Class, Class>)null; 
    Object o8 = (Test<Class<Test>, Class<Test>>)null; 

    boolean b = null instanceof Test; 
}
