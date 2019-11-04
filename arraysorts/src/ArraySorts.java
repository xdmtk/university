import com.sun.xml.internal.bind.v2.model.annotation.Quick;
import sun.applet.AppletResourceLoader;

import javax.swing.*;
import java.math.*;
import java.util.Arrays;
import java.util.Random;
import java.util.concurrent.Callable;

class ArraySorts {
    public static boolean debug = true;


    public static void main(String[] args) {
        UnitTests.execSort(UnitTests.SortMethod.QuickSort1, 100, 100 );
    }




    /**
     * Driver method for recursive insertion sort.
     *
     * @param a - Array to operate on
     * @param n - Length of array
     */
    public static void insertionSort(int a[], int n) {
        insertionSortRecursive(a,0,n);
    }

    /**
     * Recursive approach to Insertion Sort. Makes recursive calls for
     * 'n' slices of a[], each with a length of 'n-1' where 'n' is the length
     * of the last slice on the call stack
     *
     * @param a - Array to operate on
     * @param n - Length of array slice
     */
    private static void insertionSortRecursive(int a[], int begin, int n) {

        /* Base case  - Do nothing */
        if (n <= 1) {}

        /* Otherwise begin recursive Insertion Sort */
        else {

            /* Make recursive call to insertion sort on 1 less than current 'n' slice of a[] */
            insertionSortRecursive(a, begin, n - 1);

            /* Now iterate in reverse and shift, since the preceding slice of a[0] -> a[n-1]
             * will be already sorted */
            for (int i = n - 1; i > begin; --i)

                /* Previous element bigger? Initiate shift */
                if (a[i] < a[i - 1]) Helpers.shift(a, i, begin);
        }
    }

    /**
     * Iterative approach to Insertion Sort, requires no driver method
     *
     * @param a - Array to operate on
     * @param n - Length of array
     */
    public static void insertionSortIterative(int a[], int begin, int n) {

        /* Base case  - Do nothing */
        if (n <= 1) {}

        /* Otherwise begin iterative Insertion Sort */
        else
            /* Begin at element 1, compare with previous element */
            for (int i = begin+1; i < n; ++i)

                /* Previous element bigger? Initiate shift */
                if (a[i] < a[i-1]) Helpers.shift(a, i, begin);
    }





    public static void QuickSort1(int a[], int n, int cutoff) {
        QuickSort1(a, new pair(0,n), cutoff);
    }

    private static void QuickSort1(int a[], pair pivotIndex, int cutoff) {
        int[] aTemp;
        if (pivotIndex.getRight() - pivotIndex.getLeft() < 10) {
            insertionSortIterative(a,pivotIndex.getLeft(), pivotIndex.getRight());
        }
        else  {
        }
    }

    /**
     * Outside-in partitioning function. Random pivot is chosen, and left/right pointers
     * are moved successively from the outer bounds of the array, until they overlap,
     * swapping elements when greater/less conditions against the pivot are met.
     *
     * @param a - Array to operate on
     * @param left - Left index of array slice
     * @param right - Right index of array slice
     *
     * @return - pair - New pair of the modified left/right indices, with 'right' as the
     * outer bound of the left partition, and 'left' as the beginning index for the right partition
     */
    private static pair partitionOutsideIn(int a[], int left, int right)  {

        int pivot;
        Random randomGen;

        /* Base case - Do nothing */
        if (right - left < 1) {}

        /* Otherwise begin partitioning */
        else {

            randomGen = new Random();

            /* Get the pivot by generating a random index within the bounds of right - left,
             * then add left as the base index for the chosen random value  */
            pivot = a[left + randomGen.nextInt(right - left)];

            if (ArraySorts.debug) System.out.println("Pivot: " + pivot);

            /* Begin swapping elements until the left/right pointers overlap */
            while (left < right) {

                if (ArraySorts.debug) UnitTests.prettyPrintArray(a,a.length);

                /* Begin incrementing/decrementing left/right pointers until elements
                 * greater/less than the pivot are identified. */
                while (left < right && a[left] < pivot)
                    left++;
                while (right > left && a[right] > pivot)
                    right--;

                Helpers.swap(a, left, right);
            }
        }
        return new pair(right,left);
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
     * @param first - First index value of a[]
     * @param second - Second index value value of a[]
     */
    static void swap(int a[], int first, int second) {
        if (a[first] != a[second]) {
            a[first] ^= a[second];
            a[second] ^= a[first];
            a[first] ^= a[second];
        }
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

    public static enum SortMethod {
            QuickSort1
    };

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

    public static void execSort(SortMethod sortMethod, int n, int lim) {

        int a[];
        double begin, end;
        String method;

        method = null; begin = end = 0;
         a = UnitTests.generateRandomDataSet(n, lim);
        switch (sortMethod) {
            case QuickSort1:
                method = "QuickSort1";
                begin = System.nanoTime();
                ArraySorts.QuickSort1(a,n, 10);
                end = System.nanoTime();
                break;
        }
        UnitTests.prettyPrintArray(a,a.length);
        System.out.println("Code execution time for \"" + method + "\": " + (end-begin) + "ns");
    }
}
