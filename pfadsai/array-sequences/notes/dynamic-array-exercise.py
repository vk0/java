# Dynamic Array Exercise
# In this exercise we will create our own Dynamic Array class!
# We'll be using a built in library called ctypes. Check out the documentation for more info, but its basically going to be used here as a raw array from the ctypes module. If you find yourself very interested in it, check out: Ctypes Tutorial

import ctypes

class DynamicArray(object):
    '''
    DYNAMIC ARRAY CLASS (Similar to Python List)
    '''

    def __init__(self):
        self.n = 0 # Count actual elements (Default is 0)
        self.capacity = 1 # Default Capacity
        self.A = self.make_array(self.capacity)

    def __len__(self):
        """
        Return number of elements sorted in array
        """
        return self.n

    def __getitem__(self,k):
        """
        Return element at index k
        """
        if not 0 <= k <self.n:
            return IndexError('K is out of bounds!') # Check it k index is in bounds of array

        return self.A[k] #Retrieve from array at index k

    def append(self, ele):
        """
        Add element to end of the array
        """
        if self.n == self.capacity:
            self._resize(2*self.capacity) #Double capacity if not enough room

        self.A[self.n] = ele #Set self.n index to element
        self.n += 1

    def _resize(self,new_cap):
        """
        Resize internal array to capacity new_cap
        """

        B = self.make_array(new_cap) # New bigger array

        for k in range(self.n): # Reference all existing values
            B[k] = self.A[k]

        self.A = B # Call A the new bigger array
        self.capacity = new_cap # Reset the capacity

    def make_array(self,new_cap):
        """
        Returns a new array with new_cap capacity
        """
        return (new_cap * ctypes.py_object)()

# Instantiate
arr = DynamicArray()

# Append new element
arr.append(1)

# Check length
len(arr)

# Append new element
arr.append(2)

# Index
arr[0]
arr[1]