public static double[] selectionSort(double[] items) {
    for (int i = 0; i < items.length - 1; i++) {
        //----Find the minimum value between i and the end of the list---->

        //Store this minimum value and its position in minValue and minIndex respectively.
        //Initialize these to i and the value stored at i.
        int minIndex = i;
        double minValue = items[minIndex];
        for (int j = i + 1; j < items.length; j++) {
            //If a value smaller than the current minValue is found, set this to be equal
            //to minValue and store its position.
            if (items[j] < minValue) {
                minIndex = j;
                minValue = items[j];
            }
        }
        //Swap the minimum value found with the element at position i.
        items[minIndex] = items[i];
        items[i] = minValue;
    }

    //At this point the list will be properly sorted, so return it.
    return items;
}

// Suppose we have the list [9, 5, 3, 2] from before. How would we use Selection Sort to put the elements in ascending order?

// 1. [9, 5, 3, 2] – Identify that 2 is the smallest element in the list. Swap it with the element in position #1.
// 2. [2, 5, 3, 9] – Identify that 3 is the smallest element in the remaining set. Swap it with the element in position #2.
// 3. [2, 3, 5, 9] – Identify that 5 is the smallest element in the remaining set. Swap it with the element in position #3 (itself).
// 4. [2, 3, 5, 9] – Notice that our list is now properly sorted and we have achieved our goal.