



import java.net.URL;

public class T6257443
{
    public static void main(String[] args) {
        if (args.length != 2)
            throw new Error("wrong number of args");

        String state = args[0];
        String file = args[1];

        if (state.equals("-no")) {
            URL u = find(file);
            if (u != null)
                throw new Error("file " + file + " found unexpectedly");
        }
        else if (state.equals("-yes")) {
            URL u = find(file);
            if (u == null)
                throw new Error("file " + file + " not found");
        }
        else
            throw new Error("bad args");
    }

    public static URL find(String path) {
        return T6257443.class.getClassLoader().getSystemResource(path);
    }
}
