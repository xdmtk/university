/**
 * OUTPUT:
 *
 * Testing Nicholas Martinez's program.
 * QS: outside-in partition, random pivot, cutoff=50:
 *     26.25.24.23.22.21.20.19.18.17.16.15.14.13.12.11.10.9.8.7.6.5.4.3.2.1.0.
 * QS: left-to-right, 1 random pivot partition, cutoff=50:
 *     26.25.24.23.22.21.20.19.18.17.16.15.14.13.12.11.10.9.8.7.6.5.4.3.2.1.0.
 * QS: left-to-right, 2 random pivot partition, cutoff=50:
 *     26.25.24.23.22.21.20.19.18.17.16.15.14.13.12.11.10.9.8.7.6.5.4.3.2.1.0.
 * QS: outside-in partition, lf pivot, cutoff=50:
 *     26.25.24.23.22.21.20.19.18.17.16.15.14.13.12.11.10.9.8.7.6.5.4.3.2.1.0.
 * QS: left-to-right, lf pivot, cutoff=50:
 *     26.25.24.23.22.21.20.19.18.17.16.15.14.13.12.11.10.9.8.7.6.5.4.3.2.1.0.
 * QS: outside-in partition, random pivot, cutoff=2:
 *     26.25.24.23.22.21.20.19.18.17.16.15.14.13.12.11.10.9.8.7.6.5.4.3.2.1.0.
 * QS: left-to-right, 1 random pivot partition, cutoff=2:
 *     26.
 * *** Mids sorting error: QS: left-to-right, 1 random pivot partition, cutoff=2, position #21
 * *** No more QS: left-to-right, 1 random pivot partition, cutoff=2s will be tested.  Correct values and Nicholas Martinez's values follow.
 * 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
 * 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 0 0 0 0 0
 *
 * QS: left-to-right, 2 random pivot partition, cutoff=2:
 *     26.25.24.23.22.21.20.19.18.17.16.
 * *** Random sorting error: QS: left-to-right, 2 random pivot partition, cutoff=2, position #1
 * *** No more QS: left-to-right, 2 random pivot partition, cutoff=2s will be tested.  Correct values and Nicholas Martinez's values follow.
 * 0 1 3 4 4 5 6 9 10 13 13 13 13 14 14 14
 * 0 3 4 4 5 1 6 9 10 13 13 13 13 14 14 14
 *
 * QS: outside-in partition, lf pivot, cutoff=2:
 *     26.25.24.23.22.21.20.19.18.17.16.15.14.13.12.11.10.9.8.7.6.5.4.3.2.1.0.
 * QS: left-to-right, lf pivot, cutoff=2:
 *     26.
 * *** Decreasing sorting error: QS: left-to-right, lf pivot, cutoff=2, position #1
 * *** No more QS: left-to-right, lf pivot, cutoff=2s will be tested.  Correct values and Nicholas Martinez's values follow.
 * 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
 * 0 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
 *
 * Almost QS: outside-in partition, random pivot, cutoff=2:
 *     26.
 * *** Random sorting error: Almost QS: outside-in partition, random pivot, cutoff=2, position #0
 * *** No more Almost QS: outside-in partition, random pivot, cutoff=2s will be tested.  Correct values and Nicholas Martinez's values follow.
 * 0 1 3 4 5 5 6 9 13 13 14 14 17 17 17 19 20 20 20 21 22 22 22 23 24 25
 * 1 0 3 4 5 5 6 9 13 13 14 14 17 17 17 19 20 21 20 20 24 23 22 25 22 22
 *
 * Almost QS: left-to-right, 1 random pivot partition, cutoff=2:
 *     26.
 * *** Constant sorting error: Almost QS: left-to-right, 1 random pivot partition, cutoff=2, position #0
 * *** No more Almost QS: left-to-right, 1 random pivot partition, cutoff=2s will be tested.  Correct values and Nicholas Martinez's values follow.
 * 51 51 51 51 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52
 * 25 51 51 51 51 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52
 *
 * Almost QS: left-to-right, 2 random pivot partition, cutoff=2:
 *     26.
 * *** Increasing sorting error: Almost QS: left-to-right, 2 random pivot partition, cutoff=2, position #4
 * *** No more Almost QS: left-to-right, 2 random pivot partition, cutoff=2s will be tested.  Correct values and Nicholas Martinez's values follow.
 * 0 2 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
 * 0 2 2 3 5 4 6 7 8 9 10 11 13 12 14 15 16 17 18 19 20 21 22 23 24 25
 *
 * HeapSort: top-down build heap:
 *     26.25.24.23.22.21.20.19.18.17.16.15.14.13.12.11.10.9.8.7.6.5.4.3.2.1.0.
 * HeapSort: bottom-up build heap:
 *     26.25.24.23.22.21.20.19.18.17.16.15.14.13.12.11.10.9.8.7.6.5.4.3.2.1.0.
 * Bigger, QS: outside-in partition, random pivot, cutoff=50:
 *     100.631.1162.1693.2224.2755.3286.3817.4348.4879.5410.5941.6472.7003.7534.8065.8596.
 *     9127.9658.10189.10720.11251.11782.12313.12844.13375.13906.14437.14968.15499.16030.
 *     16561.17092.17623.18154.18685.19216.19747. done.
 * Bigger, QS: left-to-right, 1 random pivot partition, cutoff=50:
 *     100.631.1162.1693.2224.2755.3286.3817.4348.4879.5410.5941.6472.7003.7534.8065.8596.
 *     9127.9658.10189.10720.11251.11782.12313.12844.13375.13906.14437.14968.15499.16030.
 *     16561.17092.17623.18154.18685.19216.19747. done.
 * Bigger, QS: left-to-right, 2 random pivot partition, cutoff=50:
 *     100.631.1162.1693.2224.2755.3286.3817.4348.4879.5410.5941.
 * *** Random sorting error: QS: left-to-right, 2 random pivot partition, cutoff=50, position #1912
 * *** No more QS: left-to-right, 2 random pivot partition, cutoff=50s will be tested.  Correct values and Nicholas Martinez's values follow.
 *  done.
 * Bigger, QS: outside-in partition, lf pivot, cutoff=50:
 *     100.631.1162.1693.2224.2755.3286.3817.4348.4879.5410.5941.6472.7003.7534.8065.8596.
 *     9127.9658.10189.10720.11251.11782.12313.12844.13375.13906.14437.14968.15499.16030.
 *     16561.17092.17623.18154.18685.19216.19747. done.
 * Bigger, QS: left-to-right, lf pivot, cutoff=50:
 *     100.631.1162.1693.2224.2755.3286.3817.4348.4879.5410.5941.6472.7003.7534.8065.8596.
 *     9127.9658.10189.10720.11251.11782.12313.12844.13375.13906.14437.14968.15499.16030.
 *     16561.17092.17623.18154.18685.19216.19747.
 * *** Decreasing sorting error: QS: left-to-right, lf pivot, cutoff=50, position #1
 * *** No more QS: left-to-right, lf pivot, cutoff=50s will be tested.  Correct values and Nicholas Martinez's values follow.
 *  done.
 * Bigger, QS: outside-in partition, random pivot, cutoff=2:
 *     100.631.1162.1693.2224.2755.3286.3817.4348.4879.5410.5941.6472.7003.7534.8065.8596.
 *     9127.9658.10189.10720.11251.11782.12313.12844.13375.13906.14437.14968.15499.16030.
 *     16561.17092.17623.18154.18685.19216.19747. done.
 * Bigger, QS: left-to-right, 1 random pivot partition, cutoff=2:
 *      done.
 * Bigger, QS: left-to-right, 2 random pivot partition, cutoff=2:
 *      done.
 * Bigger, QS: outside-in partition, lf pivot, cutoff=2:
 *     100.631.1162.1693.2224.2755.3286.3817.4348.4879.5410.5941.6472.7003.7534.8065.8596.
 *     9127.9658.10189.10720.11251.11782.12313.12844.13375.13906.14437.14968.15499.16030.
 *     16561.17092.17623.18154.18685.19216.19747. done.
 * Bigger, QS: left-to-right, lf pivot, cutoff=2:
 *      done.
 * Bigger, Almost QS: outside-in partition, random pivot, cutoff=2:
 *      done.
 * Bigger, Almost QS: left-to-right, 1 random pivot partition, cutoff=2:
 *      done.
 * Bigger, Almost QS: left-to-right, 2 random pivot partition, cutoff=2:
 *      done.
 * Bigger, HeapSort: top-down build heap:
 *     100.631.1162.1693.2224.2755.3286.3817.4348.4879.5410.5941.6472.7003.7534.8065.8596.
 *     9127.9658.10189.10720.11251.11782.12313.12844.13375.13906.14437.14968.15499.16030.
 *     16561.17092.17623.18154.18685.19216.19747. done.
 * Bigger, HeapSort: bottom-up build heap:
 *     100.631.1162.1693.2224.2755.3286.3817.4348.4879.5410.5941.6472.7003.7534.8065.8596.
 *     9127.9658.10189.10720.11251.11782.12313.12844.13375.13906.14437.14968.15499.16030.
 *     16561.17092.17623.18154.18685.19216.19747. done.
 *
 * Testing Nicholas Martinez's sorts on a huge array.
 *
 * Java's QuickSort on random data runs in 3.903 seconds.
 * Java's QuickSort on the test sets runs in 0.956 seconds.
 *
 *
 * Nicholas Martinez's QS: outside-in partition, random pivot, cutoff=50
 *     on all random values runs in 4.888 seconds.      Java Ratio = 1.25
 *     on the test sets runs in 32.332 seconds.          Java Ratio = 33.82
 *
 * Nicholas Martinez's QS: left-to-right, 1 random pivot partition, cutoff=50
 *     on all random values runs in 4.395 seconds.      Java Ratio = 1.12
 *     on the test sets runs in 42.002 seconds.          Java Ratio = 43.93
 * Nicholas Martinez's QS: left-to-right, 2 random pivot partition, cutoff=50 not tested.
 *
 *
 * Nicholas Martinez's QS: outside-in partition, lf pivot, cutoff=50
 *     on all random values runs in 19.802 seconds.      Java Ratio = 5.07
 * Nicholas Martinez's QS: left-to-right, lf pivot, cutoff=50 not tested.
 *
 *
 * Nicholas Martinez's QS: outside-in partition, random pivot, cutoff=2
 *     on all random values runs in 2183.056 seconds.      Java Ratio = 559.32
 *     on the test sets runs in 469.868 seconds.          Java Ratio = 491.49
 * Nicholas Martinez's QS: left-to-right, 1 random pivot partition, cutoff=2 not tested.
 *
 * Nicholas Martinez's QS: left-to-right, 2 random pivot partition, cutoff=2 not tested.
 */

