package root.vending;

public class Main {
    //@ ensures \result <= a && \result <<= b;
    public static int min(int a, int b) {
        int result = a < b ? a : b;
        return result;
    }
    //@ ensures \forall int i; 0<i<array.length; \result<=array[i];
    static int findMin(int[] array) {
        int smallest = 1000;
        int i = 0;
        //@ loop_invariant 0<= i && i <= array.length;
        //@ loop_invariant \forall int j; 0<=j<i; smallest<=array[j];
        while (i < array.length) {
            int newSmallest = min(l, smallest);
            smallest = newSmallest;
            i = i + 1;
        }
        return smallest;
    }
}