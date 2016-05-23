public static List<Double> insertionSort(List<Double> items ){
    for (int i = 1; i < items.size(); i++) {
        //Store the value of the current item to be inserted.
        Double currItem = items.get(i);

        //Checks if the current item to be inserted belongs at the start of the list.
        if (currItem < items.get(0)) {
            //Insert the current item at the start of the list.
            items.add(0, items.remove(i));
        } else {
            for (int j = 0; j < i; j++) {
                if (currItem > items.get(j) && currItem <= items.get(j+1)) {
                    //Insert the current item in its correct location and begin
                    //processing the next item.
                    items.add(j+1, items.remove(i));
                    break;
                }
            }
        }
    }
    return items;
}

// Suppose we have the list [9, 5, 3, 2]. How would we use Insertion Sort to put the elements in ascending order?

// 1. [9, 5, 3, 2] – Consider the second element, 5. Insert it into the sorted list of length one, [9].
// 2. [5, 9, 3, 2] – Consider the third element, 3. Insert it into the sorted list of length two, [5, 9].
// 3. [3, 5, 9, 2] – Consider the fourth element, 2. Insert it into the sorted list of length three, [3, 5, 9].
// 4. [2, 3, 5, 9] – Our list is now sorted properly, so we’re done.