import java.util.Random;

class ArraySorts {
    public static boolean debug = false;
    public static boolean partitions = false;
    public static boolean printArray = true;
    public static boolean overflow = false;



    public static void main(String[] args){
        UnitTests.execSort(UnitTests.SortMethod.QuickSort1, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.QuickSort2, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.QuickSort3, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.QuickSort4, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.QuickSort5, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.AlmostQuickSort1, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.AlmostQuickSort2, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.AlmostQuickSort3, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.InsertionSort, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.HeapSortBottomUp, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.HeapSortTopDown, 101, 100, 2);
    }


    /**
     * Iterative approach to Insertion Sort, requires no driver method
     *
     * @param a - Array to operate on
     * @param n - Length of array
     */
    public static void insertionSortIterative(int a[], int begin, int n) {
        if (n <= 1) {}
        else {
            try {
                for (int i = begin+1, x = 0; x < n-1; ++i, ++x)
                    if (a[i] < a[i-1]) Helpers.shift(a, i, begin);
            }
            catch (ArrayIndexOutOfBoundsException e) {
                if (ArraySorts.debug) {
                    System.out.println("Insertion sort failure.. Dumping current contents of array:");
                    UnitTests.prettyPrintArray(a, a.length);
                    System.out.println("Fatal error");
                }
            }
        }
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
            try {
                pivotIndex = partitionOutsideIn(a, left, right);
                QuickSort1(a, left, pivotIndex.getRight(), cutoff);

                // TODO: Optimize this into a while loop
                QuickSort1(a, pivotIndex.getLeft(), right, cutoff);
            }
            catch (StackOverflowError e) {
                insertionSortIterative(a, left, right-left+1);
            }
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
            try {
                randomGen = new Random();

                /* Get the pivot by generating a random index within the bounds of right - left,
                 * then add left as the base index for the chosen random value  */
                pivot = a[left + randomGen.nextInt(right - left)];

                if (ArraySorts.debug) System.out.println("Pivot: " + pivot);

                /* Begin swapping elements until the left/right pointers overlap */
                while (left < right) {

                    if (ArraySorts.debug) UnitTests.prettyPrintArray(a, a.length);

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
            catch (ArrayIndexOutOfBoundsException e) {

            }
        }
        return new pair(left,right);
    }












    /** QuickSort2 Driver*/
    public static void QuickSort2(int[] a, int n, int cutoff) {
        QuickSort2(a, 0, n-1, cutoff);
    }

    /** QuickSort2 Recursive Method */
    private static void QuickSort2(int[] a, int left, int right, int cutoff) {
        pair pivotIndex;

        if (right - left < cutoff)
            insertionSortIterative(a,left,right-left+1);
        else  {
            try {
                pivotIndex = partitionLeftRightOneRandomPivot(a, left, right);
                QuickSort2(a, left, pivotIndex.getRight(), cutoff);

                // TODO: Optimize this into a while loop
                QuickSort2(a, pivotIndex.getLeft(), right, cutoff);
            }
            catch (StackOverflowError e){
               insertionSortIterative(a, left, right-left+1);
            }
        }

    }


    /**
     * Left to Right partitioning function. Random pivot is chosen, pivot is moved to the first element.
     * Then a partition divider pointer moves along the array, and gets advanced for each
     * element that is less than the pivot element. When an element is greater than the pivot
     * the firstUnknown pointer advances without any swaps to the less than partition
     *
     * @param a - Array to operate on
     * @param left - Left index of array slice
     * @param right - Right index of array slice
     *
     * @return - pair - New pair of the modified left/right indices, with 'right' as the
     * outer bound of the left partition, and 'left' as the beginning index for the right partition
     */
    private static pair partitionLeftRightOneRandomPivot(int[] a, int left, int right) {

        int pivot, pivotIndex, firstUknownIndex, smallPartitionLimit = left;
        Random randomGen;

        /* Base case - Do nothing except for setting the dependency in the return pair */
        if (right - left < 1) { }

        /* Otherwise begin partitioning */
        else {
            try {
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
                    if (a[firstUknownIndex] < pivot) {
                        Helpers.swap(a, firstUknownIndex, smallPartitionLimit);

                        /* Increment the limit index, since we have added another element to the
                         * smaller-than partiton  */
                        smallPartitionLimit++;
                    }
                    /* Advance first unknown index */
                    firstUknownIndex++;
                }
            }
            catch (ArrayIndexOutOfBoundsException e){

            }
        }
        return new pair(smallPartitionLimit,smallPartitionLimit+1);
    }







