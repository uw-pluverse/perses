

class List<A> {

    
    public A head;

    
    public List<A> tail;

    
    public List(A head, List<A> tail) {
        this.tail = tail;
        this.head = head;
    }

    
    public List() {
        this(null, null);
    }

    
    public static <A> List<A> make(A x1) {
        return new List<A>(x1, new List<A>());
    }

    
    public static <A> List<A> make(A x1, A x2) {
        return new List<A>(x1, new List<A>(x2, new List<A>()));
    }

    
    public static <A> List<A> make(A x1, A x2, A x3) {
        return new List<A>(x1, new List<A>(x2, new List<A>(x3, new List<A>())));
    }

    
    public static <A> List<A> make(A[] vec) {
        List<A> xs = new List<A>();
        for (int i = vec.length - 1; i >= 0; i--)
            xs = new List<A>(vec[i], xs);
        return xs;
    }

    
    public static <A> List<A> make(int len, A init) {
        List<A> l = new List<A>();
        for (int i = 0; i < len; i++) l = new List<A>(init, l);
        return l;
    }

    
    public boolean isEmpty() {
        return tail == null;
    }

    
    public boolean nonEmpty() {
        return tail != null;
    }

    
    public int length() {
        List<A> l = this;
        int len = 0;
        while (l.tail != null) {
            l = l.tail;
            len++;
        }
        return len;
    }

    
    public List<A> prepend(A x) {
        return new List<A>(x, this);
    }

    
    public List<A> prependList(List<A> xs) {
        if (this.isEmpty()) return xs;
        else if (xs.isEmpty()) return this;
        else return this.prependList(xs.tail).prepend(xs.head);
    }

    
    public List<A> reverse() {
        List<A> rev = new List<A>();
        for (List<A> l = this; l.nonEmpty(); l = l.tail)
            rev = new List<A>(l.head, rev);
        return rev;
    }

    
    public List<A> append(A x) {
        return make(x).prependList(this);
    }

    
    public List<A> appendList(List<A> x) {
        return x.prependList(this);
    }

    
    public A[] toArray(A[] vec) {
        int i = 0;
        List<A> l = this;
        while (l.nonEmpty() && i < vec.length) {
            vec[i] = l.head;
            l = l.tail;
            i++;
        }
        return vec;
    }

    
    public String toString(String sep) {
        if (isEmpty()) {
            return "";
        } else {
            StringBuffer buf = new StringBuffer();
            buf.append(((Object)head).toString());
            for (List<A> l = tail; l.nonEmpty(); l = l.tail) {
                buf.append(sep);
                buf.append(((Object)l.head).toString());
            }
            return buf.toString();
        }
    }

    
    public String toString() {
        return toString(",");
    }

    
    public int hashCode() {
        List<A> l = this;
        int h = 0;
        while (l.tail != null) {
            h = h * 41 + (head != null ? head.hashCode() : 0);
            l = l.tail;
        }
        return h;
    }

    
    public boolean equals(Object other) {
        return other instanceof List && equals(this, (List)other);
    }

    
    public static boolean equals(List xs, List ys) {
        while (xs.tail != null && ys.tail != null) {
            if (xs.head == null) {
                if (ys.head != null) return false;
            } else {
                if (!xs.head.equals(ys.head)) return false;
            }
            xs = xs.tail;
            ys = ys.tail;
        }
        return xs.tail == null && ys.tail == null;
    }

    
    public boolean contains(A x) {
        List<A> l = this;
        while (l.tail != null) {
            if (x == null) {
                if (l.head == null) return true;
            } else {
                if (x.equals(l.head)) return true;
            }
            l = l.tail;
        }
        return false;
    }

}
