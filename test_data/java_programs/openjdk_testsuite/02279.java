

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;
import javax.tools.JavaCompiler;
import javax.tools.StandardJavaFileManager;
import javax.tools.ToolProvider;


public abstract class JavacTestingAbstractThreadedTest {

    protected static AtomicInteger numberOfThreads = new AtomicInteger();

    protected static int getThreadPoolSize() {
        Integer testConc = Integer.getInteger("test.concurrency");
        if (testConc != null) return testConc;
        int cores = Runtime.getRuntime().availableProcessors();
        numberOfThreads.set(Math.max(2, Math.min(8, cores / 2)));
        return numberOfThreads.get();
    }

    protected static void checkAfterExec() throws InterruptedException {
        checkAfterExec(true);
    };

    protected static boolean throwAssertionOnError = true;

    protected static boolean printAll = false;

    protected static StringWriter errSWriter = new StringWriter();
    protected static PrintWriter errWriter = new PrintWriter(errSWriter);

    protected static StringWriter outSWriter = new StringWriter();
    protected static PrintWriter outWriter = new PrintWriter(outSWriter);

    protected static void checkAfterExec(boolean printCheckCount)
            throws InterruptedException {
        pool.shutdown();
        pool.awaitTermination(15, TimeUnit.MINUTES);
        if (errCount.get() > 0) {
            if (throwAssertionOnError) {
                closePrinters();
                System.err.println(errSWriter.toString());
                throw new AssertionError(
                    String.format("%d errors found", errCount.get()));
            } else {
                System.err.println(
                        String.format("%d errors found", errCount.get()));
            }
        } else if (printCheckCount) {
            outWriter.println("Total check executed: " + checkCount.get());
        }
        
        closePrinters();
        if (printAll) {
            System.out.println(errSWriter.toString());
            System.out.println(outSWriter.toString());
        }
        System.out.println("Total number of threads in thread pool: " +
                numberOfThreads.get());
    }

    protected static void closePrinters() {
        errWriter.close();
        outWriter.close();
    }

    protected static void processException(Throwable t) {
        errCount.incrementAndGet();
        t.printStackTrace(errWriter);
        pool.shutdown();
    }

    
    protected static AtomicInteger checkCount = new AtomicInteger();

    
    protected static AtomicInteger errCount = new AtomicInteger();

    
    protected static JavaCompiler comp = ToolProvider.getSystemJavaCompiler();

    protected static ExecutorService pool = Executors.newFixedThreadPool(
            getThreadPoolSize(), new ThreadFactory() {
        @Override
        public Thread newThread(Runnable r) {
            Thread t = new Thread(r);
            t.setUncaughtExceptionHandler(new Thread.UncaughtExceptionHandler() {
                @Override
                public void uncaughtException(Thread t, Throwable e) {
                    pool.shutdown();
                    errCount.incrementAndGet();
                    e.printStackTrace(System.err);
                }
            });
            return t;
        }
    });

    
    protected static final ThreadLocal<StandardJavaFileManager> fm =
        new ThreadLocal<StandardJavaFileManager>() {
            @Override protected StandardJavaFileManager initialValue() {
                return comp.getStandardFileManager(null, null, null);
            }
        };

}
