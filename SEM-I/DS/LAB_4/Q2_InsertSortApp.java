// insertSort.java
// demonstrates insertion sort
// to run this program: C>java InsertSortApp
//--------------------------------------------------------------
class ArrayIns
   {
   private double[] a;               // ref to array a
   private int nElems;               // number of data items
//--------------------------------------------------------------
   public ArrayIns(int max)          // constructor
      {
      a = new double[max];               // create the array
      nElems = 0;                        // no items yet
      }
//--------------------------------------------------------------
   public void insert(double value)  // put element into array
      {
      a[nElems] = value;             // insert it
      nElems++;                      // increment size
      }
//--------------------------------------------------------------
   public void display()             // displays array contents
      {
      for(int j=0; j<nElems; j++)       // for each element,
         System.out.print(a[j] + " ");  // display it
      System.out.println("");
      }
//--------------------------------------------------------------
   public void insertionSort()
      {
      int in, out,comparions=0,swaps=0,copies=0;

      for(out=1; out<nElems; out++)     // out is dividing line
         {
         double temp = a[out];          // remove marked item
		 copies++;
		 swaps++;
         in = out;                      // start shifts at out
         while(in>0) // until one is smaller,
        {
            comparions++;
            if(a[in-1] >= temp)
            {
                a[in] = a[in-1]; // shift item to right
                swaps++;
                --in;
            }
            else
                break;              // go left one position
            }
         a[in] = temp;                  // insert marked item
         }  // end for
         System.out.print("toal comparions: "+comparions+"\n total swaps: "+swaps+"\n total copies made: "+copies);
      }  // end insertionSort()
//--------------------------------------------------------------
   }  // end class ArrayIns
////////////////////////////////////////////////////////////////
class Q2_InsertSortApp
   {
   public static void main(String[] args)
      {
      int maxSize = 100;            // array size
      ArrayIns arr;                 // reference to array
      arr = new ArrayIns(maxSize);  // create the array

      arr.insert(77);               // insert 10 items
      arr.insert(99);
      arr.insert(44);
      arr.insert(55);
      arr.insert(22);
      arr.insert(88);
      arr.insert(11);
      arr.insert(00);
      arr.insert(66);
      arr.insert(33);

      arr.display();                // display items

      arr.insertionSort();          // insertion-sort them

      arr.display();                // display them again
      }  // end main()
   }  // end class InsertSortApp