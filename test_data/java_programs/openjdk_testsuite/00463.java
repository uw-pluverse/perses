



package MultipleInheritance;

import java.util.*;

interface XList1 extends List, Collection {}

interface XList2<E> extends List<E>, Collection<E> {}

interface XList3<E> extends List<E>, Collection<E>
{
    public <T> T[] toArray(T[] target);
}
