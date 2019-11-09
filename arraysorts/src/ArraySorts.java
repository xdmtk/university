
import javax.swing.*;
import java.math.*;
import java.util.Random;

class ArraySorts {
    public static boolean debug = false;


    public static void main(String[] args){
        UnitTests.execSort(UnitTests.SortMethod.QuickSort2, 50, 1000);
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
            for (int i = begin+1, x = 0; x < n-1; ++i, ++x)

                /* Previous element bigger? Initiate shift */
                if (a[i] < a[i-1]) Helpers.shift(a, i, begin);
    }











    /** QuickSort1 Driver */
    public static void QuickSort1(int a[], int n, int cutoff) {
        QuickSort1(a, 0, n-1, cutoff);
    }

    /** Quicksort1 recursive method */
    private static void QuickSort1(int a[], int left, int right, int cutoff) {

        pair pivotIndex;

        if (right - left < cutoff)
            insertionSortIterative(a,left,right-left+1);
        else  {
            pivotIndex = partitionOutsideIn(a, left, right);
            QuickSort1(a, left, pivotIndex.getRight(), cutoff);

            // TODO: Optimize this into a while loop
            QuickSort1(a, pivotIndex.getLeft(), right, cutoff);
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
                while (left <= right && a[left] <= pivot)
                    left++;
                while (right >= left && a[right] > pivot)
                    right--;

                if (left < right)
                    Helpers.swap(a, left, right);
            }
        }
        return new pair(left,right);
    }












    public static void QuickSort2(int[] a, int n, int cutoff) {
        QuickSort2(a, 0, n-1, cutoff);
    }

    private static void QuickSort2(int[] a, int left, int right, int cutoff) {
        pair pivotIndex;

        if (right - left < cutoff)
            insertionSortIterative(a,left,right-left+1);
        else  {
            pivotIndex = partitionLeftRightOneRandomPivot(a, left, right);
            QuickSort2(a, left, pivotIndex.getRight(), cutoff);

            // TODO: Optimize this into a while loop
            QuickSort2(a, pivotIndex.getLeft(), right, cutoff);
        }

    }

    private static pair partitionLeftRightOneRandomPivot(int[] a, int left, int right) {

        int pivot, pivotIndex, firstUknownIndex, smallPartitionLimit;
        Random randomGen;

        /* Base case - Do nothing except for setting the dependency in the return pair */
        if (right - left < 1) { smallPartitionLimit = left;}

        /* Otherwise begin partitioning */
        else {
            randomGen = new Random();

            /* Get the pivot by generating a random index within the bounds of right - left,
             * then add left as the base index for the chosen random value  */
            pivot = a[pivotIndex = (left + randomGen.nextInt(right - left))];
            firstUknownIndex = left + 1;
            smallPartitionLimit = left;

            /* Swap the pivot with the first element */
            Helpers.swap(a, left, pivotIndex);

            /* Walk first unknown index across the array */
            while (firstUknownIndex <= right) {

                /* When the unknown element is less than the pivot, swap it with
                 * the limiting index of the smaller partition */
                if (a[firstUknownIndex] < pivot)  {
                    Helpers.swap(a, firstUknownIndex, smallPartitionLimit);

                    /* Increment the limit index, since we have added another element to the
                     * smaller-than partiton  */
                    smallPartitionLimit++;
                }
                /* Advance first unknown index */
                firstUknownIndex++;
            }

        }
        return new pair(smallPartitionLimit,smallPartitionLimit+1);
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
     * until current element is less shift target
     *
     * @param a - Array to operate on
     * @param target - Index of element to shift
     * @param begin - Index of limiting slice of a[]
     *
     */
    static void shift(int a[], int target, int begin) {
        int temp = a[target], i = target;
        while (i > begin && temp < a[i-1])
            a[i] = a[--i];
        a[i] = temp;
    }
}


class UnitTests {

    public static enum SortMethod {
            QuickSort1, QuickSort2
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
                begin = System.currentTimeMillis();
                ArraySorts.QuickSort1(a,n, 10);
                end = System.currentTimeMillis();
                break;
            case QuickSort2:
                method = "QuickSort2";
                begin = System.currentTimeMillis();
                ArraySorts.QuickSort2(a,n, 10);
                end = System.currentTimeMillis();
                break;
        }
        UnitTests.prettyPrintArray(a,a.length);
        System.out.println("Code execution time for \"" + method + "\": " + (end-begin) + "ms");
    }
}
