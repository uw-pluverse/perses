package com.example.stream;

import java.util.Arrays;
import java.util.PrimitiveIterator;
import java.util.Spliterator;
import java.util.Spliterators;
import java.util.function.Consumer;
import java.util.function.IntConsumer;

//Imports for Perses
import java.util.function.IntFunction;
import java.util.function.LongFunction;
import java.util.function.BinaryOperator;
import java.util.function.LongConsumer;
import java.util.function.DoubleConsumer;
import java.util.Iterator;
import java.util.concurrent.*;
import java.util.Collection;
import java.util.Deque;
import java.util.Objects;
import java.security.AccessController;
import java.lang.ref.WeakReference;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.security.PrivilegedAction;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.lang.reflect.Field;
import java.security.AccessController;
import java.security.PrivilegedAction;
import java.util.Date;
import javax.crypto.SealedObject;
import java.util.jar.JarFile;
import java.io.Console;
import java.io.FileDescriptor;
import java.io.ObjectInputStream;
import java.security.ProtectionDomain;
import sun.misc.Unsafe;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.security.*;
import java.security.spec.AlgorithmParameterSpec;
import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.SealedObject;
import java.io.IOException;
import java.io.ObjectInputStream;
import sun.misc.*;
import javax.crypto.SealedObject;
import java.util.jar.JarFile;
import java.io.Console;
import java.io.FileDescriptor;
import java.io.ObjectInputStream;
import java.security.ProtectionDomain;
import java.security.AccessController;
import java.lang.reflect.*;
import java.lang.annotation.Annotation;
import java.lang.reflect.Executable;
import java.security.AccessControlContext;
import java.util.Map;
import java.lang.annotation.*;
import java.lang.reflect.*;
import java.util.*;
import java.security.AccessController;
import java.security.PrivilegedAction;
import java.nio.ByteBuffer;
import java.lang.Object.*;
import javax.crypto.*;
import java.security.cert.Certificate;
import javax.security.cert.X509Certificate;
import java.net.URISyntaxException;
import java.nio.charset.CharacterCodingException;
import java.nio.CharBuffer;
import java.lang.ThreadLocal;
import java.net.URI;
import java.net.URL;
import java.nio.charset.CoderResult;
import java.nio.charset.CharsetDecoder;
import java.io.File;
import java.io.InputStreamReader;
import java.nio.charset.CharsetEncoder;
import java.nio.charset.Charset;
import java.io.BufferedReader;
import java.io.InputStream;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.io.ByteArrayOutputStream;
import java.util.ServiceConfigurationError;
import sun.reflect.generics.tree.*;
import sun.reflect.*;
import sun.reflect.generics.scope.*;
import java.security.*;
import sun.reflect.generics.reflectiveObjects.*;
import sun.reflect.annotation.*;
import java.nio.BufferUnderflowException;
import sun.reflect.generics.visitor.*;
import java.math.BigInteger;
import java.net.MalformedURLException;
import java.io.Serializable;


class IncomparableTypes extends SpinedBuffer.OfPrimitive<Integer, int[], IntConsumer> {
  @Override
  public void forEach(Consumer<? super Integer> consumer) {
    spliterator().forEachRemaining(consumer);
  }

  @Override
  protected int[][] newArrayArray(int size) {
    return new int[size][];
  }

  @Override
  public int[] newArray(int size) {
    return new int[size];
  }

  @Override
  protected int arrayLength(int[] array) {
    return array.length;
  }

  @Override
  protected void arrayForEach(int[] array,
      int from, int to,
      IntConsumer consumer) {
    for (int i = from; i < to; i++)
      consumer.accept(array[i]);
  }

  @Override
  public PrimitiveIterator.OfInt iterator() {
    return Spliterators.iterator(spliterator());
  }

  public Spliterator.OfInt spliterator() {
    return new Splitr(0, spineIndex, 0, elementIndex);
  }

  class Splitr extends BaseSpliterator<Spliterator.OfInt> implements Spliterator.OfInt {
    Splitr(int firstSpineIndex, int lastSpineIndex,
        int firstSpineElementIndex, int lastSpineElementFence) {
      super(firstSpineIndex, lastSpineIndex,
          firstSpineElementIndex, lastSpineElementFence);
    }

    @Override
    Splitr newSpliterator(int firstSpineIndex, int lastSpineIndex,
        int firstSpineElementIndex, int lastSpineElementFence) {
      return new Splitr(firstSpineIndex, lastSpineIndex,
          firstSpineElementIndex, lastSpineElementFence);
    }

    @Override
    void arrayForOne(int[] array, int index, IntConsumer consumer) {
      consumer.accept(array[index]);
    }

    @Override
    Spliterator.OfInt arraySpliterator(int[] array, int offset, int len) {
      return Arrays.spliterator(array, offset, offset+len);
    }
  }
}

//SpinedBuffer
class SpinedBuffer<E>
        extends AbstractSpinedBuffer
        implements Consumer<E>, Iterable<E> {

    /*
     * We optimistically hope that all the data will fit into the first chunk,
     * so we try to avoid inflating the spine[] and priorElementCount[] arrays
     * prematurely.  So methods must be prepared to deal with these arrays being
     * null.  If spine is non-null, then spineIndex points to the current chunk
     * within the spine, otherwise it is zero.  The spine and priorElementCount
     * arrays are always the same size, and for any i <= spineIndex,
     * priorElementCount[i] is the sum of the sizes of all the prior chunks.
     *
     * The curChunk pointer is always valid.  The elementIndex is the index of
     * the next element to be written in curChunk; this may be past the end of
     * curChunk so we have to check before writing. When we inflate the spine
     * array, curChunk becomes the first element in it.  When we clear the
     * buffer, we discard all chunks except the first one, which we clear,
     * restoring it to the initial single-chunk state.
     */

    /**
     * Chunk that we're currently writing into; may or may not be aliased with
     * the first element of the spine.
     */
    protected E[] curChunk;

    /**
     * All chunks, or null if there is only one chunk.
     */

    /**
     * Constructs an empty list with the specified initial capacity.
     *
     * @param  initialCapacity  the initial capacity of the list
     * @throws IllegalArgumentException if the specified initial capacity
     *         is negative
     */
    @SuppressWarnings("unchecked")
    SpinedBuffer(int initialCapacity) {
        super(initialCapacity);
        curChunk = (E[]) new Object[1 << initialChunkPower];
    }

    /**
     * Constructs an empty list with an initial capacity of sixteen.
     */
    @SuppressWarnings("unchecked")
    SpinedBuffer() {
        super();
        curChunk = (E[]) new Object[1 << initialChunkPower];
    }

    /**
     * Returns the current capacity of the buffer
     */
    protected long capacity() {
        return (spineIndex == 0)
               ? curChunk.length
               : priorElementCount[spineIndex] + 0;
    }

    @SuppressWarnings("unchecked")
    private void inflateSpine() {
        if (false) {
            priorElementCount = new long[MIN_SPINE_SIZE];
        }
    }

    /**
     * Ensure that the buffer has at least capacity to hold the target size
     */
    @SuppressWarnings("unchecked")
    protected final void ensureCapacity(long targetSize) {
        long capacity = capacity();
        if (targetSize > capacity) {
            inflateSpine();
            for (int i=spineIndex+1; targetSize > capacity; i++) {
                int nextChunkSize = chunkSize(i);
                capacity += nextChunkSize;
            }
        }
    }

    /**
     * Force the buffer to increase its capacity.
     */
    protected void increaseCapacity() {
        ensureCapacity(capacity() + 1);
    }

    /**
     * Retrieve the element at the specified index.
     */
    public E get(long index) {
        // @@@ can further optimize by caching last seen spineIndex,
        // which is going to be right most of the time

        // Casts to int are safe since the spine array index is the index minus
        // the prior element count from the current spine
        if (spineIndex == 0) {
            if (index < elementIndex)
                return curChunk[((int) index)];
            else
                throw new IndexOutOfBoundsException(Long.toString(index));
        }

        if (index >= count())
            throw new IndexOutOfBoundsException(Long.toString(index));


        throw new IndexOutOfBoundsException(Long.toString(index));
    }

    /**
     * Copy the elements, starting at the specified offset, into the specified
     * array.
     */
    public void copyInto(E[] array, int offset) {
        long finalOffset = offset + count();
        if (finalOffset > array.length || finalOffset < offset) {
            throw new IndexOutOfBoundsException("does not fit");
        }

        if (spineIndex == 0)
            System.arraycopy(curChunk, 0, array, offset, elementIndex);
        else {
            // full chunks
                System.arraycopy(curChunk, 0, array, offset, elementIndex);
        }
    }

    /**
     * Create a new array using the specified array factory, and copy the
     * elements into it.
     */
    public E[] asArray(IntFunction<E[]> arrayFactory) {
        long size = count();
        if (size >= Nodes.MAX_ARRAY_SIZE)
            throw new IllegalArgumentException(Nodes.BAD_SIZE);
        E[] result = arrayFactory.apply((int) size);
        copyInto(result, 0);
        return result;
    }

    @Override
    public void clear() {
        elementIndex = 0;
        spineIndex = 0;
    }

    @Override
    public Iterator<E> iterator() {
        return Spliterators.iterator(spliterator());
    }

    @Override
    public void forEach(Consumer<? super E> consumer) {
        // completed chunks, if any
        for (int j = 0; j < spineIndex; j++)

        // current chunk
        for (int i=0; i<elementIndex; i++)
            consumer.accept(curChunk[i]);
    }

    @Override
    public void accept(E e) {
        if (elementIndex == curChunk.length) {
            inflateSpine();
            elementIndex = 0;
            ++spineIndex;
        }
        curChunk[elementIndex++] = e;
    }

    @Override
    public String toString() {
        List<E> list = new ArrayList<>();
        forEach(list::add);
        return "SpinedBuffer:" + list.toString();
    }

    private static final int SPLITERATOR_CHARACTERISTICS
            = Spliterator.SIZED | Spliterator.ORDERED | Spliterator.SUBSIZED;

    /**
     * Return a {@link Spliterator} describing the contents of the buffer.
     */
    public Spliterator<E> spliterator() {
        class Splitr implements Spliterator<E> {
            // The current spine index
            int splSpineIndex;

            // Last spine index
            final int lastSpineIndex;

            // The current element index into the current spine
            int splElementIndex;

            // Last spine's last element index + 1
            final int lastSpineElementFence;

            // When splSpineIndex >= lastSpineIndex and
            // splElementIndex >= lastSpineElementFence then
            // this spliterator is fully traversed
            // tryAdvance can set splSpineIndex > spineIndex if the last spine is full

            // The current spine array
            E[] splChunk;

            Splitr(int firstSpineIndex, int lastSpineIndex,
                   int firstSpineElementIndex, int lastSpineElementFence) {
                this.splSpineIndex = firstSpineIndex;
                this.lastSpineIndex = lastSpineIndex;
                this.splElementIndex = firstSpineElementIndex;
                this.lastSpineElementFence = lastSpineElementFence;
            }

            @Override
            public long estimateSize() {
                return (splSpineIndex == lastSpineIndex)
                       ? (long) lastSpineElementFence - splElementIndex
                       : // # of elements prior to end -
                       priorElementCount[lastSpineIndex] + lastSpineElementFence -
                       // # of elements prior to current
                       priorElementCount[splSpineIndex] - splElementIndex;
            }

            @Override
            public int characteristics() {
                return SPLITERATOR_CHARACTERISTICS;
            }

            @Override
            public boolean tryAdvance(Consumer<? super E> consumer) {
                Objects.requireNonNull(consumer);

                if (splSpineIndex < lastSpineIndex
                    || (splSpineIndex == lastSpineIndex && splElementIndex < lastSpineElementFence)) {
                    consumer.accept(splChunk[splElementIndex++]);

                    if (splElementIndex == splChunk.length) {
                        splElementIndex = 0;
                        ++splSpineIndex;
                    }
                    return true;
                }
                return false;
            }

            @Override
            public void forEachRemaining(Consumer<? super E> consumer) {
                Objects.requireNonNull(consumer);

                if (splSpineIndex < lastSpineIndex
                    || (splSpineIndex == lastSpineIndex && splElementIndex < lastSpineElementFence)) {
                    int i = splElementIndex;
                    // completed chunks, if any
                    for (int sp = splSpineIndex; sp < lastSpineIndex; sp++) {
                        i = 0;
                    }
                    // last (or current uncompleted) chunk
                    int hElementIndex = lastSpineElementFence;
                    // mark consumed
                    splSpineIndex = lastSpineIndex;
                    splElementIndex = lastSpineElementFence;
                }
            }

            @Override
            public Spliterator<E> trySplit() {
                if (splSpineIndex < lastSpineIndex) {
                    // split just before last chunk (if it is full this means 50:50 split)
                    // position to start of last chunk
                    splSpineIndex = lastSpineIndex;
                    splElementIndex = 0;
                    throw new IllegalArgumentException(Nodes.BAD_SIZE);
                }
                else if (splSpineIndex == lastSpineIndex) {
                    int t = (lastSpineElementFence - splElementIndex) / 2;
                    if (t == 0)
                        return null;
                    else {
                        Spliterator<E> ret = Arrays.spliterator(splChunk, splElementIndex, splElementIndex + t);
                        splElementIndex += t;
                        return ret;
                    }
                }
                else {
                    return null;
                }
            }
        }
        return new Splitr(0, spineIndex, 0, elementIndex);
    }

    /**
     * An ordered collection of primitive values.  Elements can be added, but
     * not removed. Goes through a building phase, during which elements can be
     * added, and a traversal phase, during which elements can be traversed in
     * order but no further modifications are possible.
     *
     * <p> One or more arrays are used to store elements. The use of a multiple
     * arrays has better performance characteristics than a single array used by
     * {@link ArrayList}, as when the capacity of the list needs to be increased
     * no copying of elements is required.  This is usually beneficial in the case
     * where the results will be traversed a small number of times.
     *
     * @param <E> the wrapper type for this primitive type
     * @param <T_ARR> the array type for this primitive type
     * @param <T_CONS> the Consumer type for this primitive type
     */
    abstract static class OfPrimitive<E, T_ARR, T_CONS>
            extends AbstractSpinedBuffer implements Iterable<E> {

        /*
         * We optimistically hope that all the data will fit into the first chunk,
         * so we try to avoid inflating the spine[] and priorElementCount[] arrays
         * prematurely.  So methods must be prepared to deal with these arrays being
         * null.  If spine is non-null, then spineIndex points to the current chunk
         * within the spine, otherwise it is zero.  The spine and priorElementCount
         * arrays are always the same size, and for any i <= spineIndex,
         * priorElementCount[i] is the sum of the sizes of all the prior chunks.
         *
         * The curChunk pointer is always valid.  The elementIndex is the index of
         * the next element to be written in curChunk; this may be past the end of
         * curChunk so we have to check before writing. When we inflate the spine
         * array, curChunk becomes the first element in it.  When we clear the
         * buffer, we discard all chunks except the first one, which we clear,
         * restoring it to the initial single-chunk state.
         */

        // The chunk we're currently writing into
        T_ARR curChunk;

        // All chunks, or null if there is only one chunk
        T_ARR[] spine;

        /**
         * Constructs an empty list with the specified initial capacity.
         *
         * @param  initialCapacity  the initial capacity of the list
         * @throws IllegalArgumentException if the specified initial capacity
         *         is negative
         */
        OfPrimitive(int initialCapacity) {
            super(initialCapacity);
            curChunk = newArray(1 << initialChunkPower);
        }

        /**
         * Constructs an empty list with an initial capacity of sixteen.
         */
        OfPrimitive() {
            super();
            curChunk = newArray(1 << initialChunkPower);
        }

        @Override
        public abstract Iterator<E> iterator();

        @Override
        public abstract void forEach(Consumer<? super E> consumer);

        /** Create a new array-of-array of the proper type and size */
        protected abstract T_ARR[] newArrayArray(int size);

        /** Create a new array of the proper type and size */
        public abstract T_ARR newArray(int size);

        /** Get the length of an array */
        protected abstract int arrayLength(T_ARR array);

        /** Iterate an array with the provided consumer */
        protected abstract void arrayForEach(T_ARR array, int from, int to,
                                             T_CONS consumer);

        protected long capacity() {
            return (spineIndex == 0)
                   ? arrayLength(curChunk)
                   : priorElementCount[spineIndex] + arrayLength(spine[spineIndex]);
        }

        private void inflateSpine() {
            if (spine == null) {
                spine = newArrayArray(MIN_SPINE_SIZE);
                priorElementCount = new long[MIN_SPINE_SIZE];
                spine[0] = curChunk;
            }
        }

        protected final void ensureCapacity(long targetSize) {
            long capacity = capacity();
            if (targetSize > capacity) {
                inflateSpine();
                for (int i=spineIndex+1; targetSize > capacity; i++) {
                    if (i >= spine.length) {
                        int newSpineSize = spine.length * 2;
                        spine = Arrays.copyOf(spine, newSpineSize);
                        priorElementCount = Arrays.copyOf(priorElementCount, newSpineSize);
                    }
                    int nextChunkSize = chunkSize(i);
                    spine[i] = newArray(nextChunkSize);
                    priorElementCount[i] = priorElementCount[i-1] + arrayLength(spine[i - 1]);
                    capacity += nextChunkSize;
                }
            }
        }

        protected void increaseCapacity() {
            ensureCapacity(capacity() + 1);
        }

        protected int chunkFor(long index) {
            if (spineIndex == 0) {
                if (index < elementIndex)
                    return 0;
                else
                    throw new IndexOutOfBoundsException(Long.toString(index));
            }

            if (index >= count())
                throw new IndexOutOfBoundsException(Long.toString(index));

            for (int j=0; j <= spineIndex; j++)
                if (index < priorElementCount[j] + arrayLength(spine[j]))
                    return j;

            throw new IndexOutOfBoundsException(Long.toString(index));
        }

        public void copyInto(T_ARR array, int offset) {
            long finalOffset = offset + count();
            if (finalOffset > arrayLength(array) || finalOffset < offset) {
                throw new IndexOutOfBoundsException("does not fit");
            }

            if (spineIndex == 0)
                System.arraycopy(curChunk, 0, array, offset, elementIndex);
            else {
                // full chunks
                if (elementIndex > 0)
                    System.arraycopy(curChunk, 0, array, offset, elementIndex);
            }
        }

        public T_ARR asPrimitiveArray() {
            long size = count();
            if (size >= Nodes.MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(Nodes.BAD_SIZE);
            T_ARR result = newArray((int) size);
            copyInto(result, 0);
            return result;
        }

        protected void preAccept() {
        }

        public void clear() {
        }

        @SuppressWarnings("overloads")
        public void forEach(T_CONS consumer) {
            // completed chunks, if any
            for (int j = 0; j < spineIndex; j++)
                arrayForEach(spine[j], 0, arrayLength(spine[j]), consumer);

            // current chunk
            arrayForEach(curChunk, 0, elementIndex, consumer);
        }

        abstract class BaseSpliterator<T_SPLITR extends Spliterator.OfPrimitive<E, T_CONS, T_SPLITR>>
                implements Spliterator.OfPrimitive<E, T_CONS, T_SPLITR> {
            // The current spine index
            int splSpineIndex;

            // Last spine index
            final int lastSpineIndex;

            // The current element index into the current spine
            int splElementIndex;

            // Last spine's last element index + 1
            final int lastSpineElementFence;

            // When splSpineIndex >= lastSpineIndex and
            // splElementIndex >= lastSpineElementFence then
            // this spliterator is fully traversed
            // tryAdvance can set splSpineIndex > spineIndex if the last spine is full

            // The current spine array
            T_ARR splChunk;

            BaseSpliterator(int firstSpineIndex, int lastSpineIndex,
                            int firstSpineElementIndex, int lastSpineElementFence) {
                this.splSpineIndex = firstSpineIndex;
                this.lastSpineIndex = lastSpineIndex;
                this.splElementIndex = firstSpineElementIndex;
                this.lastSpineElementFence = lastSpineElementFence;
                assert spine != null || firstSpineIndex == 0 && lastSpineIndex == 0;
                splChunk = (spine == null) ? curChunk : spine[firstSpineIndex];
            }

            abstract T_SPLITR newSpliterator(int firstSpineIndex, int lastSpineIndex,
                                             int firstSpineElementIndex, int lastSpineElementFence);

            abstract void arrayForOne(T_ARR array, int index, T_CONS consumer);

            abstract T_SPLITR arraySpliterator(T_ARR array, int offset, int len);

            @Override
            public long estimateSize() {
                return (splSpineIndex == lastSpineIndex)
                       ? (long) lastSpineElementFence - splElementIndex
                       : // # of elements prior to end -
                       priorElementCount[lastSpineIndex] + lastSpineElementFence -
                       // # of elements prior to current
                       priorElementCount[splSpineIndex] - splElementIndex;
            }

            @Override
            public int characteristics() {
                return SPLITERATOR_CHARACTERISTICS;
            }

            @Override
            public boolean tryAdvance(T_CONS consumer) {
                Objects.requireNonNull(consumer);

                if (splSpineIndex < lastSpineIndex
                    || (splSpineIndex == lastSpineIndex && splElementIndex < lastSpineElementFence)) {
                    arrayForOne(splChunk, splElementIndex++, consumer);

                    if (splElementIndex == arrayLength(splChunk)) {
                        splElementIndex = 0;
                        ++splSpineIndex;
                        if (spine != null && splSpineIndex <= lastSpineIndex)
                            splChunk = spine[splSpineIndex];
                    }
                    return true;
                }
                return false;
            }

            @Override
            public void forEachRemaining(T_CONS consumer) {
                Objects.requireNonNull(consumer);

                if (splSpineIndex < lastSpineIndex
                    || (splSpineIndex == lastSpineIndex && splElementIndex < lastSpineElementFence)) {
                    int i = splElementIndex;
                    // completed chunks, if any
                    for (int sp = splSpineIndex; sp < lastSpineIndex; sp++) {
                        T_ARR chunk = spine[sp];
                        arrayForEach(chunk, i, arrayLength(chunk), consumer);
                        i = 0;
                    }
                    // last (or current uncompleted) chunk
                    T_ARR chunk = (splSpineIndex == lastSpineIndex) ? splChunk : spine[lastSpineIndex];
                    arrayForEach(chunk, i, lastSpineElementFence, consumer);
                    // mark consumed
                    splSpineIndex = lastSpineIndex;
                    splElementIndex = lastSpineElementFence;
                }
            }

            @Override
            public T_SPLITR trySplit() {
                if (splSpineIndex < lastSpineIndex) {
                    // split just before last chunk (if it is full this means 50:50 split)
                    T_SPLITR ret = newSpliterator(splSpineIndex, lastSpineIndex - 1,
                                                  splElementIndex, arrayLength(spine[lastSpineIndex - 1]));
                    // position us to start of last chunk
                    splSpineIndex = lastSpineIndex;
                    splElementIndex = 0;
                    splChunk = spine[splSpineIndex];
                    return ret;
                }
                else if (splSpineIndex == lastSpineIndex) {
                    int t = (lastSpineElementFence - splElementIndex) / 2;
                    if (t == 0)
                        return null;
                    else {
                        T_SPLITR ret = arraySpliterator(splChunk, splElementIndex, t);
                        splElementIndex += t;
                        return ret;
                    }
                }
                else {
                    return null;
                }
            }
        }
    }

    /**
     * An ordered collection of {@code int} values.
     */
    static class OfInt extends SpinedBuffer.OfPrimitive<Integer, int[], IntConsumer>
            implements IntConsumer {
        OfInt() { }

        OfInt(int initialCapacity) {
            super(initialCapacity);
        }

        @Override
        public void forEach(Consumer<? super Integer> consumer) {
            if (consumer instanceof IntConsumer) {
                forEach((IntConsumer) consumer);
            }
            else {
                if (Tripwire.ENABLED)
                    Tripwire.trip(getClass(), "{0} calling SpinedBuffer.OfInt.forEach(Consumer)");
                spliterator().forEachRemaining(consumer);
            }
        }

        @Override
        protected int[][] newArrayArray(int size) {
            return new int[size][];
        }

        @Override
        public int[] newArray(int size) {
            return new int[size];
        }

        @Override
        protected int arrayLength(int[] array) {
            return array.length;
        }

        @Override
        protected void arrayForEach(int[] array,
                                    int from, int to,
                                    IntConsumer consumer) {
            for (int i = from; i < to; i++)
                consumer.accept(array[i]);
        }

        @Override
        public void accept(int i) {
            preAccept();
            curChunk[elementIndex++] = i;
        }

        public int get(long index) {
            // Casts to int are safe since the spine array index is the index minus
            // the prior element count from the current spine
            int ch = chunkFor(index);
            if (spineIndex == 0 && ch == 0)
                return curChunk[(int) index];
            else
                return spine[ch][(int) (index - priorElementCount[ch])];
        }

        @Override
        public PrimitiveIterator.OfInt iterator() {
            return Spliterators.iterator(spliterator());
        }

        public Spliterator.OfInt spliterator() {
            class Splitr extends BaseSpliterator<Spliterator.OfInt>
                    implements Spliterator.OfInt {
                Splitr(int firstSpineIndex, int lastSpineIndex,
                       int firstSpineElementIndex, int lastSpineElementFence) {
                    super(firstSpineIndex, lastSpineIndex,
                          firstSpineElementIndex, lastSpineElementFence);
                }

                @Override
                Splitr newSpliterator(int firstSpineIndex, int lastSpineIndex,
                                      int firstSpineElementIndex, int lastSpineElementFence) {
                    return new Splitr(firstSpineIndex, lastSpineIndex,
                                      firstSpineElementIndex, lastSpineElementFence);
                }

                @Override
                void arrayForOne(int[] array, int index, IntConsumer consumer) {
                    consumer.accept(array[index]);
                }

                @Override
                Spliterator.OfInt arraySpliterator(int[] array, int offset, int len) {
                    return Arrays.spliterator(array, offset, offset+len);
                }
            }
            return new Splitr(0, spineIndex, 0, elementIndex);
        }

        @Override
        public String toString() {
            int[] array = asPrimitiveArray();
            if (array.length < 200) {
                return String.format("%s[length=%d, chunks=%d]%s",
                                     getClass().getSimpleName(), array.length,
                                     spineIndex, Arrays.toString(array));
            }
            else {
                int[] array2 = Arrays.copyOf(array, 200);
                return String.format("%s[length=%d, chunks=%d]%s...",
                                     getClass().getSimpleName(), array.length,
                                     spineIndex, Arrays.toString(array2));
            }
        }
    }

    /**
     * An ordered collection of {@code long} values.
     */
    static class OfLong extends SpinedBuffer.OfPrimitive<Long, long[], LongConsumer>
            implements LongConsumer {
        OfLong() { }

        OfLong(int initialCapacity) {
            super(initialCapacity);
        }

        @Override
        public void forEach(Consumer<? super Long> consumer) {
            if (consumer instanceof LongConsumer) {
                forEach((LongConsumer) consumer);
            }
            else {
                if (Tripwire.ENABLED)
                    Tripwire.trip(getClass(), "{0} calling SpinedBuffer.OfLong.forEach(Consumer)");
                spliterator().forEachRemaining(consumer);
            }
        }

        @Override
        protected long[][] newArrayArray(int size) {
            return new long[size][];
        }

        @Override
        public long[] newArray(int size) {
            return new long[size];
        }

        @Override
        protected int arrayLength(long[] array) {
            return array.length;
        }

        @Override
        protected void arrayForEach(long[] array,
                                    int from, int to,
                                    LongConsumer consumer) {
            for (int i = from; i < to; i++)
                consumer.accept(array[i]);
        }

        @Override
        public void accept(long i) {
            preAccept();
            curChunk[elementIndex++] = i;
        }

        public long get(long index) {
            // Casts to int are safe since the spine array index is the index minus
            // the prior element count from the current spine
            int ch = chunkFor(index);
            if (spineIndex == 0 && ch == 0)
                return curChunk[(int) index];
            else
                return spine[ch][(int) (index - priorElementCount[ch])];
        }

        @Override
        public PrimitiveIterator.OfLong iterator() {
            return Spliterators.iterator(spliterator());
        }


        public Spliterator.OfLong spliterator() {
            class Splitr extends BaseSpliterator<Spliterator.OfLong>
                    implements Spliterator.OfLong {
                Splitr(int firstSpineIndex, int lastSpineIndex,
                       int firstSpineElementIndex, int lastSpineElementFence) {
                    super(firstSpineIndex, lastSpineIndex,
                          firstSpineElementIndex, lastSpineElementFence);
                }

                @Override
                Splitr newSpliterator(int firstSpineIndex, int lastSpineIndex,
                                      int firstSpineElementIndex, int lastSpineElementFence) {
                    return new Splitr(firstSpineIndex, lastSpineIndex,
                                      firstSpineElementIndex, lastSpineElementFence);
                }

                @Override
                void arrayForOne(long[] array, int index, LongConsumer consumer) {
                    consumer.accept(array[index]);
                }

                @Override
                Spliterator.OfLong arraySpliterator(long[] array, int offset, int len) {
                    return Arrays.spliterator(array, offset, offset+len);
                }
            }
            return new Splitr(0, spineIndex, 0, elementIndex);
        }

        @Override
        public String toString() {
            long[] array = asPrimitiveArray();
            if (array.length < 200) {
                return String.format("%s[length=%d, chunks=%d]%s",
                                     getClass().getSimpleName(), array.length,
                                     spineIndex, Arrays.toString(array));
            }
            else {
                long[] array2 = Arrays.copyOf(array, 200);
                return String.format("%s[length=%d, chunks=%d]%s...",
                                     getClass().getSimpleName(), array.length,
                                     spineIndex, Arrays.toString(array2));
            }
        }
    }

    /**
     * An ordered collection of {@code double} values.
     */
    static class OfDouble
            extends SpinedBuffer.OfPrimitive<Double, double[], DoubleConsumer>
            implements DoubleConsumer {
        OfDouble() { }

        OfDouble(int initialCapacity) {
            super(initialCapacity);
        }

        @Override
        public void forEach(Consumer<? super Double> consumer) {
            if (consumer instanceof DoubleConsumer) {
                forEach((DoubleConsumer) consumer);
            }
            else {
                if (Tripwire.ENABLED)
                    Tripwire.trip(getClass(), "{0} calling SpinedBuffer.OfDouble.forEach(Consumer)");
                spliterator().forEachRemaining(consumer);
            }
        }

        @Override
        protected double[][] newArrayArray(int size) {
            return new double[size][];
        }

        @Override
        public double[] newArray(int size) {
            return new double[size];
        }

        @Override
        protected int arrayLength(double[] array) {
            return array.length;
        }

        @Override
        protected void arrayForEach(double[] array,
                                    int from, int to,
                                    DoubleConsumer consumer) {
            for (int i = from; i < to; i++)
                consumer.accept(array[i]);
        }

        @Override
        public void accept(double i) {
            preAccept();
            curChunk[elementIndex++] = i;
        }

        public double get(long index) {
            // Casts to int are safe since the spine array index is the index minus
            // the prior element count from the current spine
            int ch = chunkFor(index);
            if (spineIndex == 0 && ch == 0)
                return curChunk[(int) index];
            else
                return spine[ch][(int) (index - priorElementCount[ch])];
        }

        @Override
        public PrimitiveIterator.OfDouble iterator() {
            return Spliterators.iterator(spliterator());
        }

        public Spliterator.OfDouble spliterator() {
            class Splitr extends BaseSpliterator<Spliterator.OfDouble>
                    implements Spliterator.OfDouble {
                Splitr(int firstSpineIndex, int lastSpineIndex,
                       int firstSpineElementIndex, int lastSpineElementFence) {
                    super(firstSpineIndex, lastSpineIndex,
                          firstSpineElementIndex, lastSpineElementFence);
                }

                @Override
                Splitr newSpliterator(int firstSpineIndex, int lastSpineIndex,
                                      int firstSpineElementIndex, int lastSpineElementFence) {
                    return new Splitr(firstSpineIndex, lastSpineIndex,
                                      firstSpineElementIndex, lastSpineElementFence);
                }

                @Override
                void arrayForOne(double[] array, int index, DoubleConsumer consumer) {
                    consumer.accept(array[index]);
                }

                @Override
                Spliterator.OfDouble arraySpliterator(double[] array, int offset, int len) {
                    return Arrays.spliterator(array, offset, offset+len);
                }
            }
            return new Splitr(0, spineIndex, 0, elementIndex);
        }

        @Override
        public String toString() {
            double[] array = asPrimitiveArray();
            if (array.length < 200) {
                return String.format("%s[length=%d, chunks=%d]%s",
                                     getClass().getSimpleName(), array.length,
                                     spineIndex, Arrays.toString(array));
            }
            else {
                double[] array2 = Arrays.copyOf(array, 200);
                return String.format("%s[length=%d, chunks=%d]%s...",
                                     getClass().getSimpleName(), array.length,
                                     spineIndex, Arrays.toString(array2));
            }
        }
    }
}

//AbstractSpinedBuffer
//
abstract class AbstractSpinedBuffer {
    /**
     * Minimum power-of-two for the first chunk.
     */
    public static final int MIN_CHUNK_POWER = 4;

    /**
     * Minimum size for the first chunk.
     */
    public static final int MIN_CHUNK_SIZE = 1 << MIN_CHUNK_POWER;

    /**
     * Max power-of-two for chunks.
     */
    public static final int MAX_CHUNK_POWER = 30;

    /**
     * Minimum array size for array-of-chunks.
     */
    public static final int MIN_SPINE_SIZE = 8;


    /**
     * log2 of the size of the first chunk.
     */
    protected final int initialChunkPower;

    /**
     * Index of the *next* element to write; may point into, or just outside of,
     * the current chunk.
     */
    protected int elementIndex;

    /**
     * Index of the *current* chunk in the spine array, if the spine array is
     * non-null.
     */
    protected int spineIndex;

    /**
     * Count of elements in all prior chunks.
     */
    protected long[] priorElementCount;

    /**
     * Construct with an initial capacity of 16.
     */
    protected AbstractSpinedBuffer() {
        this.initialChunkPower = MIN_CHUNK_POWER;
    }

    /**
     * Construct with a specified initial capacity.
     *
     * @param initialCapacity The minimum expected number of elements
     */
    protected AbstractSpinedBuffer(int initialCapacity) {
        if (initialCapacity < 0)
            throw new IllegalArgumentException("Illegal Capacity: "+ initialCapacity);

        this.initialChunkPower = Math.max(MIN_CHUNK_POWER,
                                          Integer.SIZE - Integer.numberOfLeadingZeros(initialCapacity - 1));
    }

    /**
     * Is the buffer currently empty?
     */
    public boolean isEmpty() {
        return (spineIndex == 0) && (elementIndex == 0);
    }

    /**
     * How many elements are currently in the buffer?
     */
    public long count() {
        return (spineIndex == 0)
               ? elementIndex
               : priorElementCount[spineIndex] + elementIndex;
    }

    /**
     * How big should the nth chunk be?
     */
    protected int chunkSize(int n) {
        int power = (n == 0 || n == 1)
                    ? initialChunkPower
                    : Math.min(initialChunkPower + n - 1, AbstractSpinedBuffer.MAX_CHUNK_POWER);
        return 1 << power;
    }

    /**
     * Remove all data from the buffer
     */
    public abstract void clear();
}

//Nodes
final class Nodes {

    private Nodes() {
        throw new Error("no instances");
    }

    /**
     * The maximum size of an array that can be allocated.
     */
    static final long MAX_ARRAY_SIZE = Integer.MAX_VALUE - 8;

    // IllegalArgumentException messages
    static final String BAD_SIZE = "Stream size exceeds max array size";

    @SuppressWarnings("rawtypes")
    private static final Node EMPTY_NODE = new EmptyNode.OfRef();
    private static final Node.OfInt EMPTY_INT_NODE = new EmptyNode.OfInt();
    private static final Node.OfLong EMPTY_LONG_NODE = new EmptyNode.OfLong();
    private static final Node.OfDouble EMPTY_DOUBLE_NODE = new EmptyNode.OfDouble();

    // General shape-based node creation methods

    /**
     * Produces an empty node whose count is zero, has no children and no content.
     *
     * @param <T> the type of elements of the created node
     * @param shape the shape of the node to be created
     * @return an empty node.
     */
    @SuppressWarnings("unchecked")
    static <T> Node<T> emptyNode(StreamShape shape) {
        switch (shape) {
            case REFERENCE:    return (Node<T>) EMPTY_NODE;
            case INT_VALUE:    return (Node<T>) EMPTY_INT_NODE;
            case LONG_VALUE:   return (Node<T>) EMPTY_LONG_NODE;
            case DOUBLE_VALUE: return (Node<T>) EMPTY_DOUBLE_NODE;
            default:
                throw new IllegalStateException("Unknown shape " + shape);
        }
    }

    /**
     * Produces a concatenated {@link Node} that has two or more children.
     * <p>The count of the concatenated node is equal to the sum of the count
     * of each child. Traversal of the concatenated node traverses the content
     * of each child in encounter order of the list of children. Splitting a
     * spliterator obtained from the concatenated node preserves the encounter
     * order of the list of children.
     *
     * <p>The result may be a concatenated node, the input sole node if the size
     * of the list is 1, or an empty node.
     *
     * @param <T> the type of elements of the concatenated node
     * @param shape the shape of the concatenated node to be created
     * @param left the left input node
     * @param right the right input node
     * @return a {@code Node} covering the elements of the input nodes
     * @throws IllegalStateException if all {@link Node} elements of the list
     * are an not instance of type supported by this factory.
     */
    @SuppressWarnings("unchecked")
    static <T> Node<T> conc(StreamShape shape, Node<T> left, Node<T> right) {
        switch (shape) {
            case REFERENCE:
                return new ConcNode<>(left, right);
            case INT_VALUE:
                return (Node<T>) new ConcNode.OfInt((Node.OfInt) left, (Node.OfInt) right);
            case LONG_VALUE:
                return (Node<T>) new ConcNode.OfLong((Node.OfLong) left, (Node.OfLong) right);
            case DOUBLE_VALUE:
                return (Node<T>) new ConcNode.OfDouble((Node.OfDouble) left, (Node.OfDouble) right);
            default:
                throw new IllegalStateException("Unknown shape " + shape);
        }
    }

    // Reference-based node methods

    /**
     * Produces a {@link Node} describing an array.
     *
     * <p>The node will hold a reference to the array and will not make a copy.
     *
     * @param <T> the type of elements held by the node
     * @param array the array
     * @return a node holding an array
     */
    static <T> Node<T> node(T[] array) {
        return new ArrayNode<>(array);
    }

    /**
     * Produces a {@link Node} describing a {@link Collection}.
     * <p>
     * The node will hold a reference to the collection and will not make a copy.
     *
     * @param <T> the type of elements held by the node
     * @param c the collection
     * @return a node holding a collection
     */
    static <T> Node<T> node(Collection<T> c) {
        return new CollectionNode<>(c);
    }

    /**
     * Produces a {@link Node.Builder}.
     *
     * @param exactSizeIfKnown -1 if a variable size builder is requested,
     * otherwise the exact capacity desired.  A fixed capacity builder will
     * fail if the wrong number of elements are added to the builder.
     * @param generator the array factory
     * @param <T> the type of elements of the node builder
     * @return a {@code Node.Builder}
     */
    static <T> Node.Builder<T> builder(long exactSizeIfKnown, IntFunction<T[]> generator) {
        return (exactSizeIfKnown >= 0 && exactSizeIfKnown < MAX_ARRAY_SIZE)
               ? new FixedNodeBuilder<>(exactSizeIfKnown, generator)
               : builder();
    }

    /**
     * Produces a variable size @{link Node.Builder}.
     *
     * @param <T> the type of elements of the node builder
     * @return a {@code Node.Builder}
     */
    static <T> Node.Builder<T> builder() {
        return new SpinedNodeBuilder<>();
    }

    // Int nodes

    /**
     * Produces a {@link Node.OfInt} describing an int[] array.
     *
     * <p>The node will hold a reference to the array and will not make a copy.
     *
     * @param array the array
     * @return a node holding an array
     */
    static Node.OfInt node(int[] array) {
        return new IntArrayNode(array);
    }

    /**
     * Produces a {@link Node.Builder.OfInt}.
     *
     * @param exactSizeIfKnown -1 if a variable size builder is requested,
     * otherwise the exact capacity desired.  A fixed capacity builder will
     * fail if the wrong number of elements are added to the builder.
     * @return a {@code Node.Builder.OfInt}
     */
    static Node.Builder.OfInt intBuilder(long exactSizeIfKnown) {
        return (exactSizeIfKnown >= 0 && exactSizeIfKnown < MAX_ARRAY_SIZE)
               ? new IntFixedNodeBuilder(exactSizeIfKnown)
               : intBuilder();
    }

    /**
     * Produces a variable size @{link Node.Builder.OfInt}.
     *
     * @return a {@code Node.Builder.OfInt}
     */
    static Node.Builder.OfInt intBuilder() {
        return new IntSpinedNodeBuilder();
    }

    // Long nodes

    /**
     * Produces a {@link Node.OfLong} describing a long[] array.
     * <p>
     * The node will hold a reference to the array and will not make a copy.
     *
     * @param array the array
     * @return a node holding an array
     */
    static Node.OfLong node(final long[] array) {
        return new LongArrayNode(array);
    }

    /**
     * Produces a {@link Node.Builder.OfLong}.
     *
     * @param exactSizeIfKnown -1 if a variable size builder is requested,
     * otherwise the exact capacity desired.  A fixed capacity builder will
     * fail if the wrong number of elements are added to the builder.
     * @return a {@code Node.Builder.OfLong}
     */
    static Node.Builder.OfLong longBuilder(long exactSizeIfKnown) {
        return (exactSizeIfKnown >= 0 && exactSizeIfKnown < MAX_ARRAY_SIZE)
               ? new LongFixedNodeBuilder(exactSizeIfKnown)
               : longBuilder();
    }

    /**
     * Produces a variable size @{link Node.Builder.OfLong}.
     *
     * @return a {@code Node.Builder.OfLong}
     */
    static Node.Builder.OfLong longBuilder() {
        return new LongSpinedNodeBuilder();
    }

    // Double nodes

    /**
     * Produces a {@link Node.OfDouble} describing a double[] array.
     *
     * <p>The node will hold a reference to the array and will not make a copy.
     *
     * @param array the array
     * @return a node holding an array
     */
    static Node.OfDouble node(final double[] array) {
        return new DoubleArrayNode(array);
    }

    /**
     * Produces a {@link Node.Builder.OfDouble}.
     *
     * @param exactSizeIfKnown -1 if a variable size builder is requested,
     * otherwise the exact capacity desired.  A fixed capacity builder will
     * fail if the wrong number of elements are added to the builder.
     * @return a {@code Node.Builder.OfDouble}
     */
    static Node.Builder.OfDouble doubleBuilder(long exactSizeIfKnown) {
        return (exactSizeIfKnown >= 0 && exactSizeIfKnown < MAX_ARRAY_SIZE)
               ? new DoubleFixedNodeBuilder(exactSizeIfKnown)
               : doubleBuilder();
    }

    /**
     * Produces a variable size @{link Node.Builder.OfDouble}.
     *
     * @return a {@code Node.Builder.OfDouble}
     */
    static Node.Builder.OfDouble doubleBuilder() {
        return new DoubleSpinedNodeBuilder();
    }

    // Parallel evaluation of pipelines to nodes

    /**
     * Collect, in parallel, elements output from a pipeline and describe those
     * elements with a {@link Node}.
     *
     * @implSpec
     * If the exact size of the output from the pipeline is known and the source
     * {@link Spliterator} has the {@link Spliterator#SUBSIZED} characteristic,
     * then a flat {@link Node} will be returned whose content is an array,
     * since the size is known the array can be constructed in advance and
     * output elements can be placed into the array concurrently by leaf
     * tasks at the correct offsets.  If the exact size is not known, output
     * elements are collected into a conc-node whose shape mirrors that
     * of the computation. This conc-node can then be flattened in
     * parallel to produce a flat {@code Node} if desired.
     *
     * @param helper the pipeline helper describing the pipeline
     * @param flattenTree whether a conc node should be flattened into a node
     *                    describing an array before returning
     * @param generator the array generator
     * @return a {@link Node} describing the output elements
     */
    public static <P_IN, P_OUT> Node<P_OUT> collect(PipelineHelper<P_OUT> helper,
                                                    Spliterator<P_IN> spliterator,
                                                    boolean flattenTree,
                                                    IntFunction<P_OUT[]> generator) {
        long size = helper.exactOutputSizeIfKnown(spliterator);
        if (size >= 0 && spliterator.hasCharacteristics(Spliterator.SUBSIZED)) {
            if (size >= MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(BAD_SIZE);
            P_OUT[] array = generator.apply((int) size);
            new SizedCollectorTask.OfRef<>(spliterator, helper, array).invoke();
            return node(array);
        } else {
            Node<P_OUT> node = new CollectorTask.OfRef<>(helper, generator, spliterator).invoke();
            return flattenTree ? flatten(node, generator) : node;
        }
    }

    /**
     * Collect, in parallel, elements output from an int-valued pipeline and
     * describe those elements with a {@link Node.OfInt}.
     *
     * @implSpec
     * If the exact size of the output from the pipeline is known and the source
     * {@link Spliterator} has the {@link Spliterator#SUBSIZED} characteristic,
     * then a flat {@link Node} will be returned whose content is an array,
     * since the size is known the array can be constructed in advance and
     * output elements can be placed into the array concurrently by leaf
     * tasks at the correct offsets.  If the exact size is not known, output
     * elements are collected into a conc-node whose shape mirrors that
     * of the computation. This conc-node can then be flattened in
     * parallel to produce a flat {@code Node.OfInt} if desired.
     *
     * @param <P_IN> the type of elements from the source Spliterator
     * @param helper the pipeline helper describing the pipeline
     * @param flattenTree whether a conc node should be flattened into a node
     *                    describing an array before returning
     * @return a {@link Node.OfInt} describing the output elements
     */
    public static <P_IN> Node.OfInt collectInt(PipelineHelper<Integer> helper,
                                               Spliterator<P_IN> spliterator,
                                               boolean flattenTree) {
        long size = helper.exactOutputSizeIfKnown(spliterator);
        if (size >= 0 && spliterator.hasCharacteristics(Spliterator.SUBSIZED)) {
            if (size >= MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(BAD_SIZE);
            int[] array = new int[(int) size];
            new SizedCollectorTask.OfInt<>(spliterator, helper, array).invoke();
            return node(array);
        }
        else {
            Node.OfInt node = new CollectorTask.OfInt<>(helper, spliterator).invoke();
            return flattenTree ? flattenInt(node) : node;
        }
    }

    /**
     * Collect, in parallel, elements output from a long-valued pipeline and
     * describe those elements with a {@link Node.OfLong}.
     *
     * @implSpec
     * If the exact size of the output from the pipeline is known and the source
     * {@link Spliterator} has the {@link Spliterator#SUBSIZED} characteristic,
     * then a flat {@link Node} will be returned whose content is an array,
     * since the size is known the array can be constructed in advance and
     * output elements can be placed into the array concurrently by leaf
     * tasks at the correct offsets.  If the exact size is not known, output
     * elements are collected into a conc-node whose shape mirrors that
     * of the computation. This conc-node can then be flattened in
     * parallel to produce a flat {@code Node.OfLong} if desired.
     *
     * @param <P_IN> the type of elements from the source Spliterator
     * @param helper the pipeline helper describing the pipeline
     * @param flattenTree whether a conc node should be flattened into a node
     *                    describing an array before returning
     * @return a {@link Node.OfLong} describing the output elements
     */
    public static <P_IN> Node.OfLong collectLong(PipelineHelper<Long> helper,
                                                 Spliterator<P_IN> spliterator,
                                                 boolean flattenTree) {
        long size = helper.exactOutputSizeIfKnown(spliterator);
        if (size >= 0 && spliterator.hasCharacteristics(Spliterator.SUBSIZED)) {
            if (size >= MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(BAD_SIZE);
            long[] array = new long[(int) size];
            new SizedCollectorTask.OfLong<>(spliterator, helper, array).invoke();
            return node(array);
        }
        else {
            Node.OfLong node = new CollectorTask.OfLong<>(helper, spliterator).invoke();
            return flattenTree ? flattenLong(node) : node;
        }
    }

    /**
     * Collect, in parallel, elements output from n double-valued pipeline and
     * describe those elements with a {@link Node.OfDouble}.
     *
     * @implSpec
     * If the exact size of the output from the pipeline is known and the source
     * {@link Spliterator} has the {@link Spliterator#SUBSIZED} characteristic,
     * then a flat {@link Node} will be returned whose content is an array,
     * since the size is known the array can be constructed in advance and
     * output elements can be placed into the array concurrently by leaf
     * tasks at the correct offsets.  If the exact size is not known, output
     * elements are collected into a conc-node whose shape mirrors that
     * of the computation. This conc-node can then be flattened in
     * parallel to produce a flat {@code Node.OfDouble} if desired.
     *
     * @param <P_IN> the type of elements from the source Spliterator
     * @param helper the pipeline helper describing the pipeline
     * @param flattenTree whether a conc node should be flattened into a node
     *                    describing an array before returning
     * @return a {@link Node.OfDouble} describing the output elements
     */
    public static <P_IN> Node.OfDouble collectDouble(PipelineHelper<Double> helper,
                                                     Spliterator<P_IN> spliterator,
                                                     boolean flattenTree) {
        long size = helper.exactOutputSizeIfKnown(spliterator);
        if (size >= 0 && spliterator.hasCharacteristics(Spliterator.SUBSIZED)) {
            if (size >= MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(BAD_SIZE);
            double[] array = new double[(int) size];
            new SizedCollectorTask.OfDouble<>(spliterator, helper, array).invoke();
            return node(array);
        }
        else {
            Node.OfDouble node = new CollectorTask.OfDouble<>(helper, spliterator).invoke();
            return flattenTree ? flattenDouble(node) : node;
        }
    }

    // Parallel flattening of nodes

    /**
     * Flatten, in parallel, a {@link Node}.  A flattened node is one that has
     * no children.  If the node is already flat, it is simply returned.
     *
     * @implSpec
     * If a new node is to be created, the generator is used to create an array
     * whose length is {@link Node#count()}.  Then the node tree is traversed
     * and leaf node elements are placed in the array concurrently by leaf tasks
     * at the correct offsets.
     *
     * @param <T> type of elements contained by the node
     * @param node the node to flatten
     * @param generator the array factory used to create array instances
     * @return a flat {@code Node}
     */
    public static <T> Node<T> flatten(Node<T> node, IntFunction<T[]> generator) {
        if (node.getChildCount() > 0) {
            long size = node.count();
            if (size >= MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(BAD_SIZE);
            T[] array = generator.apply((int) size);
            new ToArrayTask.OfRef<>(node, array, 0).invoke();
            return node(array);
        } else {
            return node;
        }
    }

    /**
     * Flatten, in parallel, a {@link Node.OfInt}.  A flattened node is one that
     * has no children.  If the node is already flat, it is simply returned.
     *
     * @implSpec
     * If a new node is to be created, a new int[] array is created whose length
     * is {@link Node#count()}.  Then the node tree is traversed and leaf node
     * elements are placed in the array concurrently by leaf tasks at the
     * correct offsets.
     *
     * @param node the node to flatten
     * @return a flat {@code Node.OfInt}
     */
    public static Node.OfInt flattenInt(Node.OfInt node) {
        if (node.getChildCount() > 0) {
            long size = node.count();
            if (size >= MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(BAD_SIZE);
            int[] array = new int[(int) size];
            new ToArrayTask.OfInt(node, array, 0).invoke();
            return node(array);
        } else {
            return node;
        }
    }

    /**
     * Flatten, in parallel, a {@link Node.OfLong}.  A flattened node is one that
     * has no children.  If the node is already flat, it is simply returned.
     *
     * @implSpec
     * If a new node is to be created, a new long[] array is created whose length
     * is {@link Node#count()}.  Then the node tree is traversed and leaf node
     * elements are placed in the array concurrently by leaf tasks at the
     * correct offsets.
     *
     * @param node the node to flatten
     * @return a flat {@code Node.OfLong}
     */
    public static Node.OfLong flattenLong(Node.OfLong node) {
        if (node.getChildCount() > 0) {
            long size = node.count();
            if (size >= MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(BAD_SIZE);
            long[] array = new long[(int) size];
            new ToArrayTask.OfLong(node, array, 0).invoke();
            return node(array);
        } else {
            return node;
        }
    }

    /**
     * Flatten, in parallel, a {@link Node.OfDouble}.  A flattened node is one that
     * has no children.  If the node is already flat, it is simply returned.
     *
     * @implSpec
     * If a new node is to be created, a new double[] array is created whose length
     * is {@link Node#count()}.  Then the node tree is traversed and leaf node
     * elements are placed in the array concurrently by leaf tasks at the
     * correct offsets.
     *
     * @param node the node to flatten
     * @return a flat {@code Node.OfDouble}
     */
    public static Node.OfDouble flattenDouble(Node.OfDouble node) {
        if (node.getChildCount() > 0) {
            long size = node.count();
            if (size >= MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(BAD_SIZE);
            double[] array = new double[(int) size];
            new ToArrayTask.OfDouble(node, array, 0).invoke();
            return node(array);
        } else {
            return node;
        }
    }

    // Implementations

    private static abstract class EmptyNode<T, T_ARR, T_CONS> implements Node<T> {
        EmptyNode() { }

        @Override
        public T[] asArray(IntFunction<T[]> generator) {
            return generator.apply(0);
        }

        public void copyInto(T_ARR array, int offset) { }

        @Override
        public long count() {
            return 0;
        }

        public void forEach(T_CONS consumer) { }

        private static class OfRef<T> extends EmptyNode<T, T[], Consumer<? super T>> {
            private OfRef() {
                super();
            }

            @Override
            public Spliterator<T> spliterator() {
                return Spliterators.emptySpliterator();
            }
        }

        private static final class OfInt
                extends EmptyNode<Integer, int[], IntConsumer>
                implements Node.OfInt {

            OfInt() { } // Avoid creation of special accessor

            @Override
            public Spliterator.OfInt spliterator() {
                return Spliterators.emptyIntSpliterator();
            }

            @Override
            public int[] asPrimitiveArray() {
                return EMPTY_INT_ARRAY;
            }
        }

        private static final class OfLong
                extends EmptyNode<Long, long[], LongConsumer>
                implements Node.OfLong {

            OfLong() { } // Avoid creation of special accessor

            @Override
            public Spliterator.OfLong spliterator() {
                return Spliterators.emptyLongSpliterator();
            }

            @Override
            public long[] asPrimitiveArray() {
                return EMPTY_LONG_ARRAY;
            }
        }

        private static final class OfDouble
                extends EmptyNode<Double, double[], DoubleConsumer>
                implements Node.OfDouble {

            OfDouble() { } // Avoid creation of special accessor

            @Override
            public Spliterator.OfDouble spliterator() {
                return Spliterators.emptyDoubleSpliterator();
            }

            @Override
            public double[] asPrimitiveArray() {
                return EMPTY_DOUBLE_ARRAY;
            }
        }
    }

    /** Node class for a reference array */
    private static class ArrayNode<T> implements Node<T> {
        final T[] array;
        int curSize;

        @SuppressWarnings("unchecked")
        ArrayNode(long size, IntFunction<T[]> generator) {
            if (size >= MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(BAD_SIZE);
            this.array = generator.apply((int) size);
            this.curSize = 0;
        }

        ArrayNode(T[] array) {
            this.array = array;
            this.curSize = array.length;
        }

        // Node

        @Override
        public Spliterator<T> spliterator() {
            return Arrays.spliterator(array, 0, curSize);
        }

        @Override
        public void copyInto(T[] dest, int destOffset) {
            System.arraycopy(array, 0, dest, destOffset, curSize);
        }

        @Override
        public T[] asArray(IntFunction<T[]> generator) {
            if (array.length == curSize) {
                return array;
            } else {
                throw new IllegalStateException();
            }
        }

        @Override
        public long count() {
            return curSize;
        }

        @Override
        public void forEach(Consumer<? super T> consumer) {
            for (int i = 0; i < curSize; i++) {
                consumer.accept(array[i]);
            }
        }

        //

        @Override
        public String toString() {
            return String.format("ArrayNode[%d][%s]",
                                 array.length - curSize, Arrays.toString(array));
        }
    }

    /** Node class for a Collection */
    private static final class CollectionNode<T> implements Node<T> {
        private final Collection<T> c;

        CollectionNode(Collection<T> c) {
            this.c = c;
        }

        // Node

        @Override
        public Spliterator<T> spliterator() {
            return c.stream().spliterator();
        }

        @Override
        public void copyInto(T[] array, int offset) {
            for (T t : c)
                array[offset++] = t;
        }

        @Override
        @SuppressWarnings("unchecked")
        public T[] asArray(IntFunction<T[]> generator) {
            return c.toArray(generator.apply(c.size()));
        }

        @Override
        public long count() {
            return c.size();
        }

        @Override
        public void forEach(Consumer<? super T> consumer) {
            c.forEach(consumer);
        }

        //

        @Override
        public String toString() {
            return String.format("CollectionNode[%d][%s]", c.size(), c);
        }
    }

    /**
     * Node class for an internal node with two or more children
     */
    private static abstract class AbstractConcNode<T, T_NODE extends Node<T>> implements Node<T> {
        protected final T_NODE left;
        protected final T_NODE right;
        private final long size;

        AbstractConcNode(T_NODE left, T_NODE right) {
            this.left = left;
            this.right = right;
            // The Node count will be required when the Node spliterator is
            // obtained and it is cheaper to aggressively calculate bottom up
            // as the tree is built rather than later on from the top down
            // traversing the tree
            this.size = left.count() + right.count();
        }

        @Override
        public int getChildCount() {
            return 2;
        }

        @Override
        public T_NODE getChild(int i) {
            if (i == 0) return left;
            if (i == 1) return right;
            throw new IndexOutOfBoundsException();
        }

        @Override
        public long count() {
            return size;
        }
    }

    static final class ConcNode<T>
            extends AbstractConcNode<T, Node<T>>
            implements Node<T> {

        ConcNode(Node<T> left, Node<T> right) {
            super(left, right);
        }

        @Override
        public Spliterator<T> spliterator() {
            return new Nodes.InternalNodeSpliterator.OfRef<>(this);
        }

        @Override
        public void copyInto(T[] array, int offset) {
            Objects.requireNonNull(array);
            left.copyInto(array, offset);
            // Cast to int is safe since it is the callers responsibility to
            // ensure that there is sufficient room in the array
            right.copyInto(array, offset + (int) left.count());
        }

        @Override
        public T[] asArray(IntFunction<T[]> generator) {
            long size = count();
            if (size >= MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(BAD_SIZE);
            T[] array = generator.apply((int) size);
            copyInto(array, 0);
            return array;
        }

        @Override
        public void forEach(Consumer<? super T> consumer) {
            left.forEach(consumer);
            right.forEach(consumer);
        }

        @Override
        public Node<T> truncate(long from, long to, IntFunction<T[]> generator) {
            if (from == 0 && to == count())
                return this;
            long leftCount = left.count();
            if (from >= leftCount)
                return right.truncate(from - leftCount, to - leftCount, generator);
            else if (to <= leftCount)
                return left.truncate(from, to, generator);
            else {
                return Nodes.conc(getShape(), left.truncate(from, leftCount, generator),
                                  right.truncate(0, to - leftCount, generator));
            }
        }

        @Override
        public String toString() {
            if (count() < 32) {
                return String.format("ConcNode[%s.%s]", left, right);
            } else {
                return String.format("ConcNode[size=%d]", count());
            }
        }

        private abstract static class OfPrimitive<E, T_CONS, T_ARR,
                                                  T_SPLITR extends Spliterator.OfPrimitive<E, T_CONS, T_SPLITR>,
                                                  T_NODE extends Node.OfPrimitive<E, T_CONS, T_ARR, T_SPLITR, T_NODE>>
                extends AbstractConcNode<E, T_NODE>
                implements Node.OfPrimitive<E, T_CONS, T_ARR, T_SPLITR, T_NODE> {

            OfPrimitive(T_NODE left, T_NODE right) {
                super(left, right);
            }

            @Override
            public void forEach(T_CONS consumer) {
                left.forEach(consumer);
                right.forEach(consumer);
            }

            @Override
            public void copyInto(T_ARR array, int offset) {
                left.copyInto(array, offset);
                // Cast to int is safe since it is the callers responsibility to
                // ensure that there is sufficient room in the array
                right.copyInto(array, offset + (int) left.count());
            }

            @Override
            public T_ARR asPrimitiveArray() {
                long size = count();
                if (size >= MAX_ARRAY_SIZE)
                    throw new IllegalArgumentException(BAD_SIZE);
                T_ARR array = newArray((int) size);
                copyInto(array, 0);
                return array;
            }

            @Override
            public String toString() {
                if (count() < 32)
                    return String.format("%s[%s.%s]", this.getClass().getName(), left, right);
                else
                    return String.format("%s[size=%d]", this.getClass().getName(), count());
            }
        }

        static final class OfInt
                extends ConcNode.OfPrimitive<Integer, IntConsumer, int[], Spliterator.OfInt, Node.OfInt>
                implements Node.OfInt {

            OfInt(Node.OfInt left, Node.OfInt right) {
                super(left, right);
            }

            @Override
            public Spliterator.OfInt spliterator() {
                return new InternalNodeSpliterator.OfInt(this);
            }
        }

        static final class OfLong
                extends ConcNode.OfPrimitive<Long, LongConsumer, long[], Spliterator.OfLong, Node.OfLong>
                implements Node.OfLong {

            OfLong(Node.OfLong left, Node.OfLong right) {
                super(left, right);
            }

            @Override
            public Spliterator.OfLong spliterator() {
                return new InternalNodeSpliterator.OfLong(this);
            }
        }

        static final class OfDouble
                extends ConcNode.OfPrimitive<Double, DoubleConsumer, double[], Spliterator.OfDouble, Node.OfDouble>
                implements Node.OfDouble {

            OfDouble(Node.OfDouble left, Node.OfDouble right) {
                super(left, right);
            }

            @Override
            public Spliterator.OfDouble spliterator() {
                return new InternalNodeSpliterator.OfDouble(this);
            }
        }
    }

    /** Abstract class for spliterator for all internal node classes */
    private static abstract class InternalNodeSpliterator<T,
                                                          S extends Spliterator<T>,
                                                          N extends Node<T>>
            implements Spliterator<T> {
        // Node we are pointing to
        // null if full traversal has occurred
        N curNode;

        // next child of curNode to consume
        int curChildIndex;

        // The spliterator of the curNode if that node is last and has no children.
        // This spliterator will be delegated to for splitting and traversing.
        // null if curNode has children
        S lastNodeSpliterator;

        // spliterator used while traversing with tryAdvance
        // null if no partial traversal has occurred
        S tryAdvanceSpliterator;

        // node stack used when traversing to search and find leaf nodes
        // null if no partial traversal has occurred
        Deque<N> tryAdvanceStack;

        InternalNodeSpliterator(N curNode) {
            this.curNode = curNode;
        }

        /**
         * Initiate a stack containing, in left-to-right order, the child nodes
         * covered by this spliterator
         */
        @SuppressWarnings("unchecked")
        protected final Deque<N> initStack() {
            // Bias size to the case where leaf nodes are close to this node
            // 8 is the minimum initial capacity for the ArrayDeque implementation
            Deque<N> stack = new ArrayDeque<>(8);
            for (int i = curNode.getChildCount() - 1; i >= curChildIndex; i--)
                stack.addFirst((N) curNode.getChild(i));
            return stack;
        }

        /**
         * Depth first search, in left-to-right order, of the node tree, using
         * an explicit stack, to find the next non-empty leaf node.
         */
        @SuppressWarnings("unchecked")
        protected final N findNextLeafNode(Deque<N> stack) {
            N n = null;
            while ((n = stack.pollFirst()) != null) {
                if (n.getChildCount() == 0) {
                    if (n.count() > 0)
                        return n;
                } else {
                    for (int i = n.getChildCount() - 1; i >= 0; i--)
                        stack.addFirst((N) n.getChild(i));
                }
            }

            return null;
        }

        @SuppressWarnings("unchecked")
        protected final boolean initTryAdvance() {
            if (curNode == null)
                return false;

            if (tryAdvanceSpliterator == null) {
                if (lastNodeSpliterator == null) {
                    // Initiate the node stack
                    tryAdvanceStack = initStack();
                    N leaf = findNextLeafNode(tryAdvanceStack);
                    if (leaf != null)
                        tryAdvanceSpliterator = (S) leaf.spliterator();
                    else {
                        // A non-empty leaf node was not found
                        // No elements to traverse
                        curNode = null;
                        return false;
                    }
                }
                else
                    tryAdvanceSpliterator = lastNodeSpliterator;
            }
            return true;
        }

        @Override
        @SuppressWarnings("unchecked")
        public final S trySplit() {
            if (curNode == null || tryAdvanceSpliterator != null)
                return null; // Cannot split if fully or partially traversed
            else if (lastNodeSpliterator != null)
                return (S) lastNodeSpliterator.trySplit();
            else if (curChildIndex < curNode.getChildCount() - 1)
                return (S) curNode.getChild(curChildIndex++).spliterator();
            else {
                curNode = (N) curNode.getChild(curChildIndex);
                if (curNode.getChildCount() == 0) {
                    lastNodeSpliterator = (S) curNode.spliterator();
                    return (S) lastNodeSpliterator.trySplit();
                }
                else {
                    curChildIndex = 0;
                    return (S) curNode.getChild(curChildIndex++).spliterator();
                }
            }
        }

        @Override
        public final long estimateSize() {
            if (curNode == null)
                return 0;

            // Will not reflect the effects of partial traversal.
            // This is compliant with the specification
            if (lastNodeSpliterator != null)
                return lastNodeSpliterator.estimateSize();
            else {
                long size = 0;
                for (int i = curChildIndex; i < curNode.getChildCount(); i++)
                    size += curNode.getChild(i).count();
                return size;
            }
        }

        @Override
        public final int characteristics() {
            return Spliterator.SIZED;
        }

        private static final class OfRef<T>
                extends InternalNodeSpliterator<T, Spliterator<T>, Node<T>> {

            OfRef(Node<T> curNode) {
                super(curNode);
            }

            @Override
            public boolean tryAdvance(Consumer<? super T> consumer) {
                if (!initTryAdvance())
                    return false;

                boolean hasNext = tryAdvanceSpliterator.tryAdvance(consumer);
                if (!hasNext) {
                    if (lastNodeSpliterator == null) {
                        // Advance to the spliterator of the next non-empty leaf node
                        Node<T> leaf = findNextLeafNode(tryAdvanceStack);
                        if (leaf != null) {
                            tryAdvanceSpliterator = leaf.spliterator();
                            // Since the node is not-empty the spliterator can be advanced
                            return tryAdvanceSpliterator.tryAdvance(consumer);
                        }
                    }
                    // No more elements to traverse
                    curNode = null;
                }
                return hasNext;
            }

            @Override
            public void forEachRemaining(Consumer<? super T> consumer) {
                if (curNode == null)
                    return;

                if (tryAdvanceSpliterator == null) {
                    if (lastNodeSpliterator == null) {
                        Deque<Node<T>> stack = initStack();
                        Node<T> leaf;
                        while ((leaf = findNextLeafNode(stack)) != null) {
                            leaf.forEach(consumer);
                        }
                        curNode = null;
                    }
                    else
                        lastNodeSpliterator.forEachRemaining(consumer);
                }
                else
                    while(tryAdvance(consumer)) { }
            }
        }

        private static abstract class OfPrimitive<T, T_CONS, T_ARR,
                                                  T_SPLITR extends Spliterator.OfPrimitive<T, T_CONS, T_SPLITR>,
                                                  N extends Node.OfPrimitive<T, T_CONS, T_ARR, T_SPLITR, N>>
                extends InternalNodeSpliterator<T, T_SPLITR, N>
                implements Spliterator.OfPrimitive<T, T_CONS, T_SPLITR> {

            OfPrimitive(N cur) {
                super(cur);
            }

            @Override
            public boolean tryAdvance(T_CONS consumer) {
                if (!initTryAdvance())
                    return false;

                boolean hasNext = tryAdvanceSpliterator.tryAdvance(consumer);
                if (!hasNext) {
                    if (lastNodeSpliterator == null) {
                        // Advance to the spliterator of the next non-empty leaf node
                        N leaf = findNextLeafNode(tryAdvanceStack);
                        if (leaf != null) {
                            tryAdvanceSpliterator = leaf.spliterator();
                            // Since the node is not-empty the spliterator can be advanced
                            return tryAdvanceSpliterator.tryAdvance(consumer);
                        }
                    }
                    // No more elements to traverse
                    curNode = null;
                }
                return hasNext;
            }

            @Override
            public void forEachRemaining(T_CONS consumer) {
                if (curNode == null)
                    return;

                if (tryAdvanceSpliterator == null) {
                    if (lastNodeSpliterator == null) {
                        Deque<N> stack = initStack();
                        N leaf;
                        while ((leaf = findNextLeafNode(stack)) != null) {
                            leaf.forEach(consumer);
                        }
                        curNode = null;
                    }
                    else
                        lastNodeSpliterator.forEachRemaining(consumer);
                }
                else
                    while(tryAdvance(consumer)) { }
            }
        }

        private static final class OfInt
                extends OfPrimitive<Integer, IntConsumer, int[], Spliterator.OfInt, Node.OfInt>
                implements Spliterator.OfInt {

            OfInt(Node.OfInt cur) {
                super(cur);
            }
        }

        private static final class OfLong
                extends OfPrimitive<Long, LongConsumer, long[], Spliterator.OfLong, Node.OfLong>
                implements Spliterator.OfLong {

            OfLong(Node.OfLong cur) {
                super(cur);
            }
        }

        private static final class OfDouble
                extends OfPrimitive<Double, DoubleConsumer, double[], Spliterator.OfDouble, Node.OfDouble>
                implements Spliterator.OfDouble {

            OfDouble(Node.OfDouble cur) {
                super(cur);
            }
        }
    }

    /**
     * Fixed-sized builder class for reference nodes
     */
    private static final class FixedNodeBuilder<T>
            extends ArrayNode<T>
            implements Node.Builder<T> {

        FixedNodeBuilder(long size, IntFunction<T[]> generator) {
            super(size, generator);
            assert size < MAX_ARRAY_SIZE;
        }

        @Override
        public Node<T> build() {
            if (curSize < array.length)
                throw new IllegalStateException(String.format("Current size %d is less than fixed size %d",
                                                              curSize, array.length));
            return this;
        }

        @Override
        public void begin(long size) {
            if (size != array.length)
                throw new IllegalStateException(String.format("Begin size %d is not equal to fixed size %d",
                                                              size, array.length));
            curSize = 0;
        }

        @Override
        public void accept(T t) {
            if (curSize < array.length) {
                array[curSize++] = t;
            } else {
                throw new IllegalStateException(String.format("Accept exceeded fixed size of %d",
                                                              array.length));
            }
        }

        @Override
        public void end() {
            if (curSize < array.length)
                throw new IllegalStateException(String.format("End size %d is less than fixed size %d",
                                                              curSize, array.length));
        }

        @Override
        public String toString() {
            return String.format("FixedNodeBuilder[%d][%s]",
                                 array.length - curSize, Arrays.toString(array));
        }
    }

    /**
     * Variable-sized builder class for reference nodes
     */
    private static final class SpinedNodeBuilder<T>
            extends SpinedBuffer<T>
            implements Node<T>, Node.Builder<T> {
        private boolean building = false;

        SpinedNodeBuilder() {} // Avoid creation of special accessor

        @Override
        public Spliterator<T> spliterator() {
            assert !building : "during building";
            return super.spliterator();
        }

        @Override
        public void forEach(Consumer<? super T> consumer) {
            assert !building : "during building";
            super.forEach(consumer);
        }

        //
        @Override
        public void begin(long size) {
            assert !building : "was already building";
            building = true;
            clear();
            ensureCapacity(size);
        }

        @Override
        public void accept(T t) {
            assert building : "not building";
            super.accept(t);
        }

        @Override
        public void end() {
            assert building : "was not building";
            building = false;
            // @@@ check begin(size) and size
        }

        @Override
        public void copyInto(T[] array, int offset) {
            assert !building : "during building";
            super.copyInto(array, offset);
        }

        @Override
        public T[] asArray(IntFunction<T[]> arrayFactory) {
            assert !building : "during building";
            return super.asArray(arrayFactory);
        }

        @Override
        public Node<T> build() {
            assert !building : "during building";
            return this;
        }
    }

    //

    private static final int[] EMPTY_INT_ARRAY = new int[0];
    private static final long[] EMPTY_LONG_ARRAY = new long[0];
    private static final double[] EMPTY_DOUBLE_ARRAY = new double[0];

    private static class IntArrayNode implements Node.OfInt {
        final int[] array;
        int curSize;

        IntArrayNode(long size) {
            if (size >= MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(BAD_SIZE);
            this.array = new int[(int) size];
            this.curSize = 0;
        }

        IntArrayNode(int[] array) {
            this.array = array;
            this.curSize = array.length;
        }

        // Node

        @Override
        public Spliterator.OfInt spliterator() {
            return Arrays.spliterator(array, 0, curSize);
        }

        @Override
        public int[] asPrimitiveArray() {
            if (array.length == curSize) {
                return array;
            } else {
                return Arrays.copyOf(array, curSize);
            }
        }

        @Override
        public void copyInto(int[] dest, int destOffset) {
            System.arraycopy(array, 0, dest, destOffset, curSize);
        }

        @Override
        public long count() {
            return curSize;
        }

        @Override
        public void forEach(IntConsumer consumer) {
            for (int i = 0; i < curSize; i++) {
                consumer.accept(array[i]);
            }
        }

        @Override
        public String toString() {
            return String.format("IntArrayNode[%d][%s]",
                                 array.length - curSize, Arrays.toString(array));
        }
    }

    private static class LongArrayNode implements Node.OfLong {
        final long[] array;
        int curSize;

        LongArrayNode(long size) {
            if (size >= MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(BAD_SIZE);
            this.array = new long[(int) size];
            this.curSize = 0;
        }

        LongArrayNode(long[] array) {
            this.array = array;
            this.curSize = array.length;
        }

        @Override
        public Spliterator.OfLong spliterator() {
            return Arrays.spliterator(array, 0, curSize);
        }

        @Override
        public long[] asPrimitiveArray() {
            if (array.length == curSize) {
                return array;
            } else {
                return Arrays.copyOf(array, curSize);
            }
        }

        @Override
        public void copyInto(long[] dest, int destOffset) {
            System.arraycopy(array, 0, dest, destOffset, curSize);
        }

        @Override
        public long count() {
            return curSize;
        }

        @Override
        public void forEach(LongConsumer consumer) {
            for (int i = 0; i < curSize; i++) {
                consumer.accept(array[i]);
            }
        }

        @Override
        public String toString() {
            return String.format("LongArrayNode[%d][%s]",
                                 array.length - curSize, Arrays.toString(array));
        }
    }

    private static class DoubleArrayNode implements Node.OfDouble {
        final double[] array;
        int curSize;

        DoubleArrayNode(long size) {
            if (size >= MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(BAD_SIZE);
            this.array = new double[(int) size];
            this.curSize = 0;
        }

        DoubleArrayNode(double[] array) {
            this.array = array;
            this.curSize = array.length;
        }

        @Override
        public Spliterator.OfDouble spliterator() {
            return Arrays.spliterator(array, 0, curSize);
        }

        @Override
        public double[] asPrimitiveArray() {
            if (array.length == curSize) {
                return array;
            } else {
                return Arrays.copyOf(array, curSize);
            }
        }

        @Override
        public void copyInto(double[] dest, int destOffset) {
            System.arraycopy(array, 0, dest, destOffset, curSize);
        }

        @Override
        public long count() {
            return curSize;
        }

        @Override
        public void forEach(DoubleConsumer consumer) {
            for (int i = 0; i < curSize; i++) {
                consumer.accept(array[i]);
            }
        }

        @Override
        public String toString() {
            return String.format("DoubleArrayNode[%d][%s]",
                                 array.length - curSize, Arrays.toString(array));
        }
    }

    private static final class IntFixedNodeBuilder
            extends IntArrayNode
            implements Node.Builder.OfInt {

        IntFixedNodeBuilder(long size) {
            super(size);
            assert size < MAX_ARRAY_SIZE;
        }

        @Override
        public Node.OfInt build() {
            if (curSize < array.length) {
                throw new IllegalStateException(String.format("Current size %d is less than fixed size %d",
                                                              curSize, array.length));
            }

            return this;
        }

        @Override
        public void begin(long size) {
            if (size != array.length) {
                throw new IllegalStateException(String.format("Begin size %d is not equal to fixed size %d",
                                                              size, array.length));
            }

            curSize = 0;
        }

        @Override
        public void accept(int i) {
            if (curSize < array.length) {
                array[curSize++] = i;
            } else {
                throw new IllegalStateException(String.format("Accept exceeded fixed size of %d",
                                                              array.length));
            }
        }

        @Override
        public void end() {
            if (curSize < array.length) {
                throw new IllegalStateException(String.format("End size %d is less than fixed size %d",
                                                              curSize, array.length));
            }
        }

        @Override
        public String toString() {
            return String.format("IntFixedNodeBuilder[%d][%s]",
                                 array.length - curSize, Arrays.toString(array));
        }
    }

    private static final class LongFixedNodeBuilder
            extends LongArrayNode
            implements Node.Builder.OfLong {

        LongFixedNodeBuilder(long size) {
            super(size);
            assert size < MAX_ARRAY_SIZE;
        }

        @Override
        public Node.OfLong build() {
            if (curSize < array.length) {
                throw new IllegalStateException(String.format("Current size %d is less than fixed size %d",
                                                              curSize, array.length));
            }

            return this;
        }

        @Override
        public void begin(long size) {
            if (size != array.length) {
                throw new IllegalStateException(String.format("Begin size %d is not equal to fixed size %d",
                                                              size, array.length));
            }

            curSize = 0;
        }

        @Override
        public void accept(long i) {
            if (curSize < array.length) {
                array[curSize++] = i;
            } else {
                throw new IllegalStateException(String.format("Accept exceeded fixed size of %d",
                                                              array.length));
            }
        }

        @Override
        public void end() {
            if (curSize < array.length) {
                throw new IllegalStateException(String.format("End size %d is less than fixed size %d",
                                                              curSize, array.length));
            }
        }

        @Override
        public String toString() {
            return String.format("LongFixedNodeBuilder[%d][%s]",
                                 array.length - curSize, Arrays.toString(array));
        }
    }

    private static final class DoubleFixedNodeBuilder
            extends DoubleArrayNode
            implements Node.Builder.OfDouble {

        DoubleFixedNodeBuilder(long size) {
            super(size);
            assert size < MAX_ARRAY_SIZE;
        }

        @Override
        public Node.OfDouble build() {
            if (curSize < array.length) {
                throw new IllegalStateException(String.format("Current size %d is less than fixed size %d",
                                                              curSize, array.length));
            }

            return this;
        }

        @Override
        public void begin(long size) {
            if (size != array.length) {
                throw new IllegalStateException(String.format("Begin size %d is not equal to fixed size %d",
                                                              size, array.length));
            }

            curSize = 0;
        }

        @Override
        public void accept(double i) {
            if (curSize < array.length) {
                array[curSize++] = i;
            } else {
                throw new IllegalStateException(String.format("Accept exceeded fixed size of %d",
                                                              array.length));
            }
        }

        @Override
        public void end() {
            if (curSize < array.length) {
                throw new IllegalStateException(String.format("End size %d is less than fixed size %d",
                                                              curSize, array.length));
            }
        }

        @Override
        public String toString() {
            return String.format("DoubleFixedNodeBuilder[%d][%s]",
                                 array.length - curSize, Arrays.toString(array));
        }
    }

    private static final class IntSpinedNodeBuilder
            extends SpinedBuffer.OfInt
            implements Node.OfInt, Node.Builder.OfInt {
        private boolean building = false;

        IntSpinedNodeBuilder() {} // Avoid creation of special accessor

        @Override
        public Spliterator.OfInt spliterator() {
            assert !building : "during building";
            return super.spliterator();
        }

        @Override
        public void forEach(IntConsumer consumer) {
            assert !building : "during building";
            super.forEach(consumer);
        }

        //
        @Override
        public void begin(long size) {
            assert !building : "was already building";
            building = true;
            clear();
            ensureCapacity(size);
        }

        @Override
        public void accept(int i) {
            assert building : "not building";
            super.accept(i);
        }

        @Override
        public void end() {
            assert building : "was not building";
            building = false;
            // @@@ check begin(size) and size
        }

        @Override
        public void copyInto(int[] array, int offset) throws IndexOutOfBoundsException {
            assert !building : "during building";
            super.copyInto(array, offset);
        }

        @Override
        public int[] asPrimitiveArray() {
            assert !building : "during building";
            return super.asPrimitiveArray();
        }

        @Override
        public Node.OfInt build() {
            assert !building : "during building";
            return this;
        }
    }

    private static final class LongSpinedNodeBuilder
            extends SpinedBuffer.OfLong
            implements Node.OfLong, Node.Builder.OfLong {
        private boolean building = false;

        LongSpinedNodeBuilder() {} // Avoid creation of special accessor

        @Override
        public Spliterator.OfLong spliterator() {
            assert !building : "during building";
            return super.spliterator();
        }

        @Override
        public void forEach(LongConsumer consumer) {
            assert !building : "during building";
            super.forEach(consumer);
        }

        //
        @Override
        public void begin(long size) {
            assert !building : "was already building";
            building = true;
            clear();
            ensureCapacity(size);
        }

        @Override
        public void accept(long i) {
            assert building : "not building";
            super.accept(i);
        }

        @Override
        public void end() {
            assert building : "was not building";
            building = false;
            // @@@ check begin(size) and size
        }

        @Override
        public void copyInto(long[] array, int offset) {
            assert !building : "during building";
            super.copyInto(array, offset);
        }

        @Override
        public long[] asPrimitiveArray() {
            assert !building : "during building";
            return super.asPrimitiveArray();
        }

        @Override
        public Node.OfLong build() {
            assert !building : "during building";
            return this;
        }
    }

    private static final class DoubleSpinedNodeBuilder
            extends SpinedBuffer.OfDouble
            implements Node.OfDouble, Node.Builder.OfDouble {
        private boolean building = false;

        DoubleSpinedNodeBuilder() {} // Avoid creation of special accessor

        @Override
        public Spliterator.OfDouble spliterator() {
            assert !building : "during building";
            return super.spliterator();
        }

        @Override
        public void forEach(DoubleConsumer consumer) {
            assert !building : "during building";
            super.forEach(consumer);
        }

        //
        @Override
        public void begin(long size) {
            assert !building : "was already building";
            building = true;
            clear();
            ensureCapacity(size);
        }

        @Override
        public void accept(double i) {
            assert building : "not building";
            super.accept(i);
        }

        @Override
        public void end() {
            assert building : "was not building";
            building = false;
            // @@@ check begin(size) and size
        }

        @Override
        public void copyInto(double[] array, int offset) {
            assert !building : "during building";
            super.copyInto(array, offset);
        }

        @Override
        public double[] asPrimitiveArray() {
            assert !building : "during building";
            return super.asPrimitiveArray();
        }

        @Override
        public Node.OfDouble build() {
            assert !building : "during building";
            return this;
        }
    }

    /*
     * This and subclasses are not intended to be serializable
     */
    @SuppressWarnings("serial")
    private static abstract class SizedCollectorTask<P_IN, P_OUT, T_SINK extends Sink<P_OUT>,
                                                     K extends SizedCollectorTask<P_IN, P_OUT, T_SINK, K>>
            extends CountedCompleter<Void>
            implements Sink<P_OUT> {
        protected final Spliterator<P_IN> spliterator;
        protected final PipelineHelper<P_OUT> helper;
        protected final long targetSize;
        protected long offset;
        protected long length;
        // For Sink implementation
        protected int index, fence;

        SizedCollectorTask(Spliterator<P_IN> spliterator,
                           PipelineHelper<P_OUT> helper,
                           int arrayLength) {
            assert spliterator.hasCharacteristics(Spliterator.SUBSIZED);
            this.spliterator = spliterator;
            this.helper = helper;
            this.targetSize = AbstractTask.suggestTargetSize(spliterator.estimateSize());
            this.offset = 0;
            this.length = arrayLength;
        }

        SizedCollectorTask(K parent, Spliterator<P_IN> spliterator,
                           long offset, long length, int arrayLength) {
            super(parent);
            assert spliterator.hasCharacteristics(Spliterator.SUBSIZED);
            this.spliterator = spliterator;
            this.helper = parent.helper;
            this.targetSize = parent.targetSize;
            this.offset = offset;
            this.length = length;

            if (offset < 0 || length < 0 || (offset + length - 1 >= arrayLength)) {
                throw new IllegalArgumentException(
                        String.format("offset and length interval [%d, %d + %d) is not within array size interval [0, %d)",
                                      offset, offset, length, arrayLength));
            }
        }

        @Override
        public void compute() {
            SizedCollectorTask<P_IN, P_OUT, T_SINK, K> task = this;
            Spliterator<P_IN> rightSplit = spliterator, leftSplit;
            while (rightSplit.estimateSize() > task.targetSize &&
                   (leftSplit = rightSplit.trySplit()) != null) {
                task.setPendingCount(1);
                long leftSplitSize = leftSplit.estimateSize();
                task.makeChild(leftSplit, task.offset, leftSplitSize).fork();
                task = task.makeChild(rightSplit, task.offset + leftSplitSize,
                                      task.length - leftSplitSize);
            }

            assert task.offset + task.length < MAX_ARRAY_SIZE;
            @SuppressWarnings("unchecked")
            T_SINK sink = (T_SINK) task;
            task.helper.wrapAndCopyInto(sink, rightSplit);
            task.propagateCompletion();
        }

        abstract K makeChild(Spliterator<P_IN> spliterator, long offset, long size);

        @Override
        public void begin(long size) {
            if (size > length)
                throw new IllegalStateException("size passed to Sink.begin exceeds array length");
            // Casts to int are safe since absolute size is verified to be within
            // bounds when the root concrete SizedCollectorTask is constructed
            // with the shared array
            index = (int) offset;
            fence = index + (int) length;
        }

        @SuppressWarnings("serial")
        static final class OfRef<P_IN, P_OUT>
                extends SizedCollectorTask<P_IN, P_OUT, Sink<P_OUT>, OfRef<P_IN, P_OUT>>
                implements Sink<P_OUT> {
            private final P_OUT[] array;

            OfRef(Spliterator<P_IN> spliterator, PipelineHelper<P_OUT> helper, P_OUT[] array) {
                super(spliterator, helper, array.length);
                this.array = array;
            }

            OfRef(OfRef<P_IN, P_OUT> parent, Spliterator<P_IN> spliterator,
                  long offset, long length) {
                super(parent, spliterator, offset, length, parent.array.length);
                this.array = parent.array;
            }

            @Override
            OfRef<P_IN, P_OUT> makeChild(Spliterator<P_IN> spliterator,
                                         long offset, long size) {
                return new OfRef<>(this, spliterator, offset, size);
            }

            @Override
            public void accept(P_OUT value) {
                if (index >= fence) {
                    throw new IndexOutOfBoundsException(Integer.toString(index));
                }
                array[index++] = value;
            }
        }

        @SuppressWarnings("serial")
        static final class OfInt<P_IN>
                extends SizedCollectorTask<P_IN, Integer, Sink.OfInt, OfInt<P_IN>>
                implements Sink.OfInt {
            private final int[] array;

            OfInt(Spliterator<P_IN> spliterator, PipelineHelper<Integer> helper, int[] array) {
                super(spliterator, helper, array.length);
                this.array = array;
            }

            OfInt(SizedCollectorTask.OfInt<P_IN> parent, Spliterator<P_IN> spliterator,
                  long offset, long length) {
                super(parent, spliterator, offset, length, parent.array.length);
                this.array = parent.array;
            }

            @Override
            SizedCollectorTask.OfInt<P_IN> makeChild(Spliterator<P_IN> spliterator,
                                                     long offset, long size) {
                return new SizedCollectorTask.OfInt<>(this, spliterator, offset, size);
            }

            @Override
            public void accept(int value) {
                if (index >= fence) {
                    throw new IndexOutOfBoundsException(Integer.toString(index));
                }
                array[index++] = value;
            }
        }

        @SuppressWarnings("serial")
        static final class OfLong<P_IN>
                extends SizedCollectorTask<P_IN, Long, Sink.OfLong, OfLong<P_IN>>
                implements Sink.OfLong {
            private final long[] array;

            OfLong(Spliterator<P_IN> spliterator, PipelineHelper<Long> helper, long[] array) {
                super(spliterator, helper, array.length);
                this.array = array;
            }

            OfLong(SizedCollectorTask.OfLong<P_IN> parent, Spliterator<P_IN> spliterator,
                   long offset, long length) {
                super(parent, spliterator, offset, length, parent.array.length);
                this.array = parent.array;
            }

            @Override
            SizedCollectorTask.OfLong<P_IN> makeChild(Spliterator<P_IN> spliterator,
                                                      long offset, long size) {
                return new SizedCollectorTask.OfLong<>(this, spliterator, offset, size);
            }

            @Override
            public void accept(long value) {
                if (index >= fence) {
                    throw new IndexOutOfBoundsException(Integer.toString(index));
                }
                array[index++] = value;
            }
        }

        @SuppressWarnings("serial")
        static final class OfDouble<P_IN>
                extends SizedCollectorTask<P_IN, Double, Sink.OfDouble, OfDouble<P_IN>>
                implements Sink.OfDouble {
            private final double[] array;

            OfDouble(Spliterator<P_IN> spliterator, PipelineHelper<Double> helper, double[] array) {
                super(spliterator, helper, array.length);
                this.array = array;
            }

            OfDouble(SizedCollectorTask.OfDouble<P_IN> parent, Spliterator<P_IN> spliterator,
                     long offset, long length) {
                super(parent, spliterator, offset, length, parent.array.length);
                this.array = parent.array;
            }

            @Override
            SizedCollectorTask.OfDouble<P_IN> makeChild(Spliterator<P_IN> spliterator,
                                                        long offset, long size) {
                return new SizedCollectorTask.OfDouble<>(this, spliterator, offset, size);
            }

            @Override
            public void accept(double value) {
                if (index >= fence) {
                    throw new IndexOutOfBoundsException(Integer.toString(index));
                }
                array[index++] = value;
            }
        }
    }

    @SuppressWarnings("serial")
    private static abstract class ToArrayTask<T, T_NODE extends Node<T>,
                                              K extends ToArrayTask<T, T_NODE, K>>
            extends CountedCompleter<Void> {
        protected final T_NODE node;
        protected final int offset;

        ToArrayTask(T_NODE node, int offset) {
            this.node = node;
            this.offset = offset;
        }

        ToArrayTask(K parent, T_NODE node, int offset) {
            super(parent);
            this.node = node;
            this.offset = offset;
        }

        abstract void copyNodeToArray();

        abstract K makeChild(int childIndex, int offset);

        @Override
        public void compute() {
            ToArrayTask<T, T_NODE, K> task = this;
            while (true) {
                if (task.node.getChildCount() == 0) {
                    task.copyNodeToArray();
                    task.propagateCompletion();
                    return;
                }
                else {
                    task.setPendingCount(task.node.getChildCount() - 1);

                    int size = 0;
                    int i = 0;
                    for (;i < task.node.getChildCount() - 1; i++) {
                        K leftTask = task.makeChild(i, task.offset + size);
                        size += leftTask.node.count();
                        leftTask.fork();
                    }
                    task = task.makeChild(i, task.offset + size);
                }
            }
        }

        @SuppressWarnings("serial")
        private static final class OfRef<T>
                extends ToArrayTask<T, Node<T>, OfRef<T>> {
            private final T[] array;

            private OfRef(Node<T> node, T[] array, int offset) {
                super(node, offset);
                this.array = array;
            }

            private OfRef(OfRef<T> parent, Node<T> node, int offset) {
                super(parent, node, offset);
                this.array = parent.array;
            }

            @Override
            OfRef<T> makeChild(int childIndex, int offset) {
                return new OfRef<>(this, node.getChild(childIndex), offset);
            }

            @Override
            void copyNodeToArray() {
                node.copyInto(array, offset);
            }
        }

        @SuppressWarnings("serial")
        private static class OfPrimitive<T, T_CONS, T_ARR,
                                         T_SPLITR extends Spliterator.OfPrimitive<T, T_CONS, T_SPLITR>,
                                         T_NODE extends Node.OfPrimitive<T, T_CONS, T_ARR, T_SPLITR, T_NODE>>
                extends ToArrayTask<T, T_NODE, OfPrimitive<T, T_CONS, T_ARR, T_SPLITR, T_NODE>> {
            private final T_ARR array;

            private OfPrimitive(T_NODE node, T_ARR array, int offset) {
                super(node, offset);
                this.array = array;
            }

            private OfPrimitive(OfPrimitive<T, T_CONS, T_ARR, T_SPLITR, T_NODE> parent, T_NODE node, int offset) {
                super(parent, node, offset);
                this.array = parent.array;
            }

            @Override
            OfPrimitive<T, T_CONS, T_ARR, T_SPLITR, T_NODE> makeChild(int childIndex, int offset) {
                return new OfPrimitive<>(this, node.getChild(childIndex), offset);
            }

            @Override
            void copyNodeToArray() {
                node.copyInto(array, offset);
            }
        }

        @SuppressWarnings("serial")
        private static final class OfInt
                extends OfPrimitive<Integer, IntConsumer, int[], Spliterator.OfInt, Node.OfInt> {
            private OfInt(Node.OfInt node, int[] array, int offset) {
                super(node, array, offset);
            }
        }

        @SuppressWarnings("serial")
        private static final class OfLong
                extends OfPrimitive<Long, LongConsumer, long[], Spliterator.OfLong, Node.OfLong> {
            private OfLong(Node.OfLong node, long[] array, int offset) {
                super(node, array, offset);
            }
        }

        @SuppressWarnings("serial")
        private static final class OfDouble
                extends OfPrimitive<Double, DoubleConsumer, double[], Spliterator.OfDouble, Node.OfDouble> {
            private OfDouble(Node.OfDouble node, double[] array, int offset) {
                super(node, array, offset);
            }
        }
    }

    @SuppressWarnings("serial")
    private static class CollectorTask<P_IN, P_OUT, T_NODE extends Node<P_OUT>, T_BUILDER extends Node.Builder<P_OUT>>
            extends AbstractTask<P_IN, P_OUT, T_NODE, CollectorTask<P_IN, P_OUT, T_NODE, T_BUILDER>> {
        protected final PipelineHelper<P_OUT> helper;
        protected final LongFunction<T_BUILDER> builderFactory;
        protected final BinaryOperator<T_NODE> concFactory;

        CollectorTask(PipelineHelper<P_OUT> helper,
                      Spliterator<P_IN> spliterator,
                      LongFunction<T_BUILDER> builderFactory,
                      BinaryOperator<T_NODE> concFactory) {
            super(helper, spliterator);
            this.helper = helper;
            this.builderFactory = builderFactory;
            this.concFactory = concFactory;
        }

        CollectorTask(CollectorTask<P_IN, P_OUT, T_NODE, T_BUILDER> parent,
                      Spliterator<P_IN> spliterator) {
            super(parent, spliterator);
            helper = parent.helper;
            builderFactory = parent.builderFactory;
            concFactory = parent.concFactory;
        }

        @Override
        protected CollectorTask<P_IN, P_OUT, T_NODE, T_BUILDER> makeChild(Spliterator<P_IN> spliterator) {
            return new CollectorTask<>(this, spliterator);
        }

        @Override
        @SuppressWarnings("unchecked")
        protected T_NODE doLeaf() {
            T_BUILDER builder = builderFactory.apply(helper.exactOutputSizeIfKnown(spliterator));
            return (T_NODE) helper.wrapAndCopyInto(builder, spliterator).build();
        }

        @Override
        public void onCompletion(CountedCompleter<?> caller) {
            if (!isLeaf())
                setLocalResult(concFactory.apply(leftChild.getLocalResult(), rightChild.getLocalResult()));
            super.onCompletion(caller);
        }

        @SuppressWarnings("serial")
        private static final class OfRef<P_IN, P_OUT>
                extends CollectorTask<P_IN, P_OUT, Node<P_OUT>, Node.Builder<P_OUT>> {
            OfRef(PipelineHelper<P_OUT> helper,
                  IntFunction<P_OUT[]> generator,
                  Spliterator<P_IN> spliterator) {
                super(helper, spliterator, s -> builder(s, generator), ConcNode::new);
            }
        }

        @SuppressWarnings("serial")
        private static final class OfInt<P_IN>
                extends CollectorTask<P_IN, Integer, Node.OfInt, Node.Builder.OfInt> {
            OfInt(PipelineHelper<Integer> helper, Spliterator<P_IN> spliterator) {
                super(helper, spliterator, Nodes::intBuilder, ConcNode.OfInt::new);
            }
        }

        @SuppressWarnings("serial")
        private static final class OfLong<P_IN>
                extends CollectorTask<P_IN, Long, Node.OfLong, Node.Builder.OfLong> {
            OfLong(PipelineHelper<Long> helper, Spliterator<P_IN> spliterator) {
                super(helper, spliterator, Nodes::longBuilder, ConcNode.OfLong::new);
            }
        }

        @SuppressWarnings("serial")
        private static final class OfDouble<P_IN>
                extends CollectorTask<P_IN, Double, Node.OfDouble, Node.Builder.OfDouble> {
            OfDouble(PipelineHelper<Double> helper, Spliterator<P_IN> spliterator) {
                super(helper, spliterator, Nodes::doubleBuilder, ConcNode.OfDouble::new);
            }
        }
    }
}

//Node
interface Node<T> {

    /**
     * Returns a {@link Spliterator} describing the elements contained in this
     * {@code Node}.
     *
     * @return a {@code Spliterator} describing the elements contained in this
     *         {@code Node}
     */
    Spliterator<T> spliterator();

    /**
     * Traverses the elements of this node, and invoke the provided
     * {@code Consumer} with each element.  Elements are provided in encounter
     * order if the source for the {@code Node} has a defined encounter order.
     *
     * @param consumer a {@code Consumer} that is to be invoked with each
     *        element in this {@code Node}
     */
    void forEach(Consumer<? super T> consumer);

    /**
     * Returns the number of child nodes of this node.
     *
     * @implSpec The default implementation returns zero.
     *
     * @return the number of child nodes
     */
    default int getChildCount() {
        return 0;
    }

    /**
     * Retrieves the child {@code Node} at a given index.
     *
     * @implSpec The default implementation always throws
     * {@code IndexOutOfBoundsException}.
     *
     * @param i the index to the child node
     * @return the child node
     * @throws IndexOutOfBoundsException if the index is less than 0 or greater
     *         than or equal to the number of child nodes
     */
    default Node<T> getChild(int i) {
        throw new IndexOutOfBoundsException();
    }

    /**
     * Return a node describing a subsequence of the elements of this node,
     * starting at the given inclusive start offset and ending at the given
     * exclusive end offset.
     *
     * @param from The (inclusive) starting offset of elements to include, must
     *             be in range 0..count().
     * @param to The (exclusive) end offset of elements to include, must be
     *           in range 0..count().
     * @param generator A function to be used to create a new array, if needed,
     *                  for reference nodes.
     * @return the truncated node
     */
    default Node<T> truncate(long from, long to, IntFunction<T[]> generator) {
        if (from == 0 && to == count())
            return this;
        Spliterator<T> spliterator = spliterator();
        long size = to - from;
        Node.Builder<T> nodeBuilder = Nodes.builder(size, generator);
        nodeBuilder.begin(size);
        for (int i = 0; i < from && spliterator.tryAdvance(e -> { }); i++) { }
        for (int i = 0; (i < size) && spliterator.tryAdvance(nodeBuilder); i++) { }
        nodeBuilder.end();
        return nodeBuilder.build();
    }

    /**
     * Provides an array view of the contents of this node.
     *
     * <p>Depending on the underlying implementation, this may return a
     * reference to an internal array rather than a copy.  Since the returned
     * array may be shared, the returned array should not be modified.  The
     * {@code generator} function may be consulted to create the array if a new
     * array needs to be created.
     *
     * @param generator a factory function which takes an integer parameter and
     *        returns a new, empty array of that size and of the appropriate
     *        array type
     * @return an array containing the contents of this {@code Node}
     */
    T[] asArray(IntFunction<T[]> generator);

    /**
     * Copies the content of this {@code Node} into an array, starting at a
     * given offset into the array.  It is the caller's responsibility to ensure
     * there is sufficient room in the array, otherwise unspecified behaviour
     * will occur if the array length is less than the number of elements
     * contained in this node.
     *
     * @param array the array into which to copy the contents of this
     *       {@code Node}
     * @param offset the starting offset within the array
     * @throws IndexOutOfBoundsException if copying would cause access of data
     *         outside array bounds
     * @throws NullPointerException if {@code array} is {@code null}
     */
    void copyInto(T[] array, int offset);

    /**
     * Gets the {@code StreamShape} associated with this {@code Node}.
     *
     * @implSpec The default in {@code Node} returns
     * {@code StreamShape.REFERENCE}
     *
     * @return the stream shape associated with this node
     */
    default StreamShape getShape() {
        return StreamShape.REFERENCE;
    }

    /**
     * Returns the number of elements contained in this node.
     *
     * @return the number of elements contained in this node
     */
    long count();

    /**
     * A mutable builder for a {@code Node} that implements {@link Sink}, which
     * builds a flat node containing the elements that have been pushed to it.
     */
    interface Builder<T> extends Sink<T> {

        /**
         * Builds the node.  Should be called after all elements have been
         * pushed and signalled with an invocation of {@link Sink#end()}.
         *
         * @return the resulting {@code Node}
         */
        Node<T> build();

        /**
         * Specialized @{code Node.Builder} for int elements
         */
        interface OfInt extends Node.Builder<Integer>, Sink.OfInt {
            @Override
            Node.OfInt build();
        }

        /**
         * Specialized @{code Node.Builder} for long elements
         */
        interface OfLong extends Node.Builder<Long>, Sink.OfLong {
            @Override
            Node.OfLong build();
        }

        /**
         * Specialized @{code Node.Builder} for double elements
         */
        interface OfDouble extends Node.Builder<Double>, Sink.OfDouble {
            @Override
            Node.OfDouble build();
        }
    }

    public interface OfPrimitive<T, T_CONS, T_ARR,
                                 T_SPLITR extends Spliterator.OfPrimitive<T, T_CONS, T_SPLITR>,
                                 T_NODE extends OfPrimitive<T, T_CONS, T_ARR, T_SPLITR, T_NODE>>
            extends Node<T> {

        /**
         * {@inheritDoc}
         *
         * @return a {@link Spliterator.OfPrimitive} describing the elements of
         *         this node
         */
        @Override
        T_SPLITR spliterator();

        /**
         * Traverses the elements of this node, and invoke the provided
         * {@code action} with each element.
         *
         * @param action a consumer that is to be invoked with each
         *        element in this {@code Node.OfPrimitive}
         */
        @SuppressWarnings("overloads")
        void forEach(T_CONS action);

        @Override
        default T_NODE getChild(int i) {
            throw new IndexOutOfBoundsException();
        }

        T_NODE truncate(long from, long to, IntFunction<T[]> generator);

        /**
         * {@inheritDoc}
         *
         * @implSpec the default implementation invokes the generator to create
         * an instance of a boxed primitive array with a length of
         * {@link #count()} and then invokes {@link #copyInto(T[], int)} with
         * that array at an offset of 0.
         */
        @Override
        default T[] asArray(IntFunction<T[]> generator) {

            long size = count();
            if (size >= Nodes.MAX_ARRAY_SIZE)
                throw new IllegalArgumentException(Nodes.BAD_SIZE);
            T[] boxed = generator.apply((int) count());
            copyInto(boxed, 0);
            return boxed;
        }

        /**
         * Views this node as a primitive array.
         *
         * <p>Depending on the underlying implementation this may return a
         * reference to an internal array rather than a copy.  It is the callers
         * responsibility to decide if either this node or the array is utilized
         * as the primary reference for the data.CECH-250X</p>
         *
         * @return an array containing the contents of this {@code Node}
         */
        T_ARR asPrimitiveArray();

        /**
         * Creates a new primitive array.
         *
         * @param count the length of the primitive array.
         * @return the new primitive array.
         */
        T_ARR newArray(int count);

        /**
         * Copies the content of this {@code Node} into a primitive array,
         * starting at a given offset into the array.  It is the caller's
         * responsibility to ensure there is sufficient room in the array.
         *
         * @param array the array into which to copy the contents of this
         *              {@code Node}
         * @param offset the starting offset within the array
         * @throws IndexOutOfBoundsException if copying would cause access of
         *         data outside array bounds
         * @throws NullPointerException if {@code array} is {@code null}
         */
        void copyInto(T_ARR array, int offset);
    }

    /**
     * Specialized {@code Node} for int elements
     */
    interface OfInt extends OfPrimitive<Integer, IntConsumer, int[], Spliterator.OfInt, OfInt> {

        /**
         * {@inheritDoc}
         *
         * @param consumer a {@code Consumer} that is to be invoked with each
         *        element in this {@code Node}.  If this is an
         *        {@code IntConsumer}, it is cast to {@code IntConsumer} so the
         *        elements may be processed without boxing.
         */
        @Override
        default void forEach(Consumer<? super Integer> consumer) {
            if (consumer instanceof IntConsumer) {
                forEach((IntConsumer) consumer);
            }
            else {
                if (Tripwire.ENABLED)
                    Tripwire.trip(getClass(), "{0} calling Node.OfInt.forEachRemaining(Consumer)");
                spliterator().forEachRemaining(consumer);
            }
        }

        /**
         * {@inheritDoc}
         *
         * @implSpec the default implementation invokes {@link #asPrimitiveArray()} to
         * obtain an int[] array then and copies the elements from that int[]
         * array into the boxed Integer[] array.  This is not efficient and it
         * is recommended to invoke {@link #copyInto(Object, int)}.
         */
        @Override
        default void copyInto(Integer[] boxed, int offset) {
            if (Tripwire.ENABLED)
                Tripwire.trip(getClass(), "{0} calling Node.OfInt.copyInto(Integer[], int)");

            int[] array = asPrimitiveArray();
            for (int i = 0; i < array.length; i++) {
                boxed[offset + i] = array[i];
            }
        }

        @Override
        default Node.OfInt truncate(long from, long to, IntFunction<Integer[]> generator) {
            if (from == 0 && to == count())
                return this;
            long size = to - from;
            Spliterator.OfInt spliterator = spliterator();
            Node.Builder.OfInt nodeBuilder = Nodes.intBuilder(size);
            nodeBuilder.begin(size);
            for (int i = 0; i < from && spliterator.tryAdvance((IntConsumer) e -> { }); i++) { }
            for (int i = 0; (i < size) && spliterator.tryAdvance((IntConsumer) nodeBuilder); i++) { }
            nodeBuilder.end();
            return nodeBuilder.build();
        }

        @Override
        default int[] newArray(int count) {
            return new int[count];
        }

        /**
         * {@inheritDoc}
         * @implSpec The default in {@code Node.OfInt} returns
         * {@code StreamShape.INT_VALUE}
         */
        default StreamShape getShape() {
            return StreamShape.INT_VALUE;
        }
    }

    /**
     * Specialized {@code Node} for long elements
     */
    interface OfLong extends OfPrimitive<Long, LongConsumer, long[], Spliterator.OfLong, OfLong> {

        /**
         * {@inheritDoc}
         *
         * @param consumer A {@code Consumer} that is to be invoked with each
         *        element in this {@code Node}.  If this is an
         *        {@code LongConsumer}, it is cast to {@code LongConsumer} so
         *        the elements may be processed without boxing.
         */
        @Override
        default void forEach(Consumer<? super Long> consumer) {
            if (consumer instanceof LongConsumer) {
                forEach((LongConsumer) consumer);
            }
            else {
                if (Tripwire.ENABLED)
                    Tripwire.trip(getClass(), "{0} calling Node.OfLong.forEachRemaining(Consumer)");
                spliterator().forEachRemaining(consumer);
            }
        }

        /**
         * {@inheritDoc}
         *
         * @implSpec the default implementation invokes {@link #asPrimitiveArray()}
         * to obtain a long[] array then and copies the elements from that
         * long[] array into the boxed Long[] array.  This is not efficient and
         * it is recommended to invoke {@link #copyInto(Object, int)}.
         */
        @Override
        default void copyInto(Long[] boxed, int offset) {
            if (Tripwire.ENABLED)
                Tripwire.trip(getClass(), "{0} calling Node.OfInt.copyInto(Long[], int)");

            long[] array = asPrimitiveArray();
            for (int i = 0; i < array.length; i++) {
                boxed[offset + i] = array[i];
            }
        }

        @Override
        default Node.OfLong truncate(long from, long to, IntFunction<Long[]> generator) {
            if (from == 0 && to == count())
                return this;
            long size = to - from;
            Spliterator.OfLong spliterator = spliterator();
            Node.Builder.OfLong nodeBuilder = Nodes.longBuilder(size);
            nodeBuilder.begin(size);
            for (int i = 0; i < from && spliterator.tryAdvance((LongConsumer) e -> { }); i++) { }
            for (int i = 0; (i < size) && spliterator.tryAdvance((LongConsumer) nodeBuilder); i++) { }
            nodeBuilder.end();
            return nodeBuilder.build();
        }

        @Override
        default long[] newArray(int count) {
            return new long[count];
        }

        /**
         * {@inheritDoc}
         * @implSpec The default in {@code Node.OfLong} returns
         * {@code StreamShape.LONG_VALUE}
         */
        default StreamShape getShape() {
            return StreamShape.LONG_VALUE;
        }
    }

    /**
     * Specialized {@code Node} for double elements
     */
    interface OfDouble extends OfPrimitive<Double, DoubleConsumer, double[], Spliterator.OfDouble, OfDouble> {

        /**
         * {@inheritDoc}
         *
         * @param consumer A {@code Consumer} that is to be invoked with each
         *        element in this {@code Node}.  If this is an
         *        {@code DoubleConsumer}, it is cast to {@code DoubleConsumer}
         *        so the elements may be processed without boxing.
         */
        @Override
        default void forEach(Consumer<? super Double> consumer) {
            if (consumer instanceof DoubleConsumer) {
                forEach((DoubleConsumer) consumer);
            }
            else {
                if (Tripwire.ENABLED)
                    Tripwire.trip(getClass(), "{0} calling Node.OfLong.forEachRemaining(Consumer)");
                spliterator().forEachRemaining(consumer);
            }
        }

        //

        /**
         * {@inheritDoc}
         *
         * @implSpec the default implementation invokes {@link #asPrimitiveArray()}
         * to obtain a double[] array then and copies the elements from that
         * double[] array into the boxed Double[] array.  This is not efficient
         * and it is recommended to invoke {@link #copyInto(Object, int)}.
         */
        @Override
        default void copyInto(Double[] boxed, int offset) {
            if (Tripwire.ENABLED)
                Tripwire.trip(getClass(), "{0} calling Node.OfDouble.copyInto(Double[], int)");

            double[] array = asPrimitiveArray();
            for (int i = 0; i < array.length; i++) {
                boxed[offset + i] = array[i];
            }
        }

        @Override
        default Node.OfDouble truncate(long from, long to, IntFunction<Double[]> generator) {
            if (from == 0 && to == count())
                return this;
            long size = to - from;
            Spliterator.OfDouble spliterator = spliterator();
            Node.Builder.OfDouble nodeBuilder = Nodes.doubleBuilder(size);
            nodeBuilder.begin(size);
            for (int i = 0; i < from && spliterator.tryAdvance((DoubleConsumer) e -> { }); i++) { }
            for (int i = 0; (i < size) && spliterator.tryAdvance((DoubleConsumer) nodeBuilder); i++) { }
            nodeBuilder.end();
            return nodeBuilder.build();
        }

        @Override
        default double[] newArray(int count) {
            return new double[count];
        }

        /**
         * {@inheritDoc}
         *
         * @implSpec The default in {@code Node.OfDouble} returns
         * {@code StreamShape.DOUBLE_VALUE}
         */
        default StreamShape getShape() {
            return StreamShape.DOUBLE_VALUE;
        }
    }
}

//StreamShape
enum StreamShape {
    /**
     * The shape specialization corresponding to {@code Stream} and elements
     * that are object references.
     */
    REFERENCE,
    /**
     * The shape specialization corresponding to {@code IntStream} and elements
     * that are {@code int} values.
     */
    INT_VALUE,
    /**
     * The shape specialization corresponding to {@code LongStream} and elements
     * that are {@code long} values.
     */
    LONG_VALUE,
    /**
     * The shape specialization corresponding to {@code DoubleStream} and
     * elements that are {@code double} values.
     */
    DOUBLE_VALUE
}

//PipelineHelper
abstract class PipelineHelper<P_OUT> {

    /**
     * Gets the stream shape for the source of the pipeline segment.
     *
     * @return the stream shape for the source of the pipeline segment.
     */
    abstract StreamShape getSourceShape();

    /**
     * Gets the combined stream and operation flags for the output of the described
     * pipeline.  This will incorporate stream flags from the stream source, all
     * the intermediate operations and the terminal operation.
     *
     * @return the combined stream and operation flags
     * @see StreamOpFlag
     */
    abstract int getStreamAndOpFlags();

    /**
     * Returns the exact output size of the portion of the output resulting from
     * applying the pipeline stages described by this {@code PipelineHelper} to
     * the portion of the input described by the provided
     * {@code Spliterator}, if known.  If not known or known infinite, will
     * return {@code -1}.
     *
     * @apiNote
     * The exact output size is known if the {@code Spliterator} has the
     * {@code SIZED} characteristic, and the operation flags
     * {@link StreamOpFlag#SIZED} is known on the combined stream and operation
     * flags.
     *
     * @param spliterator the spliterator describing the relevant portion of the
     *        source data
     * @return the exact size if known, or -1 if infinite or unknown
     */
    abstract<P_IN> long exactOutputSizeIfKnown(Spliterator<P_IN> spliterator);

    /**
     * Applies the pipeline stages described by this {@code PipelineHelper} to
     * the provided {@code Spliterator} and send the results to the provided
     * {@code Sink}.
     *
     * @implSpec
     * The implementation behaves as if:
     * <pre>{@code
     *     intoWrapped(wrapSink(sink), spliterator);
     * }</pre>
     *
     * @param sink the {@code Sink} to receive the results
     * @param spliterator the spliterator describing the source input to process
     */
    abstract<P_IN, S extends Sink<P_OUT>> S wrapAndCopyInto(S sink, Spliterator<P_IN> spliterator);

    /**
     * Pushes elements obtained from the {@code Spliterator} into the provided
     * {@code Sink}.  If the stream pipeline is known to have short-circuiting
     * stages in it (see {@link StreamOpFlag#SHORT_CIRCUIT}), the
     * {@link Sink#cancellationRequested()} is checked after each
     * element, stopping if cancellation is requested.
     *
     * @implSpec
     * This method conforms to the {@code Sink} protocol of calling
     * {@code Sink.begin} before pushing elements, via {@code Sink.accept}, and
     * calling {@code Sink.end} after all elements have been pushed.
     *
     * @param wrappedSink the destination {@code Sink}
     * @param spliterator the source {@code Spliterator}
     */
    abstract<P_IN> void copyInto(Sink<P_IN> wrappedSink, Spliterator<P_IN> spliterator);

    /**
     * Pushes elements obtained from the {@code Spliterator} into the provided
     * {@code Sink}, checking {@link Sink#cancellationRequested()} after each
     * element, and stopping if cancellation is requested.
     *
     * @implSpec
     * This method conforms to the {@code Sink} protocol of calling
     * {@code Sink.begin} before pushing elements, via {@code Sink.accept}, and
     * calling {@code Sink.end} after all elements have been pushed or if
     * cancellation is requested.
     *
     * @param wrappedSink the destination {@code Sink}
     * @param spliterator the source {@code Spliterator}
     */
    abstract <P_IN> void copyIntoWithCancel(Sink<P_IN> wrappedSink, Spliterator<P_IN> spliterator);

    /**
     * Takes a {@code Sink} that accepts elements of the output type of the
     * {@code PipelineHelper}, and wrap it with a {@code Sink} that accepts
     * elements of the input type and implements all the intermediate operations
     * described by this {@code PipelineHelper}, delivering the result into the
     * provided {@code Sink}.
     *
     * @param sink the {@code Sink} to receive the results
     * @return a {@code Sink} that implements the pipeline stages and sends
     *         results to the provided {@code Sink}
     */
    abstract<P_IN> Sink<P_IN> wrapSink(Sink<P_OUT> sink);

    /**
     *
     * @param spliterator
     * @param <P_IN>
     * @return
     */
    abstract<P_IN> Spliterator<P_OUT> wrapSpliterator(Spliterator<P_IN> spliterator);

    /**
     * Constructs a @{link Node.Builder} compatible with the output shape of
     * this {@code PipelineHelper}.
     *
     * @param exactSizeIfKnown if >=0 then a builder will be created that has a
     *        fixed capacity of exactly sizeIfKnown elements; if < 0 then the
     *        builder has variable capacity.  A fixed capacity builder will fail
     *        if an element is added after the builder has reached capacity.
     * @param generator a factory function for array instances
     * @return a {@code Node.Builder} compatible with the output shape of this
     *         {@code PipelineHelper}
     */
    abstract Node.Builder<P_OUT> makeNodeBuilder(long exactSizeIfKnown,
                                                 IntFunction<P_OUT[]> generator);

    /**
     * Collects all output elements resulting from applying the pipeline stages
     * to the source {@code Spliterator} into a {@code Node}.
     *
     * @implNote
     * If the pipeline has no intermediate operations and the source is backed
     * by a {@code Node} then that {@code Node} will be returned (or flattened
     * and then returned). This reduces copying for a pipeline consisting of a
     * stateful operation followed by a terminal operation that returns an
     * array, such as:
     * <pre>{@code
     *     stream.sorted().toArray();
     * }</pre>
     *
     * @param spliterator the source {@code Spliterator}
     * @param flatten if true and the pipeline is a parallel pipeline then the
     *        {@code Node} returned will contain no children, otherwise the
     *        {@code Node} may represent the root in a tree that reflects the
     *        shape of the computation tree.
     * @param generator a factory function for array instances
     * @return the {@code Node} containing all output elements
     */
    abstract<P_IN> Node<P_OUT> evaluate(Spliterator<P_IN> spliterator,
                                        boolean flatten,
                                        IntFunction<P_OUT[]> generator);
}

//Sink
interface Sink<T> extends Consumer<T> {
    /**
     * Resets the sink state to receive a fresh data set.  This must be called
     * before sending any data to the sink.  After calling {@link #end()},
     * you may call this method to reset the sink for another calculation.
     * @param size The exact size of the data to be pushed downstream, if
     * known or {@code -1} if unknown or infinite.
     *
     * <p>Prior to this call, the sink must be in the initial state, and after
     * this call it is in the active state.
     */
    default void begin(long size) {}

    /**
     * Indicates that all elements have been pushed.  If the {@code Sink} is
     * stateful, it should send any stored state downstream at this time, and
     * should clear any accumulated state (and associated resources).
     *
     * <p>Prior to this call, the sink must be in the active state, and after
     * this call it is returned to the initial state.
     */
    default void end() {}

    /**
     * Indicates that this {@code Sink} does not wish to receive any more data.
     *
     * @implSpec The default implementation always returns false.
     *
     * @return true if cancellation is requested
     */
    default boolean cancellationRequested() {
        return false;
    }

    /**
     * Accepts an int value.
     *
     * @implSpec The default implementation throws IllegalStateException.
     *
     * @throws IllegalStateException if this sink does not accept int values
     */
    default void accept(int value) {
        throw new IllegalStateException("called wrong accept method");
    }

    /**
     * Accepts a long value.
     *
     * @implSpec The default implementation throws IllegalStateException.
     *
     * @throws IllegalStateException if this sink does not accept long values
     */
    default void accept(long value) {
        throw new IllegalStateException("called wrong accept method");
    }

    /**
     * Accepts a double value.
     *
     * @implSpec The default implementation throws IllegalStateException.
     *
     * @throws IllegalStateException if this sink does not accept double values
     */
    default void accept(double value) {
        throw new IllegalStateException("called wrong accept method");
    }

    /**
     * {@code Sink} that implements {@code Sink<Integer>}, re-abstracts
     * {@code accept(int)}, and wires {@code accept(Integer)} to bridge to
     * {@code accept(int)}.
     */
    interface OfInt extends Sink<Integer>, IntConsumer {
        @Override
        void accept(int value);

        @Override
        default void accept(Integer i) {
            if (Tripwire.ENABLED)
                Tripwire.trip(getClass(), "{0} calling Sink.OfInt.accept(Integer)");
            accept(i.intValue());
        }
    }

    /**
     * {@code Sink} that implements {@code Sink<Long>}, re-abstracts
     * {@code accept(long)}, and wires {@code accept(Long)} to bridge to
     * {@code accept(long)}.
     */
    interface OfLong extends Sink<Long>, LongConsumer {
        @Override
        void accept(long value);

        @Override
        default void accept(Long i) {
            if (Tripwire.ENABLED)
                Tripwire.trip(getClass(), "{0} calling Sink.OfLong.accept(Long)");
            accept(i.longValue());
        }
    }

    /**
     * {@code Sink} that implements {@code Sink<Double>}, re-abstracts
     * {@code accept(double)}, and wires {@code accept(Double)} to bridge to
     * {@code accept(double)}.
     */
    interface OfDouble extends Sink<Double>, DoubleConsumer {
        @Override
        void accept(double value);

        @Override
        default void accept(Double i) {
            if (Tripwire.ENABLED)
                Tripwire.trip(getClass(), "{0} calling Sink.OfDouble.accept(Double)");
            accept(i.doubleValue());
        }
    }

    /**
     * Abstract {@code Sink} implementation for creating chains of
     * sinks.  The {@code begin}, {@code end}, and
     * {@code cancellationRequested} methods are wired to chain to the
     * downstream {@code Sink}.  This implementation takes a downstream
     * {@code Sink} of unknown input shape and produces a {@code Sink<T>}.  The
     * implementation of the {@code accept()} method must call the correct
     * {@code accept()} method on the downstream {@code Sink}.
     */
    static abstract class ChainedReference<T, E_OUT> implements Sink<T> {
        protected final Sink<? super E_OUT> downstream;

        public ChainedReference(Sink<? super E_OUT> downstream) {
            this.downstream = Objects.requireNonNull(downstream);
        }

        @Override
        public void begin(long size) {
            downstream.begin(size);
        }

        @Override
        public void end() {
            downstream.end();
        }

        @Override
        public boolean cancellationRequested() {
            return downstream.cancellationRequested();
        }
    }

    /**
     * Abstract {@code Sink} implementation designed for creating chains of
     * sinks.  The {@code begin}, {@code end}, and
     * {@code cancellationRequested} methods are wired to chain to the
     * downstream {@code Sink}.  This implementation takes a downstream
     * {@code Sink} of unknown input shape and produces a {@code Sink.OfInt}.
     * The implementation of the {@code accept()} method must call the correct
     * {@code accept()} method on the downstream {@code Sink}.
     */
    static abstract class ChainedInt<E_OUT> implements Sink.OfInt {
        protected final Sink<? super E_OUT> downstream;

        public ChainedInt(Sink<? super E_OUT> downstream) {
            this.downstream = Objects.requireNonNull(downstream);
        }

        @Override
        public void begin(long size) {
            downstream.begin(size);
        }

        @Override
        public void end() {
            downstream.end();
        }

        @Override
        public boolean cancellationRequested() {
            return downstream.cancellationRequested();
        }
    }

    /**
     * Abstract {@code Sink} implementation designed for creating chains of
     * sinks.  The {@code begin}, {@code end}, and
     * {@code cancellationRequested} methods are wired to chain to the
     * downstream {@code Sink}.  This implementation takes a downstream
     * {@code Sink} of unknown input shape and produces a {@code Sink.OfLong}.
     * The implementation of the {@code accept()} method must call the correct
     * {@code accept()} method on the downstream {@code Sink}.
     */
    static abstract class ChainedLong<E_OUT> implements Sink.OfLong {
        protected final Sink<? super E_OUT> downstream;

        public ChainedLong(Sink<? super E_OUT> downstream) {
            this.downstream = Objects.requireNonNull(downstream);
        }

        @Override
        public void begin(long size) {
            downstream.begin(size);
        }

        @Override
        public void end() {
            downstream.end();
        }

        @Override
        public boolean cancellationRequested() {
            return downstream.cancellationRequested();
        }
    }

    /**
     * Abstract {@code Sink} implementation designed for creating chains of
     * sinks.  The {@code begin}, {@code end}, and
     * {@code cancellationRequested} methods are wired to chain to the
     * downstream {@code Sink}.  This implementation takes a downstream
     * {@code Sink} of unknown input shape and produces a {@code Sink.OfDouble}.
     * The implementation of the {@code accept()} method must call the correct
     * {@code accept()} method on the downstream {@code Sink}.
     */
    static abstract class ChainedDouble<E_OUT> implements Sink.OfDouble {
        protected final Sink<? super E_OUT> downstream;

        public ChainedDouble(Sink<? super E_OUT> downstream) {
            this.downstream = Objects.requireNonNull(downstream);
        }

        @Override
        public void begin(long size) {
            downstream.begin(size);
        }

        @Override
        public void end() {
            downstream.end();
        }

        @Override
        public boolean cancellationRequested() {
            return downstream.cancellationRequested();
        }
    }
}

//AbstractTask
@SuppressWarnings("serial")
abstract class AbstractTask<P_IN, P_OUT, R,
                            K extends AbstractTask<P_IN, P_OUT, R, K>>
        extends CountedCompleter<R> {

    private static final int LEAF_TARGET = ForkJoinPool.getCommonPoolParallelism() << 2;

    /** The pipeline helper, common to all tasks in a computation */
    protected final PipelineHelper<P_OUT> helper;

    /**
     * The spliterator for the portion of the input associated with the subtree
     * rooted at this task
     */
    protected Spliterator<P_IN> spliterator;

    /** Target leaf size, common to all tasks in a computation */
    protected long targetSize; // may be laziliy initialized

    /**
     * The left child.
     * null if no children
     * if non-null rightChild is non-null
     */
    protected K leftChild;

    /**
     * The right child.
     * null if no children
     * if non-null leftChild is non-null
     */
    protected K rightChild;

    /** The result of this node, if completed */
    private R localResult;

    /**
     * Constructor for root nodes.
     *
     * @param helper The {@code PipelineHelper} describing the stream pipeline
     *               up to this operation
     * @param spliterator The {@code Spliterator} describing the source for this
     *                    pipeline
     */
    protected AbstractTask(PipelineHelper<P_OUT> helper,
                           Spliterator<P_IN> spliterator) {
        super(null);
        this.helper = helper;
        this.spliterator = spliterator;
        this.targetSize = 0L;
    }

    /**
     * Constructor for non-root nodes.
     *
     * @param parent this node's parent task
     * @param spliterator {@code Spliterator} describing the subtree rooted at
     *        this node, obtained by splitting the parent {@code Spliterator}
     */
    protected AbstractTask(K parent,
                           Spliterator<P_IN> spliterator) {
        super(parent);
        this.spliterator = spliterator;
        this.helper = parent.helper;
        this.targetSize = parent.targetSize;
    }

    /**
     * Default target of leaf tasks for parallel decomposition.
     * To allow load balancing, we over-partition, currently to approximately
     * four tasks per processor, which enables others to help out
     * if leaf tasks are uneven or some processors are otherwise busy.
     */
    public static int getLeafTarget() {
        Thread t = Thread.currentThread();
        if (t instanceof ForkJoinWorkerThread) {
            return ((ForkJoinWorkerThread) t).getPool().getParallelism() << 2;
        }
        else {
            return LEAF_TARGET;
        }
    }

    /**
     * Constructs a new node of type T whose parent is the receiver; must call
     * the AbstractTask(T, Spliterator) constructor with the receiver and the
     * provided Spliterator.
     *
     * @param spliterator {@code Spliterator} describing the subtree rooted at
     *        this node, obtained by splitting the parent {@code Spliterator}
     * @return newly constructed child node
     */
    protected abstract K makeChild(Spliterator<P_IN> spliterator);

    /**
     * Computes the result associated with a leaf node.  Will be called by
     * {@code compute()} and the result passed to @{code setLocalResult()}
     *
     * @return the computed result of a leaf node
     */
    protected abstract R doLeaf();

    /**
     * Returns a suggested target leaf size based on the initial size estimate.
     *
     * @return suggested target leaf size
     */
    public static long suggestTargetSize(long sizeEstimate) {
        long est = sizeEstimate / getLeafTarget();
        return est > 0L ? est : 1L;
    }

    /**
     * Returns the targetSize, initializing it via the supplied
     * size estimate if not already initialized.
     */
    protected final long getTargetSize(long sizeEstimate) {
        long s;
        return ((s = targetSize) != 0 ? s :
                (targetSize = suggestTargetSize(sizeEstimate)));
    }

    /**
     * Returns the local result, if any. Subclasses should use
     * {@link #setLocalResult(Object)} and {@link #getLocalResult()} to manage
     * results.  This returns the local result so that calls from within the
     * fork-join framework will return the correct result.
     *
     * @return local result for this node previously stored with
     * {@link #setLocalResult}
     */
    @Override
    public R getRawResult() {
        return localResult;
    }

    /**
     * Does nothing; instead, subclasses should use
     * {@link #setLocalResult(Object)}} to manage results.
     *
     * @param result must be null, or an exception is thrown (this is a safety
     *        tripwire to detect when {@code setRawResult()} is being used
     *        instead of {@code setLocalResult()}
     */
    @Override
    protected void setRawResult(R result) {
        if (result != null)
            throw new IllegalStateException();
    }

    /**
     * Retrieves a result previously stored with {@link #setLocalResult}
     *
     * @return local result for this node previously stored with
     * {@link #setLocalResult}
     */
    protected R getLocalResult() {
        return localResult;
    }

    /**
     * Associates the result with the task, can be retrieved with
     * {@link #getLocalResult}
     *
     * @param localResult local result for this node
     */
    protected void setLocalResult(R localResult) {
        this.localResult = localResult;
    }

    /**
     * Indicates whether this task is a leaf node.  (Only valid after
     * {@link #compute} has been called on this node).  If the node is not a
     * leaf node, then children will be non-null and numChildren will be
     * positive.
     *
     * @return {@code true} if this task is a leaf node
     */
    protected boolean isLeaf() {
        return leftChild == null;
    }

    /**
     * Indicates whether this task is the root node
     *
     * @return {@code true} if this task is the root node.
     */
    protected boolean isRoot() {
        return getParent() == null;
    }

    /**
     * Returns the parent of this task, or null if this task is the root
     *
     * @return the parent of this task, or null if this task is the root
     */
    @SuppressWarnings("unchecked")
    protected K getParent() {
        return (K) getCompleter();
    }

    /**
     * Decides whether or not to split a task further or compute it
     * directly. If computing directly, calls {@code doLeaf} and pass
     * the result to {@code setRawResult}. Otherwise splits off
     * subtasks, forking one and continuing as the other.
     *
     * <p> The method is structured to conserve resources across a
     * range of uses.  The loop continues with one of the child tasks
     * when split, to avoid deep recursion. To cope with spliterators
     * that may be systematically biased toward left-heavy or
     * right-heavy splits, we alternate which child is forked versus
     * continued in the loop.
     */
    @Override
    public void compute() {
        Spliterator<P_IN> rs = spliterator, ls; // right, left spliterators
        long sizeEstimate = rs.estimateSize();
        long sizeThreshold = getTargetSize(sizeEstimate);
        boolean forkRight = false;
        @SuppressWarnings("unchecked") K task = (K) this;
        while (sizeEstimate > sizeThreshold && (ls = rs.trySplit()) != null) {
            K leftChild, rightChild, taskToFork;
            task.leftChild  = leftChild = task.makeChild(ls);
            task.rightChild = rightChild = task.makeChild(rs);
            task.setPendingCount(1);
            if (forkRight) {
                forkRight = false;
                rs = ls;
                task = leftChild;
                taskToFork = rightChild;
            }
            else {
                forkRight = true;
                task = rightChild;
                taskToFork = leftChild;
            }
            taskToFork.fork();
            sizeEstimate = rs.estimateSize();
        }
        task.setLocalResult(task.doLeaf());
        task.tryComplete();
    }

    /**
     * {@inheritDoc}
     *
     * @implNote
     * Clears spliterator and children fields.  Overriders MUST call
     * {@code super.onCompletion} as the last thing they do if they want these
     * cleared.
     */
    @Override
    public void onCompletion(CountedCompleter<?> caller) {
        spliterator = null;
        leftChild = rightChild = null;
    }

    /**
     * Returns whether this node is a "leftmost" node -- whether the path from
     * the root to this node involves only traversing leftmost child links.  For
     * a leaf node, this means it is the first leaf node in the encounter order.
     *
     * @return {@code true} if this node is a "leftmost" node
     */
    protected boolean isLeftmostNode() {
        @SuppressWarnings("unchecked")
        K node = (K) this;
        while (node != null) {
            K parent = node.getParent();
            if (parent != null && parent.leftChild != node)
                return false;
            node = parent;
        }
        return true;
    }
}

//Tripwire
final class Tripwire {
    private static final String TRIPWIRE_PROPERTY = "org.openjdk.java.util.stream.tripwire";

    /** Should debugging checks be enabled? */
    static final boolean ENABLED = AccessController.doPrivileged(
            (PrivilegedAction<Boolean>) () -> Boolean.getBoolean(TRIPWIRE_PROPERTY));

    private Tripwire() { }

    /**
     * Produces a log warning, using {@code PlatformLogger.getLogger(className)},
     * using the supplied message.  The class name of {@code trippingClass} will
     * be used as the first parameter to the message.
     *
     * @param trippingClass Name of the class generating the message
     * @param msg A message format string of the type expected by
     * {@link PlatformLogger}
     */
    static void trip(Class<?> trippingClass, String msg) {
        PlatformLogger.getLogger(trippingClass.getName()).warning(msg, trippingClass.getName());
    }
}

//PlatformLogger
class PlatformLogger {

    // The integer values must match that of {@code java.util.logging.Level}
    // objects.
    private static final int OFF     = Integer.MAX_VALUE;
    private static final int SEVERE  = 1000;
    private static final int WARNING = 900;
    private static final int INFO    = 800;
    private static final int CONFIG  = 700;
    private static final int FINE    = 500;
    private static final int FINER   = 400;
    private static final int FINEST  = 300;
    private static final int ALL     = Integer.MIN_VALUE;

    /**
     * PlatformLogger logging levels.
     */
    public static enum Level {
        // The name and value must match that of {@code java.util.logging.Level}s.
        // Declare in ascending order of the given value for binary search.
        ALL,
        FINEST,
        FINER,
        FINE,
        CONFIG,
        INFO,
        WARNING,
        SEVERE,
        OFF;

        /**
         * Associated java.util.logging.Level lazily initialized in
         * JavaLoggerProxy's static initializer only once
         * when java.util.logging is available and enabled.
         * Only accessed by JavaLoggerProxy.
         */
        /* java.util.logging.Level */ Object javaLevel;

        // ascending order for binary search matching the list of enum constants
        private static final int[] LEVEL_VALUES = new int[] {
            PlatformLogger.ALL, PlatformLogger.FINEST, PlatformLogger.FINER,
            PlatformLogger.FINE, PlatformLogger.CONFIG, PlatformLogger.INFO,
            PlatformLogger.WARNING, PlatformLogger.SEVERE, PlatformLogger.OFF
        };

        public int intValue() {
            return LEVEL_VALUES[this.ordinal()];
        }

        static Level valueOf(int level) {
            switch (level) {
                // ordering per the highest occurrences in the jdk source
                // finest, fine, finer, info first
                case PlatformLogger.FINEST  : return Level.FINEST;
                case PlatformLogger.FINE    : return Level.FINE;
                case PlatformLogger.FINER   : return Level.FINER;
                case PlatformLogger.INFO    : return Level.INFO;
                case PlatformLogger.WARNING : return Level.WARNING;
                case PlatformLogger.CONFIG  : return Level.CONFIG;
                case PlatformLogger.SEVERE  : return Level.SEVERE;
                case PlatformLogger.OFF     : return Level.OFF;
                case PlatformLogger.ALL     : return Level.ALL;
            }
            // return the nearest Level value >= the given level,
            // for level > SEVERE, return SEVERE and exclude OFF
            int i = Arrays.binarySearch(LEVEL_VALUES, 0, LEVEL_VALUES.length-2, level);
            return values()[i >= 0 ? i : (-i-1)];
        }
    }

    private static final Level DEFAULT_LEVEL = Level.INFO;
    private static boolean loggingEnabled;
    static {
        loggingEnabled = AccessController.doPrivileged(
            new PrivilegedAction<Boolean>() {
                public Boolean run() {
                    String cname = System.getProperty("java.util.logging.config.class");
                    String fname = System.getProperty("java.util.logging.config.file");
                    return (cname != null || fname != null);
                }
            });

        // force loading of all JavaLoggerProxy (sub)classes to make JIT de-optimizations
        // less probable.  Don't initialize JavaLoggerProxy class since
        // java.util.logging may not be enabled.
        try {
            Class.forName("sun.util.logging.PlatformLogger$DefaultLoggerProxy",
                          false,
                          PlatformLogger.class.getClassLoader());
            Class.forName("sun.util.logging.PlatformLogger$JavaLoggerProxy",
                          false,   // do not invoke class initializer
                          PlatformLogger.class.getClassLoader());
        } catch (ClassNotFoundException ex) {
            throw new InternalError(ex);
        }
    }

    // Table of known loggers.  Maps names to PlatformLoggers.
    private static Map<String,WeakReference<PlatformLogger>> loggers =
        new HashMap<>();

    /**
     * Returns a PlatformLogger of a given name.
     */
    public static synchronized PlatformLogger getLogger(String name) {
        PlatformLogger log = null;
        WeakReference<PlatformLogger> ref = loggers.get(name);
        if (ref != null) {
            log = ref.get();
        }
        if (log == null) {
            log = new PlatformLogger(name);
            loggers.put(name, new WeakReference<>(log));
        }
        return log;
    }

    /**
     * Initialize java.util.logging.Logger objects for all platform loggers.
     * This method is called from LogManager.readPrimordialConfiguration().
     */
    public static synchronized void redirectPlatformLoggers() {
        if (loggingEnabled || !LoggingSupport.isAvailable()) return;

        loggingEnabled = true;
        for (Map.Entry<String, WeakReference<PlatformLogger>> entry : loggers.entrySet()) {
            WeakReference<PlatformLogger> ref = entry.getValue();
            PlatformLogger plog = ref.get();
            if (plog != null) {
                plog.redirectToJavaLoggerProxy();
            }
        }
    }

    /**
     * Creates a new JavaLoggerProxy and redirects the platform logger to it
     */
    private void redirectToJavaLoggerProxy() {
        DefaultLoggerProxy lp = DefaultLoggerProxy.class.cast(this.loggerProxy);
        JavaLoggerProxy jlp = new JavaLoggerProxy(lp.name, lp.level);
        // the order of assignments is important
        this.javaLoggerProxy = jlp;   // isLoggable checks javaLoggerProxy if set
        this.loggerProxy = jlp;
    }

    // DefaultLoggerProxy may be replaced with a JavaLoggerProxy object
    // when the java.util.logging facility is enabled
    private volatile LoggerProxy loggerProxy;
    // javaLoggerProxy is only set when the java.util.logging facility is enabled
    private volatile JavaLoggerProxy javaLoggerProxy;
    private PlatformLogger(String name) {
        if (loggingEnabled) {
            this.loggerProxy = this.javaLoggerProxy = new JavaLoggerProxy(name);
        } else {
            this.loggerProxy = new DefaultLoggerProxy(name);
        }
    }

    /**
     * A convenience method to test if the logger is turned off.
     * (i.e. its level is OFF).
     */
    public boolean isEnabled() {
        return loggerProxy.isEnabled();
    }

    /**
     * Gets the name for this platform logger.
     */
    public String getName() {
        return loggerProxy.name;
    }

    /**
     * Returns true if a message of the given level would actually
     * be logged by this logger.
     */
    public boolean isLoggable(Level level) {
        if (level == null) {
            throw new NullPointerException();
        }
        // performance-sensitive method: use two monomorphic call-sites
        JavaLoggerProxy jlp = javaLoggerProxy;
        return jlp != null ? jlp.isLoggable(level) : loggerProxy.isLoggable(level);
    }

    /**
     * Get the log level that has been specified for this PlatformLogger.
     * The result may be null, which means that this logger's
     * effective level will be inherited from its parent.
     *
     * @return  this PlatformLogger's level
     */
    public Level level() {
        return loggerProxy.getLevel();
    }

    /**
     * Set the log level specifying which message levels will be
     * logged by this logger.  Message levels lower than this
     * value will be discarded.  The level value {@link #OFF}
     * can be used to turn off logging.
     * <p>
     * If the new level is null, it means that this node should
     * inherit its level from its nearest ancestor with a specific
     * (non-null) level value.
     *
     * @param newLevel the new value for the log level (may be null)
     */
    public void setLevel(Level newLevel) {
        loggerProxy.setLevel(newLevel);
    }

    /**
     * Logs a SEVERE message.
     */
    public void severe(String msg) {
        loggerProxy.doLog(Level.SEVERE, msg);
    }

    public void severe(String msg, Throwable t) {
        loggerProxy.doLog(Level.SEVERE, msg, t);
    }

    public void severe(String msg, Object... params) {
        loggerProxy.doLog(Level.SEVERE, msg, params);
    }

    /**
     * Logs a WARNING message.
     */
    public void warning(String msg) {
        loggerProxy.doLog(Level.WARNING, msg);
    }

    public void warning(String msg, Throwable t) {
        loggerProxy.doLog(Level.WARNING, msg, t);
    }

    public void warning(String msg, Object... params) {
        loggerProxy.doLog(Level.WARNING, msg, params);
    }

    /**
     * Logs an INFO message.
     */
    public void info(String msg) {
        loggerProxy.doLog(Level.INFO, msg);
    }

    public void info(String msg, Throwable t) {
        loggerProxy.doLog(Level.INFO, msg, t);
    }

    public void info(String msg, Object... params) {
        loggerProxy.doLog(Level.INFO, msg, params);
    }

    /**
     * Logs a CONFIG message.
     */
    public void config(String msg) {
        loggerProxy.doLog(Level.CONFIG, msg);
    }

    public void config(String msg, Throwable t) {
        loggerProxy.doLog(Level.CONFIG, msg, t);
    }

    public void config(String msg, Object... params) {
        loggerProxy.doLog(Level.CONFIG, msg, params);
    }

    /**
     * Logs a FINE message.
     */
    public void fine(String msg) {
        loggerProxy.doLog(Level.FINE, msg);
    }

    public void fine(String msg, Throwable t) {
        loggerProxy.doLog(Level.FINE, msg, t);
    }

    public void fine(String msg, Object... params) {
        loggerProxy.doLog(Level.FINE, msg, params);
    }

    /**
     * Logs a FINER message.
     */
    public void finer(String msg) {
        loggerProxy.doLog(Level.FINER, msg);
    }

    public void finer(String msg, Throwable t) {
        loggerProxy.doLog(Level.FINER, msg, t);
    }

    public void finer(String msg, Object... params) {
        loggerProxy.doLog(Level.FINER, msg, params);
    }

    /**
     * Logs a FINEST message.
     */
    public void finest(String msg) {
        loggerProxy.doLog(Level.FINEST, msg);
    }

    public void finest(String msg, Throwable t) {
        loggerProxy.doLog(Level.FINEST, msg, t);
    }

    public void finest(String msg, Object... params) {
        loggerProxy.doLog(Level.FINEST, msg, params);
    }

    /**
     * Abstract base class for logging support, defining the API and common field.
     */
    private static abstract class LoggerProxy {
        final String name;

        protected LoggerProxy(String name) {
            this.name = name;
        }

        abstract boolean isEnabled();

        abstract Level getLevel();
        abstract void setLevel(Level newLevel);

        abstract void doLog(Level level, String msg);
        abstract void doLog(Level level, String msg, Throwable thrown);
        abstract void doLog(Level level, String msg, Object... params);

        abstract boolean isLoggable(Level level);
    }


    private static final class DefaultLoggerProxy extends LoggerProxy {
        /**
         * Default platform logging support - output messages to System.err -
         * equivalent to ConsoleHandler with SimpleFormatter.
         */
        private static PrintStream outputStream() {
            return System.err;
        }

        volatile Level effectiveLevel; // effective level (never null)
        volatile Level level;          // current level set for this node (may be null)

        DefaultLoggerProxy(String name) {
            super(name);
            this.effectiveLevel = deriveEffectiveLevel(null);
            this.level = null;
        }

        boolean isEnabled() {
            return effectiveLevel != Level.OFF;
        }

        Level getLevel() {
            return level;
        }

        void setLevel(Level newLevel) {
            Level oldLevel = level;
            if (oldLevel != newLevel) {
                level = newLevel;
                effectiveLevel = deriveEffectiveLevel(newLevel);
            }
        }

        void doLog(Level level, String msg) {
            if (isLoggable(level)) {
                outputStream().print(format(level, msg, null));
            }
        }

        void doLog(Level level, String msg, Throwable thrown) {
            if (isLoggable(level)) {
                outputStream().print(format(level, msg, thrown));
            }
        }

        void doLog(Level level, String msg, Object... params) {
            if (isLoggable(level)) {
                String newMsg = formatMessage(msg, params);
                outputStream().print(format(level, newMsg, null));
            }
        }

        boolean isLoggable(Level level) {
            Level effectiveLevel = this.effectiveLevel;
            return level.intValue() >= effectiveLevel.intValue() && effectiveLevel != Level.OFF;
        }

        // derive effective level (could do inheritance search like j.u.l.Logger)
        private Level deriveEffectiveLevel(Level level) {
            return level == null ? DEFAULT_LEVEL : level;
        }

        // Copied from java.util.logging.Formatter.formatMessage
        private String formatMessage(String format, Object... parameters) {
            // Do the formatting.
            try {
                if (parameters == null || parameters.length == 0) {
                    // No parameters.  Just return format string.
                    return format;
                }
                // Is it a java.text style format?
                // Ideally we could match with
                // Pattern.compile("\\{\\d").matcher(format).find())
                // However the cost is 14% higher, so we cheaply check for
                // 1 of the first 4 parameters
                if (format.indexOf("{0") >= 0 || format.indexOf("{1") >=0 ||
                            format.indexOf("{2") >=0|| format.indexOf("{3") >=0) {
                    return java.text.MessageFormat.format(format, parameters);
                }
                return format;
            } catch (Exception ex) {
                // Formatting failed: use format string.
                return format;
            }
        }

        private static final String formatString =
            LoggingSupport.getSimpleFormat(false); // don't check logging.properties

        // minimize memory allocation
        private Date date = new Date();
        private synchronized String format(Level level, String msg, Throwable thrown) {
            date.setTime(System.currentTimeMillis());
            String throwable = "";
            if (thrown != null) {
                StringWriter sw = new StringWriter();
                PrintWriter pw = new PrintWriter(sw);
                pw.println();
                thrown.printStackTrace(pw);
                pw.close();
                throwable = sw.toString();
            }

            return String.format(formatString,
                                 date,
                                 getCallerInfo(),
                                 name,
                                 level.name(),
                                 msg,
                                 throwable);
        }

        // Returns the caller's class and method's name; best effort
        // if cannot infer, return the logger's name.
        private String getCallerInfo() {
            String sourceClassName = null;
            String sourceMethodName = null;

            JavaLangAccess access = SharedSecrets.getJavaLangAccess();
            Throwable throwable = new Throwable();
            int depth = access.getStackTraceDepth(throwable);

            String logClassName = "sun.util.logging.PlatformLogger";
            boolean lookingForLogger = true;
            for (int ix = 0; ix < depth; ix++) {
                // Calling getStackTraceElement directly prevents the VM
                // from paying the cost of building the entire stack frame.
                StackTraceElement frame =
                    access.getStackTraceElement(throwable, ix);
                String cname = frame.getClassName();
                if (lookingForLogger) {
                    // Skip all frames until we have found the first logger frame.
                    if (cname.equals(logClassName)) {
                        lookingForLogger = false;
                    }
                } else {
                    if (!cname.equals(logClassName)) {
                        // We've found the relevant frame.
                        sourceClassName = cname;
                        sourceMethodName = frame.getMethodName();
                        break;
                    }
                }
            }

            if (sourceClassName != null) {
                return sourceClassName + " " + sourceMethodName;
            } else {
                return name;
            }
        }
    }

    /**
     * JavaLoggerProxy forwards all the calls to its corresponding
     * java.util.logging.Logger object.
     */
    private static final class JavaLoggerProxy extends LoggerProxy {
        // initialize javaLevel fields for mapping from Level enum -> j.u.l.Level object
        static {
            for (Level level : Level.values()) {
                level.javaLevel = LoggingSupport.parseLevel(level.name());
            }
        }

        private final /* java.util.logging.Logger */ Object javaLogger;

        JavaLoggerProxy(String name) {
            this(name, null);
        }

        JavaLoggerProxy(String name, Level level) {
            super(name);
            this.javaLogger = LoggingSupport.getLogger(name);
            if (level != null) {
                // level has been updated and so set the Logger's level
                LoggingSupport.setLevel(javaLogger, level.javaLevel);
            }
        }

        void doLog(Level level, String msg) {
            LoggingSupport.log(javaLogger, level.javaLevel, msg);
        }

        void doLog(Level level, String msg, Throwable t) {
            LoggingSupport.log(javaLogger, level.javaLevel, msg, t);
        }

        void doLog(Level level, String msg, Object... params) {
            if (!isLoggable(level)) {
                return;
            }
            // only pass String objects to the j.u.l.Logger which may
            // be created by untrusted code
            int len = (params != null) ? params.length : 0;
            Object[] sparams = new String[len];
            for (int i = 0; i < len; i++) {
                sparams [i] = String.valueOf(params[i]);
            }
            LoggingSupport.log(javaLogger, level.javaLevel, msg, sparams);
        }

        boolean isEnabled() {
            return LoggingSupport.isLoggable(javaLogger, Level.OFF.javaLevel);
        }

        /**
         * Returns the PlatformLogger.Level mapped from j.u.l.Level
         * set in the logger.  If the j.u.l.Logger is set to a custom Level,
         * this method will return the nearest Level.
         */
        Level getLevel() {
            Object javaLevel = LoggingSupport.getLevel(javaLogger);
            if (javaLevel == null) return null;

            try {
                return Level.valueOf(LoggingSupport.getLevelName(javaLevel));
            } catch (IllegalArgumentException e) {
                return Level.valueOf(LoggingSupport.getLevelValue(javaLevel));
            }
        }

        void setLevel(Level level) {
            LoggingSupport.setLevel(javaLogger, level == null ? null : level.javaLevel);
        }

        boolean isLoggable(Level level) {
            return LoggingSupport.isLoggable(javaLogger, level.javaLevel);
        }
    }
}

//LoggingSupport
class LoggingSupport {
    private LoggingSupport() { }

    private static final LoggingProxy proxy =
        AccessController.doPrivileged(new PrivilegedAction<LoggingProxy>() {
            public LoggingProxy run() {
                try {
                    // create a LoggingProxyImpl instance when
                    // java.util.logging classes exist
                    Class<?> c = Class.forName("java.util.logging.LoggingProxyImpl", true, null);
                    Field f = c.getDeclaredField("INSTANCE");
                    f.setAccessible(true);
                    return (LoggingProxy) f.get(null);
                } catch (ClassNotFoundException cnf) {
                    return null;
                } catch (NoSuchFieldException e) {
                    throw new AssertionError(e);
                } catch (IllegalAccessException e) {
                    throw new AssertionError(e);
                }
            }});

    /**
     * Returns true if java.util.logging support is available.
     */
    public static boolean isAvailable() {
        return proxy != null;
    }

    private static void ensureAvailable() {
        if (proxy == null)
            throw new AssertionError("Should not here");
    }

    public static java.util.List<String> getLoggerNames() {
        ensureAvailable();
        return proxy.getLoggerNames();
    }
    public static String getLoggerLevel(String loggerName) {
        ensureAvailable();
        return proxy.getLoggerLevel(loggerName);
    }

    public static void setLoggerLevel(String loggerName, String levelName) {
        ensureAvailable();
        proxy.setLoggerLevel(loggerName, levelName);
    }

    public static String getParentLoggerName(String loggerName) {
        ensureAvailable();
        return proxy.getParentLoggerName(loggerName);
    }

    public static Object getLogger(String name) {
        ensureAvailable();
        return proxy.getLogger(name);
    }

    public static Object getLevel(Object logger) {
        ensureAvailable();
        return proxy.getLevel(logger);
    }

    public static void setLevel(Object logger, Object newLevel) {
        ensureAvailable();
        proxy.setLevel(logger, newLevel);
    }

    public static boolean isLoggable(Object logger, Object level) {
        ensureAvailable();
        return proxy.isLoggable(logger,level);
    }

    public static void log(Object logger, Object level, String msg) {
        ensureAvailable();
        proxy.log(logger, level, msg);
    }

    public static void log(Object logger, Object level, String msg, Throwable t) {
        ensureAvailable();
        proxy.log(logger, level, msg, t);
    }

    public static void log(Object logger, Object level, String msg, Object... params) {
        ensureAvailable();
        proxy.log(logger, level, msg, params);
    }

    public static Object parseLevel(String levelName) {
        ensureAvailable();
        return proxy.parseLevel(levelName);
    }

    public static String getLevelName(Object level) {
        ensureAvailable();
        return proxy.getLevelName(level);
    }

    public static int getLevelValue(Object level) {
        ensureAvailable();
        return proxy.getLevelValue(level);
    }

    private static final String DEFAULT_FORMAT =
        "%1$tb %1$td, %1$tY %1$tl:%1$tM:%1$tS %1$Tp %2$s%n%4$s: %5$s%6$s%n";

    private static final String FORMAT_PROP_KEY = "java.util.logging.SimpleFormatter.format";
    public static String getSimpleFormat() {
        return getSimpleFormat(true);
    }

    // useProxy if true will cause initialization of
    // java.util.logging and read its configuration
    static String getSimpleFormat(boolean useProxy) {
        String format =
            AccessController.doPrivileged(
                new PrivilegedAction<String>() {
                    public String run() {
                        return System.getProperty(FORMAT_PROP_KEY);
                    }
                });

        if (useProxy && proxy != null && format == null) {
            format = proxy.getProperty(FORMAT_PROP_KEY);
        }

        if (format != null) {
            try {
                // validate the user-defined format string
                String.format(format, new Date(), "", "", "", "", "");
            } catch (IllegalArgumentException e) {
                // illegal syntax; fall back to the default format
                format = DEFAULT_FORMAT;
            }
        } else {
            format = DEFAULT_FORMAT;
        }
        return format;
    }

}

//LoggingProxy
interface LoggingProxy {
    // Methods to bridge java.util.logging.Logger methods
    public Object getLogger(String name);

    public Object getLevel(Object logger);

    public void setLevel(Object logger, Object newLevel);

    public boolean isLoggable(Object logger, Object level);

    public void log(Object logger, Object level, String msg);

    public void log(Object logger, Object level, String msg, Throwable t);

    public void log(Object logger, Object level, String msg, Object... params);

    // Methods to bridge java.util.logging.LoggingMXBean methods
    public java.util.List<String> getLoggerNames();

    public String getLoggerLevel(String loggerName);

    public void setLoggerLevel(String loggerName, String levelName);

    public String getParentLoggerName(String loggerName);

    // Methods to bridge Level.parse() and Level.getName() method
    public Object parseLevel(String levelName);

    public String getLevelName(Object level);

    public int getLevelValue(Object level);

    // return the logging property
    public String getProperty(String key);
}

//SharedSecrets.java
class SharedSecrets {
    private static final Unsafe unsafe = Unsafe.getUnsafe();
    private static JavaUtilJarAccess javaUtilJarAccess;
    private static JavaLangAccess javaLangAccess;
    private static JavaLangRefAccess javaLangRefAccess;
    private static JavaIOAccess javaIOAccess;
    private static JavaNetAccess javaNetAccess;
    private static JavaNetHttpCookieAccess javaNetHttpCookieAccess;
    private static JavaNioAccess javaNioAccess;
    private static JavaIOFileDescriptorAccess javaIOFileDescriptorAccess;
    private static JavaSecurityProtectionDomainAccess javaSecurityProtectionDomainAccess;
    private static JavaSecurityAccess javaSecurityAccess;
    private static JavaUtilZipFileAccess javaUtilZipFileAccess;
    private static JavaAWTAccess javaAWTAccess;
    private static JavaOISAccess javaOISAccess;
    private static JavaxCryptoSealedObjectAccess javaxCryptoSealedObjectAccess;
    private static JavaObjectInputStreamReadString javaObjectInputStreamReadString;
    private static JavaObjectInputStreamAccess javaObjectInputStreamAccess;
    private static JavaSecuritySignatureAccess javaSecuritySignatureAccess;

    public static JavaUtilJarAccess javaUtilJarAccess() {
        return javaUtilJarAccess;
    }

    public static void setJavaUtilJarAccess(JavaUtilJarAccess access) {
        javaUtilJarAccess = access;
    }

    public static void setJavaLangAccess(JavaLangAccess jla) {
        javaLangAccess = jla;
    }

    public static JavaLangAccess getJavaLangAccess() {
        return javaLangAccess;
    }

    public static void setJavaLangRefAccess(JavaLangRefAccess jlra) {
        javaLangRefAccess = jlra;
    }

    public static JavaLangRefAccess getJavaLangRefAccess() {
        return javaLangRefAccess;
    }

    public static void setJavaNetAccess(JavaNetAccess jna) {
        javaNetAccess = jna;
    }

    public static JavaNetAccess getJavaNetAccess() {
        return javaNetAccess;
    }

    public static void setJavaNetHttpCookieAccess(JavaNetHttpCookieAccess a) {
        javaNetHttpCookieAccess = a;
    }

    public static JavaNetHttpCookieAccess getJavaNetHttpCookieAccess() {
        return javaNetHttpCookieAccess;
    }

    public static void setJavaNioAccess(JavaNioAccess jna) {
        javaNioAccess = jna;
    }

    public static JavaNioAccess getJavaNioAccess() {
        return javaNioAccess;
    }

    public static void setJavaIOAccess(JavaIOAccess jia) {
        javaIOAccess = jia;
    }

    public static JavaIOAccess getJavaIOAccess() {
        return javaIOAccess;
    }

    public static void setJavaIOFileDescriptorAccess(JavaIOFileDescriptorAccess jiofda) {
        javaIOFileDescriptorAccess = jiofda;
    }

    public static JavaIOFileDescriptorAccess getJavaIOFileDescriptorAccess() {

        return javaIOFileDescriptorAccess;
    }

    public static void setJavaOISAccess(JavaOISAccess access) {
        javaOISAccess = access;
    }

    public static JavaOISAccess getJavaOISAccess() {

        return javaOISAccess;
    }


    public static void setJavaSecurityProtectionDomainAccess
        (JavaSecurityProtectionDomainAccess jspda) {
            javaSecurityProtectionDomainAccess = jspda;
    }

    public static JavaSecurityProtectionDomainAccess
        getJavaSecurityProtectionDomainAccess() {
            return javaSecurityProtectionDomainAccess;
    }

    public static void setJavaSecurityAccess(JavaSecurityAccess jsa) {
        javaSecurityAccess = jsa;
    }

    public static JavaSecurityAccess getJavaSecurityAccess() {
        return javaSecurityAccess;
    }

    public static JavaUtilZipFileAccess getJavaUtilZipFileAccess() {
        return javaUtilZipFileAccess;
    }

    public static void setJavaUtilZipFileAccess(JavaUtilZipFileAccess access) {
        javaUtilZipFileAccess = access;
    }

    public static void setJavaAWTAccess(JavaAWTAccess jaa) {
        javaAWTAccess = jaa;
    }

    public static JavaAWTAccess getJavaAWTAccess() {
        // this may return null in which case calling code needs to
        // provision for.
        if (javaAWTAccess == null) {
            return null;
        }
        return javaAWTAccess;
    }

    public static JavaObjectInputStreamReadString getJavaObjectInputStreamReadString() {
        return javaObjectInputStreamReadString;
    }

    public static void setJavaObjectInputStreamReadString(JavaObjectInputStreamReadString access) {
        javaObjectInputStreamReadString = access;
    }

    public static JavaObjectInputStreamAccess getJavaObjectInputStreamAccess() {
        return javaObjectInputStreamAccess;
    }

    public static void setJavaObjectInputStreamAccess(JavaObjectInputStreamAccess access) {
        javaObjectInputStreamAccess = access;
    }

    public static void setJavaSecuritySignatureAccess(JavaSecuritySignatureAccess jssa) {
        javaSecuritySignatureAccess = jssa;
    }

    public static JavaSecuritySignatureAccess getJavaSecuritySignatureAccess() {
        return javaSecuritySignatureAccess;
    }

    public static void setJavaxCryptoSealedObjectAccess(JavaxCryptoSealedObjectAccess jcsoa) {
        javaxCryptoSealedObjectAccess = jcsoa;
    }

    public static JavaxCryptoSealedObjectAccess getJavaxCryptoSealedObjectAccess() {
        return javaxCryptoSealedObjectAccess;
    }
}

//JavaSecuritySignatureAccess
interface JavaSecuritySignatureAccess {

    void initVerify(Signature s, PublicKey publicKey, AlgorithmParameterSpec params)
            throws InvalidKeyException, InvalidAlgorithmParameterException;

    void initVerify(Signature s, java.security.cert.Certificate certificate,
             AlgorithmParameterSpec params)
             throws InvalidKeyException, InvalidAlgorithmParameterException;

    void initSign(Signature s, PrivateKey privateKey,
             AlgorithmParameterSpec params, SecureRandom random)
             throws InvalidKeyException, InvalidAlgorithmParameterException;
}

//JavaxCryptoSealedObjectAccess
interface JavaxCryptoSealedObjectAccess {
    ObjectInputStream getExtObjectInputStream(
            SealedObject sealed, Cipher cipher)
            throws BadPaddingException, IllegalBlockSizeException, IOException;
}

//JavaLangAccess
interface JavaLangAccess {
    /** Return the constant pool for a class. */
    ConstantPool getConstantPool(Class<?> klass);

    /**
     * Compare-And-Swap the AnnotationType instance corresponding to this class.
     * (This method only applies to annotation types.)
     */
    boolean casAnnotationType(Class<?> klass, AnnotationType oldType, AnnotationType newType);

    /**
     * Get the AnnotationType instance corresponding to this class.
     * (This method only applies to annotation types.)
     */
    AnnotationType getAnnotationType(Class<?> klass);

    /**
     * Get the declared annotations for a given class, indexed by their types.
     */
    Map<Class<? extends Annotation>, Annotation> getDeclaredAnnotationMap(Class<?> klass);

    /**
     * Get the array of bytes that is the class-file representation
     * of this Class' annotations.
     */
    byte[] getRawClassAnnotations(Class<?> klass);

    /**
     * Get the array of bytes that is the class-file representation
     * of this Class' type annotations.
     */
    byte[] getRawClassTypeAnnotations(Class<?> klass);

    /**
     * Get the array of bytes that is the class-file representation
     * of this Executable's type annotations.
     */
    byte[] getRawExecutableTypeAnnotations(Executable executable);

    /**
     * Returns the elements of an enum class or null if the
     * Class object does not represent an enum type;
     * the result is uncloned, cached, and shared by all callers.
     */
    <E extends Enum<E>> E[] getEnumConstantsShared(Class<E> klass);

    /** Set thread's blocker field. */
    void blockedOn(Thread t, Interruptible b);

    /**
     * Registers a shutdown hook.
     *
     * It is expected that this method with registerShutdownInProgress=true
     * is only used to register DeleteOnExitHook since the first file
     * may be added to the delete on exit list by the application shutdown
     * hooks.
     *
     * @params slot  the slot in the shutdown hook array, whose element
     *               will be invoked in order during shutdown
     * @params registerShutdownInProgress true to allow the hook
     *               to be registered even if the shutdown is in progress.
     * @params hook  the hook to be registered
     *
     * @throw IllegalStateException if shutdown is in progress and
     *          the slot is not valid to register.
     */
    void registerShutdownHook(int slot, boolean registerShutdownInProgress, Runnable hook);

    /**
     * Returns the number of stack frames represented by the given throwable.
     */
    int getStackTraceDepth(Throwable t);

    /**
     * Returns the ith StackTraceElement for the given throwable.
     */
    StackTraceElement getStackTraceElement(Throwable t, int i);

    /**
     * Returns a new string backed by the provided character array. The
     * character array is not copied and must never be modified after the
     * String is created, in order to fulfill String's contract.
     *
     * @param chars the character array to back the string
     * @return a newly created string whose content is the character array
     */
    String newStringUnsafe(char[] chars);

    /**
     * Returns a new Thread with the given Runnable and an
     * inherited AccessControlContext.
     */
    Thread newThreadWithAcc(Runnable target, AccessControlContext acc);

    /**
     * Invokes the finalize method of the given object.
     */
    void invokeFinalize(Object o) throws Throwable;
}

//Interruptible
interface Interruptible {

    public void interrupt(Thread t);

}

//AnnotationType
class AnnotationType {
    /**
     * Member name -> type mapping. Note that primitive types
     * are represented by the class objects for the corresponding wrapper
     * types.  This matches the return value that must be used for a
     * dynamic proxy, allowing for a simple isInstance test.
     */
    private final Map<String, Class<?>> memberTypes;

    /**
     * Member name -> default value mapping.
     */
    private final Map<String, Object> memberDefaults;

    /**
     * Member name -> Method object mapping. This (and its assoicated
     * accessor) are used only to generate AnnotationTypeMismatchExceptions.
     */
    private final Map<String, Method> members;

    /**
     * The retention policy for this annotation type.
     */
    private final RetentionPolicy retention;

    /**
     * Whether this annotation type is inherited.
     */
    private final boolean inherited;

    /**
     * Returns an AnnotationType instance for the specified annotation type.
     *
     * @throw IllegalArgumentException if the specified class object for
     *     does not represent a valid annotation type
     */
    public static AnnotationType getInstance(
        Class<? extends Annotation> annotationClass)
    {
        JavaLangAccess jla = SharedSecrets.getJavaLangAccess();
        AnnotationType result = jla.getAnnotationType(annotationClass); // volatile read
        if (result == null) {
            result = new AnnotationType(annotationClass);
            // try to CAS the AnnotationType: null -> result
            if (!jla.casAnnotationType(annotationClass, null, result)) {
                // somebody was quicker -> read it's result
                result = jla.getAnnotationType(annotationClass);
                assert result != null;
            }
        }

        return result;
    }

    /**
     * Sole constructor.
     *
     * @param annotationClass the class object for the annotation type
     * @throw IllegalArgumentException if the specified class object for
     *     does not represent a valid annotation type
     */
    private AnnotationType(final Class<? extends Annotation> annotationClass) {
        if (!annotationClass.isAnnotation())
            throw new IllegalArgumentException("Not an annotation type");

        Method[] methods =
            AccessController.doPrivileged(new PrivilegedAction<Method[]>() {
                public Method[] run() {
                    // Initialize memberTypes and defaultValues
                    return annotationClass.getDeclaredMethods();
                }
            });

        memberTypes = new HashMap<String,Class<?>>(methods.length+1, 1.0f);
        memberDefaults = new HashMap<String, Object>(0);
        members = new HashMap<String, Method>(methods.length+1, 1.0f);

        for (Method method :  methods) {
            if (Modifier.isPublic(method.getModifiers()) &&
                Modifier.isAbstract(method.getModifiers()) &&
                !method.isSynthetic()) {
                if (method.getParameterTypes().length != 0) {
                    throw new IllegalArgumentException(method + " has params");
                }
                String name = method.getName();
                Class<?> type = method.getReturnType();
                memberTypes.put(name, invocationHandlerReturnType(type));
                members.put(name, method);

                Object defaultValue = method.getDefaultValue();
                if (defaultValue != null) {
                    memberDefaults.put(name, defaultValue);
                }
            }
        }

        // Initialize retention, & inherited fields.  Special treatment
        // of the corresponding annotation types breaks infinite recursion.
        if (annotationClass != Retention.class &&
            annotationClass != Inherited.class) {
            JavaLangAccess jla = SharedSecrets.getJavaLangAccess();
            Map<Class<? extends Annotation>, Annotation> metaAnnotations =
                AnnotationParser.parseSelectAnnotations(
                    jla.getRawClassAnnotations(annotationClass),
                    jla.getConstantPool(annotationClass),
                    annotationClass,
                    Retention.class, Inherited.class
                );
            Retention ret = (Retention) metaAnnotations.get(Retention.class);
            retention = (ret == null ? RetentionPolicy.CLASS : ret.value());
            inherited = metaAnnotations.containsKey(Inherited.class);
        }
        else {
            retention = RetentionPolicy.RUNTIME;
            inherited = false;
        }
    }

    /**
     * Returns the type that must be returned by the invocation handler
     * of a dynamic proxy in order to have the dynamic proxy return
     * the specified type (which is assumed to be a legal member type
     * for an annotation).
     */
    public static Class<?> invocationHandlerReturnType(Class<?> type) {
        // Translate primitives to wrappers
        if (type == byte.class)
            return Byte.class;
        if (type == char.class)
            return Character.class;
        if (type == double.class)
            return Double.class;
        if (type == float.class)
            return Float.class;
        if (type == int.class)
            return Integer.class;
        if (type == long.class)
            return Long.class;
        if (type == short.class)
            return Short.class;
        if (type == boolean.class)
            return Boolean.class;

        // Otherwise, just return declared type
        return type;
    }

    /**
     * Returns member types for this annotation type
     * (member name -> type mapping).
     */
    public Map<String, Class<?>> memberTypes() {
        return memberTypes;
    }

    /**
     * Returns members of this annotation type
     * (member name -> associated Method object mapping).
     */
    public Map<String, Method> members() {
        return members;
    }

    /**
     * Returns the default values for this annotation type
     * (Member name -> default value mapping).
     */
    public Map<String, Object> memberDefaults() {
        return memberDefaults;
    }

    /**
     * Returns the retention policy for this annotation type.
     */
    public RetentionPolicy retention() {
        return retention;
    }

    /**
     * Returns true if this this annotation type is inherited.
     */
    public boolean isInherited() {
        return inherited;
    }

    /**
     * For debugging.
     */
    public String toString() {
        return "Annotation Type:\n" +
               "   Member types: " + memberTypes + "\n" +
               "   Member defaults: " + memberDefaults + "\n" +
               "   Retention policy: " + retention + "\n" +
               "   Inherited: " + inherited;
    }
}

//AnnotationParser
class AnnotationParser {
    /**
     * Parses the annotations described by the specified byte array.
     * resolving constant references in the specified constant pool.
     * The array must contain an array of annotations as described
     * in the RuntimeVisibleAnnotations_attribute:
     *
     *   u2 num_annotations;
     *   annotation annotations[num_annotations];
     *
     * @throws AnnotationFormatError if an annotation is found to be
     *         malformed.
     */
    public static Map<Class<? extends Annotation>, Annotation> parseAnnotations(
                byte[] rawAnnotations,
                ConstantPool constPool,
                Class<?> container) {
        if (rawAnnotations == null)
            return Collections.emptyMap();

        try {
            return parseAnnotations2(rawAnnotations, constPool, container, null);
        } catch(BufferUnderflowException e) {
            throw new AnnotationFormatError("Unexpected end of annotations.");
        } catch(IllegalArgumentException e) {
            // Type mismatch in constant pool
            throw new AnnotationFormatError(e);
        }
    }

    /**
     * Like {@link #parseAnnotations(byte[], sun.reflect.ConstantPool, Class)}
     * with an additional parameter {@code selectAnnotationClasses} which selects the
     * annotation types to parse (other than selected are quickly skipped).<p>
     * This method is only used to parse select meta annotations in the construction
     * phase of {@link AnnotationType} instances to prevent infinite recursion.
     *
     * @param selectAnnotationClasses an array of annotation types to select when parsing
     */
    @SafeVarargs
    @SuppressWarnings("varargs") // selectAnnotationClasses is used safely
    static Map<Class<? extends Annotation>, Annotation> parseSelectAnnotations(
                byte[] rawAnnotations,
                ConstantPool constPool,
                Class<?> container,
                Class<? extends Annotation> ... selectAnnotationClasses) {
        if (rawAnnotations == null)
            return Collections.emptyMap();

        try {
            return parseAnnotations2(rawAnnotations, constPool, container, selectAnnotationClasses);
        } catch(BufferUnderflowException e) {
            throw new AnnotationFormatError("Unexpected end of annotations.");
        } catch(IllegalArgumentException e) {
            // Type mismatch in constant pool
            throw new AnnotationFormatError(e);
        }
    }

    private static Map<Class<? extends Annotation>, Annotation> parseAnnotations2(
                byte[] rawAnnotations,
                ConstantPool constPool,
                Class<?> container,
                Class<? extends Annotation>[] selectAnnotationClasses) {
        Map<Class<? extends Annotation>, Annotation> result =
            new LinkedHashMap<Class<? extends Annotation>, Annotation>();
        ByteBuffer buf = ByteBuffer.wrap(rawAnnotations);
        int numAnnotations = buf.getShort() & 0xFFFF;
        for (int i = 0; i < numAnnotations; i++) {
            Annotation a = parseAnnotation2(buf, constPool, container, false, selectAnnotationClasses);
            if (a != null) {
                Class<? extends Annotation> klass = a.annotationType();
                if (AnnotationType.getInstance(klass).retention() == RetentionPolicy.RUNTIME &&
                    result.put(klass, a) != null) {
                        throw new AnnotationFormatError(
                            "Duplicate annotation for class: "+klass+": " + a);
            }
        }
        }
        return result;
    }

    /**
     * Parses the parameter annotations described by the specified byte array.
     * resolving constant references in the specified constant pool.
     * The array must contain an array of annotations as described
     * in the RuntimeVisibleParameterAnnotations_attribute:
     *
     *    u1 num_parameters;
     *    {
     *        u2 num_annotations;
     *        annotation annotations[num_annotations];
     *    } parameter_annotations[num_parameters];
     *
     * Unlike parseAnnotations, rawAnnotations must not be null!
     * A null value must be handled by the caller.  This is so because
     * we cannot determine the number of parameters if rawAnnotations
     * is null.  Also, the caller should check that the number
     * of parameters indicated by the return value of this method
     * matches the actual number of method parameters.  A mismatch
     * indicates that an AnnotationFormatError should be thrown.
     *
     * @throws AnnotationFormatError if an annotation is found to be
     *         malformed.
     */
    public static Annotation[][] parseParameterAnnotations(
                    byte[] rawAnnotations,
                    ConstantPool constPool,
                    Class<?> container) {
        try {
            return parseParameterAnnotations2(rawAnnotations, constPool, container);
        } catch(BufferUnderflowException e) {
            throw new AnnotationFormatError(
                "Unexpected end of parameter annotations.");
        } catch(IllegalArgumentException e) {
            // Type mismatch in constant pool
            throw new AnnotationFormatError(e);
        }
    }

    private static Annotation[][] parseParameterAnnotations2(
                    byte[] rawAnnotations,
                    ConstantPool constPool,
                    Class<?> container) {
        ByteBuffer buf = ByteBuffer.wrap(rawAnnotations);
        int numParameters = buf.get() & 0xFF;
        Annotation[][] result = new Annotation[numParameters][];

        for (int i = 0; i < numParameters; i++) {
            int numAnnotations = buf.getShort() & 0xFFFF;
            List<Annotation> annotations =
                new ArrayList<Annotation>(numAnnotations);
            for (int j = 0; j < numAnnotations; j++) {
                Annotation a = parseAnnotation(buf, constPool, container, false);
                if (a != null) {
                    AnnotationType type = AnnotationType.getInstance(
                                              a.annotationType());
                    if (type.retention() == RetentionPolicy.RUNTIME)
                        annotations.add(a);
                }
            }
            result[i] = annotations.toArray(EMPTY_ANNOTATIONS_ARRAY);
        }
        return result;
    }

    private static final Annotation[] EMPTY_ANNOTATIONS_ARRAY =
                    new Annotation[0];

    /**
     * Parses the annotation at the current position in the specified
     * byte buffer, resolving constant references in the specified constant
     * pool.  The cursor of the byte buffer must point to an "annotation
     * structure" as described in the RuntimeVisibleAnnotations_attribute:
     *
     * annotation {
     *    u2    type_index;
     *       u2    num_member_value_pairs;
     *       {    u2    member_name_index;
     *             member_value value;
     *       }    member_value_pairs[num_member_value_pairs];
     *    }
     * }
     *
     * Returns the annotation, or null if the annotation's type cannot
     * be found by the VM, or is not a valid annotation type.
     *
     * @param exceptionOnMissingAnnotationClass if true, throw
     * TypeNotPresentException if a referenced annotation type is not
     * available at runtime
     */
    static Annotation parseAnnotation(ByteBuffer buf,
                                              ConstantPool constPool,
                                              Class<?> container,
                                              boolean exceptionOnMissingAnnotationClass) {
       return parseAnnotation2(buf, constPool, container, exceptionOnMissingAnnotationClass, null);
    }

    @SuppressWarnings("unchecked")
    private static Annotation parseAnnotation2(ByteBuffer buf,
                                              ConstantPool constPool,
                                              Class<?> container,
                                              boolean exceptionOnMissingAnnotationClass,
                                              Class<? extends Annotation>[] selectAnnotationClasses) {
        int typeIndex = buf.getShort() & 0xFFFF;
        Class<? extends Annotation> annotationClass = null;
        String sig = "[unknown]";
        try {
            try {
                sig = constPool.getUTF8At(typeIndex);
                annotationClass = (Class<? extends Annotation>)parseSig(sig, container);
            } catch (IllegalArgumentException ex) {
                // support obsolete early jsr175 format class files
                annotationClass = (Class<? extends Annotation>)constPool.getClassAt(typeIndex);
            }
        } catch (NoClassDefFoundError e) {
            if (exceptionOnMissingAnnotationClass)
                // note: at this point sig is "[unknown]" or VM-style
                // name instead of a binary name
                throw new TypeNotPresentException(sig, e);
            skipAnnotation(buf, false);
            return null;
        }
        catch (TypeNotPresentException e) {
            if (exceptionOnMissingAnnotationClass)
                throw e;
            skipAnnotation(buf, false);
            return null;
        }
        if (selectAnnotationClasses != null && !contains(selectAnnotationClasses, annotationClass)) {
            skipAnnotation(buf, false);
            return null;
        }
        AnnotationType type = null;
        try {
            type = AnnotationType.getInstance(annotationClass);
        } catch (IllegalArgumentException e) {
            skipAnnotation(buf, false);
            return null;
        }

        Map<String, Class<?>> memberTypes = type.memberTypes();
        Map<String, Object> memberValues =
            new LinkedHashMap<String, Object>(type.memberDefaults());

        int numMembers = buf.getShort() & 0xFFFF;
        for (int i = 0; i < numMembers; i++) {
            int memberNameIndex = buf.getShort() & 0xFFFF;
            String memberName = constPool.getUTF8At(memberNameIndex);
            Class<?> memberType = memberTypes.get(memberName);

            if (memberType == null) {
                // Member is no longer present in annotation type; ignore it
                skipMemberValue(buf);
            } else {
                Object value = parseMemberValue(memberType, buf, constPool, container);
                if (value instanceof AnnotationTypeMismatchExceptionProxy)
                    ((AnnotationTypeMismatchExceptionProxy) value).
                        setMember(type.members().get(memberName));
                memberValues.put(memberName, value);
            }
        }
        return annotationForMap(annotationClass, memberValues);
    }

    /**
     * Returns an annotation of the given type backed by the given
     * member -> value map.
     */
    public static Annotation annotationForMap(final Class<? extends Annotation> type,
                                              final Map<String, Object> memberValues)
    {
        return AccessController.doPrivileged(new PrivilegedAction<Annotation>() {
            public Annotation run() {
                return (Annotation) Proxy.newProxyInstance(
                    type.getClassLoader(), new Class<?>[] { type },
                    new AnnotationInvocationHandler(type, memberValues));
            }});
    }

    /**
     * Parses the annotation member value at the current position in the
     * specified byte buffer, resolving constant references in the specified
     * constant pool.  The cursor of the byte buffer must point to a
     * "member_value structure" as described in the
     * RuntimeVisibleAnnotations_attribute:
     *
     *  member_value {
     *    u1 tag;
     *    union {
     *       u2   const_value_index;
     *       {
     *           u2   type_name_index;
     *           u2   const_name_index;
     *       } enum_const_value;
     *       u2   class_info_index;
     *       annotation annotation_value;
     *       {
     *           u2    num_values;
     *           member_value values[num_values];
     *       } array_value;
     *    } value;
     * }
     *
     * The member must be of the indicated type. If it is not, this
     * method returns an AnnotationTypeMismatchExceptionProxy.
     */
    @SuppressWarnings("unchecked")
    public static Object parseMemberValue(Class<?> memberType,
                                          ByteBuffer buf,
                                          ConstantPool constPool,
                                          Class<?> container) {
        Object result = null;
        int tag = buf.get();
        switch(tag) {
          case 'e':
              return parseEnumValue((Class<? extends Enum<?>>)memberType, buf, constPool, container);
          case 'c':
              result = parseClassValue(buf, constPool, container);
              break;
          case '@':
              result = parseAnnotation(buf, constPool, container, true);
              break;
          case '[':
              return parseArray(memberType, buf, constPool, container);
          default:
              result = parseConst(tag, buf, constPool);
        }

        if (!(result instanceof ExceptionProxy) &&
            !memberType.isInstance(result))
            result = new AnnotationTypeMismatchExceptionProxy(
                result.getClass() + "[" + result + "]");
        return result;
    }

    /**
     * Parses the primitive or String annotation member value indicated by
     * the specified tag byte at the current position in the specified byte
     * buffer, resolving constant reference in the specified constant pool.
     * The cursor of the byte buffer must point to an annotation member value
     * of the type indicated by the specified tag, as described in the
     * RuntimeVisibleAnnotations_attribute:
     *
     *       u2   const_value_index;
     */
    private static Object parseConst(int tag,
                                     ByteBuffer buf, ConstantPool constPool) {
        int constIndex = buf.getShort() & 0xFFFF;
        switch(tag) {
          case 'B':
            return Byte.valueOf((byte) constPool.getIntAt(constIndex));
          case 'C':
            return Character.valueOf((char) constPool.getIntAt(constIndex));
          case 'D':
            return Double.valueOf(constPool.getDoubleAt(constIndex));
          case 'F':
            return Float.valueOf(constPool.getFloatAt(constIndex));
          case 'I':
            return Integer.valueOf(constPool.getIntAt(constIndex));
          case 'J':
            return Long.valueOf(constPool.getLongAt(constIndex));
          case 'S':
            return Short.valueOf((short) constPool.getIntAt(constIndex));
          case 'Z':
            return Boolean.valueOf(constPool.getIntAt(constIndex) != 0);
          case 's':
            return constPool.getUTF8At(constIndex);
          default:
            throw new AnnotationFormatError(
                "Invalid member-value tag in annotation: " + tag);
        }
    }

    /**
     * Parses the Class member value at the current position in the
     * specified byte buffer, resolving constant references in the specified
     * constant pool.  The cursor of the byte buffer must point to a "class
     * info index" as described in the RuntimeVisibleAnnotations_attribute:
     *
     *       u2   class_info_index;
     */
    private static Object parseClassValue(ByteBuffer buf,
                                          ConstantPool constPool,
                                          Class<?> container) {
        int classIndex = buf.getShort() & 0xFFFF;
        try {
            try {
                String sig = constPool.getUTF8At(classIndex);
                return parseSig(sig, container);
            } catch (IllegalArgumentException ex) {
                // support obsolete early jsr175 format class files
                return constPool.getClassAt(classIndex);
            }
        } catch (NoClassDefFoundError e) {
            return new TypeNotPresentExceptionProxy("[unknown]", e);
        }
        catch (TypeNotPresentException e) {
            return new TypeNotPresentExceptionProxy(e.typeName(), e.getCause());
        }
    }

    private static Class<?> parseSig(String sig, Class<?> container) {
        if (sig.equals("V")) return void.class;
        SignatureParser parser = SignatureParser.make();
        TypeSignature typeSig = parser.parseTypeSig(sig);
        GenericsFactory factory = CoreReflectionFactory.make(container, ClassScope.make(container));
        Reifier reify = Reifier.make(factory);
        typeSig.accept(reify);
        Type result = reify.getResult();
        return toClass(result);
    }
    static Class<?> toClass(Type o) {
        if (o instanceof GenericArrayType)
            return Array.newInstance(toClass(((GenericArrayType)o).getGenericComponentType()),
                                     0)
                .getClass();
        return (Class)o;
    }

    /**
     * Parses the enum constant member value at the current position in the
     * specified byte buffer, resolving constant references in the specified
     * constant pool.  The cursor of the byte buffer must point to a
     * "enum_const_value structure" as described in the
     * RuntimeVisibleAnnotations_attribute:
     *
     *       {
     *           u2   type_name_index;
     *           u2   const_name_index;
     *       } enum_const_value;
     */
    @SuppressWarnings({"rawtypes", "unchecked"})
    private static Object parseEnumValue(Class<? extends Enum> enumType, ByteBuffer buf,
                                         ConstantPool constPool,
                                         Class<?> container) {
        int typeNameIndex = buf.getShort() & 0xFFFF;
        String typeName  = constPool.getUTF8At(typeNameIndex);
        int constNameIndex = buf.getShort() & 0xFFFF;
        String constName = constPool.getUTF8At(constNameIndex);

        if (!typeName.endsWith(";")) {
            // support now-obsolete early jsr175-format class files.
            if (!enumType.getName().equals(typeName))
            return new AnnotationTypeMismatchExceptionProxy(
                typeName + "." + constName);
        } else if (enumType != parseSig(typeName, container)) {
            return new AnnotationTypeMismatchExceptionProxy(
                typeName + "." + constName);
        }

        try {
            return  Enum.valueOf(enumType, constName);
        } catch(IllegalArgumentException e) {
            return new EnumConstantNotPresentExceptionProxy(
                (Class<? extends Enum<?>>)enumType, constName);
        }
    }

    /**
     * Parses the array value at the current position in the specified byte
     * buffer, resolving constant references in the specified constant pool.
     * The cursor of the byte buffer must point to an array value struct
     * as specified in the RuntimeVisibleAnnotations_attribute:
     *
     *       {
     *           u2    num_values;
     *           member_value values[num_values];
     *       } array_value;
     *
     * If the array values do not match arrayType, an
     * AnnotationTypeMismatchExceptionProxy will be returned.
     */
    @SuppressWarnings("unchecked")
    private static Object parseArray(Class<?> arrayType,
                                     ByteBuffer buf,
                                     ConstantPool constPool,
                                     Class<?> container) {
        int length = buf.getShort() & 0xFFFF;  // Number of array components
        Class<?> componentType = arrayType.getComponentType();

        if (componentType == byte.class) {
            return parseByteArray(length, buf, constPool);
        } else if (componentType == char.class) {
            return parseCharArray(length, buf, constPool);
        } else if (componentType == double.class) {
            return parseDoubleArray(length, buf, constPool);
        } else if (componentType == float.class) {
            return parseFloatArray(length, buf, constPool);
        } else if (componentType == int.class) {
            return parseIntArray(length, buf, constPool);
        } else if (componentType == long.class) {
            return parseLongArray(length, buf, constPool);
        } else if (componentType == short.class) {
            return parseShortArray(length, buf, constPool);
        } else if (componentType == boolean.class) {
            return parseBooleanArray(length, buf, constPool);
        } else if (componentType == String.class) {
            return parseStringArray(length, buf, constPool);
        } else if (componentType == Class.class) {
            return parseClassArray(length, buf, constPool, container);
        } else if (componentType.isEnum()) {
            return parseEnumArray(length, (Class<? extends Enum<?>>)componentType, buf,
                                  constPool, container);
        } else {
            assert componentType.isAnnotation();
            return parseAnnotationArray(length, (Class <? extends Annotation>)componentType, buf,
                                        constPool, container);
        }
    }

    private static Object parseByteArray(int length,
                                  ByteBuffer buf, ConstantPool constPool) {
        byte[] result = new byte[length];
        boolean typeMismatch = false;
        int tag = 0;

        for (int i = 0; i < length; i++) {
            tag = buf.get();
            if (tag == 'B') {
                int index = buf.getShort() & 0xFFFF;
                result[i] = (byte) constPool.getIntAt(index);
            } else {
                skipMemberValue(tag, buf);
                typeMismatch = true;
            }
        }
        return typeMismatch ? exceptionProxy(tag) : result;
    }

    private static Object parseCharArray(int length,
                                  ByteBuffer buf, ConstantPool constPool) {
        char[] result = new char[length];
        boolean typeMismatch = false;
        byte tag = 0;

        for (int i = 0; i < length; i++) {
            tag = buf.get();
            if (tag == 'C') {
                int index = buf.getShort() & 0xFFFF;
                result[i] = (char) constPool.getIntAt(index);
            } else {
                skipMemberValue(tag, buf);
                typeMismatch = true;
            }
        }
        return typeMismatch ? exceptionProxy(tag) : result;
    }

    private static Object parseDoubleArray(int length,
                                    ByteBuffer buf, ConstantPool constPool) {
        double[] result = new  double[length];
        boolean typeMismatch = false;
        int tag = 0;

        for (int i = 0; i < length; i++) {
            tag = buf.get();
            if (tag == 'D') {
                int index = buf.getShort() & 0xFFFF;
                result[i] = constPool.getDoubleAt(index);
            } else {
                skipMemberValue(tag, buf);
                typeMismatch = true;
            }
        }
        return typeMismatch ? exceptionProxy(tag) : result;
    }

    private static Object parseFloatArray(int length,
                                   ByteBuffer buf, ConstantPool constPool) {
        float[] result = new float[length];
        boolean typeMismatch = false;
        int tag = 0;

        for (int i = 0; i < length; i++) {
            tag = buf.get();
            if (tag == 'F') {
                int index = buf.getShort() & 0xFFFF;
                result[i] = constPool.getFloatAt(index);
            } else {
                skipMemberValue(tag, buf);
                typeMismatch = true;
            }
        }
        return typeMismatch ? exceptionProxy(tag) : result;
    }

    private static Object parseIntArray(int length,
                                 ByteBuffer buf, ConstantPool constPool) {
        int[] result = new  int[length];
        boolean typeMismatch = false;
        int tag = 0;

        for (int i = 0; i < length; i++) {
            tag = buf.get();
            if (tag == 'I') {
                int index = buf.getShort() & 0xFFFF;
                result[i] = constPool.getIntAt(index);
            } else {
                skipMemberValue(tag, buf);
                typeMismatch = true;
            }
        }
        return typeMismatch ? exceptionProxy(tag) : result;
    }

    private static Object parseLongArray(int length,
                                  ByteBuffer buf, ConstantPool constPool) {
        long[] result = new long[length];
        boolean typeMismatch = false;
        int tag = 0;

        for (int i = 0; i < length; i++) {
            tag = buf.get();
            if (tag == 'J') {
                int index = buf.getShort() & 0xFFFF;
                result[i] = constPool.getLongAt(index);
            } else {
                skipMemberValue(tag, buf);
                typeMismatch = true;
            }
        }
        return typeMismatch ? exceptionProxy(tag) : result;
    }

    private static Object parseShortArray(int length,
                                   ByteBuffer buf, ConstantPool constPool) {
        short[] result = new short[length];
        boolean typeMismatch = false;
        int tag = 0;

        for (int i = 0; i < length; i++) {
            tag = buf.get();
            if (tag == 'S') {
                int index = buf.getShort() & 0xFFFF;
                result[i] = (short) constPool.getIntAt(index);
            } else {
                skipMemberValue(tag, buf);
                typeMismatch = true;
            }
        }
        return typeMismatch ? exceptionProxy(tag) : result;
    }

    private static Object parseBooleanArray(int length,
                                     ByteBuffer buf, ConstantPool constPool) {
        boolean[] result = new boolean[length];
        boolean typeMismatch = false;
        int tag = 0;

        for (int i = 0; i < length; i++) {
            tag = buf.get();
            if (tag == 'Z') {
                int index = buf.getShort() & 0xFFFF;
                result[i] = (constPool.getIntAt(index) != 0);
            } else {
                skipMemberValue(tag, buf);
                typeMismatch = true;
            }
        }
        return typeMismatch ? exceptionProxy(tag) : result;
    }

    private static Object parseStringArray(int length,
                                    ByteBuffer buf,  ConstantPool constPool) {
        String[] result = new String[length];
        boolean typeMismatch = false;
        int tag = 0;

        for (int i = 0; i < length; i++) {
            tag = buf.get();
            if (tag == 's') {
                int index = buf.getShort() & 0xFFFF;
                result[i] = constPool.getUTF8At(index);
            } else {
                skipMemberValue(tag, buf);
                typeMismatch = true;
            }
        }
        return typeMismatch ? exceptionProxy(tag) : result;
    }

    private static Object parseClassArray(int length,
                                          ByteBuffer buf,
                                          ConstantPool constPool,
                                          Class<?> container) {
        Object[] result = new Class<?>[length];
        boolean typeMismatch = false;
        int tag = 0;

        for (int i = 0; i < length; i++) {
            tag = buf.get();
            if (tag == 'c') {
                result[i] = parseClassValue(buf, constPool, container);
            } else {
                skipMemberValue(tag, buf);
                typeMismatch = true;
            }
        }
        return typeMismatch ? exceptionProxy(tag) : result;
    }

    private static Object parseEnumArray(int length, Class<? extends Enum<?>> enumType,
                                         ByteBuffer buf,
                                         ConstantPool constPool,
                                         Class<?> container) {
        Object[] result = (Object[]) Array.newInstance(enumType, length);
        boolean typeMismatch = false;
        int tag = 0;

        for (int i = 0; i < length; i++) {
            tag = buf.get();
            if (tag == 'e') {
                result[i] = parseEnumValue(enumType, buf, constPool, container);
            } else {
                skipMemberValue(tag, buf);
                typeMismatch = true;
            }
        }
        return typeMismatch ? exceptionProxy(tag) : result;
    }

    private static Object parseAnnotationArray(int length,
                                               Class<? extends Annotation> annotationType,
                                               ByteBuffer buf,
                                               ConstantPool constPool,
                                               Class<?> container) {
        Object[] result = (Object[]) Array.newInstance(annotationType, length);
        boolean typeMismatch = false;
        int tag = 0;

        for (int i = 0; i < length; i++) {
            tag = buf.get();
            if (tag == '@') {
                result[i] = parseAnnotation(buf, constPool, container, true);
            } else {
                skipMemberValue(tag, buf);
                typeMismatch = true;
            }
        }
        return typeMismatch ? exceptionProxy(tag) : result;
    }

    /**
     * Return an appropriate exception proxy for a mismatching array
     * annotation where the erroneous array has the specified tag.
     */
    private static ExceptionProxy exceptionProxy(int tag) {
        return new AnnotationTypeMismatchExceptionProxy(
            "Array with component tag: " + tag);
    }

    /**
     * Skips the annotation at the current position in the specified
     * byte buffer.  The cursor of the byte buffer must point to
     * an "annotation structure" OR two bytes into an annotation
     * structure (i.e., after the type index).
     *
     * @parameter complete true if the byte buffer points to the beginning
     *     of an annotation structure (rather than two bytes in).
     */
    private static void skipAnnotation(ByteBuffer buf, boolean complete) {
        if (complete)
            buf.getShort();   // Skip type index
        int numMembers = buf.getShort() & 0xFFFF;
        for (int i = 0; i < numMembers; i++) {
            buf.getShort();   // Skip memberNameIndex
            skipMemberValue(buf);
        }
    }

    /**
     * Skips the annotation member value at the current position in the
     * specified byte buffer.  The cursor of the byte buffer must point to a
     * "member_value structure."
     */
    private static void skipMemberValue(ByteBuffer buf) {
        int tag = buf.get();
        skipMemberValue(tag, buf);
    }

    /**
     * Skips the annotation member value at the current position in the
     * specified byte buffer.  The cursor of the byte buffer must point
     * immediately after the tag in a "member_value structure."
     */
    private static void skipMemberValue(int tag, ByteBuffer buf) {
        switch(tag) {
          case 'e': // Enum value
            buf.getInt();  // (Two shorts, actually.)
            break;
          case '@':
            skipAnnotation(buf, true);
            break;
          case '[':
            skipArray(buf);
            break;
          default:
            // Class, primitive, or String
            buf.getShort();
        }
    }

    /**
     * Skips the array value at the current position in the specified byte
     * buffer.  The cursor of the byte buffer must point to an array value
     * struct.
     */
    private static void skipArray(ByteBuffer buf) {
        int length = buf.getShort() & 0xFFFF;
        for (int i = 0; i < length; i++)
            skipMemberValue(buf);
    }

    /**
     * Searches for given {@code element} in given {@code array} by identity.
     * Returns {@code true} if found {@code false} if not.
     */
    private static boolean contains(Object[] array, Object element) {
        for (Object e : array)
            if (e == element)
                return true;
        return false;
    }

    /*
     * This method converts the annotation map returned by the parseAnnotations()
     * method to an array.  It is called by Field.getDeclaredAnnotations(),
     * Method.getDeclaredAnnotations(), and Constructor.getDeclaredAnnotations().
     * This avoids the reflection classes to load the Annotation class until
     * it is needed.
     */
    private static final Annotation[] EMPTY_ANNOTATION_ARRAY = new Annotation[0];
    public static Annotation[] toArray(Map<Class<? extends Annotation>, Annotation> annotations) {
        return annotations.values().toArray(EMPTY_ANNOTATION_ARRAY);
    }

    static Annotation[] getEmptyAnnotationArray() { return EMPTY_ANNOTATION_ARRAY; }
}

//AnnotationTypeMismatchExceptionProxy
class AnnotationTypeMismatchExceptionProxy extends ExceptionProxy {
    private static final long serialVersionUID = 7844069490309503934L;
    private Method member;
    private String foundType;

    /**
     * It turns out to be convenient to construct these proxies in
     * two stages.  Since this is a private implementation class, we
     * permit ourselves this liberty even though it's normally a very
     * bad idea.
     */
    AnnotationTypeMismatchExceptionProxy(String foundType) {
        this.foundType = foundType;
    }

    AnnotationTypeMismatchExceptionProxy setMember(Method member) {
        this.member = member;
        return this;
    }

    protected RuntimeException generateException() {
        return new AnnotationTypeMismatchException(member, foundType);
    }
}

//EnumConstantNotPresetnExceptionProxy
class EnumConstantNotPresentExceptionProxy extends ExceptionProxy {
    private static final long serialVersionUID = -604662101303187330L;
    Class<? extends Enum<?>> enumType;
    String constName;

    public EnumConstantNotPresentExceptionProxy(Class<? extends Enum<?>> enumType,
                                                String constName) {
        this.enumType = enumType;
        this.constName = constName;
    }

    protected RuntimeException generateException() {
        return new EnumConstantNotPresentException(enumType, constName);
    }
}

//Reifier
class Reifier implements TypeTreeVisitor<Type> {
    private Type resultType;
    private GenericsFactory factory;

    private Reifier(GenericsFactory f){
        factory = f;
    }

    private GenericsFactory getFactory(){ return factory;}

    /**
     * Factory method. The resulting visitor will convert an AST
     * representing generic signatures into corresponding reflective
     * objects, using the provided factory, <tt>f</tt>.
     * @param f - a factory that can be used to manufacture reflective
     * objects returned by this visitor
     * @return A visitor that can be used to reify ASTs representing
     * generic type information into reflective objects
     */
    public static Reifier make(GenericsFactory f){
        return new Reifier(f);
    }

    // Helper method. Visits an array of TypeArgument and produces
    // reified Type array.
    private Type[] reifyTypeArguments(TypeArgument[] tas) {
        Type[] ts = new Type[tas.length];
        for (int i = 0; i < tas.length; i++) {
            tas[i].accept(this);
            ts[i] = resultType;
        }
        return ts;
    }


    /**
     * Accessor for the result of the last visit by this visitor,
     * @return The type computed by this visitor based on its last
     * visit
     */
    public Type getResult() { assert resultType != null;return resultType;}

    public void visitFormalTypeParameter(FormalTypeParameter ftp){}


    public void visitClassTypeSignature(ClassTypeSignature ct){}

    public void visitArrayTypeSignature(ArrayTypeSignature a){}

    public void visitTypeVariableSignature(TypeVariableSignature tv){
        resultType = getFactory().findTypeVariable(tv.getIdentifier());
    }

    public void visitWildcard(Wildcard w){
        resultType = getFactory().makeWildcard(w.getUpperBounds(),
                                               w.getLowerBounds());
    }

    public void visitSimpleClassTypeSignature(SimpleClassTypeSignature sct){
        resultType = getFactory().makeNamedType(sct.getName());
    }

    public void visitBottomSignature(BottomSignature b){

    }

    public void visitByteSignature(ByteSignature b){
        resultType = getFactory().makeByte();
    }

    public void visitBooleanSignature(BooleanSignature b){
        resultType = getFactory().makeBool();
    }

    public void visitShortSignature(ShortSignature s){
        resultType = getFactory().makeShort();
    }

    public void visitCharSignature(CharSignature c){
        resultType = getFactory().makeChar();
    }

    public void visitIntSignature(IntSignature i){
        resultType = getFactory().makeInt();
    }

    public void visitLongSignature(LongSignature l){
        resultType = getFactory().makeLong();
    }

    public void visitFloatSignature(FloatSignature f){
        resultType = getFactory().makeFloat();
    }

    public void visitDoubleSignature(DoubleSignature d){
        resultType = getFactory().makeDouble();
    }

    public void visitVoidDescriptor(VoidDescriptor v){
        resultType = getFactory().makeVoid();
    }


}

//VoidDescriptor
class VoidDescriptor implements ReturnType {
    private static final VoidDescriptor singleton = new VoidDescriptor();

    private VoidDescriptor(){}

    public static VoidDescriptor make() {return singleton;}



    public void accept(TypeTreeVisitor<?> v){v.visitVoidDescriptor(this);}
}


//ReturnType
interface ReturnType extends TypeTree{}

//TypeTree
interface TypeTree extends Tree {
    /**
     * Accept method for the visitor pattern.
     * @param v - a <tt>TypeTreeVisitor</tt> that will process this
     * tree
     */
    void accept(TypeTreeVisitor<?> v);
}

//Tree
interface Tree{}

//SimpleClassTypeSignature
class SimpleClassTypeSignature implements FieldTypeSignature {
    private final boolean dollar;
    private final String name;
    private final TypeArgument[] typeArgs;

    private SimpleClassTypeSignature(String n, boolean dollar, TypeArgument[] tas) {
        name = n;
        this.dollar = dollar;
        typeArgs = tas;
    }

    public static SimpleClassTypeSignature make(String n,
                                                boolean dollar,
                                                TypeArgument[] tas){
        return new SimpleClassTypeSignature(n, dollar, tas);
    }

    /*
     * Should a '$' be used instead of '.' to separate this component
     * of the name from the previous one when composing a string to
     * pass to Class.forName; in other words, is this a transition to
     * a nested class.
     */
    public boolean getDollar(){return dollar;}
    public String getName(){return name;}
    public TypeArgument[] getTypeArguments(){return typeArgs;}

    public void accept(TypeTreeVisitor<?> v){
        v.visitSimpleClassTypeSignature(this);
    }
}

interface FieldTypeSignature
    extends BaseType, TypeSignature, TypeArgument {}

interface BaseType extends TypeSignature{}

interface TypeSignature extends ReturnType {}

interface TypeArgument extends TypeTree {}

class CoreReflectionFactory implements GenericsFactory {
    private final GenericDeclaration decl;
    private final Scope scope;

    private CoreReflectionFactory(GenericDeclaration d, Scope s) {
        decl = d;
        scope = s;
    }

    private GenericDeclaration getDecl(){ return decl;}

    private Scope getScope(){ return scope;}


    private ClassLoader getDeclsLoader() {
        if (decl instanceof Class) {return ((Class) decl).getClassLoader();}
        if (decl instanceof Method) {
            return ((Method) decl).getDeclaringClass().getClassLoader();
        }
        assert decl instanceof Constructor : "Constructor expected";
        return ((Constructor) decl).getDeclaringClass().getClassLoader();

    }

    /**
     * Factory for this class. Returns an instance of
     * <tt>CoreReflectionFactory</tt> for the declaration and scope
     * provided.
     * This factory will produce reflective objects of the appropriate
     * kind. Classes produced will be those that would be loaded by the
     * defining class loader of the declaration <tt>d</tt> (if <tt>d</tt>
     * is a type declaration, or by the defining loader of the declaring
     * class of <tt>d</tt>  otherwise.
     * <p> Type variables will be created or lookup as necessary in the
     * scope <tt> s</tt>.
     * @param d - the generic declaration (class, interface, method or
     * constructor) that thsi factory services
     * @param s  the scope in which the factory will allocate and search for
     * type variables
     * @return an instance of <tt>CoreReflectionFactory</tt>
     */
    public static CoreReflectionFactory make(GenericDeclaration d, Scope s) {
        return new CoreReflectionFactory(d, s);
    }

    public TypeVariable<?> makeTypeVariable(String name,
                                            FieldTypeSignature[] bounds){
        return null;
    }

    public WildcardType makeWildcard(FieldTypeSignature[] ubs,
                                     FieldTypeSignature[] lbs) {
        return null;
    }

    public ParameterizedType makeParameterizedType(Type declaration,
                                                   Type[] typeArgs,
                                                   Type owner) {
        return ParameterizedTypeImpl.make((Class<?>) declaration,
                                          typeArgs, owner);
    }

    public TypeVariable<?> findTypeVariable(String name){
        return getScope().lookup(name);
    }

    public Type makeNamedType(String name){
        try {return Class.forName(name, false, // don't initialize
                                  getDeclsLoader());}
        catch (ClassNotFoundException c) {
            throw new TypeNotPresentException(name, c);
        }
    }

    public Type makeArrayType(Type componentType){
        if (componentType instanceof Class<?>)
            return Array.newInstance((Class<?>) componentType, 0).getClass();
        else
            return GenericArrayTypeImpl.make(componentType);
    }

    public Type makeByte(){return byte.class;}
    public Type makeBool(){return boolean.class;}
    public Type makeShort(){return short.class;}
    public Type makeChar(){return char.class;}
    public Type makeInt(){return int.class;}
    public Type makeLong(){return long.class;}
    public Type makeFloat(){return float.class;}
    public Type makeDouble(){return double.class;}

    public Type makeVoid(){return void.class;}
}

interface GenericsFactory {
    /**
     * Returns a new type variable declaration. Note that <tt>name</tt>
     * may be empty (but not <tt>null</tt>). If <tt>bounds</tt> is
     * empty, a bound of <tt>java.lang.Object</tt> is used.
     * @param name The name of the type variable
     * @param bounds An array of abstract syntax trees representing
     * the upper bound(s) on the type variable being declared
     * @return a new type variable declaration
     * @throws NullPointerException - if any of the actual parameters
     * or any of the elements of <tt>bounds</tt> are <tt>null</tt>.
     */
    TypeVariable<?> makeTypeVariable(String name,
                                     FieldTypeSignature[] bounds);
    /**
     * Return an instance of the <tt>ParameterizedType</tt> interface
     * that corresponds to a generic type instantiation of the
     * generic declaration <tt>declaration</tt> with actual type arguments
     * <tt>typeArgs</tt>.
     * If <tt>owner</tt> is <tt>null</tt>, the declaring class of
     * <tt>declaration</tt> is used as the owner of this parameterized
     * type.
     * <p> This method throws a MalformedParameterizedTypeException
     * under the following circumstances:
     * If the type declaration does not represent a generic declaration
     * (i.e., it is not an instance of <tt>GenericDeclaration</tt>).
     * If the number of actual type arguments (i.e., the size of the
     * array <tt>typeArgs</tt>) does not correspond to the number of
     * formal type arguments.
     * If any of the actual type arguments is not an instance of the
     * bounds on the corresponding formal.
     * @param declaration - the generic type declaration that is to be
     * instantiated
     * @param typeArgs - the list of actual type arguments
     * @return - a parameterized type representing the instantiation
     * of the declaration with the actual type arguments
     * @throws MalformedParameterizedTypeException - if the instantiation
     * is invalid
     * @throws NullPointerException - if any of <tt>declaration</tt>
     * , <tt>typeArgs</tt>
     * or any of the elements of <tt>typeArgs</tt> are <tt>null</tt>
     */
    ParameterizedType makeParameterizedType(Type declaration,
                                            Type[] typeArgs,
                                            Type owner);

    /**
     * Returns the type variable with name <tt>name</tt>, if such
     * a type variable is declared in the
     * scope used to create this factory.
     * Returns <tt>null</tt> otherwise.
     * @param name - the name of the type variable to search for
     * @return - the type variable with name <tt>name</tt>, or <tt>null</tt>
     * @throws  NullPointerException - if any of actual parameters are
     * <tt>null</tt>
     */
    TypeVariable<?> findTypeVariable(String name);

    /**
     * Returns a new wildcard type variable. If
     * <tt>ubs</tt> is empty, a bound of <tt>java.lang.Object</tt> is used.
     * @param ubs An array of abstract syntax trees representing
     * the upper bound(s) on the type variable being declared
     * @param lbs An array of abstract syntax trees representing
     * the lower bound(s) on the type variable being declared
     * @return a new wildcard type variable
     * @throws NullPointerException - if any of the actual parameters
     * or any of the elements of <tt>ubs</tt> or <tt>lbs</tt>are
     * <tt>null</tt>
     */
    WildcardType makeWildcard(FieldTypeSignature[] ubs,
                              FieldTypeSignature[] lbs);

    Type makeNamedType(String name);

    /**
     * Returns a (possibly generic) array type.
     * If the component type is a parameterized type, it must
     * only have unbounded wildcard arguemnts, otherwise
     * a MalformedParameterizedTypeException is thrown.
     * @param componentType - the component type of the array
     * @return a (possibly generic) array type.
     * @throws MalformedParameterizedTypeException if <tt>componentType</tt>
     * is a parameterized type with non-wildcard type arguments
     * @throws NullPointerException - if any of the actual parameters
     * are <tt>null</tt>
     */
    Type makeArrayType(Type componentType);

    /**
     * Returns the reflective representation of type <tt>byte</tt>.
     * @return the reflective representation of type <tt>byte</tt>.
     */
    Type makeByte();

    /**
     * Returns the reflective representation of type <tt>boolean</tt>.
     * @return the reflective representation of type <tt>boolean</tt>.
     */
    Type makeBool();

    /**
     * Returns the reflective representation of type <tt>short</tt>.
     * @return the reflective representation of type <tt>short</tt>.
     */
    Type makeShort();

    /**
     * Returns the reflective representation of type <tt>char</tt>.
     * @return the reflective representation of type <tt>char</tt>.
     */
    Type makeChar();

    /**
     * Returns the reflective representation of type <tt>int</tt>.
     * @return the reflective representation of type <tt>int</tt>.
     */
    Type makeInt();

    /**
     * Returns the reflective representation of type <tt>long</tt>.
     * @return the reflective representation of type <tt>long</tt>.
     */
    Type makeLong();

    /**
     * Returns the reflective representation of type <tt>float</tt>.
     * @return the reflective representation of type <tt>float</tt>.
     */
    Type makeFloat();

    /**
     * Returns the reflective representation of type <tt>double</tt>.
     * @return the reflective representation of type <tt>double</tt>.
     */
    Type makeDouble();

    /**
     * Returns the reflective representation of <tt>void</tt>.
     * @return the reflective representation of <tt>void</tt>.
     */
    Type makeVoid();
}

class SignatureParser {
    // The input is conceptually a character stream (though currently it's
    // a string). This is slightly different than traditional parsers,
    // because there is no lexical scanner performing tokenization.
    // Having a separate tokenizer does not fit with the nature of the
    // input format.
    // Other than the absence of a tokenizer, this parser is a classic
    // recursive descent parser. Its structure corresponds as closely
    // as possible to the grammar in the JVMS.
    //
    // A note on asserts vs. errors: The code contains assertions
    // in situations that should never occur. An assertion failure
    // indicates a failure of the parser logic. A common pattern
    // is an assertion that the current input is a particular
    // character. This is often paired with a separate check
    // that this is the case, which seems redundant. For example:
    //
    // assert(current() != x);
    // if (current != x {error("expected an x");
    //
    // where x is some character constant.
    // The assertion indicates, that, as currently written,
    // the code should never reach this point unless the input is an
    // x. On the other hand, the test is there to check the legality
    // of the input wrt to a given production. It may be that at a later
    // time the code might be called directly, and if the input is
    // invalid, the parser should flag an error in accordance
    // with its logic.

    private String input; // the input signature
    private int index;    // index into the input
    private int mark;     // index of mark
    // used to mark end of input
    private static final char EOI = ':';
    private static final boolean DEBUG = false;

    // private constructor - enforces use of static factory
    private SignatureParser(){}

    // prepares parser for new parsing session
    private void init(String s) {
        input = s;
        mark = index = 0;
    }

    // Utility methods.

    // Most parsing routines use the following routines to access the
    // input stream, and advance it as necessary.
    // This makes it easy to adapt the parser to operate on streams
    // of various kinds as well as strings.

    // returns current element of the input
    private char current(){
        assert(index <= input.length());
        return index < input.length() ? input.charAt(index) : EOI;
    }

    // advance the input
    private void advance(){
        assert(index <= input.length());
        if (index < input.length()) index++;
    }

    // mark current position
    private void mark() {
        mark = index;
    }

    // For debugging, prints current character to the end of the input.
    private String remainder() {
        return input.substring(index);
    }

    // returns a substring of input from mark (inclusive)
    // to current position (exclusive)
    private String markToCurrent() {
        return input.substring(mark, index);
    }

    // Error handling routine. Encapsulates error handling.
    // Takes a string error message as argument.
    // Currently throws a GenericSignatureFormatError.

    private Error error(String errorMsg) {
        return new GenericSignatureFormatError("Signature Parse error: " + errorMsg +
                                               "\n\tRemaining input: " + remainder());
    }

    /**
     * Verify the parse has made forward progress; throw an exception
     * if no progress.
     */
    private void progress(int startingPosition) {
        if (index <= startingPosition)
            throw error("Failure to make progress!");
    }

    /**
     * Static factory method. Produces a parser instance.
     * @return an instance of <tt>SignatureParser</tt>
     */
    public static SignatureParser make() {
        return new SignatureParser();
    }

    /**
     * Parses a class signature (as defined in the JVMS, chapter 4)
     * and produces an abstract syntax tree representing it.
     * @param s a string representing the input class signature
     * @return An abstract syntax tree for a class signature
     * corresponding to the input string
     * @throws GenericSignatureFormatError if the input is not a valid
     * class signature
     */
    public ClassSignature parseClassSig(String s) {
        if (DEBUG) System.out.println("Parsing class sig:" + s);
        init(s);
        return parseClassSignature();
    }

    /**
     * Parses a method signature (as defined in the JVMS, chapter 4)
     * and produces an abstract syntax tree representing it.
     * @param s a string representing the input method signature
     * @return An abstract syntax tree for a method signature
     * corresponding to the input string
     * @throws GenericSignatureFormatError if the input is not a valid
     * method signature
     */
    public MethodTypeSignature parseMethodSig(String s) {
        if (DEBUG) System.out.println("Parsing method sig:" + s);
        init(s);
        return parseMethodTypeSignature();
    }


    /**
     * Parses a type signature
     * and produces an abstract syntax tree representing it.
     *
     * @param s a string representing the input type signature
     * @return An abstract syntax tree for a type signature
     * corresponding to the input string
     * @throws GenericSignatureFormatError if the input is not a valid
     * type signature
     */
    public TypeSignature parseTypeSig(String s) {
        if (DEBUG) System.out.println("Parsing type sig:" + s);
        init(s);
        return parseTypeSignature();
    }

    // Parsing routines.
    // As a rule, the parsing routines access the input using the
    // utilities current() and advance().
    // The convention is that when a parsing routine is invoked
    // it expects the current input to be the first character it should parse
    // and when it completes parsing, it leaves the input at the first
    // character after the input parses.

    /*
     * Note on grammar conventions: a trailing "*" matches zero or
     * more occurrences, a trailing "+" matches one or more occurrences,
     * "_opt" indicates an optional component.
     */

    /**
     * ClassSignature:
     *     FormalTypeParameters_opt SuperclassSignature SuperinterfaceSignature*
     */
    private ClassSignature parseClassSignature() {
        // parse a class signature based on the implicit input.
        assert(index == 0);
        return ClassSignature.make(parseZeroOrMoreFormalTypeParameters(),
                                   parseClassTypeSignature(), // Only rule for SuperclassSignature
                                   parseSuperInterfaces());
    }

    private FormalTypeParameter[] parseZeroOrMoreFormalTypeParameters(){
        if (current() == '<') {
            return parseFormalTypeParameters();
        } else {
            return new FormalTypeParameter[0];
        }
    }

    /**
     * FormalTypeParameters:
     *     "<" FormalTypeParameter+ ">"
     */
    private FormalTypeParameter[] parseFormalTypeParameters(){
        List<FormalTypeParameter> ftps =  new ArrayList<>(3);
        assert(current() == '<'); // should not have been called at all
        if (current() != '<') { throw error("expected '<'");}
        advance();
        ftps.add(parseFormalTypeParameter());
        while (current() != '>') {
            int startingPosition = index;
            ftps.add(parseFormalTypeParameter());
            progress(startingPosition);
        }
        advance();
        return ftps.toArray(new FormalTypeParameter[ftps.size()]);
    }

    /**
     * FormalTypeParameter:
     *     Identifier ClassBound InterfaceBound*
     */
    private FormalTypeParameter parseFormalTypeParameter(){
        String id = parseIdentifier();
        FieldTypeSignature[] bs = parseBounds();
        return null;
    }

    private String parseIdentifier() {
        mark();
        skipIdentifier();
        return markToCurrent();
    }

    private void skipIdentifier() {
        char c = current();
        while (c != ';' && c != '.' && c != '/' &&
               c != '[' && c != ':' && c != '>' &&
               c != '<' && !Character.isWhitespace(c)) {
            advance();
            c = current();
        }
    }

    /**
     * FieldTypeSignature:
     *     ClassTypeSignature
     *     ArrayTypeSignature
     *     TypeVariableSignature
     */
    private FieldTypeSignature parseFieldTypeSignature() {
        return parseFieldTypeSignature(true);
    }

    private FieldTypeSignature parseFieldTypeSignature(boolean allowArrays) {
        switch(current()) {
        case 'L':
           return null;
        case 'T':
            return parseTypeVariableSignature();
        case '[':
            throw error("Array signature not allowed here.");
        default: throw error("Expected Field Type Signature");
        }
    }

    /**
     * ClassTypeSignature:
     *     "L" PackageSpecifier_opt SimpleClassTypeSignature ClassTypeSignatureSuffix* ";"
     */
    private ClassTypeSignature parseClassTypeSignature(){
        assert(current() == 'L');
        if (current() != 'L') { throw error("expected a class type");}
        advance();
        List<SimpleClassTypeSignature> scts = new ArrayList<>(5);
        scts.add(parsePackageNameAndSimpleClassTypeSignature());

        parseClassTypeSignatureSuffix(scts);
        if (current() != ';')
            throw error("expected ';' got '" + current() + "'");

        advance();
        return null;
    }

    /**
     * PackageSpecifier:
     *     Identifier "/" PackageSpecifier*
     */
    private SimpleClassTypeSignature parsePackageNameAndSimpleClassTypeSignature() {
        // Parse both any optional leading PackageSpecifier as well as
        // the following SimpleClassTypeSignature.

        mark();
        skipIdentifier();
        while (current() == '/') {
            advance();
            skipIdentifier();
        }
        String id = markToCurrent().replace('/', '.');

        switch (current()) {
        case ';':
            return SimpleClassTypeSignature.make(id, false, new TypeArgument[0]); // all done!
        case '<':
            if (DEBUG) System.out.println("\t remainder: " + remainder());
            return SimpleClassTypeSignature.make(id, false, parseTypeArguments());
        default:
            throw error("expected '<' or ';' but got " + current());
        }
    }

    /**
     * SimpleClassTypeSignature:
     *     Identifier TypeArguments_opt
     */
    private SimpleClassTypeSignature parseSimpleClassTypeSignature(boolean dollar){
        String id = parseIdentifier();
        char c = current();

        switch (c) {
        case ';':
        case '.':
            return SimpleClassTypeSignature.make(id, dollar, new TypeArgument[0]) ;
        case '<':
            return SimpleClassTypeSignature.make(id, dollar, parseTypeArguments());
        default:
            throw error("expected '<' or ';' or '.', got '" + c + "'.");
        }
    }

    /**
     * ClassTypeSignatureSuffix:
     *     "." SimpleClassTypeSignature
     */
    private void parseClassTypeSignatureSuffix(List<SimpleClassTypeSignature> scts) {
        while (current() == '.') {
            advance();
            scts.add(parseSimpleClassTypeSignature(true));
        }
    }

    /**
     * TypeArguments:
     *     "<" TypeArgument+ ">"
     */
    private TypeArgument[] parseTypeArguments() {
        List<TypeArgument> tas = new ArrayList<>(3);
        assert(current() == '<');
        if (current() != '<') { throw error("expected '<'");}
        advance();
        tas.add(parseTypeArgument());
        while (current() != '>') {
                //(matches(current(),  '+', '-', 'L', '[', 'T', '*')) {
            tas.add(parseTypeArgument());
        }
        advance();
        return tas.toArray(new TypeArgument[tas.size()]);
    }

    /**
     * TypeArgument:
     *     WildcardIndicator_opt FieldTypeSignature
     *     "*"
     */
    private TypeArgument parseTypeArgument() {
        FieldTypeSignature[] ub, lb;
        ub = new FieldTypeSignature[1];
        lb = new FieldTypeSignature[1];
        TypeArgument[] ta = new TypeArgument[0];
        char c = current();
        switch (c) {
        case '+': {
            advance();
            return null;
        }
        case '*':{
            advance();
            return null;
        }
        case '-': {
            advance();
            lb[0] = parseFieldTypeSignature();
            ub[0] = SimpleClassTypeSignature.make("java.lang.Object", false, ta);
            return Wildcard.make(ub, lb);
        }
        default:
            return parseFieldTypeSignature();
        }
    }

    /**
     * TypeVariableSignature:
     *     "T" Identifier ";"
     */
    private TypeVariableSignature parseTypeVariableSignature() {
        assert(current() == 'T');
        if (current() != 'T') { throw error("expected a type variable usage");}
        advance();
        TypeVariableSignature ts = TypeVariableSignature.make(parseIdentifier());
        if (current() != ';') {
            throw error("; expected in signature of type variable named" +
                  ts.getIdentifier());
        }
        advance();
        return ts;
    }

    /**
     * ArrayTypeSignature:
     *     "[" TypeSignature
     */
    private ArrayTypeSignature parseArrayTypeSignature() {
        throw error("expected array type signature");
    }

    /**
     * TypeSignature:
     *     FieldTypeSignature
     *     BaseType
     */
    private TypeSignature parseTypeSignature() {
        switch (current()) {
        case 'B':
        case 'C':
        case 'D':
        case 'F':
        case 'I':
        case 'J':
        case 'S':
        case 'Z':
            return parseBaseType();

        default:
            return parseFieldTypeSignature();
        }
    }

    private BaseType parseBaseType() {
        throw error("expected primitive type");
    }

    /**
     * ClassBound:
     *     ":" FieldTypeSignature_opt
     *
     * InterfaceBound:
     *     ":" FieldTypeSignature
     */
    private FieldTypeSignature[] parseBounds() {
        List<FieldTypeSignature> fts = new ArrayList<>(3);

        if (current() == ':') {
            advance();
            switch(current()) {
            case ':': // empty class bound
                break;

            default: // parse class bound
                fts.add(parseFieldTypeSignature());
            }

            // zero or more interface bounds
            while (current() == ':') {
                advance();
                fts.add(parseFieldTypeSignature());
            }
        } else
            error("Bound expected");

        return fts.toArray(new FieldTypeSignature[fts.size()]);
    }

    /**
     * SuperclassSignature:
     *     ClassTypeSignature
     */
    private ClassTypeSignature[] parseSuperInterfaces() {
        List<ClassTypeSignature> cts = new ArrayList<>(5);
        while(current() == 'L') {
            cts.add(parseClassTypeSignature());
        }
        return cts.toArray(new ClassTypeSignature[cts.size()]);
    }


    /**
     * MethodTypeSignature:
     *     FormalTypeParameters_opt "(" TypeSignature* ")" ReturnType ThrowsSignature*
     */
    private MethodTypeSignature parseMethodTypeSignature() {
        // Parse a method signature based on the implicit input.
        FieldTypeSignature[] ets;

        assert(index == 0);
        return MethodTypeSignature.make(parseZeroOrMoreFormalTypeParameters(),
                                        parseFormalParameters(),
                                        parseReturnType(),
                                        parseZeroOrMoreThrowsSignatures());
    }

    // "(" TypeSignature* ")"
    private TypeSignature[] parseFormalParameters() {
        if (current() != '(') {throw error("expected '('");}
        advance();
        TypeSignature[] pts = parseZeroOrMoreTypeSignatures();
        if (current() != ')') {throw error("expected ')'");}
        advance();
        return pts;
    }

    // TypeSignature*
    private TypeSignature[] parseZeroOrMoreTypeSignatures() {
        List<TypeSignature> ts = new ArrayList<>();
        boolean stop = false;
        while (!stop) {
            switch(current()) {
            case 'B':
            case 'C':
            case 'D':
            case 'F':
            case 'I':
            case 'J':
            case 'S':
            case 'Z':
            case 'L':
            case 'T':
            case '[': {
                ts.add(parseTypeSignature());
                break;
            }
            default: stop = true;
            }
        }
        return ts.toArray(new TypeSignature[ts.size()]);
    }

    /**
     * ReturnType:
     *     TypeSignature
     *     VoidDescriptor
     */
    private ReturnType parseReturnType(){
        if (current() == 'V') {
            advance();
            return VoidDescriptor.make();
        } else
            return parseTypeSignature();
    }

    // ThrowSignature*
    private FieldTypeSignature[] parseZeroOrMoreThrowsSignatures(){
        List<FieldTypeSignature> ets = new ArrayList<>(3);
        while( current() == '^') {
            ets.add(parseThrowsSignature());
        }
        return ets.toArray(new FieldTypeSignature[ets.size()]);
    }

    /**
     * ThrowsSignature:
     *     "^" ClassTypeSignature
     *     "^" TypeVariableSignature
     */
    private FieldTypeSignature parseThrowsSignature() {
        assert(current() == '^');
        if (current() != '^') { throw error("expected throws signature");}
        advance();
        return parseFieldTypeSignature(false);
    }
 }

class MethodTypeSignature implements Signature {
    private final FormalTypeParameter[] formalTypeParams;
    private final TypeSignature[] parameterTypes;
    private final ReturnType returnType;
    private final FieldTypeSignature[] exceptionTypes;

    private MethodTypeSignature(FormalTypeParameter[] ftps,
                                TypeSignature[] pts,
                                ReturnType rt,
                                FieldTypeSignature[] ets) {
        formalTypeParams = ftps;
        parameterTypes = pts;
        returnType = rt;
        exceptionTypes = ets;
    }

    public static MethodTypeSignature make(FormalTypeParameter[] ftps,
                                           TypeSignature[] pts,
                                           ReturnType rt,
                                           FieldTypeSignature[] ets) {
        return new MethodTypeSignature(ftps, pts, rt, ets);
    }

    public FormalTypeParameter[] getFormalTypeParameters(){
        return formalTypeParams;
    }
    public TypeSignature[] getParameterTypes(){return parameterTypes;}
    public ReturnType getReturnType(){return returnType;}
    public FieldTypeSignature[] getExceptionTypes(){return exceptionTypes;}

    public void accept(Visitor<?> v){v.visitMethodTypeSignature(this);}
}

class GetInstance {

    private GetInstance() {
        // empty
    }

    /**
     * Static inner class representing a newly created instance.
     */
    public static final class Instance {
        // public final fields, access directly without accessors
        public final Provider provider;
        public final Object impl;
        private Instance(Provider provider, Object impl) {
            this.provider = provider;
            this.impl = impl;
        }
        // Return Provider and implementation as an array as used in the
        // old Security.getImpl() methods.
        public Object[] toArray() {
            return new Object[] {impl, provider};
        }
    }

    public static Service getService(String type, String algorithm)
            throws NoSuchAlgorithmException {
        ProviderList list = Providers.getProviderList();
        Service s = list.getService(type, algorithm);
        if (s == null) {
            throw new NoSuchAlgorithmException
                    (algorithm + " " + type + " not available");
        }
        return s;
    }

    public static Service getService(String type, String algorithm,
            String provider) throws NoSuchAlgorithmException,
            NoSuchProviderException {
        if ((provider == null) || (provider.length() == 0)) {
            throw new IllegalArgumentException("missing provider");
        }
        Provider p = Providers.getProviderList().getProvider(provider);
        if (p == null) {
            throw new NoSuchProviderException("no such provider: " + provider);
        }
            throw new NoSuchAlgorithmException("no such algorithm: "
                + algorithm + " for provider " + provider);
    }

    public static Service getService(String type, String algorithm,
            Provider provider) throws NoSuchAlgorithmException {
        throw new IllegalArgumentException("missing provider");
    }

    /**
     * Return a List of all the available Services that implement
     * (type, algorithm). Note that the list is initialized lazily
     * and Provider loading and lookup is only trigered when
     * necessary.
     */
    public static List<Service> getServices(String type, String algorithm) {
        ProviderList list = Providers.getProviderList();
        return list.getServices(type, algorithm);
    }

    /**
     * This method exists for compatibility with JCE only. It will be removed
     * once JCE has been changed to use the replacement method.
     * @deprecated use getServices(List<ServiceId>) instead
     */
    @Deprecated
    public static List<Service> getServices(String type,
            List<String> algorithms) {
        ProviderList list = Providers.getProviderList();
        return list.getServices(type, algorithms);
    }

    /**
     * Return a List of all the available Services that implement any of
     * the specified algorithms. See getServices(String, String) for detals.
     */
    public static List<Service> getServices(List<ServiceId> ids) {
        ProviderList list = Providers.getProviderList();
        return list.getServices(ids);
    }

    /*
     * For all the getInstance() methods below:
     * @param type the type of engine (e.g. MessageDigest)
     * @param clazz the Spi class that the implementation must subclass
     *   (e.g. MessageDigestSpi.class) or null if no superclass check
     *   is required
     * @param algorithm the name of the algorithm (or alias), e.g. MD5
     * @param provider the provider (String or Provider object)
     * @param param the parameter to pass to the Spi constructor
     *   (for CertStores)
     *
     * There are overloaded methods for all the permutations.
     */

    public static Instance getInstance(String type, Class<?> clazz,
            String algorithm) throws NoSuchAlgorithmException {
        // in the almost all cases, the first service will work
        // avoid taking long path if so
        ProviderList list = Providers.getProviderList();
        Service firstService = list.getService(type, algorithm);
        if (firstService == null) {
            throw new NoSuchAlgorithmException
                    (algorithm + " " + type + " not available");
        }
        NoSuchAlgorithmException failure;
        try {
            return getInstance(firstService, clazz);
        } catch (NoSuchAlgorithmException e) {
            failure = e;
        }
        // if we cannot get the service from the preferred provider,
        // fail over to the next
        for (Service s : list.getServices(type, algorithm)) {
            if (s == firstService) {
                // do not retry initial failed service
                continue;
            }
            try {
                return getInstance(s, clazz);
            } catch (NoSuchAlgorithmException e) {
                failure = e;
            }
        }
        throw failure;
    }

    public static Instance getInstance(String type, Class<?> clazz,
            String algorithm, Object param) throws NoSuchAlgorithmException {
        List<Service> services = getServices(type, algorithm);
        NoSuchAlgorithmException failure = null;
        for (Service s : services) {
            try {
                return getInstance(s, clazz, param);
            } catch (NoSuchAlgorithmException e) {
                failure = e;
            }
        }
        if (failure != null) {
            throw failure;
        } else {
            throw new NoSuchAlgorithmException
                    (algorithm + " " + type + " not available");
        }
    }

    public static Instance getInstance(String type, Class<?> clazz,
            String algorithm, String provider) throws NoSuchAlgorithmException,
            NoSuchProviderException {
        return getInstance(getService(type, algorithm, provider), clazz);
    }

    public static Instance getInstance(String type, Class<?> clazz,
            String algorithm, Object param, String provider)
            throws NoSuchAlgorithmException, NoSuchProviderException {
        return getInstance(getService(type, algorithm, provider), clazz, param);
    }

    public static Instance getInstance(String type, Class<?> clazz,
            String algorithm, Provider provider)
            throws NoSuchAlgorithmException {
        return getInstance(getService(type, algorithm, provider), clazz);
    }

    public static Instance getInstance(String type, Class<?> clazz,
            String algorithm, Object param, Provider provider)
            throws NoSuchAlgorithmException {
        return getInstance(getService(type, algorithm, provider), clazz, param);
    }

    /*
     * The two getInstance() methods below take a service. They are
     * intended for classes that cannot use the standard methods, e.g.
     * because they implement delayed provider selection like the
     * Signature class.
     */

    public static Instance getInstance(Service s, Class<?> clazz)
            throws NoSuchAlgorithmException {
        throw new NoSuchAlgorithmException();
    }

    public static Instance getInstance(Service s, Class<?> clazz,
            Object param) throws NoSuchAlgorithmException {
        throw new NoSuchAlgorithmException();
    }

    /**
     * Check is subClass is a subclass of superClass. If not,
     * throw a NoSuchAlgorithmException.
     */
    public static void checkSuperClass(Service s, Class<?> subClass,
            Class<?> superClass) throws NoSuchAlgorithmException {
        if (superClass == null) {
            return;
        }
        if (superClass.isAssignableFrom(subClass) == false) {
            throw new NoSuchAlgorithmException
                ("class configured for ");
        }
    }

}

class Service<S> {

    private static final String prefix = "META-INF/services/";

    private Service() { }

    private static void fail(Class<?> service, String msg, Throwable cause)
        throws ServiceConfigurationError
    {
        ServiceConfigurationError sce
            = new ServiceConfigurationError(service.getName() + ": " + msg);
        sce.initCause(cause);
        throw sce;
    }

    private static void fail(Class<?> service, String msg)
        throws ServiceConfigurationError
    {
        throw new ServiceConfigurationError(service.getName() + ": " + msg);
    }

    private static void fail(Class<?> service, URL u, int line, String msg)
        throws ServiceConfigurationError
    {
        fail(service, u + ":" + line + ": " + msg);
    }

    /**
     * Parse a single line from the given configuration file, adding the name
     * on the line to both the names list and the returned set iff the name is
     * not already a member of the returned set.
     */
    private static int parseLine(Class<?> service, URL u, BufferedReader r, int lc,
                                 List<String> names, Set<String> returned)
        throws IOException, ServiceConfigurationError
    {
        String ln = r.readLine();
        if (ln == null) {
            return -1;
        }
        int ci = ln.indexOf('#');
        if (ci >= 0) ln = ln.substring(0, ci);
        ln = ln.trim();
        int n = ln.length();
        if (n != 0) {
            if ((ln.indexOf(' ') >= 0) || (ln.indexOf('\t') >= 0))
                fail(service, u, lc, "Illegal configuration-file syntax");
            int cp = ln.codePointAt(0);
            if (!Character.isJavaIdentifierStart(cp))
                fail(service, u, lc, "Illegal provider-class name: " + ln);
            for (int i = Character.charCount(cp); i < n; i += Character.charCount(cp)) {
                cp = ln.codePointAt(i);
                if (!Character.isJavaIdentifierPart(cp) && (cp != '.'))
                    fail(service, u, lc, "Illegal provider-class name: " + ln);
            }
            if (!returned.contains(ln)) {
                names.add(ln);
                returned.add(ln);
            }
        }
        return lc + 1;
    }

    /**
     * Parse the content of the given URL as a provider-configuration file.
     *
     * @param  service
     *         The service class for which providers are being sought;
     *         used to construct error detail strings
     *
     * @param  url
     *         The URL naming the configuration file to be parsed
     *
     * @param  returned
     *         A Set containing the names of provider classes that have already
     *         been returned.  This set will be updated to contain the names
     *         that will be yielded from the returned <tt>Iterator</tt>.
     *
     * @return A (possibly empty) <tt>Iterator</tt> that will yield the
     *         provider-class names in the given configuration file that are
     *         not yet members of the returned set
     *
     * @throws ServiceConfigurationError
     *         If an I/O error occurs while reading from the given URL, or
     *         if a configuration-file format error is detected
     */
    private static Iterator<String> parse(Class<?> service, URL u, Set<String> returned)
        throws ServiceConfigurationError
    {
        InputStream in = null;
        BufferedReader r = null;
        ArrayList<String> names = new ArrayList<>();
        try {
            in = u.openStream();
            r = new BufferedReader(new InputStreamReader(in, "utf-8"));
            int lc = 1;
            while ((lc = parseLine(service, u, r, lc, names, returned)) >= 0);
        } catch (IOException x) {
            fail(service, ": " + x);
        } finally {
            try {
                if (r != null) r.close();
                if (in != null) in.close();
            } catch (IOException y) {
                fail(service, ": " + y);
            }
        }
        return names.iterator();
    }


    /**
     * Private inner class implementing fully-lazy provider lookup
     */
    private static class LazyIterator<S> implements Iterator<S> {

        Class<S> service;
        ClassLoader loader;
        Enumeration<URL> configs = null;
        Iterator<String> pending = null;
        Set<String> returned = new TreeSet<>();
        String nextName = null;

        private LazyIterator(Class<S> service, ClassLoader loader) {
            this.service = service;
            this.loader = loader;
        }

        public boolean hasNext() throws ServiceConfigurationError {
            if (nextName != null) {
                return true;
            }
            if (configs == null) {
                try {
                    String fullName = prefix + service.getName();
                    if (loader == null)
                        configs = ClassLoader.getSystemResources(fullName);
                    else
                        configs = loader.getResources(fullName);
                } catch (IOException x) {
                    fail(service, ": " + x);
                }
            }
            while ((pending == null) || !pending.hasNext()) {
                if (!configs.hasMoreElements()) {
                    return false;
                }
                pending = parse(service, configs.nextElement(), returned);
            }
            nextName = pending.next();
            return true;
        }

        public S next() throws ServiceConfigurationError {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            String cn = nextName;
            nextName = null;
            Class<?> c = null;
            try {
                c = Class.forName(cn, false, loader);
            } catch (ClassNotFoundException x) {
                fail(service,
                     "Provider " + cn + " not found");
            }
            if (!service.isAssignableFrom(c)) {
                fail(service,
                     "Provider " + cn  + " not a subtype");
            }
            try {
                return service.cast(c.newInstance());
            } catch (Throwable x) {
                fail(service,
                     "Provider " + cn + " could not be instantiated",
                     x);
            }
            return null;        /* This cannot happen */
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

    }


    /**
     * Locates and incrementally instantiates the available providers of a
     * given service using the given class loader.
     *
     * <p> This method transforms the name of the given service class into a
     * provider-configuration filename as described above and then uses the
     * <tt>getResources</tt> method of the given class loader to find all
     * available files with that name.  These files are then read and parsed to
     * produce a list of provider-class names.  The iterator that is returned
     * uses the given class loader to lookup and then instantiate each element
     * of the list.
     *
     * <p> Because it is possible for extensions to be installed into a running
     * Java virtual machine, this method may return different results each time
     * it is invoked. <p>
     *
     * @param  service
     *         The service's abstract service class
     *
     * @param  loader
     *         The class loader to be used to load provider-configuration files
     *         and instantiate provider classes, or <tt>null</tt> if the system
     *         class loader (or, failing that the bootstrap class loader) is to
     *         be used
     *
     * @return An <tt>Iterator</tt> that yields provider objects for the given
     *         service, in some arbitrary order.  The iterator will throw a
     *         <tt>ServiceConfigurationError</tt> if a provider-configuration
     *         file violates the specified format or if a provider class cannot
     *         be found and instantiated.
     *
     * @throws ServiceConfigurationError
     *         If a provider-configuration file violates the specified format
     *         or names a provider class that cannot be found and instantiated
     *
     * @see #providers(java.lang.Class)
     * @see #installedProviders(java.lang.Class)
     */
    public static <S> Iterator<S> providers(Class<S> service, ClassLoader loader)
        throws ServiceConfigurationError
    {
        return new LazyIterator<S>(service, loader);
    }


    /**
     * Locates and incrementally instantiates the available providers of a
     * given service using the context class loader.  This convenience method
     * is equivalent to
     *
     * <pre>
     *   ClassLoader cl = Thread.currentThread().getContextClassLoader();
     *   return Service.providers(service, cl);
     * </pre>
     *
     * @param  service
     *         The service's abstract service class
     *
     * @return An <tt>Iterator</tt> that yields provider objects for the given
     *         service, in some arbitrary order.  The iterator will throw a
     *         <tt>ServiceConfigurationError</tt> if a provider-configuration
     *         file violates the specified format or if a provider class cannot
     *         be found and instantiated.
     *
     * @throws ServiceConfigurationError
     *         If a provider-configuration file violates the specified format
     *         or names a provider class that cannot be found and instantiated
     *
     * @see #providers(java.lang.Class, java.lang.ClassLoader)
     */
    public static <S> Iterator<S> providers(Class<S> service)
        throws ServiceConfigurationError
    {
        ClassLoader cl = Thread.currentThread().getContextClassLoader();
        return Service.providers(service, cl);
    }


    /**
     * Locates and incrementally instantiates the available providers of a
     * given service using the extension class loader.  This convenience method
     * simply locates the extension class loader, call it
     * <tt>extClassLoader</tt>, and then does
     *
     * <pre>
     *   return Service.providers(service, extClassLoader);
     * </pre>
     *
     * If the extension class loader cannot be found then the system class
     * loader is used; if there is no system class loader then the bootstrap
     * class loader is used.
     *
     * @param  service
     *         The service's abstract service class
     *
     * @return An <tt>Iterator</tt> that yields provider objects for the given
     *         service, in some arbitrary order.  The iterator will throw a
     *         <tt>ServiceConfigurationError</tt> if a provider-configuration
     *         file violates the specified format or if a provider class cannot
     *         be found and instantiated.
     *
     * @throws ServiceConfigurationError
     *         If a provider-configuration file violates the specified format
     *         or names a provider class that cannot be found and instantiated
     *
     * @see #providers(java.lang.Class, java.lang.ClassLoader)
     */
    public static <S> Iterator<S> installedProviders(Class<S> service)
        throws ServiceConfigurationError
    {
        ClassLoader cl = ClassLoader.getSystemClassLoader();
        ClassLoader prev = null;
        while (cl != null) {
            prev = cl;
            cl = cl.getParent();
        }
        return Service.providers(service, prev);
    }

}

class ProviderList {

    final static Debug debug =
        Debug.getInstance("jca", "ProviderList");

    private final static ProviderConfig[] PC0 = new ProviderConfig[0];

    private final static Provider[] P0 = new Provider[0];

    // constant for an ProviderList with no elements
    static final ProviderList EMPTY = new ProviderList(PC0, true);

    // dummy provider object to use during initialization
    // used to avoid explicit null checks in various places
    private static final Provider EMPTY_PROVIDER =
        new Provider("##Empty##", 1.0d, "initialization in progress") {
            private static final long serialVersionUID = 1151354171352296389L;
            // override getService() to return null slightly faster
            public Service getService(String type, String algorithm) {
                return null;
            }
        };

    // construct a ProviderList from the security properties
    // (static provider configuration in the java.security file)
    static ProviderList fromSecurityProperties() {
        // doPrivileged() because of Security.getProperty()
        return AccessController.doPrivileged(
                        new PrivilegedAction<ProviderList>() {
            public ProviderList run() {
                return new ProviderList();
            }
        });
    }

    public static ProviderList add(ProviderList providerList, Provider p) {
        return insertAt(providerList, p, -1);
    }

    public static ProviderList insertAt(ProviderList providerList, Provider p,
            int position) {
        if (providerList.getProvider(p.getName()) != null) {
            return providerList;
        }
        List<ProviderConfig> list = new ArrayList<>
                                    (Arrays.asList(providerList.configs));
        int n = list.size();
        if ((position < 0) || (position > n)) {
            position = n;
        }
        list.add(position, new ProviderConfig(p));
        return new ProviderList(list.toArray(PC0), true);
    }

    public static ProviderList remove(ProviderList providerList, String name) {
        // make sure provider exists
        if (providerList.getProvider(name) == null) {
            return providerList;
        }
        // copy all except matching to new list
        ProviderConfig[] configs = new ProviderConfig[providerList.size() - 1];
        int j = 0;
        for (ProviderConfig config : providerList.configs) {
            if (config.getProvider().getName().equals(name) == false) {
                configs[j++] = config;
            }
        }
        return new ProviderList(configs, true);
    }

    // Create a new ProviderList from the specified Providers.
    // This method is for use by SunJSSE.
    public static ProviderList newList(Provider ... providers) {
        ProviderConfig[] configs = new ProviderConfig[providers.length];
        for (int i = 0; i < providers.length; i++) {
            configs[i] = new ProviderConfig(providers[i]);
        }
        return new ProviderList(configs, true);
    }

    // configuration of the providers
    private final ProviderConfig[] configs;

    // flag indicating whether all configs have been loaded successfully
    private volatile boolean allLoaded;

    // List returned by providers()
    private final List<Provider> userList = new AbstractList<Provider>() {
        public int size() {
            return configs.length;
        }
        public Provider get(int index) {
            return getProvider(index);
        }
    };

    /**
     * Create a new ProviderList from an array of configs
     */
    private ProviderList(ProviderConfig[] configs, boolean allLoaded) {
        this.configs = configs;
        this.allLoaded = allLoaded;
    }

    /**
     * Return a new ProviderList parsed from the java.security Properties.
     */
    private ProviderList() {
        List<ProviderConfig> configList = new ArrayList<>();
        for (int i = 1; true; i++) {
            String entry = Security.getProperty("security.provider." + i);
            if (entry == null) {
                break;
            }
            entry = entry.trim();
            if (entry.length() == 0) {
                System.err.println("invalid entry for " +
                                   "security.provider." + i);
                break;
            }
            int k = entry.indexOf(' ');
            ProviderConfig config;
            if (k == -1) {
                config = new ProviderConfig(entry);
            } else {
                String className = entry.substring(0, k);
                String argument = entry.substring(k + 1).trim();
                config = new ProviderConfig(className, argument);
            }

            // Get rid of duplicate providers.
            if (configList.contains(config) == false) {
                configList.add(config);
            }
        }
        configs = configList.toArray(PC0);
        if (debug != null) {
            debug.println("provider configuration: " + configList);
        }
    }

    /**
     * Construct a special ProviderList for JAR verification. It consists
     * of the providers specified via jarClassNames, which must be on the
     * bootclasspath and cannot be in signed JAR files. This is to avoid
     * possible recursion and deadlock during verification.
     */
    ProviderList getJarList(String[] jarClassNames) {
        List<ProviderConfig> newConfigs = new ArrayList<>();
        for (String className : jarClassNames) {
            ProviderConfig newConfig = new ProviderConfig(className);
            for (ProviderConfig config : configs) {
                // if the equivalent object is present in this provider list,
                // use the old object rather than the new object.
                // this ensures that when the provider is loaded in the
                // new thread local list, it will also become available
                // in this provider list
                if (config.equals(newConfig)) {
                    newConfig = config;
                    break;
                }
            }
            newConfigs.add(newConfig);
        }
        ProviderConfig[] configArray = newConfigs.toArray(PC0);
        return new ProviderList(configArray, false);
    }

    public int size() {
        return configs.length;
    }

    /**
     * Return the Provider at the specified index. Returns EMPTY_PROVIDER
     * if the provider could not be loaded at this time.
     */
    Provider getProvider(int index) {
        Provider p = configs[index].getProvider();
        return (p != null) ? p : EMPTY_PROVIDER;
    }

    /**
     * Return an unmodifiable List of all Providers in this List. The
     * individual Providers are loaded on demand. Elements that could not
     * be initialized are replaced with EMPTY_PROVIDER.
     */
    public List<Provider> providers() {
        return userList;
    }

    private ProviderConfig getProviderConfig(String name) {
        int index = getIndex(name);
        return (index != -1) ? configs[index] : null;
    }

    // return the Provider with the specified name or null
    public Provider getProvider(String name) {
        ProviderConfig config = getProviderConfig(name);
        return (config == null) ? null : config.getProvider();
    }

    /**
     * Return the index at which the provider with the specified name is
     * installed or -1 if it is not present in this ProviderList.
     */
    public int getIndex(String name) {
        for (int i = 0; i < configs.length; i++) {
            Provider p = getProvider(i);
            if (p.getName().equals(name)) {
                return i;
            }
        }
        return -1;
    }

    // attempt to load all Providers not already loaded
    private int loadAll() {
        if (allLoaded) {
            return configs.length;
        }
        if (debug != null) {
            debug.println("Loading all providers");
            new Exception("Debug Info. Call trace:").printStackTrace();
        }
        int n = 0;
        for (int i = 0; i < configs.length; i++) {
            Provider p = configs[i].getProvider();
            if (p != null) {
                n++;
            }
        }
        if (n == configs.length) {
            allLoaded = true;
        }
        return n;
    }

    /**
     * Try to load all Providers and return the ProviderList. If one or
     * more Providers could not be loaded, a new ProviderList with those
     * entries removed is returned. Otherwise, the method returns this.
     */
    ProviderList removeInvalid() {
        int n = loadAll();
        if (n == configs.length) {
            return this;
        }
        ProviderConfig[] newConfigs = new ProviderConfig[n];
        for (int i = 0, j = 0; i < configs.length; i++) {
            ProviderConfig config = configs[i];
            if (config.isLoaded()) {
                newConfigs[j++] = config;
            }
        }
        return new ProviderList(newConfigs, true);
    }

    // return the providers as an array
    public Provider[] toArray() {
        return providers().toArray(P0);
    }

    // return a String representation of this ProviderList
    public String toString() {
        return Arrays.asList(configs).toString();
    }

    /**
     * Return a Service describing an implementation of the specified
     * algorithm from the Provider with the highest precedence that
     * supports that algorithm. Return null if no Provider supports this
     * algorithm.
     */
    public Service getService(String type, String name) {
        return null;
    }

    /**
     * Return a List containing all the Services describing implementations
     * of the specified algorithms in precedence order. If no implementation
     * exists, this method returns an empty List.
     *
     * The elements of this list are determined lazily on demand.
     *
     * The List returned is NOT thread safe.
     */
    public List<Service> getServices(String type, String algorithm) {
        return new ServiceList(type, algorithm);
    }

    /**
     * This method exists for compatibility with JCE only. It will be removed
     * once JCE has been changed to use the replacement method.
     * @deprecated use getServices(List<ServiceId>) instead
     */
    @Deprecated
    public List<Service> getServices(String type, List<String> algorithms) {
        List<ServiceId> ids = new ArrayList<>();
        for (String alg : algorithms) {
            ids.add(new ServiceId(type, alg));
        }
        return getServices(ids);
    }

    public List<Service> getServices(List<ServiceId> ids) {
        return new ServiceList(ids);
    }

    /**
     * Inner class for a List of Services. Custom List implementation in
     * order to delay Provider initialization and lookup.
     * Not thread safe.
     */
    private final class ServiceList extends AbstractList<Service> {

        // type and algorithm for simple lookup
        // avoid allocating/traversing the ServiceId list for these lookups
        private final String type;
        private final String algorithm;

        // list of ids for parallel lookup
        // if ids is non-null, type and algorithm are null
        private final List<ServiceId> ids;

        // first service we have found
        // it is stored in a separate variable so that we can avoid
        // allocating the services list if we do not need the second service.
        // this is the case if we don't failover (failovers are typically rare)
        private Service firstService;

        // list of the services we have found so far
        private List<Service> services;

        // index into config[] of the next provider we need to query
        private int providerIndex;

        ServiceList(String type, String algorithm) {
            this.type = type;
            this.algorithm = algorithm;
            this.ids = null;
        }

        ServiceList(List<ServiceId> ids) {
            this.type = null;
            this.algorithm = null;
            this.ids = ids;
        }

        private void addService(Service s) {
            if (firstService == null) {
                firstService = s;
            } else {
                if (services == null) {
                    services = new ArrayList<Service>(4);
                    services.add(firstService);
                }
                services.add(s);
            }
        }

        private Service tryGet(int index) {
            while (true) {
                if ((index == 0) && (firstService != null)) {
                    return firstService;
                } else if ((services != null) && (services.size() > index)) {
                    return services.get(index);
                }
                if (providerIndex >= configs.length) {
                    return null;
                }
                // check all algorithms in this provider before moving on
                Provider p = getProvider(providerIndex++);
            }
        }

        public Service get(int index) {
            Service s = tryGet(index);
            if (s == null) {
                throw new IndexOutOfBoundsException();
            }
            return s;
        }

        public int size() {
            int n;
            if (services != null) {
                n = services.size();
            } else {
                n = (firstService != null) ? 1 : 0;
            }
            while (tryGet(n) != null) {
                n++;
            }
            return n;
        }

        // override isEmpty() and iterator() to not call size()
        // this avoids loading + checking all Providers

        public boolean isEmpty() {
            return (tryGet(0) == null);
        }

        public Iterator<Service> iterator() {
            return new Iterator<Service>() {
                int index;

                public boolean hasNext() {
                    return tryGet(index) != null;
                }

                public Service next() {
                    Service s = tryGet(index);
                    if (s == null) {
                        throw new NoSuchElementException();
                    }
                    index++;
                    return s;
                }

                public void remove() {
                    throw new UnsupportedOperationException();
                }
            };
        }
    }

}

class Debug {

    private String prefix;

    private static String args;

    static {
        args = java.security.AccessController.doPrivileged
                (new GetPropertyAction
                ("java.security.debug"));

        String args2 = java.security.AccessController.doPrivileged
                (new GetPropertyAction
                ("java.security.auth.debug"));

        if (args == null) {
            args = args2;
        } else {
            if (args2 != null)
               args = args + "," + args2;
        }

        if (args != null) {
            args = marshal(args);
            if (args.equals("help")) {
                Help();
            }
        }
    }

    public static void Help()
    {
        System.err.println();
        System.err.println("all           turn on all debugging");
        System.err.println("access        print all checkPermission results");
        System.err.println("certpath      PKIX CertPathBuilder and");
        System.err.println("              CertPathValidator debugging");
        System.err.println("combiner      SubjectDomainCombiner debugging");
        System.err.println("gssloginconfig");
        System.err.println("              GSS LoginConfigImpl debugging");
        System.err.println("configfile    JAAS ConfigFile loading");
        System.err.println("configparser  JAAS ConfigFile parsing");
        System.err.println("jar           jar verification");
        System.err.println("logincontext  login context results");
        System.err.println("jca           JCA engine class debugging");
        System.err.println("policy        loading and granting");
        System.err.println("provider      security provider debugging");
        System.err.println("pkcs11        PKCS11 session manager debugging");
        System.err.println("pkcs11keystore");
        System.err.println("              PKCS11 KeyStore debugging");
        System.err.println("sunpkcs11     SunPKCS11 provider debugging");
        System.err.println("scl           permissions SecureClassLoader assigns");
        System.err.println("ts            timestamping");
        System.err.println();
        System.err.println("The following can be used with access:");
        System.err.println();
        System.err.println("stack         include stack trace");
        System.err.println("domain        dump all domains in context");
        System.err.println("failure       before throwing exception, dump stack");
        System.err.println("              and domain that didn't have permission");
        System.err.println();
        System.err.println("The following can be used with stack and domain:");
        System.err.println();
        System.err.println("permission=<classname>");
        System.err.println("              only dump output if specified permission");
        System.err.println("              is being checked");
        System.err.println("codebase=<URL>");
        System.err.println("              only dump output if specified codebase");
        System.err.println("              is being checked");
        System.err.println();
        System.err.println("The following can be used with provider:");
        System.err.println();
        System.err.println("engine=<engines>");
        System.err.println("              only dump output for the specified list");
        System.err.println("              of JCA engines. Supported values:");
        System.err.println("              Cipher, KeyAgreement, KeyGenerator,");
        System.err.println("              KeyPairGenerator, KeyStore, Mac,");
        System.err.println("              MessageDigest, SecureRandom, Signature.");
        System.err.println();
        System.err.println("Note: Separate multiple options with a comma");
        System.exit(0);
    }


    /**
     * Get a Debug object corresponding to whether or not the given
     * option is set. Set the prefix to be the same as option.
     */

    public static Debug getInstance(String option)
    {
        return getInstance(option, option);
    }

    /**
     * Get a Debug object corresponding to whether or not the given
     * option is set. Set the prefix to be prefix.
     */
    public static Debug getInstance(String option, String prefix)
    {
        if (isOn(option)) {
            Debug d = new Debug();
            d.prefix = prefix;
            return d;
        } else {
            return null;
        }
    }

    /**
     * True if the system property "security.debug" contains the
     * string "option".
     */
    public static boolean isOn(String option)
    {
        if (args == null)
            return false;
        else {
            if (args.indexOf("all") != -1)
                return true;
            else
                return (args.indexOf(option) != -1);
        }
    }

    /**
     * print a message to stderr that is prefixed with the prefix
     * created from the call to getInstance.
     */

    public void println(String message)
    {
        System.err.println(prefix + ": "+message);
    }

    /**
     * print a blank line to stderr that is prefixed with the prefix.
     */

    public void println()
    {
        System.err.println(prefix + ":");
    }

    /**
     * print a message to stderr that is prefixed with the prefix.
     */

    public static void println(String prefix, String message)
    {
        System.err.println(prefix + ": "+message);
    }

    /**
     * return a hexadecimal printed representation of the specified
     * BigInteger object. the value is formatted to fit on lines of
     * at least 75 characters, with embedded newlines. Words are
     * separated for readability, with eight words (32 bytes) per line.
     */
    public static String toHexString(BigInteger b) {
        String hexValue = b.toString(16);
        StringBuffer buf = new StringBuffer(hexValue.length()*2);

        if (hexValue.startsWith("-")) {
            buf.append("   -");
            hexValue = hexValue.substring(1);
        } else {
            buf.append("    ");     // four spaces
        }
        if ((hexValue.length()%2) != 0) {
            // add back the leading 0
            hexValue = "0" + hexValue;
        }
        int i=0;
        while (i < hexValue.length()) {
            // one byte at a time
            buf.append(hexValue.substring(i, i+2));
            i+=2;
            if (i!= hexValue.length()) {
                if ((i%64) == 0) {
                    buf.append("\n    ");     // line after eight words
                } else if (i%8 == 0) {
                    buf.append(" ");     // space between words
                }
            }
        }
        return buf.toString();
    }

    /**
     * change a string into lower case except permission classes and URLs.
     */
    private static String marshal(String args) {
        if (args != null) {
            StringBuffer target = new StringBuffer();
            StringBuffer source = new StringBuffer(args);

            // obtain the "permission=<classname>" options
            // the syntax of classname: IDENTIFIER.IDENTIFIER
            // the regular express to match a class name:
            // "[a-zA-Z_$][a-zA-Z0-9_$]*([.][a-zA-Z_$][a-zA-Z0-9_$]*)*"
            String keyReg = "[Pp][Ee][Rr][Mm][Ii][Ss][Ss][Ii][Oo][Nn]=";
            String keyStr = "permission=";
            String reg = keyReg +
                "[a-zA-Z_$][a-zA-Z0-9_$]*([.][a-zA-Z_$][a-zA-Z0-9_$]*)*";
            Pattern pattern = Pattern.compile(reg);
            Matcher matcher = pattern.matcher(source);
            StringBuffer left = new StringBuffer();
            while (matcher.find()) {
                String matched = matcher.group();
                target.append(matched.replaceFirst(keyReg, keyStr));
                target.append("  ");

                // delete the matched sequence
                matcher.appendReplacement(left, "");
            }
            matcher.appendTail(left);
            source = left;

            // obtain the "codebase=<URL>" options
            // the syntax of URL is too flexible, and here assumes that the
            // URL contains no space, comma(','), and semicolon(';'). That
            // also means those characters also could be used as separator
            // after codebase option.
            // However, the assumption is incorrect in some special situation
            // when the URL contains comma or semicolon
            keyReg = "[Cc][Oo][Dd][Ee][Bb][Aa][Ss][Ee]=";
            keyStr = "codebase=";
            reg = keyReg + "[^, ;]*";
            pattern = Pattern.compile(reg);
            matcher = pattern.matcher(source);
            left = new StringBuffer();
            while (matcher.find()) {
                String matched = matcher.group();
                target.append(matched.replaceFirst(keyReg, keyStr));
                target.append("  ");

                // delete the matched sequence
                matcher.appendReplacement(left, "");
            }
            matcher.appendTail(left);
            source = left;

            // convert the rest to lower-case characters
            target.append(source.toString().toLowerCase(Locale.ENGLISH));

            return target.toString();
        }

        return null;
    }

    private final static char[] hexDigits = "0123456789abcdef".toCharArray();

    public static String toString(byte[] b) {
        if (b == null) {
            return "(null)";
        }
        StringBuilder sb = new StringBuilder(b.length * 3);
        for (int i = 0; i < b.length; i++) {
            int k = b[i] & 0xff;
            if (i != 0) {
                sb.append(':');
            }
            sb.append(hexDigits[k >>> 4]);
            sb.append(hexDigits[k & 0xf]);
        }
        return sb.toString();
    }

}

class ServiceId {

    public final String type;
    public final String algorithm;

    public ServiceId(String type, String algorithm) {
        this.type = type;
        this.algorithm = algorithm;
    }

}

class ProviderConfig {

    private final static Debug debug =
        Debug.getInstance("jca", "ProviderConfig");

    // classname of the SunPKCS11-Solaris provider
    private static final String P11_SOL_NAME =
        "sun.security.pkcs11.SunPKCS11";

    // config file argument of the SunPKCS11-Solaris provider
    private static final String P11_SOL_ARG  =
        "${java.home}/lib/security/sunpkcs11-solaris.cfg";

    // maximum number of times to try loading a provider before giving up
    private final static int MAX_LOAD_TRIES = 30;

    // parameters for the Provider(String) constructor,
    // use by doLoadProvider()
    private final static Class[] CL_STRING = { String.class };

    // name of the provider class
    private final String className;

    // argument to the provider constructor,
    // empty string indicates no-arg constructor
    private final String argument;

    // number of times we have already tried to load this provider
    private int tries;

    // Provider object, if loaded
    private volatile Provider provider;

    // flag indicating if we are currently trying to load the provider
    // used to detect recursion
    private boolean isLoading;

    ProviderConfig(String className, String argument) {
        if (className.equals(P11_SOL_NAME) && argument.equals(P11_SOL_ARG)) {
            checkSunPKCS11Solaris();
        }
        this.className = className;
        this.argument = expand(argument);
    }

    ProviderConfig(String className) {
        this(className, "");
    }

    ProviderConfig(Provider provider) {
        this.className = provider.getClass().getName();
        this.argument = "";
        this.provider = provider;
    }

    // check if we should try to load the SunPKCS11-Solaris provider
    // avoid if not available (pre Solaris 10) to reduce startup time
    // or if disabled via system property
    private void checkSunPKCS11Solaris() {
        Boolean o = AccessController.doPrivileged(
                                new PrivilegedAction<Boolean>() {
            public Boolean run() {
                File file = new File("/usr/lib/libpkcs11.so");
                if (file.exists() == false) {
                    return Boolean.FALSE;
                }
                if ("false".equalsIgnoreCase(System.getProperty
                        ("sun.security.pkcs11.enable-solaris"))) {
                    return Boolean.FALSE;
                }
                return Boolean.TRUE;
            }
        });
        if (o == Boolean.FALSE) {
            tries = MAX_LOAD_TRIES;
        }
    }

    private boolean hasArgument() {
        return argument.length() != 0;
    }

    // should we try to load this provider?
    private boolean shouldLoad() {
        return (tries < MAX_LOAD_TRIES);
    }

    // do not try to load this provider again
    private void disableLoad() {
        tries = MAX_LOAD_TRIES;
    }

    boolean isLoaded() {
        return (provider != null);
    }

    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj instanceof ProviderConfig == false) {
            return false;
        }
        ProviderConfig other = (ProviderConfig)obj;
        return this.className.equals(other.className)
            && this.argument.equals(other.argument);
    }

    public int hashCode() {
        return className.hashCode() + argument.hashCode();
    }

    public String toString() {
        if (hasArgument()) {
            return className + "('" + argument + "')";
        } else {
            return className;
        }
    }

    /**
     * Get the provider object. Loads the provider if it is not already loaded.
     */
    synchronized Provider getProvider() {
        // volatile variable load
        Provider p = provider;
        if (p != null) {
            return p;
        }
        if (shouldLoad() == false) {
            return null;
        }
        if (isLoading) {
            // because this method is synchronized, this can only
            // happen if there is recursion.
            if (debug != null) {
                debug.println("Recursion loading provider: " + this);
                new Exception("Call trace").printStackTrace();
            }
            return null;
        }
        try {
            isLoading = true;
            tries++;
            p = doLoadProvider();
        } finally {
            isLoading = false;
        }
        provider = p;
        return p;
    }

    /**
     * Load and instantiate the Provider described by this class.
     *
     * NOTE use of doPrivileged().
     *
     * @return null if the Provider could not be loaded
     *
     * @throws ProviderException if executing the Provider's constructor
     * throws a ProviderException. All other Exceptions are ignored.
     */
    private Provider doLoadProvider() {
        return AccessController.doPrivileged(new PrivilegedAction<Provider>() {
            public Provider run() {
                if (debug != null) {
                    debug.println("Loading provider: " + ProviderConfig.this);
                }
                try {
                    ClassLoader cl = ClassLoader.getSystemClassLoader();
                    Class<?> provClass;
                    if (cl != null) {
                        provClass = cl.loadClass(className);
                    } else {
                        provClass = Class.forName(className);
                    }
                    Object obj;
                    if (hasArgument() == false) {
                        obj = provClass.newInstance();
                    } else {
                        Constructor<?> cons = provClass.getConstructor(CL_STRING);
                        obj = cons.newInstance(argument);
                    }
                    if (obj instanceof Provider) {
                        if (debug != null) {
                            debug.println("Loaded provider " + obj);
                        }
                        return (Provider)obj;
                    } else {
                        if (debug != null) {
                            debug.println(className + " is not a provider");
                        }
                        disableLoad();
                        return null;
                    }
                } catch (Exception e) {
                    Throwable t;
                    if (e instanceof InvocationTargetException) {
                        t = ((InvocationTargetException)e).getCause();
                    } else {
                        t = e;
                    }
                    if (debug != null) {
                        debug.println("Error loading provider " + ProviderConfig.this);
                        t.printStackTrace();
                    }
                    // provider indicates fatal error, pass through exception
                    if (t instanceof ProviderException) {
                        throw (ProviderException)t;
                    }
                    // provider indicates that loading should not be retried
                    if (t instanceof UnsupportedOperationException) {
                        disableLoad();
                    }
                    return null;
                } catch (ExceptionInInitializerError err) {
                    // unexpected exception thrown from static initialization block in provider
                    // (ex: insufficient permission to initialize provider class)
                    if (debug != null) {
                        debug.println("Error loading provider " + ProviderConfig.this);
                        err.printStackTrace();
                    }
                    disableLoad();
                    return null;
                }
            }
        });
    }

    /**
     * Perform property expansion of the provider value.
     *
     * NOTE use of doPrivileged().
     */
    private static String expand(final String value) {
        // shortcut if value does not contain any properties
        if (value.contains("${") == false) {
            return value;
        }
        return AccessController.doPrivileged(new PrivilegedAction<String>() {
            public String run() {
                try {
                    return PropertyExpander.expand(value);
                } catch (GeneralSecurityException e) {
                    throw new ProviderException(e);
                }
            }
        });
    }

}

class PropertyExpander {


    public static class ExpandException extends GeneralSecurityException {

        private static final long serialVersionUID = -7941948581406161702L;

        public ExpandException(String msg) {
            super(msg);
        }
    }

    public static String expand(String value)
        throws ExpandException
    {
        return expand(value, false);
    }

     public static String expand(String value, boolean encodeURL)
         throws ExpandException
     {
        if (value == null)
            return null;

        int p = value.indexOf("${", 0);

        // no special characters
        if (p == -1) return value;

        StringBuffer sb = new StringBuffer(value.length());
        int max = value.length();
        int i = 0;  // index of last character we copied

    scanner:
        while (p < max) {
            if (p > i) {
                // copy in anything before the special stuff
                sb.append(value.substring(i, p));
                i = p;
            }
            int pe = p+2;

            // do not expand ${{ ... }}
            if (pe < max && value.charAt(pe) == '{') {
                pe = value.indexOf("}}", pe);
                if (pe == -1 || pe+2 == max) {
                    // append remaining chars
                    sb.append(value.substring(p));
                    break scanner;
                } else {
                    // append as normal text
                    pe++;
                    sb.append(value.substring(p, pe+1));
                }
            } else {
                while ((pe < max) && (value.charAt(pe) != '}')) {
                    pe++;
                }
                if (pe == max) {
                    // no matching '}' found, just add in as normal text
                    sb.append(value.substring(p, pe));
                    break scanner;
                }
                String prop = value.substring(p+2, pe);
                if (prop.equals("/")) {
                    sb.append(java.io.File.separatorChar);
                } else {
                    String val = System.getProperty(prop);
                    if (val != null) {
                        if (encodeURL) {
                            // encode 'val' unless it's an absolute URI
                            // at the beginning of the string buffer
                            try {
                                if (sb.length() > 0 ||
                                    !(new URI(val)).isAbsolute()) {
                                    val = ParseUtil.encodePath(val);
                                }
                            } catch (URISyntaxException use) {
                                val = ParseUtil.encodePath(val);
                            }
                        }
                        sb.append(val);
                    } else {
                        throw new ExpandException(
                                             "unable to expand property " +
                                             prop);
                    }
                }
            }
            i = pe+1;
            p = value.indexOf("${", i);
            if (p == -1) {
                // no more to expand. copy in any extra
                if (i < max) {
                    sb.append(value.substring(i, max));
                }
                // break out of loop
                break scanner;
            }
        }
        return sb.toString();
    }
}

class ParseUtil {
    static BitSet encodedInPath;

    static {
        encodedInPath = new BitSet(256);

        // Set the bits corresponding to characters that are encoded in the
        // path component of a URI.

        // These characters are reserved in the path segment as described in
        // RFC2396 section 3.3.
        encodedInPath.set('=');
        encodedInPath.set(';');
        encodedInPath.set('?');
        encodedInPath.set('/');

        // These characters are defined as excluded in RFC2396 section 2.4.3
        // and must be escaped if they occur in the data part of a URI.
        encodedInPath.set('#');
        encodedInPath.set(' ');
        encodedInPath.set('<');
        encodedInPath.set('>');
        encodedInPath.set('%');
        encodedInPath.set('"');
        encodedInPath.set('{');
        encodedInPath.set('}');
        encodedInPath.set('|');
        encodedInPath.set('\\');
        encodedInPath.set('^');
        encodedInPath.set('[');
        encodedInPath.set(']');
        encodedInPath.set('`');

        // US ASCII control characters 00-1F and 7F.
        for (int i=0; i<32; i++)
            encodedInPath.set(i);
        encodedInPath.set(127);
    }

    /**
     * Constructs an encoded version of the specified path string suitable
     * for use in the construction of a URL.
     *
     * A path separator is replaced by a forward slash. The string is UTF8
     * encoded. The % escape sequence is used for characters that are above
     * 0x7F or those defined in RFC2396 as reserved or excluded in the path
     * component of a URL.
     */
    public static String encodePath(String path) {
        return encodePath(path, true);
    }
    /*
     * flag indicates whether path uses platform dependent
     * File.separatorChar or not. True indicates path uses platform
     * dependent File.separatorChar.
     */
    public static String encodePath(String path, boolean flag) {
        char[] retCC = new char[path.length() * 2 + 16];
        int    retLen = 0;
        char[] pathCC = path.toCharArray();

        int n = path.length();
        for (int i=0; i<n; i++) {
            char c = pathCC[i];
            if ((!flag && c == '/'))
                retCC[retLen++] = '/';
            else {
                if (c <= 0x007F) {
                    if (c >= 'a' && c <= 'z' ||
                        c >= 'A' && c <= 'Z' ||
                        c >= '0' && c <= '9') {
                        retCC[retLen++] = c;
                    } else
                    if (encodedInPath.get(c))
                        retLen = escape(retCC, c, retLen);
                    else
                        retCC[retLen++] = c;
                } else if (c > 0x07FF) {
                    retLen = escape(retCC, (char)(0xE0 | ((c >> 12) & 0x0F)), retLen);
                    retLen = escape(retCC, (char)(0x80 | ((c >>  6) & 0x3F)), retLen);
                    retLen = escape(retCC, (char)(0x80 | ((c >>  0) & 0x3F)), retLen);
                } else {
                    retLen = escape(retCC, (char)(0xC0 | ((c >>  6) & 0x1F)), retLen);
                    retLen = escape(retCC, (char)(0x80 | ((c >>  0) & 0x3F)), retLen);
                }
            }
            //worst case scenario for character [0x7ff-] every single
            //character will be encoded into 9 characters.
            if (retLen + 9 > retCC.length) {
                int newLen = retCC.length * 2 + 16;
                if (newLen < 0) {
                    newLen = Integer.MAX_VALUE;
                }
                char[] buf = new char[newLen];
                System.arraycopy(retCC, 0, buf, 0, retLen);
                retCC = buf;
            }
        }
        return new String(retCC, 0, retLen);
    }

    /**
     * Appends the URL escape sequence for the specified char to the
     * specified StringBuffer.
     */
    private static int escape(char[] cc, char c, int index) {
        cc[index++] = '%';
        cc[index++] = Character.forDigit((c >> 4) & 0xF, 16);
        cc[index++] = Character.forDigit(c & 0xF, 16);
        return index;
    }

    /**
     * Un-escape and return the character at position i in string s.
     */
    private static byte unescape(String s, int i) {
        return (byte) Integer.parseInt(s.substring(i+1,i+3),16);
    }


    /**
     * Returns a new String constructed from the specified String by replacing
     * the URL escape sequences and UTF8 encoding with the characters they
     * represent.
     */
    public static String decode(String s) {
        int n = s.length();
        if ((n == 0) || (s.indexOf('%') < 0))
            return s;

        StringBuilder sb = new StringBuilder(n);
        ByteBuffer bb = ByteBuffer.allocate(n);
        CharBuffer cb = CharBuffer.allocate(n);
        CharsetDecoder dec = ThreadLocalCoders.decoderFor("UTF-8");

        char c = s.charAt(0);
        for (int i = 0; i < n;) {
            assert c == s.charAt(i);
            if (c != '%') {
                sb.append(c);
                if (++i >= n)
                    break;
                c = s.charAt(i);
                continue;
            }
            bb.clear();
            int ui = i;
            for (;;) {
                assert (n - i >= 2);
                try {
                    bb.put(unescape(s, i));
                } catch (NumberFormatException e) {
                    throw new IllegalArgumentException();
                }
                i += 3;
                if (i >= n)
                    break;
                c = s.charAt(i);
                if (c != '%')
                    break;
            }
            bb.flip();
            cb.clear();
            dec.reset();
            CoderResult cr = dec.decode(bb, cb, true);
            if (cr.isError())
                throw new IllegalArgumentException("Error decoding percent encoded characters");
            cr = dec.flush(cb);
            if (cr.isError())
                throw new IllegalArgumentException("Error decoding percent encoded characters");
            sb.append(cb.flip().toString());
        }

        return sb.toString();
    }

    /**
     * Returns a canonical version of the specified string.
     */
    public String canonizeString(String file) {
        int i = 0;
        int lim = file.length();

        // Remove embedded /../
        while ((i = file.indexOf("/../")) >= 0) {
            if ((lim = file.lastIndexOf('/', i - 1)) >= 0) {
                file = file.substring(0, lim) + file.substring(i + 3);
            } else {
                file = file.substring(i + 3);
            }
        }
        // Remove embedded /./
        while ((i = file.indexOf("/./")) >= 0) {
            file = file.substring(0, i) + file.substring(i + 2);
        }
        // Remove trailing ..
        while (file.endsWith("/..")) {
            i = file.indexOf("/..");
            if ((lim = file.lastIndexOf('/', i - 1)) >= 0) {
                file = file.substring(0, lim+1);
            } else {
                file = file.substring(0, i);
            }
        }
        // Remove trailing .
        if (file.endsWith("/."))
            file = file.substring(0, file.length() -1);

        return file;
    }

    public static URL fileToEncodedURL(File file)
        throws MalformedURLException
    {
        String path = file.getAbsolutePath();
        path = ParseUtil.encodePath(path);
        if (!path.startsWith("/")) {
            path = "/" + path;
        }
        if (!path.endsWith("/") && file.isDirectory()) {
            path = path + "/";
        }
        return new URL("file", "", path);
    }

    public static java.net.URI toURI(URL url) {
        String protocol = url.getProtocol();
        String auth = url.getAuthority();
        String path = url.getPath();
        String query = url.getQuery();
        String ref = url.getRef();
        if (path != null && !(path.startsWith("/")))
            path = "/" + path;

        //
        // In java.net.URI class, a port number of -1 implies the default
        // port number. So get it stripped off before creating URI instance.
        //
        if (auth != null && auth.endsWith(":-1"))
            auth = auth.substring(0, auth.length() - 3);

        java.net.URI uri;
        try {
            uri = createURI(protocol, auth, path, query, ref);
        } catch (java.net.URISyntaxException e) {
            uri = null;
        }
        return uri;
    }

    //
    // createURI() and its auxiliary code are cloned from java.net.URI.
    // Most of the code are just copy and paste, except that quote()
    // has been modified to avoid double-escape.
    //
    // Usually it is unacceptable, but we're forced to do it because
    // otherwise we need to change public API, namely java.net.URI's
    // multi-argument constructors. It turns out that the changes cause
    // incompatibilities so can't be done.
    //
    private static URI createURI(String scheme,
                                 String authority,
                                 String path,
                                 String query,
                                 String fragment) throws URISyntaxException
    {
        String s = toString(scheme, null,
                            authority, null, null, -1,
                            path, query, fragment);
        checkPath(s, scheme, path);
        return new URI(s);
    }

    private static String toString(String scheme,
                            String opaquePart,
                            String authority,
                            String userInfo,
                            String host,
                            int port,
                            String path,
                            String query,
                            String fragment)
    {
        StringBuffer sb = new StringBuffer();
        if (scheme != null) {
            sb.append(scheme);
            sb.append(':');
        }
        appendSchemeSpecificPart(sb, opaquePart,
                                 authority, userInfo, host, port,
                                 path, query);
        appendFragment(sb, fragment);
        return sb.toString();
    }

    private static void appendSchemeSpecificPart(StringBuffer sb,
                                          String opaquePart,
                                          String authority,
                                          String userInfo,
                                          String host,
                                          int port,
                                          String path,
                                          String query)
    {
        if (opaquePart != null) {
            /* check if SSP begins with an IPv6 address
             * because we must not quote a literal IPv6 address
             */
            if (opaquePart.startsWith("//[")) {
                int end =  opaquePart.indexOf("]");
                if (end != -1 && opaquePart.indexOf(":")!=-1) {
                    String doquote, dontquote;
                    if (end == opaquePart.length()) {
                        dontquote = opaquePart;
                        doquote = "";
                    } else {
                        dontquote = opaquePart.substring(0,end+1);
                        doquote = opaquePart.substring(end+1);
                    }
                    sb.append (dontquote);
                    sb.append(quote(doquote, L_URIC, H_URIC));
                }
            } else {
                sb.append(quote(opaquePart, L_URIC, H_URIC));
            }
        } else {
            appendAuthority(sb, authority, userInfo, host, port);
            if (path != null)
                sb.append(quote(path, L_PATH, H_PATH));
            if (query != null) {
                sb.append('?');
                sb.append(quote(query, L_URIC, H_URIC));
            }
        }
    }

    private static void appendAuthority(StringBuffer sb,
                                 String authority,
                                 String userInfo,
                                 String host,
                                 int port)
    {
        if (host != null) {
            sb.append("//");
            if (userInfo != null) {
                sb.append(quote(userInfo, L_USERINFO, H_USERINFO));
                sb.append('@');
            }
            boolean needBrackets = ((host.indexOf(':') >= 0)
                                    && !host.startsWith("[")
                                    && !host.endsWith("]"));
            if (needBrackets) sb.append('[');
            sb.append(host);
            if (needBrackets) sb.append(']');
            if (port != -1) {
                sb.append(':');
                sb.append(port);
            }
        } else if (authority != null) {
            sb.append("//");
            if (authority.startsWith("[")) {
                int end = authority.indexOf("]");
                if (end != -1 && authority.indexOf(":")!=-1) {
                    String doquote, dontquote;
                    if (end == authority.length()) {
                        dontquote = authority;
                        doquote = "";
                    } else {
                        dontquote = authority.substring(0,end+1);
                        doquote = authority.substring(end+1);
                    }
                    sb.append (dontquote);
                    sb.append(quote(doquote,
                            L_REG_NAME | L_SERVER,
                            H_REG_NAME | H_SERVER));
                }
            } else {
                sb.append(quote(authority,
                            L_REG_NAME | L_SERVER,
                            H_REG_NAME | H_SERVER));
            }
        }
    }

    private static void appendFragment(StringBuffer sb, String fragment) {
        if (fragment != null) {
            sb.append('#');
            sb.append(quote(fragment, L_URIC, H_URIC));
        }
    }

    // Quote any characters in s that are not permitted
    // by the given mask pair
    //
    private static String quote(String s, long lowMask, long highMask) {
        int n = s.length();
        StringBuffer sb = null;
        boolean allowNonASCII = ((lowMask & L_ESCAPED) != 0);
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c < '\u0080') {
                if (!match(c, lowMask, highMask) && !isEscaped(s, i)) {
                    if (sb == null) {
                        sb = new StringBuffer();
                        sb.append(s.substring(0, i));
                    }
                    appendEscape(sb, (byte)c);
                } else {
                    if (sb != null)
                        sb.append(c);
                }
            } else if (allowNonASCII
                       && (Character.isSpaceChar(c)
                           || Character.isISOControl(c))) {
                if (sb == null) {
                    sb = new StringBuffer();
                    sb.append(s.substring(0, i));
                }
                appendEncoded(sb, c);
            } else {
                if (sb != null)
                    sb.append(c);
            }
        }
        return (sb == null) ? s : sb.toString();
    }

    //
    // To check if the given string has an escaped triplet
    // at the given position
    //
    private static boolean isEscaped(String s, int pos) {
        if (s == null || (s.length() <= (pos + 2)))
            return false;

        return s.charAt(pos) == '%'
               && match(s.charAt(pos + 1), L_HEX, H_HEX)
               && match(s.charAt(pos + 2), L_HEX, H_HEX);
    }

    private static void appendEncoded(StringBuffer sb, char c) {
        ByteBuffer bb = null;
        try {
            bb = ThreadLocalCoders.encoderFor("UTF-8")
                .encode(CharBuffer.wrap("" + c));
        } catch (CharacterCodingException x) {
            assert false;
        }
        while (bb.hasRemaining()) {
            int b = bb.get() & 0xff;
            if (b >= 0x80)
                appendEscape(sb, (byte)b);
            else
                sb.append((char)b);
        }
    }

    private final static char[] hexDigits = {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
    };

    private static void appendEscape(StringBuffer sb, byte b) {
        sb.append('%');
        sb.append(hexDigits[(b >> 4) & 0x0f]);
        sb.append(hexDigits[(b >> 0) & 0x0f]);
    }

    // Tell whether the given character is permitted by the given mask pair
    private static boolean match(char c, long lowMask, long highMask) {
        if (c < 64)
            return ((1L << c) & lowMask) != 0;
        if (c < 128)
            return ((1L << (c - 64)) & highMask) != 0;
        return false;
    }

    // If a scheme is given then the path, if given, must be absolute
    //
    private static void checkPath(String s, String scheme, String path)
        throws URISyntaxException
    {
        if (scheme != null) {
            if ((path != null)
                && ((path.length() > 0) && (path.charAt(0) != '/')))
                throw new URISyntaxException(s,
                                             "Relative path in absolute URI");
        }
    }


    // -- Character classes for parsing --

    // Compute a low-order mask for the characters
    // between first and last, inclusive
    private static long lowMask(char first, char last) {
        long m = 0;
        int f = Math.max(Math.min(first, 63), 0);
        int l = Math.max(Math.min(last, 63), 0);
        for (int i = f; i <= l; i++)
            m |= 1L << i;
        return m;
    }

    // Compute the low-order mask for the characters in the given string
    private static long lowMask(String chars) {
        int n = chars.length();
        long m = 0;
        for (int i = 0; i < n; i++) {
            char c = chars.charAt(i);
            if (c < 64)
                m |= (1L << c);
        }
        return m;
    }

    // Compute a high-order mask for the characters
    // between first and last, inclusive
    private static long highMask(char first, char last) {
        long m = 0;
        int f = Math.max(Math.min(first, 127), 64) - 64;
        int l = Math.max(Math.min(last, 127), 64) - 64;
        for (int i = f; i <= l; i++)
            m |= 1L << i;
        return m;
    }

    // Compute the high-order mask for the characters in the given string
    private static long highMask(String chars) {
        int n = chars.length();
        long m = 0;
        for (int i = 0; i < n; i++) {
            char c = chars.charAt(i);
            if ((c >= 64) && (c < 128))
                m |= (1L << (c - 64));
        }
        return m;
    }


    // Character-class masks

    // digit    = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" |
    //            "8" | "9"
    private static final long L_DIGIT = lowMask('0', '9');
    private static final long H_DIGIT = 0L;

    // hex           =  digit | "A" | "B" | "C" | "D" | "E" | "F" |
    //                          "a" | "b" | "c" | "d" | "e" | "f"
    private static final long L_HEX = L_DIGIT;
    private static final long H_HEX = highMask('A', 'F') | highMask('a', 'f');

    // upalpha  = "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" |
    //            "J" | "K" | "L" | "M" | "N" | "O" | "P" | "Q" | "R" |
    //            "S" | "T" | "U" | "V" | "W" | "X" | "Y" | "Z"
    private static final long L_UPALPHA = 0L;
    private static final long H_UPALPHA = highMask('A', 'Z');

    // lowalpha = "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" |
    //            "j" | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r" |
    //            "s" | "t" | "u" | "v" | "w" | "x" | "y" | "z"
    private static final long L_LOWALPHA = 0L;
    private static final long H_LOWALPHA = highMask('a', 'z');

    // alpha         = lowalpha | upalpha
    private static final long L_ALPHA = L_LOWALPHA | L_UPALPHA;
    private static final long H_ALPHA = H_LOWALPHA | H_UPALPHA;

    // alphanum      = alpha | digit
    private static final long L_ALPHANUM = L_DIGIT | L_ALPHA;
    private static final long H_ALPHANUM = H_DIGIT | H_ALPHA;

    // mark          = "-" | "_" | "." | "!" | "~" | "*" | "'" |
    //                 "(" | ")"
    private static final long L_MARK = lowMask("-_.!~*'()");
    private static final long H_MARK = highMask("-_.!~*'()");

    // unreserved    = alphanum | mark
    private static final long L_UNRESERVED = L_ALPHANUM | L_MARK;
    private static final long H_UNRESERVED = H_ALPHANUM | H_MARK;

    // reserved      = ";" | "/" | "?" | ":" | "@" | "&" | "=" | "+" |
    //                 "$" | "," | "[" | "]"
    // Added per RFC2732: "[", "]"
    private static final long L_RESERVED = lowMask(";/?:@&=+$,[]");
    private static final long H_RESERVED = highMask(";/?:@&=+$,[]");

    // The zero'th bit is used to indicate that escape pairs and non-US-ASCII
    // characters are allowed; this is handled by the scanEscape method below.
    private static final long L_ESCAPED = 1L;
    private static final long H_ESCAPED = 0L;

    // Dash, for use in domainlabel and toplabel
    private static final long L_DASH = lowMask("-");
    private static final long H_DASH = highMask("-");

    // uric          = reserved | unreserved | escaped
    private static final long L_URIC = L_RESERVED | L_UNRESERVED | L_ESCAPED;
    private static final long H_URIC = H_RESERVED | H_UNRESERVED | H_ESCAPED;

    // pchar         = unreserved | escaped |
    //                 ":" | "@" | "&" | "=" | "+" | "$" | ","
    private static final long L_PCHAR
        = L_UNRESERVED | L_ESCAPED | lowMask(":@&=+$,");
    private static final long H_PCHAR
        = H_UNRESERVED | H_ESCAPED | highMask(":@&=+$,");

    // All valid path characters
    private static final long L_PATH = L_PCHAR | lowMask(";/");
    private static final long H_PATH = H_PCHAR | highMask(";/");

    // userinfo      = *( unreserved | escaped |
    //                    ";" | ":" | "&" | "=" | "+" | "$" | "," )
    private static final long L_USERINFO
        = L_UNRESERVED | L_ESCAPED | lowMask(";:&=+$,");
    private static final long H_USERINFO
        = H_UNRESERVED | H_ESCAPED | highMask(";:&=+$,");

    // reg_name      = 1*( unreserved | escaped | "$" | "," |
    //                     ";" | ":" | "@" | "&" | "=" | "+" )
    private static final long L_REG_NAME
        = L_UNRESERVED | L_ESCAPED | lowMask("$,;:@&=+");
    private static final long H_REG_NAME
        = H_UNRESERVED | H_ESCAPED | highMask("$,;:@&=+");

    // All valid characters for server-based authorities
    private static final long L_SERVER
        = L_USERINFO | L_ALPHANUM | L_DASH | lowMask(".:@[]");
    private static final long H_SERVER
        = H_USERINFO | H_ALPHANUM | H_DASH | highMask(".:@[]");
}

class CodingErrorAction {

    private String name;

    private CodingErrorAction(String name) {
        this.name = name;
    }

    /**
     * Action indicating that a coding error is to be handled by dropping the
     * erroneous input and resuming the coding operation.
     */
    public static final CodingErrorAction IGNORE
        = new CodingErrorAction("IGNORE");

    /**
     * Action indicating that a coding error is to be handled by dropping the
     * erroneous input, appending the coder's replacement value to the output
     * buffer, and resuming the coding operation.
     */
    public static final CodingErrorAction REPLACE
        = new CodingErrorAction("REPLACE");

    /**
     * Action indicating that a coding error is to be reported, either by
     * returning a {@link CoderResult} object or by throwing a {@link
     * CharacterCodingException}, whichever is appropriate for the method
     * implementing the coding process.
     */
    public static final CodingErrorAction REPORT
        = new CodingErrorAction("REPORT");

    /**
     * Returns a string describing this action.
     *
     * @return  A descriptive string
     */
    public String toString() {
        return name;
    }

}

class Providers {

    private static final ThreadLocal<ProviderList> threadLists =
        new InheritableThreadLocal<>();

    // number of threads currently using thread-local provider lists
    // tracked to allow an optimization if == 0
    private static volatile int threadListsUsed;

    // current system-wide provider list
    // Note volatile immutable object, so no synchronization needed.
    private static volatile ProviderList providerList;

    static {
        // set providerList to empty list first in case initialization somehow
        // triggers a getInstance() call (although that should not happen)
        providerList = ProviderList.EMPTY;
        providerList = ProviderList.fromSecurityProperties();
    }

    private Providers() {
        // empty
    }

    // we need special handling to resolve circularities when loading
    // signed JAR files during startup. The code below is part of that.

    // Basically, before we load data from a signed JAR file, we parse
    // the PKCS#7 file and verify the signature. We need a
    // CertificateFactory, Signatures, etc. to do that. We have to make
    // sure that we do not try to load the implementation from the JAR
    // file we are just verifying.
    //
    // To avoid that, we use different provider settings during JAR
    // verification.  However, we do not want those provider settings to
    // interfere with other parts of the system. Therefore, we make them local
    // to the Thread executing the JAR verification code.
    //
    // The code here is used by sun.security.util.SignatureFileVerifier.
    // See there for details.

    private static final String BACKUP_PROVIDER_CLASSNAME =
        "sun.security.provider.VerificationProvider";

    // Hardcoded classnames of providers to use for JAR verification.
    // MUST NOT be on the bootclasspath and not in signed JAR files.
    private static final String[] jarVerificationProviders = {
        "sun.security.provider.Sun",
        "sun.security.rsa.SunRsaSign",
        // Note: SunEC *is* in a signed JAR file, but it's not signed
        // by EC itself. So it's still safe to be listed here.
        "sun.security.ec.SunEC",
        "com.sun.crypto.provider.SunJCE",
        BACKUP_PROVIDER_CLASSNAME,
    };

    // Return to Sun provider or its backup.
    // This method should only be called by
    // sun.security.util.ManifestEntryVerifier and java.security.SecureRandom.
    public static Provider getSunProvider() {
        try {
            Class<?> clazz = Class.forName(jarVerificationProviders[0]);
            return (Provider)clazz.newInstance();
        } catch (Exception e) {
            try {
                Class<?> clazz = Class.forName(BACKUP_PROVIDER_CLASSNAME);
                return (Provider)clazz.newInstance();
            } catch (Exception ee) {
                throw new RuntimeException("Sun provider not found", e);
            }
        }
    }

    /**
     * Start JAR verification. This sets a special provider list for
     * the current thread. You MUST save the return value from this
     * method and you MUST call stopJarVerification() with that object
     * once you are done.
     */
    public static Object startJarVerification() {
        ProviderList currentList = getProviderList();
        ProviderList jarList = currentList.getJarList(jarVerificationProviders);
        // return the old thread-local provider list, usually null
        return beginThreadProviderList(jarList);
    }

    /**
     * Stop JAR verification. Call once you have completed JAR verification.
     */
    public static void stopJarVerification(Object obj) {
        // restore old thread-local provider list
        endThreadProviderList((ProviderList)obj);
    }

    /**
     * Return the current ProviderList. If the thread-local list is set,
     * it is returned. Otherwise, the system wide list is returned.
     */
    public static ProviderList getProviderList() {
        ProviderList list = getThreadProviderList();
        if (list == null) {
            list = getSystemProviderList();
        }
        return list;
    }

    /**
     * Set the current ProviderList. Affects the thread-local list if set,
     * otherwise the system wide list.
     */
    public static void setProviderList(ProviderList newList) {
        if (getThreadProviderList() == null) {
            setSystemProviderList(newList);
        } else {
            changeThreadProviderList(newList);
        }
    }

    /**
     * Get the full provider list with invalid providers (those that
     * could not be loaded) removed. This is the list we need to
     * present to applications.
     */
    public static ProviderList getFullProviderList() {
        ProviderList list;
        synchronized (Providers.class) {
            list = getThreadProviderList();
            if (list != null) {
                ProviderList newList = list.removeInvalid();
                if (newList != list) {
                    changeThreadProviderList(newList);
                    list = newList;
                }
                return list;
            }
        }
        list = getSystemProviderList();
        ProviderList newList = list.removeInvalid();
        if (newList != list) {
            setSystemProviderList(newList);
            list = newList;
        }
        return list;
    }

    private static ProviderList getSystemProviderList() {
        return providerList;
    }

    private static void setSystemProviderList(ProviderList list) {
        providerList = list;
    }

    public static ProviderList getThreadProviderList() {
        // avoid accessing the threadlocal if none are currently in use
        // (first use of ThreadLocal.get() for a Thread allocates a Map)
        if (threadListsUsed == 0) {
            return null;
        }
        return threadLists.get();
    }

    // Change the thread local provider list. Use only if the current thread
    // is already using a thread local list and you want to change it in place.
    // In other cases, use the begin/endThreadProviderList() methods.
    private static void changeThreadProviderList(ProviderList list) {
        threadLists.set(list);
    }

    /**
     * Methods to manipulate the thread local provider list. It is for use by
     * JAR verification (see above) and the SunJSSE FIPS mode only.
     *
     * It should be used as follows:
     *
     *   ProviderList list = ...;
     *   ProviderList oldList = Providers.beginThreadProviderList(list);
     *   try {
     *     // code that needs thread local provider list
     *   } finally {
     *     Providers.endThreadProviderList(oldList);
     *   }
     *
     */

    public static synchronized ProviderList beginThreadProviderList(ProviderList list) {
        if (ProviderList.debug != null) {
            ProviderList.debug.println("ThreadLocal providers: " + list);
        }
        ProviderList oldList = threadLists.get();
        threadListsUsed++;
        threadLists.set(list);
        return oldList;
    }

    public static synchronized void endThreadProviderList(ProviderList list) {
        if (list == null) {
            if (ProviderList.debug != null) {
                ProviderList.debug.println("Disabling ThreadLocal providers");
            }
            threadLists.remove();
        } else {
            if (ProviderList.debug != null) {
                ProviderList.debug.println
                    ("Restoring previous ThreadLocal providers: " + list);
            }
            threadLists.set(list);
        }
        threadListsUsed--;
    }

}

class ThreadLocalCoders {

    private static final int CACHE_SIZE = 3;

    private static abstract class Cache {

        // Thread-local reference to array of cached objects, in LRU order
        private ThreadLocal<Object[]> cache = new ThreadLocal<>();
        private final int size;

        Cache(int size) {
            this.size = size;
        }

        abstract Object create(Object name);

        private void moveToFront(Object[] oa, int i) {
            Object ob = oa[i];
            for (int j = i; j > 0; j--)
                oa[j] = oa[j - 1];
            oa[0] = ob;
        }

        abstract boolean hasName(Object ob, Object name);

        Object forName(Object name) {
            Object[] oa = cache.get();
            if (oa == null) {
                oa = new Object[size];
                cache.set(oa);
            } else {
                for (int i = 0; i < oa.length; i++) {
                    Object ob = oa[i];
                    if (ob == null)
                        continue;
                    if (hasName(ob, name)) {
                        if (i > 0)
                            moveToFront(oa, i);
                        return ob;
                    }
                }
            }

            // Create a new object
            Object ob = create(name);
            oa[oa.length - 1] = ob;
            moveToFront(oa, oa.length - 1);
            return ob;
        }

    }

    private static Cache decoderCache = new Cache(CACHE_SIZE) {
            boolean hasName(Object ob, Object name) {
                if (name instanceof String)
                    return (((CharsetDecoder)ob).charset().name().equals(name));
                if (name instanceof Charset)
                    return ((CharsetDecoder)ob).charset().equals(name);
                return false;
            }
            Object create(Object name) {
                if (name instanceof String)
                    return Charset.forName((String)name).newDecoder();
                if (name instanceof Charset)
                    return ((Charset)name).newDecoder();
                assert false;
                return null;
            }
        };

    public static CharsetDecoder decoderFor(Object name) {
        CharsetDecoder cd = (CharsetDecoder)decoderCache.forName(name);
        cd.reset();
        return cd;
    }

    private static Cache encoderCache = new Cache(CACHE_SIZE) {
            boolean hasName(Object ob, Object name) {
                if (name instanceof String)
                    return (((CharsetEncoder)ob).charset().name().equals(name));
                if (name instanceof Charset)
                    return ((CharsetEncoder)ob).charset().equals(name);
                return false;
            }
            Object create(Object name) {
                if (name instanceof String)
                    return Charset.forName((String)name).newEncoder();
                if (name instanceof Charset)
                    return ((Charset)name).newEncoder();
                assert false;
                return null;
            }
        };

    public static CharsetEncoder encoderFor(Object name) {
        CharsetEncoder ce = (CharsetEncoder)encoderCache.forName(name);
        ce.reset();
        return ce;
    }

}

class GetPropertyAction implements PrivilegedAction<String> {
    private String theProp;
    private String defaultVal;

    /**
     * Constructor that takes the name of the system property whose
     * string value needs to be determined.
     *
     * @param theProp the name of the system property.
     */
    public GetPropertyAction(String theProp) {
        this.theProp = theProp;
    }

    /**
     * Constructor that takes the name of the system property and the default
     * value of that property.
     *
     * @param theProp the name of the system property.
     * @param defaulVal the default value.
     */
    public GetPropertyAction(String theProp, String defaultVal) {
        this.theProp = theProp;
        this.defaultVal = defaultVal;
    }

    /**
     * Determines the string value of the system property whose
     * name was specified in the constructor.
     *
     * @return the string value of the system property,
     *         or the default value if there is no property with that key.
     */
    public String run() {
        String value = System.getProperty(theProp);
        return (value == null) ? defaultVal : value;
    }

    /**
     * Convenience method to get a property without going through doPrivileged
     * if no security manager is present. This is unsafe for inclusion in a
     * public API but allowable here since this class is by default restricted
     * by the package.access security property.
     *
     * Note that this method performs a privileged action using caller-provided
     * inputs. The caller of this method should take care to ensure that the
     * inputs are not tainted and the returned property is not made accessible
     * to untrusted code if it contains sensitive information.
     *
     * @param theProp the name of the system property.
     */
    public static String privilegedGetProperty(String theProp) {
        if (System.getSecurityManager() == null) {
            return System.getProperty(theProp);
        } else {
            return AccessController.doPrivileged(
                    new GetPropertyAction(theProp));
        }
    }

    /**
     * Convenience method to get a property without going through doPrivileged
     * if no security manager is present. This is unsafe for inclusion in a
     * public API but allowable here since this class is now encapsulated.
     *
     * Note that this method performs a privileged action using caller-provided
     * inputs. The caller of this method should take care to ensure that the
     * inputs are not tainted and the returned property is not made accessible
     * to untrusted code if it contains sensitive information.
     *
     * @param theProp the name of the system property.
     * @param defaultVal the default value.
     */
    public static String privilegedGetProperty(String theProp,
            String defaultVal) {
        if (System.getSecurityManager() == null) {
            return System.getProperty(theProp, defaultVal);
        } else {
            return AccessController.doPrivileged(
                    new GetPropertyAction(theProp, defaultVal));
        }
    }
}

class GenericArrayTypeImpl
    implements GenericArrayType {
    private final Type genericComponentType;

    // private constructor enforces use of static factory
    private GenericArrayTypeImpl(Type ct) {
        genericComponentType = ct;
    }

    /**
     * Factory method.
     * @param ct - the desired component type of the generic array type
     * being created
     * @return a generic array type with the desired component type
     */
    public static GenericArrayTypeImpl make(Type ct) {
        return new GenericArrayTypeImpl(ct);
    }


    /**
     * Returns  a <tt>Type</tt> object representing the component type
     * of this array.
     *
     * @return  a <tt>Type</tt> object representing the component type
     *     of this array
     * @since 1.5
     */
    public Type getGenericComponentType() {
        return genericComponentType; // return cached component type
    }

    public String toString() {
        Type componentType = getGenericComponentType();
        StringBuilder sb = new StringBuilder();

        if (componentType instanceof Class)
            sb.append(((Class)componentType).getName() );
        else
            sb.append(componentType.toString());
        sb.append("[]");
        return sb.toString();
    }

    @Override
    public boolean equals(Object o) {
        if (o instanceof GenericArrayType) {
            GenericArrayType that = (GenericArrayType) o;

            return Objects.equals(genericComponentType, that.getGenericComponentType());
        } else
            return false;
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(genericComponentType);
    }
}

class ClassSignature implements Signature {
    private final FormalTypeParameter[] formalTypeParams;
    private final ClassTypeSignature superclass;
    private final ClassTypeSignature[] superInterfaces;

    private ClassSignature(FormalTypeParameter[] ftps,
                                      ClassTypeSignature sc,
                                      ClassTypeSignature[] sis) {
        formalTypeParams = ftps;
        superclass = sc;
        superInterfaces = sis;
    }

    public static ClassSignature make(FormalTypeParameter[] ftps,
                                      ClassTypeSignature sc,
                                      ClassTypeSignature[] sis) {
        return new ClassSignature(ftps, sc, sis);
    }

    public FormalTypeParameter[] getFormalTypeParameters(){
        return formalTypeParams;
    }
    public ClassTypeSignature getSuperclass(){return superclass;}
    public ClassTypeSignature[] getSuperInterfaces(){return superInterfaces;}

    public void accept(Visitor<?> v){v.visitClassSignature(this);}
}

class Wildcard implements TypeArgument {
    private FieldTypeSignature[] upperBounds;
    private FieldTypeSignature[] lowerBounds;

    private Wildcard(FieldTypeSignature[] ubs, FieldTypeSignature[] lbs) {
        upperBounds = ubs;
        lowerBounds = lbs;
    }

    private static final FieldTypeSignature[] emptyBounds = new FieldTypeSignature[0];

    public static Wildcard make(FieldTypeSignature[] ubs,
                                FieldTypeSignature[] lbs) {
        return new Wildcard(ubs, lbs);
    }

    public FieldTypeSignature[] getUpperBounds(){
        return upperBounds;
    }

    public FieldTypeSignature[] getLowerBounds(){
        if (lowerBounds.length == 1 &&
            lowerBounds[0] == BottomSignature.make())
            return emptyBounds;
        else
            return lowerBounds;
    }

    public void accept(TypeTreeVisitor<?> v){v.visitWildcard(this);}
}

class TypeVariableSignature implements FieldTypeSignature {
    private final String identifier;

    private TypeVariableSignature(String id) {identifier = id;}


    public static TypeVariableSignature make(String id) {
        return new TypeVariableSignature(id);
    }

    public String getIdentifier(){return identifier;}

    public void accept(TypeTreeVisitor<?> v){
        v.visitTypeVariableSignature(this);
    }
}

abstract class ExceptionProxy implements java.io.Serializable {
    protected abstract RuntimeException generateException();
}

interface TypeTreeVisitor<T> {

    /**
     * Returns the result of the visit.
     * @return the result of the visit
     */
    T getResult();

    // Visitor methods, per node type

    void visitFormalTypeParameter(FormalTypeParameter ftp);

    void visitClassTypeSignature(ClassTypeSignature ct);
    void visitArrayTypeSignature(ArrayTypeSignature a);
    void visitTypeVariableSignature(TypeVariableSignature tv);
    void visitWildcard(Wildcard w);

    void visitSimpleClassTypeSignature(SimpleClassTypeSignature sct);
    void visitBottomSignature(BottomSignature b);

    //  Primitives and Void
    void visitByteSignature(ByteSignature b);
    void visitBooleanSignature(BooleanSignature b);
    void visitShortSignature(ShortSignature s);
    void visitCharSignature(CharSignature c);
    void visitIntSignature(IntSignature i);
    void visitLongSignature(LongSignature l);
    void visitFloatSignature(FloatSignature f);
    void visitDoubleSignature(DoubleSignature d);

    void visitVoidDescriptor(VoidDescriptor v);
}

class AnnotationInvocationHandler implements InvocationHandler, Serializable {
    private static final long serialVersionUID = 6182022883658399397L;
    private final Class<? extends Annotation> type;
    private final Map<String, Object> memberValues;

    AnnotationInvocationHandler(Class<? extends Annotation> type, Map<String, Object> memberValues) {
        Class<?>[] superInterfaces = type.getInterfaces();
        if (!type.isAnnotation() ||
            superInterfaces.length != 1 ||
            superInterfaces[0] != java.lang.annotation.Annotation.class)
            throw new AnnotationFormatError("Attempt to create proxy for a non-annotation type.");
        this.type = type;
        this.memberValues = memberValues;
    }

    public Object invoke(Object proxy, Method method, Object[] args) {
        String member = method.getName();
        Class<?>[] paramTypes = method.getParameterTypes();

        // Handle Object and Annotation methods
        if (member.equals("equals") && paramTypes.length == 1 &&
            paramTypes[0] == Object.class)
            return equalsImpl(args[0]);
        if (paramTypes.length != 0)
            throw new AssertionError("Too many parameters for an annotation method");

        switch(member) {
        case "toString":
            return toStringImpl();
        case "hashCode":
            return hashCodeImpl();
        case "annotationType":
            return type;
        }

        // Handle annotation member accessors
        Object result = memberValues.get(member);

        if (result == null)
            throw new IncompleteAnnotationException(type, member);

        if (result instanceof ExceptionProxy)
            throw ((ExceptionProxy) result).generateException();

        if (result.getClass().isArray() && Array.getLength(result) != 0)
            result = cloneArray(result);

        return result;
    }

    /**
     * This method, which clones its array argument, would not be necessary
     * if Cloneable had a public clone method.
     */
    private Object cloneArray(Object array) {
        Class<?> type = array.getClass();

        if (type == byte[].class) {
            byte[] byteArray = (byte[])array;
            return byteArray.clone();
        }
        if (type == char[].class) {
            char[] charArray = (char[])array;
            return charArray.clone();
        }
        if (type == double[].class) {
            double[] doubleArray = (double[])array;
            return doubleArray.clone();
        }
        if (type == float[].class) {
            float[] floatArray = (float[])array;
            return floatArray.clone();
        }
        if (type == int[].class) {
            int[] intArray = (int[])array;
            return intArray.clone();
        }
        if (type == long[].class) {
            long[] longArray = (long[])array;
            return longArray.clone();
        }
        if (type == short[].class) {
            short[] shortArray = (short[])array;
            return shortArray.clone();
        }
        if (type == boolean[].class) {
            boolean[] booleanArray = (boolean[])array;
            return booleanArray.clone();
        }

        Object[] objectArray = (Object[])array;
        return objectArray.clone();
    }


    /**
     * Implementation of dynamicProxy.toString()
     */
    private String toStringImpl() {
        StringBuilder result = new StringBuilder(128);
        result.append('@');
        result.append(type.getName());
        result.append('(');
        boolean firstMember = true;
        for (Map.Entry<String, Object> e : memberValues.entrySet()) {
            if (firstMember)
                firstMember = false;
            else
                result.append(", ");

            result.append(e.getKey());
            result.append('=');
            result.append(memberValueToString(e.getValue()));
        }
        result.append(')');
        return result.toString();
    }

    /**
     * Translates a member value (in "dynamic proxy return form") into a string
     */
    private static String memberValueToString(Object value) {
        Class<?> type = value.getClass();
        if (!type.isArray())    // primitive, string, class, enum const,
                                // or annotation
            return value.toString();

        if (type == byte[].class)
            return Arrays.toString((byte[]) value);
        if (type == char[].class)
            return Arrays.toString((char[]) value);
        if (type == double[].class)
            return Arrays.toString((double[]) value);
        if (type == float[].class)
            return Arrays.toString((float[]) value);
        if (type == int[].class)
            return Arrays.toString((int[]) value);
        if (type == long[].class)
            return Arrays.toString((long[]) value);
        if (type == short[].class)
            return Arrays.toString((short[]) value);
        if (type == boolean[].class)
            return Arrays.toString((boolean[]) value);
        return Arrays.toString((Object[]) value);
    }

    /**
     * Implementation of dynamicProxy.equals(Object o)
     */
    private Boolean equalsImpl(Object o) {
        if (o == this)
            return true;

        if (!type.isInstance(o))
            return false;
        for (Method memberMethod : getMemberMethods()) {
            String member = memberMethod.getName();
            Object ourValue = memberValues.get(member);
            Object hisValue = null;
            AnnotationInvocationHandler hisHandler = asOneOfUs(o);
            if (hisHandler != null) {
                hisValue = hisHandler.memberValues.get(member);
            } else {
                try {
                    hisValue = memberMethod.invoke(o);
                } catch (InvocationTargetException e) {
                    return false;
                } catch (IllegalAccessException e) {
                    throw new AssertionError(e);
                }
            }
            if (!memberValueEquals(ourValue, hisValue))
                return false;
        }
        return true;
    }

    /**
     * Returns an object's invocation handler if that object is a dynamic
     * proxy with a handler of type AnnotationInvocationHandler.
     * Returns null otherwise.
     */
    private AnnotationInvocationHandler asOneOfUs(Object o) {
        if (Proxy.isProxyClass(o.getClass())) {
            InvocationHandler handler = Proxy.getInvocationHandler(o);
            if (handler instanceof AnnotationInvocationHandler)
                return (AnnotationInvocationHandler) handler;
        }
        return null;
    }

    /**
     * Returns true iff the two member values in "dynamic proxy return form"
     * are equal using the appropriate equality function depending on the
     * member type.  The two values will be of the same type unless one of
     * the containing annotations is ill-formed.  If one of the containing
     * annotations is ill-formed, this method will return false unless the
     * two members are identical object references.
     */
    private static boolean memberValueEquals(Object v1, Object v2) {
        Class<?> type = v1.getClass();

        // Check for primitive, string, class, enum const, annotation,
        // or ExceptionProxy
        if (!type.isArray())
            return v1.equals(v2);

        // Check for array of string, class, enum const, annotation,
        // or ExceptionProxy
        if (v1 instanceof Object[] && v2 instanceof Object[])
            return Arrays.equals((Object[]) v1, (Object[]) v2);

        // Check for ill formed annotation(s)
        if (v2.getClass() != type)
            return false;

        // Deal with array of primitives
        if (type == byte[].class)
            return Arrays.equals((byte[]) v1, (byte[]) v2);
        if (type == char[].class)
            return Arrays.equals((char[]) v1, (char[]) v2);
        if (type == double[].class)
            return Arrays.equals((double[]) v1, (double[]) v2);
        if (type == float[].class)
            return Arrays.equals((float[]) v1, (float[]) v2);
        if (type == int[].class)
            return Arrays.equals((int[]) v1, (int[]) v2);
        if (type == long[].class)
            return Arrays.equals((long[]) v1, (long[]) v2);
        if (type == short[].class)
            return Arrays.equals((short[]) v1, (short[]) v2);
        assert type == boolean[].class;
        return Arrays.equals((boolean[]) v1, (boolean[]) v2);
    }

    /**
     * Returns the member methods for our annotation type.  These are
     * obtained lazily and cached, as they're expensive to obtain
     * and we only need them if our equals method is invoked (which should
     * be rare).
     */
    private Method[] getMemberMethods() {
        if (memberMethods == null) {
            memberMethods = AccessController.doPrivileged(
                new PrivilegedAction<Method[]>() {
                    public Method[] run() {
                        final Method[] mm = type.getDeclaredMethods();
                        validateAnnotationMethods(mm);
                        AccessibleObject.setAccessible(mm, true);
                        return mm;
                    }
                });
        }
        return memberMethods;
    }
    private transient volatile Method[] memberMethods = null;

    /**
     * Validates that a method is structurally appropriate for an
     * annotation type. As of Java SE 8, annotation types cannot
     * contain static methods and the declared methods of an
     * annotation type must take zero arguments and there are
     * restrictions on the return type.
     */
    private void validateAnnotationMethods(Method[] memberMethods) {
        /*
         * Specification citations below are from JLS
         * 9.6.1. Annotation Type Elements
         */
        boolean valid = true;
        for(Method method : memberMethods) {
            /*
             * "By virtue of the AnnotationTypeElementDeclaration
             * production, a method declaration in an annotation type
             * declaration cannot have formal parameters, type
             * parameters, or a throws clause.
             *
             * "By virtue of the AnnotationTypeElementModifier
             * production, a method declaration in an annotation type
             * declaration cannot be default or static."
             */
            if (method.getModifiers() != (Modifier.PUBLIC | Modifier.ABSTRACT) ||
                method.isDefault() ||
                method.getParameterCount() != 0 ||
                method.getExceptionTypes().length != 0) {
                valid = false;
                break;
            }

            /*
             * "It is a compile-time error if the return type of a
             * method declared in an annotation type is not one of the
             * following: a primitive type, String, Class, any
             * parameterized invocation of Class, an enum type
             * (section 8.9), an annotation type, or an array type
             * (chapter 10) whose element type is one of the preceding
             * types."
             */
            Class<?> returnType = method.getReturnType();
            if (returnType.isArray()) {
                returnType = returnType.getComponentType();
                if (returnType.isArray()) { // Only single dimensional arrays
                    valid = false;
                    break;
                }
            }

            if (!((returnType.isPrimitive() && returnType != void.class) ||
                  returnType == java.lang.String.class ||
                  returnType == java.lang.Class.class ||
                  returnType.isEnum() ||
                  returnType.isAnnotation())) {
                valid = false;
                break;
            }

            /*
             * "It is a compile-time error if any method declared in an
             * annotation type has a signature that is
             * override-equivalent to that of any public or protected
             * method declared in class Object or in the interface
             * java.lang.annotation.Annotation."
             *
             * The methods in Object or Annotation meeting the other
             * criteria (no arguments, contrained return type, etc.)
             * above are:
             *
             * String toString()
             * int hashCode()
             * Class<? extends Annotation> annotationType()
             */
            String methodName = method.getName();
            if ((methodName.equals("toString") && returnType == java.lang.String.class) ||
                (methodName.equals("hashCode") && returnType == int.class) ||
                (methodName.equals("annotationType") && returnType == java.lang.Class.class)) {
                valid = false;
                break;
            }
        }
        if (valid)
            return;
        else
            throw new AnnotationFormatError("Malformed method on an annotation type");
    }

    /**
     * Implementation of dynamicProxy.hashCode()
     */
    private int hashCodeImpl() {
        int result = 0;
        for (Map.Entry<String, Object> e : memberValues.entrySet()) {
            result += (127 * e.getKey().hashCode()) ^
                memberValueHashCode(e.getValue());
        }
        return result;
    }

    /**
     * Computes hashCode of a member value (in "dynamic proxy return form")
     */
    private static int memberValueHashCode(Object value) {
        Class<?> type = value.getClass();
        if (!type.isArray())    // primitive, string, class, enum const,
                                // or annotation
            return value.hashCode();

        if (type == byte[].class)
            return Arrays.hashCode((byte[]) value);
        if (type == char[].class)
            return Arrays.hashCode((char[]) value);
        if (type == double[].class)
            return Arrays.hashCode((double[]) value);
        if (type == float[].class)
            return Arrays.hashCode((float[]) value);
        if (type == int[].class)
            return Arrays.hashCode((int[]) value);
        if (type == long[].class)
            return Arrays.hashCode((long[]) value);
        if (type == short[].class)
            return Arrays.hashCode((short[]) value);
        if (type == boolean[].class)
            return Arrays.hashCode((boolean[]) value);
        return Arrays.hashCode((Object[]) value);
    }

    private void readObject(java.io.ObjectInputStream s)
        throws java.io.IOException, ClassNotFoundException {
        ObjectInputStream.GetField fields = s.readFields();

        @SuppressWarnings("unchecked")
        Class<? extends Annotation> t = (Class<? extends Annotation>)fields.get("type", null);
        @SuppressWarnings("unchecked")
        Map<String, Object> streamVals = (Map<String, Object>)fields.get("memberValues", null);

        // Check to make sure that types have not evolved incompatibly

        AnnotationType annotationType = null;
        try {
            annotationType = AnnotationType.getInstance(t);
        } catch(IllegalArgumentException e) {
            // Class is no longer an annotation type; time to punch out
            throw new java.io.InvalidObjectException("Non-annotation type in annotation serial stream");
        }

        Map<String, Class<?>> memberTypes = annotationType.memberTypes();
        // consistent with runtime Map type
        Map<String, Object> mv = new LinkedHashMap<>();

        // If there are annotation members without values, that
        // situation is handled by the invoke method.
        for (Map.Entry<String, Object> memberValue : streamVals.entrySet()) {
            String name = memberValue.getKey();
            Object value = null;
            Class<?> memberType = memberTypes.get(name);
            if (memberType != null) {  // i.e. member still exists
                value = memberValue.getValue();
                if (!(memberType.isInstance(value) ||
                      value instanceof ExceptionProxy)) {
                    value = new AnnotationTypeMismatchExceptionProxy(
                                objectToString(value))
                        .setMember(annotationType.members().get(name));
                }
            }
            mv.put(name, value);
        }

        UnsafeAccessor.setType(this, t);
        UnsafeAccessor.setMemberValues(this, mv);
    }

    /*
     * Create a textual representation of the argument without calling
     * any overridable methods of the argument.
     */
    private static String objectToString(Object value) {
        return value.getClass().getName() + "@" +
            Integer.toHexString(System.identityHashCode(value));
    }

    private static class UnsafeAccessor {
        private static final sun.misc.Unsafe unsafe;
        private static final long typeOffset;
        private static final long memberValuesOffset;
        static {
            try {
                unsafe = sun.misc.Unsafe.getUnsafe();
                typeOffset = unsafe.objectFieldOffset
                        (AnnotationInvocationHandler.class.getDeclaredField("type"));
                memberValuesOffset = unsafe.objectFieldOffset
                        (AnnotationInvocationHandler.class.getDeclaredField("memberValues"));
            } catch (Exception ex) {
                throw new ExceptionInInitializerError(ex);
            }
        }
        static void setType(AnnotationInvocationHandler o,
                            Class<? extends Annotation> type) {
            unsafe.putObject(o, typeOffset, type);
        }

        static void setMemberValues(AnnotationInvocationHandler o,
                                    Map<String, Object> memberValues) {
            unsafe.putObject(o, memberValuesOffset, memberValues);
        }
    }
}

interface Signature extends Tree{
    FormalTypeParameter[] getFormalTypeParameters();
}
