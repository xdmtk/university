
import javax.swing.*;
import java.math.*;
import java.util.Random;
import java.util.Stack;

class ArraySorts {
    public static boolean debug = false;
    public static boolean partitions = false;
    public static boolean printArray = true;



    public static void main(String[] args){
        UnitTests.execSort(UnitTests.SortMethod.QuickSort1, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.QuickSort2, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.QuickSort3, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.QuickSort4, 101, 100, 2);
        UnitTests.execSort(UnitTests.SortMethod.QuickSort5, 101, 100, 2);
        //UnitTests.execSort(UnitTests.SortMethod.AlmostQuickSort1, 101, 100, 2);
//        UnitTests.execSort(UnitTests.SortMethod.AlmostQuickSort2, 101, 100, 2);
 //       UnitTests.execSort(UnitTests.SortMethod.AlmostQuickSort3, 101, 100, 2);
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












    public static void QuickSort2(int[] a, int n, int cutoff) {
        QuickSort2(a, 0, n-1, cutoff);
    }

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







    public static void QuickSort3(int[] a, int n, int cutoff) {
        QuickSort3(a, 0, n-1, cutoff);
    }

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






    /** QuickSort1 Driver */
    public static void QuickSort4(int a[], int n, int cutoff) {
        QuickSort4(a, 0, n-1, cutoff);
    }

    /** Quicksort1 recursive method */
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



    public static void QuickSort5(int[] a, int n, int cutoff) {
        QuickSort5(a, 0, n-1, cutoff);
    }

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
         buildHeapBU(a,n);
  
         //2. Go through array while removing the largest value to be sorted
         for( int i = n - 1;i > 0; --i){
             Helpers.swap(a,0,i);
             ArraySorts.trickleDown(a,0,i);
         }
     }
     public static void buildHeapBU(int a[], int n){
          for(int i = (n-1)/2; i >= 0; i--)
              trickleDown(a,i,n);
     }
  
     public static void trickleDown(int a[],int index, int n){

          int trickleValue,rightChild,leftChild,largest;
          trickleValue = a[index];
          rightChild = (index*2)+2;
          leftChild = (index*2)+1;
          largest = largestChild(a,n-1,leftChild,rightChild);
  
          //1.Keep shifting until you reach a leaf or trickleValue is in the right place
          while(largest < n && trickleValue < a[largest]){
              //2. Shift largest child up to parent
              a[(largest -1)/2] = a[largest];
              //Get children and check
              rightChild = (largest*2) + 2;
              leftChild = (largest*2) + 1;
              //Now find the next largest child
              largest = largestChild(a,n-1,leftChild,rightChild);
          }
          //4.Since trickle value is greater then largest make it its parent
          a[(largest-1)/2] = trickleValue;
  
     }
      //Gets the largest child of parent
      public static int largestChild(int a[], int n,int leftIndex, int rightIndex){
          int largest = 0;
          //1. If indexs are not out of bounds then find then the largest child
          if(leftIndex <= n && rightIndex <= n){
              if(a[leftIndex] > a[rightIndex])
                  largest = leftIndex;
              else
                  largest = rightIndex;
          }
          //2.Its out of bounds so the only possible case is left index
          else
              largest = leftIndex;
  
          return largest;
      }



      //--------------------------------------------Heap Sort TD-----------------------------------------------------------
      //HSTD method
      public static void HeapSortTD(int a[], int n){
          //1. Build the heap top down
          buildHeapTD(a,n);
          //2.Go through array while removing the largest item to be sorted
          for(int i = n -1;i >0; i--){
              Helpers.swap(a,0,i);
              ArraySorts.trickleDown(a,0,i);
          }
      }
      //HSTD buildHeap method
      public static void buildHeapTD(int a[], int n){
          //1.Call trickle Up on the first node all the way to the last
          for(int i = 0; i < n; i++)
              trickleUp(a,i,n);
      }
     
      public static void trickleUp(int a[],int index,int n){
          int trickleValue,parent;
          trickleValue = a[index];
          parent = (index -1 )/2;
          //1.If parent is greater than 0 and parent is less than trickle value by trickle up (shift parent down)
          while(index > 0 && a[parent] < trickleValue){
              a[index] = a[parent];
              parent = (parent -1)/2;
              index = (index -1)/2;
          }
          //2.
          if(a[index] != trickleValue)
          a[index] = trickleValue;
  
      }