    /** QuickSort3 Driver*/
    public static void QuickSort3(int[] a, int n, int cutoff) {
        QuickSort3(a, 0, n-1, cutoff);
    }

    /** QuickSort3 Recursive Method*/
    private static void QuickSort3(int[] a, int left, int right, int cutoff) {
        pair pivotIndex;

        if (right - left < cutoff)
            insertionSortIterative(a,left,right-left+1);
        else  {
            try {
                pivotIndex = partitionLeftRightTwoRandomPivots(a, left, right);
                QuickSort3(a, left, pivotIndex.getLeft(), cutoff);
                QuickSort3(a, pivotIndex.getLeft(), pivotIndex.getRight(), cutoff);

                // TODO: Optimize this into a while loop
                QuickSort3(a, pivotIndex.getRight(), right, cutoff);
            }
            catch (StackOverflowError e) {
                insertionSortIterative(a, left, right-left+1);
            }
        }

    }

    /**
     * Left to Right partitioning function. Random pivot is chosen, pivot is moved to the first element.
     * Then a partition divider pointer moves along the array, and gets advanced for each
     * element that is less than the pivot element. When an element is greater than the pivot
     * the firstUnknown pointer advances without any swaps to the less than partition
     *
     * @param a - Array to operate on
     * @param left - Left index of array slice
     * @param right - Right index of array slice
     *
     * @return - pair - New pair of the modified left/right indices, with 'right' as the
     * outer bound of the left partition, and 'left' as the beginning index for the right partition
     */
    private static pair partitionLeftRightTwoRandomPivots(int[] a, int left, int right) {

        int pivotLeft, pivotRight, pivotIndexLeft = left, pivotIndexRight = right, firstUnknown;
        Random randomGen;

        /* Base case - Do nothing except for setting the dependencies in the return pair */
        if (right - left < 1) {
        }
        /* Otherwise begin partitioning */
        else {
            try {
                randomGen = new Random();

                /* Get the first pivot by generating a random index within the bounds of right - left,
                 * then add left as the base index for the chosen random value  */
                pivotLeft = a[pivotIndexLeft = (left + randomGen.nextInt(right - left))];

                /* Get the second pivot via the same method, except repeat if the indices are
                 * generated to be the same */
                do pivotRight = a[pivotIndexRight = (left + randomGen.nextInt(right - left))];
                while (pivotIndexRight == pivotIndexLeft);

                /* Set pivot locations to left/right indices of partition */
                if (pivotLeft > pivotRight) {
                    pivotRight ^= pivotLeft;
                    pivotLeft ^= pivotRight;
                    pivotRight ^= pivotLeft;
                    Helpers.swap(a, right, pivotIndexLeft);
                    Helpers.swap(a, left, pivotIndexRight);
                } else {
                    Helpers.swap(a, left, pivotIndexLeft);
                    Helpers.swap(a, right, pivotIndexRight);
                }

                /* Reset the indices to left/right */
                pivotIndexLeft = left;
                pivotIndexRight = right;

                /* Begin iteration on the first element after the left pivot index */
                firstUnknown = left + 1;

                while (firstUnknown <= pivotIndexRight) {

                    /* Elements less than the left pivot get moved into partition 1 via a swap,
                     * then increment the dividing index */
                    if (a[firstUnknown] < pivotLeft)
                        Helpers.swap(a, firstUnknown++, pivotIndexLeft++);

                        /* If the element is greater than the right pivot, it belongs in partition 3,
                         * but this time, only decrement the partition divider, since the swap will introduce
                         * another unknown into the 'first unknown' index. */
                    else if (a[firstUnknown] > pivotRight)
                        Helpers.swap(a, firstUnknown, pivotIndexRight--);

                        /* If the element is between the value of the two pivots, firstUnknown can be advanced
                         * and no dividing partitions moved, since it will be the middle partition */
                    else
                        firstUnknown++;
                }

                if (ArraySorts.partitions) {
                    System.out.println("Pivot Left: " + pivotLeft + " - Pivot Right: " + pivotRight + "\n");
                    System.out.println("\nPartition 1:");
                    for (int i = left; i < pivotIndexLeft; ++i) {
                        System.out.print(a[i] + " ");
                    }
                    System.out.println("\nPartition 2:");
                    for (int i = pivotIndexLeft + 1; i < pivotIndexRight; ++i) {
                        System.out.print(a[i] + " ");
                    }
                    System.out.println("\nPartition 3:");
                    for (int i = pivotIndexRight + 1; i < right; ++i) {
                        System.out.print(a[i] + " ");
                    }
                }
            }
            catch (ArrayIndexOutOfBoundsException e) {}
        }
        return new pair(pivotIndexLeft, pivotIndexRight);
    }






