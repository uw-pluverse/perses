



import java.util.*;

public class T5070671 {
    void foo1() {
        Comparator<int[]> c = new Comparator<int[]>() {
            public int compare(int[] c1, int[] c2) { return 0; }
        };
        int[][] arr = { { 1 } };
        int[] elem = arr[0];
        Arrays.sort(arr, c);
        Arrays.binarySearch(arr, elem, c);
        Arrays.<int[]>binarySearch(arr, elem, c);
    }
    void foo2() {
        Comparator<Integer[]> c = new Comparator<Integer[]>() {
            public int compare(Integer[] c1, Integer[] c2) { return 0; }
        };
        Integer[][] arr = { { 1 } };
        Integer[] elem = arr[0];
        Arrays.sort(arr, c);
        Arrays.binarySearch(arr, elem, c);
    }
}
