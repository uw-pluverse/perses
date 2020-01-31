




class MethodInvokedWithWrongNumberOfArgs {
    static java.lang.invoke.MethodHandle getNamedMember;
    public static Object getMember(String name, Object rec) throws Throwable {
        return getNamedMember.invoke(rec, name);
    }
}
