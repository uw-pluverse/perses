



interface DA<T> { }
interface DB<T> extends DA<T> { }
interface DC<T> extends DA<Integer> { }

public class T5034609 {
    Object o = (DC<?>) (DA<?>) null; 
}
