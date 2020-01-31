



interface I<T> {
    public int m(T t);
}
interface J<T> {
    public int m(T t);
}
class A implements J<String>, I<String>{
    public int m(String s){return 4321;}
}
