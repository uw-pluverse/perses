



interface SAM<T> {
    T get();
}

public class T8023558c {
    public static void main(String[] args) {
        SAM<SAM> sam = () -> Object::new;
        SAM temp = sam.get()::get;
    }
}