  //-----------------------------------------------AlmostQS1--------------------------------------------------------------
      //AQS#1 Driver method
      public static void AlmostQS1(int a[],int n,int cutoff){
          AlmostQS1(a,0,n,cutoff);
      }
      //AQS#1 Recursive method
      public static void AlmostQS1(int a[], int lf, int rt, int cutoff){
        int pivotIndex,sum;
          pair mid;
  
          //1. While the partition is bigger then the cutoff
          while(rt - lf >= cutoff) {
  
              mid = partitionOutsideIn(a, lf, rt-1);
  
              //3.Recursively call AQS#1 on the smaller of the 2 partitions
              if ((mid.getRight() - lf) < (rt - mid.getLeft())){
                  AlmostQS1(a,lf,mid.getLeft(),cutoff);
                  lf = mid.getRight();
              }
              else{
                  AlmostQS1(a,mid.getRight(),rt,cutoff);
                  rt = mid.getLeft();
              }
          }
      }
  //-----------------------------------------------AlmostQS2--------------------------------------------------------------
      //AQS#2 Driver method
      public static void AlmostQS2(int a[],int n,int cutoff){
          AlmostQS2(a,0,n,cutoff);
      }
      //AQS#2 Recursive method
      public static void AlmostQS2(int a[],int lf, int rt, int cutoff){
          pair pivotIndex;
  
          //1.While the partition is bigger then the cutoff
          while(rt - lf >= cutoff){
  
              //2.Get pivot point and call left to right parition method
              pivotIndex =  partitionLeftRightOneRandomPivot(a,lf,rt-1);
  
              //3. Recursively call AQS#2 on the smaller partition
              if((pivotIndex.getRight() - lf) < (rt - pivotIndex.getLeft())){
                  AlmostQS2(a,lf,pivotIndex.getLeft(),cutoff);
                  lf = pivotIndex.getRight();
              }
              else{
                  AlmostQS2(a,pivotIndex.getRight(),rt,cutoff);
                  rt = pivotIndex.getLeft();
              }
          }
      }
  //------------------------------------------------AlmostQS3-------------------------------------------------------------
      //AQS#3 Driver method
       public static void AlmostQS3(int a[], int n,int cutoff){
          AlmostQS3(a,0,n,cutoff);
      }
      //AQS#3 Recursive method
      public static void AlmostQS3(int a[], int lf, int rt, int cutoff){
          int leftPartition,middlePartition,rightPartition,pivotIndex,pivotIndex2;
          pair mid;
          Random randomGen;
  
          //1.While the partition is bigger then the cutoff
          while(rt - lf >= cutoff){


              randomGen = new Random();
              /* Get the pivot by generating a random index within the bounds of right - left,
               * then add left as the base index for the chosen random value  */
              pivotIndex = a[pivotIndex = (lf + randomGen.nextInt(rt - lf))];
              //1.Get pivot points and place them in there correct positions
              Helpers.swap(a,pivotIndex,lf);

              /* Dont choose the same pivot */
              while ((pivotIndex2 = a[pivotIndex = (lf + randomGen.nextInt(rt - lf))]) != pivotIndex)
                    pivotIndex2 = pivotIndex2;

              Helpers.swap(a,pivotIndex2,rt-1);
              if(a[lf] > a[rt-1])
                  Helpers.swap(a,lf,rt-1);

              //2.Get the mid point and then calculate the different partition sizes
              mid = partitionLeftRightTwoRandomPivots(a,lf,rt-1);
              leftPartition = mid.getLeft() - lf;
              middlePartition = mid.getRight() - mid.getLeft();
              rightPartition = rt - mid.getRight();
  
              //1. Case leftPartition is smallest
              if(leftPartition < middlePartition && leftPartition < rightPartition){
                  AlmostQS3(a,lf,mid.getLeft(),cutoff);
                  lf = mid.getLeft() + 1;
              }
              //2. Case middlePartition is smallest
              else if(middlePartition < rightPartition){
                  AlmostQS3(a,mid.getLeft(),mid.getRight(),cutoff);
              }
              //3. Case rightPartition is smallest
              else{
                  AlmostQS3(a,mid.getRight(),rt,cutoff);
                  rt = mid.getRight() ;
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
