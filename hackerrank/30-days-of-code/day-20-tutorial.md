Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate).

Sorting
Sorting is the act of ordering elements. The ability of a program to organize and retrieve data quickly and efficiently is incredibly important in software development. Learning how to effectively sort and retrieve the data you're working with enables you to write better, faster algorithms.

Bubble Sort
This is a very simple sorting algorithm. Because it's also very inefficient, Bubble Sort is not practical for real-world use and is generally only discussed in an academic context. The basic theory behind BubbleSort is that you take an array of integers and iterate through it; for each element at some index i whose value is greater than the element at the index following it (i.e.: index i + 1), you must swap the two values. The act of swapping these values causes the larger, unsorted values to float to the back (like a bubble) of the data structure until they land in the correct location.

Example
class Sorting {
    private static void printArray(String s, int[] x){
        System.out.print(s + " Array: ");
        for(int i : x){
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static void bubbleSort(int[] x){
        printArray("Initial", x);

        int endPosition = x.length - 1;
        int swapPosition;

        while( endPosition > 0 ){
            swapPosition = 0;

            for(int i = 0; i < endPosition; i++){

                if( x[i] > x[i + 1] ){
                    // Swap elements 'i' and 'i + 1':
                    int tmp = x[i];
                    x[i] = x[i + 1];
                    x[i + 1] = tmp;

                    swapPosition = i;
                } // end if

                printArray("Current", x);
            } // end for

            endPosition = swapPosition;
        } // end while

        printArray("Sorted", x);
    } // end bubbleSort

    public static void main(String[] args) {
        int[] unsorted = {1, 5, 2, 4, 3};
        bubbleSort(unsorted);
    }
}

This version of BubbleSort produces the following output:
Initial Array: 1 5 2 4 3
Current Array: 1 5 2 4 3
Current Array: 1 2 5 4 3
Current Array: 1 2 4 5 3
Current Array: 1 2 4 3 5
Current Array: 1 2 4 3 5
Current Array: 1 2 4 3 5
Current Array: 1 2 3 4 5
Current Array: 1 2 3 4 5
Current Array: 1 2 3 4 5
Sorted Array: 1 2 3 4 5