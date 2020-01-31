

class LambdaConv21 {

    interface SAM_void<X> {
        void m();
    }

    interface SAM_java_lang_Void {
        Void m();
    }

    static void m_void() { }

    static Void m_java_lang_Void() { return null; }

    static void testExpressionLambda() {
        SAM_void s1 = ()->m_void(); 
        SAM_java_lang_Void s2 = ()->m_void(); 
        SAM_void s3 = ()->m_java_lang_Void(); 
        SAM_java_lang_Void s4 = ()->m_java_lang_Void(); 
    }

    static void testStatementLambda() {
        SAM_void s1 = ()-> { m_void(); }; 
        SAM_java_lang_Void s2 = ()-> { m_void(); }; 
        SAM_void s3 = ()-> { return m_java_lang_Void(); }; 
        SAM_java_lang_Void s4 = ()-> { return m_java_lang_Void(); }; 
        SAM_void s5 = ()-> { m_java_lang_Void(); }; 
        SAM_java_lang_Void s6 = ()-> { m_java_lang_Void(); }; 
    }
}