    /** QuickSort4 Driver */
    public static void QuickSort4(int a[], int n, int cutoff) {
        QuickSort4(a, 0, n-1, cutoff);
    }

    /** Quicksort4 recursive method */
    private static void QuickSort4(int a[], int left, int right, int cutoff) {

        pair pivotIndex;

        if (right - left < cutoff)
            insertionSortIterative(a,left,right-left+1);
        else  {
            try {
                pivotIndex = partitionOutsideInStaticPivot(a, left, right);
                QuickSort4(a, left, pivotIndex.getRight(), cutoff);

                // TODO: Optimize this into a while loop
                QuickSort4(a, pivotIndex.getLeft(), right, cutoff);
            }
            catch (StackOverflowError e) {
                insertionSortIterative(a, left, right-left+1);
            }
        }
    }

    /**
     * Outside-in partitioning function. Static pivot is chosen, and left/right pointers
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
    private static pair partitionOutsideInStaticPivot(int a[], int left, int right)  {

        int pivot, origindex = left;

        /* Base case - Do nothing */
        if (right - left < 1) {}

        /* Otherwise begin partitioning */
        else {
            try {
                /* Constant left pivot */
                pivot = a[left];


                if (ArraySorts.debug) System.out.println("Pivot: " + pivot);

                /* Begin swapping elements until the left/right pointers overlap */
                while (left < right) {

                    if (ArraySorts.debug) UnitTests.prettyPrintArray(a, a.length);

                    /* Begin incrementing/decrementing left/right pointers until elements
                     * greater/less than the pivot are identified. */
                    while (left <= right && a[left] <= pivot)
                        left++;
                    while (right >= left && a[right] > pivot)
                        right--;

                    if (left < right)
                        Helpers.swap(a, left, right);
                }

                /* Since our pivot is now always the left pointer, we need to swap it where
                 * the partition divides */
                Helpers.swap(a, origindex, right);
            }
            catch (ArrayIndexOutOfBoundsException e) {}
        }

