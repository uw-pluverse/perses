



public class EmptySwitch {
    public static void main(String[] args) {
        int arr[] = { 1, 2, 3 };
        int i = -1;
        try {
            switch (arr[--i]) {}
            throw new Error("oops");
        } catch (ArrayIndexOutOfBoundsException ex) {
            
        }
    }
}
