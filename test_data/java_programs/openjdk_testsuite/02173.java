



import java.io.Serializable;


class Serial implements Serializable
{
    static class Inner implements Serializable
    {
    }

    @SuppressWarnings("serial")
    void m() {
        class Inner implements Serializable
        {
        }
    }
}


@SuppressWarnings("serial")
class Serial1 implements Serializable
{
    static class Inner implements Serializable
    {
    }
}

class Serial2
{
    @SuppressWarnings("serial")
    static class Inner implements Serializable
    {
    }

    @SuppressWarnings("serial")
    void m() {
        class Inner implements Serializable
        {
        }
    }
}


class Serial3 extends Serial1
{
    static class Inner implements Serializable
    {
    }
}