        return new pair(left,right);
    }









    /** QuickSort5 Driver */
    public static void QuickSort5(int[] a, int n, int cutoff) {
        QuickSort5(a, 0, n-1, cutoff);
    }

    /** QuickSort5 Recursive Method */
    private static void QuickSort5(int[] a, int left, int right, int cutoff) {
        pair pivotIndex;

        if (right - left < cutoff)
            insertionSortIterative(a,left,right-left+1);
        else  {
            try {
                pivotIndex = partitionLeftRightOneStaticPivot(a, left, right);
                QuickSort5(a, left, pivotIndex.getRight(), cutoff);

                // TODO: Optimize this into a while loop
                QuickSort5(a, pivotIndex.getLeft(), right, cutoff);
            }
            catch (StackOverflowError e) {
                insertionSortIterative(a, left, right-left+1);
            }
        }

    }

    /**
     * Left to Right partitioning function. One static pivot is chosen, pivot is moved to the first element.
     * Then a partition divider pointer moves along the array, and gets advanced for each
     * element that is less than the pivot element. When an element is greater than the pivot
     * the firstUnknown pointer advances without any swaps to the less than partition
     *
     * @param a - Array to operate on
     * @param left - Left index of array slice
     * @param right - Right index of array slice
     *
     * @return - pair - New pair of the modified left/right indices, with 'right' as the
     * outer bound of the left partition, and 'left' as the beginning index for the right partition
     */
    private static pair partitionLeftRightOneStaticPivot(int[] a, int left, int right) {

        int pivot, firstUknownIndex, smallPartitionLimit = left;

        /* Base case - Do nothing except for setting the dependency in the return pair */
        if (right - left < 1) { }

        /* Otherwise begin partitioning */
        else {
            try {
                /* Constant left pivot */
                pivot = a[left];
                firstUknownIndex = left + 1;

                /* Walk first unknown index across the array */
                while (firstUknownIndex <= right) {

                    /* When the unknown element is less than the pivot, swap it with
                     * the limiting index of the smaller partition */
                    if (a[firstUknownIndex] < pivot) {
                        Helpers.swap(a, firstUknownIndex, smallPartitionLimit);

                        /* Increment the limit index, since we have added another element to the
                         * smaller-than partiton  */
                        smallPartitionLimit++;
                    }
                    /* Advance first unknown index */
                    firstUknownIndex++;
                }
            }
            catch (ArrayIndexOutOfBoundsException e){}
        }
        return new pair(smallPartitionLimit,smallPartitionLimit+1);
    }








    public static void HeapSortBU(int a[], int n){

        heapifyBottomUp(a,n);
        for( int i = n - 1;i > 0; --i){
            Helpers.swap(a,0,i);
            ArraySorts.trickleDown(a,0,i);
        }
    }
    public static void heapifyBottomUp(int[] a, int n){

        for (int i = (n-1)/2; i >= 0; --i)
            trickleDown(a,i,n);
    }

    public static void trickleDown(int a[],int index, int n){

        int trickleVal, right, left, max;

        trickleVal = a[index];
        right = (index*2)+2;
        left = (index*2)+1;
        max = Helpers.getLargestChild(a,n-1,left,right);

        while(max < n && trickleVal < a[max]){
            a[(max -1)/2] = a[max];
            right = (max*2) + 2;
            left = (max*2) + 1;
            max = Helpers.getLargestChild(a,n-1,left,right);
        }
        a[(max-1)/2] = trickleVal;

    }




    public static void HeapSortTD(int a[], int n){
        heapifyTopDown(a,n);
        for(int i = n -1;i >0; i--){
            Helpers.swap(a,0,i);
            ArraySorts.trickleDown(a,0,i);
        }
    }

    public static void heapifyTopDown(int[] a, int n){
        for(int i = 0; i < n; i++)
            trickleUp(a,i,n);
    }

    public static void trickleUp(int a[],int index, int n){

        int trickleValue,parent;
        trickleValue = a[index];
        parent = (index -1 )/2;

        while(index > 0 && a[parent] < trickleValue){
            a[index] = a[parent];
            parent = (parent -1)/2;
            index = (index -1)/2;
        }
        //2.
        if(a[index] != trickleValue)
            a[index] = trickleValue;

    }


    /**
     * NOTE: Because of a fundamental error in previous Quicksort implementations,
     * namely that of handling arrays with many similar values, commenting out insertion sort
     * during the inevitable handling of stackoverflow results in an infinite loop of
     * continuously abusing the stack -> unwinding the stack.
     *
     * Fully understanding this is in no way correct, to get this program to at the very least not stall
     * up the test program, an 'Overflow' flag was utilized and essentially alerts AlmostQS that
     * more partitioning cannot be achieved without overflowing the stack, but because the cutoff might
     * never be reached the base case now includes the activation of the overflow flag, to avoid infinitely
     * looping.
     *
     * Sorry about that...
     */



    /** AlmostQuickSort1 Driver */
    public static void AlmostQS1(int a[],int n,int cutoff){
        AlmostQS1(a,0,n,cutoff);
        if (ArraySorts.overflow)
            ArraySorts.overflow = false;
    }
    /** AlmostQuickSort1 Recursive Method*/
    public static void AlmostQS1(int a[], int left, int right, int cutoff){
          pair pivotIndex;

          if (right - left < cutoff || ArraySorts.overflow) {
          }
          else  {
              try {
                  pivotIndex = partitionOutsideIn(a, left, right);
                  AlmostQS1(a, left, pivotIndex.getRight(), cutoff);

                  // TODO: Optimize this into a while loop
                  AlmostQS1(a, pivotIndex.getLeft(), right, cutoff);
              }
              catch (StackOverflowError e) {
                    ArraySorts.overflow = true;
              }
          }
      }

    /** AlmostQuickSort2 Driver */
    public static void AlmostQS2(int a[],int n,int cutoff){
        AlmostQS2(a,0,n,cutoff);
        if (ArraySorts.overflow)
            ArraySorts.overflow = false;
    }
    /** AlmostQuickSort2 Recursive Method*/
    public static void AlmostQS2(int a[],int left, int right, int cutoff){
        pair pivotIndex;

        if (right - left < cutoff) {}
        else  {
            try {
                pivotIndex = partitionLeftRightOneRandomPivot(a, left, right);
                AlmostQS2(a, left, pivotIndex.getRight(), cutoff);

                // TODO: Optimize this into a while loop
                AlmostQS2(a, pivotIndex.getLeft(), right, cutoff);
            }
            catch (StackOverflowError e){
                ArraySorts.overflow = true;
            }
        }

    }
    /** AlmostQuickSort3 Driver */
    public static void AlmostQS3(int a[], int n,int cutoff){
        AlmostQS3(a, 0, n, cutoff);
        if (ArraySorts.overflow)
            ArraySorts.overflow = false;
    }
    /** AlmostQuickSort3 Recursive Method */
    public static void AlmostQS3(int a[], int left, int right, int cutoff){

        pair pivotIndex;

        if (right - left < cutoff) {}
        else  {
            try {
                pivotIndex = partitionLeftRightTwoRandomPivots(a, left, right);
                AlmostQS3(a, left, pivotIndex.getLeft(), cutoff);
                AlmostQS3(a, pivotIndex.getLeft(), pivotIndex.getRight(), cutoff);

                // TODO: Optimize this into a while loop
                AlmostQS3(a, pivotIndex.getRight(), right, cutoff);
            }
            catch (StackOverflowError e) {
                ArraySorts.overflow = true;
            }
        }

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


    /**
     * Helper function to find the larger of the
     * children when building a heap top down
     *
     * @param a - Heap to operate on
     * @param n - Heap boundary
     * @param left - Index of left child
     * @param right - Index of right child
     *
     */
    public static int getLargestChild(int[] a, int n, int left, int right){
        int max = 0;
        if(left <= n && right <= n){
            if(a[left] > a[right])
                max = left;
            else
                max = right;
        }
        else
            max = left;

        return max;
    }

}


