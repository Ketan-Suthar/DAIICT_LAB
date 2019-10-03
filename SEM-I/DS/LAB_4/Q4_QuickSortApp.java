// quickSort.java
// demonstrates simple version of quick sort
// to run this program: C>java QuickSort1App
////////////////////////////////////////////////////////////////
class ArrayIns
{
	private long[] theArray; // ref to array theArray
	private int nElems; // number of data items
//--------------------------------------------------------------
public ArrayIns(int max) // constructor
{
	theArray = new long[max]; // create the array
	nElems = 0; // no items yet
}
//--------------------------------------------------------------
public void insert(long value) // put element into array
{
	theArray[nElems] = value; // insert it
	nElems++; // increment size
}
//--------------------------------------------------------------
public void display() // displays array contents
{
	System.out.print("A=");
	for(int j=0; j<nElems; j++) // for each element,
		System.out.print(theArray[j] + " "); // display it
	System.out.println("");
}
//--------------------------------------------------------------
public void quickSort()
{
	recQuickSort(0, nElems-1);
}
//--------------------------------------------------------------
public void recQuickSort(int left, int right)
{
	if(right-left <= 0) // if size <= 1,
	return; // already sorted
	else // size is 2 or larger
	{
		long pivot = theArray[right]; // rightmost item
		// partition range
		int partition = partitionIt(left, right, pivot);
		recQuickSort(left, partition-1); // sort left side
		recQuickSort(partition+1, right); // sort right side
	}
} // end recQuickSort()
//--------------------------------------------------------------
public int partitionIt(int left, int right, long pivot)
{
	int leftPtr = left-1; // left (after ++)
	int rightPtr = right; // right-1 (after --)
	while(true)
	{ 
		// find bigger item
		while( theArray[++leftPtr] < pivot ); // (nop)
		// find smaller item
		while(rightPtr > 0 && theArray[--rightPtr] > pivot); // (nop)
		if(leftPtr >= rightPtr) // if pointers cross,
			break; // partition done
		else // not crossed, so
			swap(leftPtr, rightPtr); // swap elements
	} // end while(true)
	swap(leftPtr, right); // restore pivot
	return leftPtr; // return pivot location
} // end partitionIt()
//--------------------------------------------------------------
public void swap(int dex1, int dex2) // swap two elements
{
	long temp = theArray[dex1]; // A into temp
	theArray[dex1] = theArray[dex2]; // B into A
	theArray[dex2] = temp; // temp into B
} // end swap(
//--------------------------------------------------------------
} // end class ArrayIns
////////////////////////////////////////////////////////////////
class Q4_QuickSortApp
{
	public static void main(String[] args)
	{
		int maxSize = 16; // array size
		ArrayIns arr;
		arr = new ArrayIns(maxSize); // create array
		for(int j=0; j<maxSize; j++) // fill array with
		{ 
			// random numbers
			long n = (int)(java.lang.Math.random()*99);
			arr.insert(n);
		}
		arr.display(); // display items
		arr.quickSort(); // quicksort them
		arr.display(); // display them again
	} // end main()
} // end class QuickSortApp