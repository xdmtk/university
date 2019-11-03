import java.math.*;
import java.util.Random;

class ArraySorts {

    public static void main(String[] args) {
        int a[] = UnitTests.generateRandomDataSet(100, 100);
        insertionSortIterative(a,a.length);
        UnitTests.prettyPrintArray(a,a.length);
    }


    public static void insertionSortIterative(int a[], int n) {

        /* Base case  - Do nothing */
        if (n <= 1) {}

        /* Otherwise begin iterative Insertion Sort */
        else
            /* Begin at element 1, compare with previous element */
            for (int i = 1; i < n; ++i)

                /* Previous element bigger? Initiate shift */
                if (a[i] < a[i-1]) Helpers.shift(a, i, 0);
    }
    public static void insertionSort(int a[], int n) {

    }
    public static void QuickSort1(int a[], int n, int cutoff) {

    }
    public static void HeapSortBU(int a[], int n){

    }

    public static String myName () {
        return "Nicholas Martinez";
    }
}


class pair {

    private int left, right;

    public pair(int left, int right) {
        this.left = left;
        this.right = right;
    }

    public int getLeft() {
        return left;
    }
    public int getRight() {
        return right;
    }
}


class Helpers {

    /**
     * Reusable in-place swap function. XOR's elements a[first] and a[second]
     * against each other repeatedly to swap values
     *
     * @param a - Array to operate on
     * @param first - First value
     * @param second - Second value
     */
    static void swap(int a[], int first, int second) {
        a[first] ^= a[second];
        a[second] ^= a[first];
        a[first] ^= a[second];
    }

    /**
     * Reusable shift function. Shifts lesser elements left
     * by continuously swapping until left element is less than the
     * current element
     *
     * @param a - Array to operate on
     * @param start - Index of element to shift
     * @param end - Index of limiting slice of a[]
     *
     */
    static void shift(int a[], int start, int end) {

        /* Begin iterating in reverse from current element */
        for (int j = start; j > end; --j)

            /* Swap elements successively ( shift ) until previous element is smaller */
            if (a[j] < a[j - 1]) Helpers.swap(a, j, j - 1);

            /* No need to iterate further after reaching smaller previous element, already
             * sorted */
            else break;
    }
}


class UnitTests {

    public static int[] generateRandomDataSet(int n, int lim) {
        int a[] = new int[n];
        Random randomGen = new Random();
        for (int i = 0; i < n; ++i)
            a[i] = randomGen.nextInt(lim);
        return a;
    }

    public static void prettyPrintArray(int a[], int n) {
        for (int i = 0; i < n; ) {
            for (int j = 0; j < 10 && i < n; ++j, ++i)
                System.out.print(a[i] + " ");
            System.out.print("\n");
        }
    }
}