class UnitTests {

    public static enum SortMethod {
        QuickSort1, QuickSort2, QuickSort3, QuickSort4, 
        QuickSort5, InsertionSort, HeapSortBottomUp,
        HeapSortTopDown, AlmostQuickSort1, AlmostQuickSort2,
        AlmostQuickSort3;
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

    public static void execSort(SortMethod sortMethod, int n, int lim, int cutoff) {

        int a[];
        double begin, end;
        String method;

        method = null; begin = end = 0;
        a = UnitTests.generateRandomDataSet(n, lim);
        switch (sortMethod) {
            case QuickSort1:
                method = "QuickSort1";
                begin = System.currentTimeMillis();
                ArraySorts.QuickSort1(a,n, cutoff);
                end = System.currentTimeMillis();
                break;
            case QuickSort2:
                method = "QuickSort2";
                begin = System.currentTimeMillis();
                ArraySorts.QuickSort2(a,n, cutoff);
                end = System.currentTimeMillis();
                break;
            case QuickSort3:
                method = "QuickSort3";
                begin = System.currentTimeMillis();
                ArraySorts.QuickSort3(a,n, cutoff);
                end = System.currentTimeMillis();
                break;
            case QuickSort4:
                method = "QuickSort4";
                begin = System.currentTimeMillis();
                ArraySorts.QuickSort4(a,n, cutoff);
                end = System.currentTimeMillis();
                break;
            case QuickSort5:
                method = "QuickSort5";
                begin = System.currentTimeMillis();
                ArraySorts.QuickSort5(a,n, cutoff);
                end = System.currentTimeMillis();
                break;
            case AlmostQuickSort1:
                method = "AlmostQuickSort1";
                begin = System.currentTimeMillis();
                ArraySorts.AlmostQS1(a,n, cutoff);
                end = System.currentTimeMillis();
                break;
            case AlmostQuickSort2:
                method = "AlmostQuickSort2";
                begin = System.currentTimeMillis();
                ArraySorts.AlmostQS2(a,n, cutoff);
                end = System.currentTimeMillis();
                break;
            case AlmostQuickSort3:
                method = "AlmostQuickSort3";
                begin = System.currentTimeMillis();
                ArraySorts.AlmostQS3(a,n, cutoff);
                end = System.currentTimeMillis();
                break;
            case HeapSortBottomUp:
                method = "HeapSort Bottom-up";
                begin = System.currentTimeMillis();
                ArraySorts.HeapSortBU(a, n);
                end = System.currentTimeMillis();
                break;
            case HeapSortTopDown:
                method = "HeapSort Top-Down";
                begin = System.currentTimeMillis();
                ArraySorts.HeapSortTD(a, n);
                end = System.currentTimeMillis();
                break;
            case InsertionSort:
                method = "InsertionSort";
                begin = System.currentTimeMillis();
                ArraySorts.insertionSortIterative(a, 0, n);
                end = System.currentTimeMillis();
                break;
        }
        if (ArraySorts.printArray) {UnitTests.prettyPrintArray(a,a.length);};
        System.out.println("Code execution time for \"" + method + "\": " + (end-begin) + "ms");
    }
}
