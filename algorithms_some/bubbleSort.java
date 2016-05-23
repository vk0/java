public static double[] bubbleSort(double[] items) {
    //This variable keeps track of whether we've swapped any items in the array.
    //If we haven't swapped any, that means the list is already properly arranged.
    boolean noChange;

    for (int i = 0; i < items.length - 1; i++) {
        noChange = true;
        for (int j = 0; j < items.length - 1 - i; j++) {
            if (items[j] > items[j+1]) {
                //Swap the items and mark that we have made a change.
                double temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
                noChange = false;
            }
        }
        if (noChange) {
            //At this point, if noChange is still true, we know we've gone through
            //items without making changes, so we're done.
            return items;
        }
    }
    return items;
}

// Suppose we have the list [9, 5, 3, 2]. How would we use Bubble Sort to put the elements in ascending order?

// 1. [9, 5, 3, 2] – Compare the first and second elements. As they are not ordered correctly, switch them.
// 2. [5, 9, 3, 2] – Now consider the second and third elements. As they are once again ordered incorrectly, switch them.
// 3. [5, 3, 9, 2] – Consider the third and fourth and elements. Once again they are not in order, so switch them.
// 4. [5, 3, 2, 9] – Notice that as expected, 9, the largest element, is in the proper position.
// 5. [5, 3, 2, 9] – Consider the first two elements. As they are ordered incorrectly, switch them.
// 6. [3, 5, 2, 9] – Consider the second and third elements. They are not ordered correctly, so switch them.
// 7. [3, 2, 5, 9] – Notice that 5, the second largest element, is now in the proper position.
// 8. [3, 2, 5, 9] – Consider the first two elements, as they are in the wrong order, switch them.
// 9. [2, 3, 5, 9] – Notice that the list is now ordered properly, so we’re done.