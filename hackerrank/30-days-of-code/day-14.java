// Your constructor must save the argument passed as its integer array parameter to the integer array instance variable (elementselements).

// The computeDifference method must then access the the integer array instance variable (elementselements) and find its maximum and minimum elements. Once these are found, the method must save their absolute difference to the maximumDifferencemaximumDifference instance variable.

// Note: The use of Math.absMath.abs is not really necessary. Because the problem constraints stipulate that we are only dealing with positive numbers, max−minmax−min will always be positive.

// Alternate Method
// A different, less efficient way of finding the maximum absolute difference would to be to iterate through element and track the smallest and largest elements, then compute their difference:

/** Finds max abs difference
*   Saves it to maximumDifference. **/
public void computeDifference(){
    // set max to its minimum possible value set by Constraints
    int max = 1;

    // set min to its maximum possible value set by Constraints
    int min = 100;
    for(int element : elements){
        if(element < min){
            min = element;
        }
        if(element > max){
            max = element;
        }
    }

    this.maximumDifference = Math.abs(max - min);
}

// class Difference{
//     // instance variables
//     private int[] elements;
//     public int maximumDifference;

//     public Difference(int[] elements){
//         this.elements = elements;
//     }

//     * Sorts the array
//     *   Saves max abs difference between first and last element to maximumDifference. *
//     public void computeDifference(){
//         Arrays.sort(elements);
//         this.maximumDifference = Math.abs(elements[elements.length - 1] - elements[0]);
//     }
// }