// Queue.java
////////////////////////////////////////////////////////////////
class Queue
   {
   private int maxSize;
   private int [] queArray;
   private int front;
   private int rear;
   private int nItems;
//--------------------------------------------------------------
// This is a constructor that is given the maximum possible
// queue size. In this implementation, the queue is static
// i.e., the number of elements we can enqueue cannot exceed the
// maximum specified. This implementation can be made dynamic
// by resizing the array. Alternately, a linked list can be used
   public Queue(int s)          
      {
      maxSize = s;
      queArray = new int[maxSize];
      front = 0;
      rear = -1;
      nItems = 0;
      }
//--------------------------------------------------------------
   public void insert(int item)   // put item at rear of queue
      {
      if(rear == maxSize-1)         // deal with wraparound
         rear = -1;

      queArray[++rear] = item;         // increment rear and insert
      nItems++;                     // one more item
      }
//--------------------------------------------------------------
   public int remove()         // take item from front of queue
      {
      int temp = queArray[front++]; // get value and incr front
      if(front == maxSize)           // deal with wraparound
         front = 0;
      nItems--;                      // one less item
      return temp;
      }
//--------------------------------------------------------------
   public int peek()      // peek at front of queue
      {
      return queArray[front];
      }
//--------------------------------------------------------------
   public boolean isEmpty()    // true if queue is empty
      {
      return (nItems==0);
      }
//--------------------------------------------------------------
   public boolean isFull()     // true if queue is full
      {
      return (nItems==maxSize);
      }
//--------------------------------------------------------------
   public int size()           // number of items in queue
      {
      return nItems;
      }
	  public void displayQueue()
	  {
		if(rear!=-1)
		{
			System.out.print("\nQueue Is:: ");
			for(int i=front;i<=rear;++i)
				System.out.print(queArray[i]+" ");
		}
	  }
	  
//--------------------------------------------------------------
   }  // end class Queue
class QueueApp
   {
          public static void reverse(Queue q)
    	  {
    		  // Base case 
			if (q.isEmpty()) 
				return; 

			// Dequeue current item
			int data = q.peek(); //store current item
			q.remove(); 
			// Reverse remaining queue 
			reverse(q); 

			// Enqueue current item
			q.insert(data); 
    	  }
      public static void main(String[] args)
      {
          Queue theQueue = new Queue(5); // queue holds 5 items
          theQueue.insert(10); 
          theQueue.insert(20);
          theQueue.insert(30);
          theQueue.insert(40);
          theQueue.insert(50); 
          
          theQueue.displayQueue();
          reverse(theQueue);
          System.out.println("\nAfter reversing queue:: ");
          theQueue.displayQueue();
        } // end main()
     } // end class QueueApp
        	  
        	  
        	