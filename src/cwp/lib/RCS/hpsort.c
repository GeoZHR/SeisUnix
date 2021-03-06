/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

void
hpsort (int n, float a[])
/*****************************************************************************
sort an array so that a[0] <= a[1] <= ... <= a[n-1]
******************************************************************************
Input:
n		number of elements in a
a		array[n] to be sorted

Output:
a		array[n] sorted
******************************************************************************
Notes:
Adapted from Standish, T. A., Data Structure Techniques, p. 91.
******************************************************************************
Author:  Dave Hale, Colorado School of Mines, 12/26/89
*****************************************************************************/
{
	int kroot,klast,kparent,kchild;
	float aparent;
	
	/* initialize indices of root node and last node in heap */
	kroot = n/2-1;
	klast = n-1;
	
	/* loop until array is sorted */
	while (klast>0) {
	
		/* if in the heap building phase */
		if (kroot>=0) {
		
			/* set index of parent to be added to the heap */
			kparent = kroot;

			/* set value of parent to be added to the heap */
			aparent = a[kroot--];
		
		/* else, the tree is a heap and in the sorting phase */
		} else {
			
			/* set index of parent at which to begin sifting */
			kparent = 0;
	
			/* set parent value to last value in heap */
			aparent = a[klast];
			
			/* copy top of heap to sorted elements at end */
			a[klast--] = a[0];
		}

		/* sift parent down until greater than both children */
		for (kchild=kparent*2+1; kchild<=klast; kchild=kparent*2+1) {

			/* get index of greater of two children */
			if (kchild<klast && a[kchild+1]>a[kchild]) kchild++;

			/* if greater child is greater than parent */
			if (a[kchild]>aparent) {
			
				/* promote the greater child */
				a[kparent] = a[kchild];

				/* demote the parent */
				kparent = kchild;
			
			/* else, if parent is greater than children, break */
			} else 
				break;
		}
	
		/* set value of parent (which may have been demoted) */
		a[kparent] = aparent;
	}
}
