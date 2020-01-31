



class WrongNewList<T> {}
class WrongNewArrayList<T> extends WrongNewList<T> {}

public class WrongNew
{
    public static void main(String[] ps)
    {
        WrongNewList<String> list = getList();
    }

    public static WrongNewList<String> getList()
    {
        return new WrongNewArrayList();
    }
}
