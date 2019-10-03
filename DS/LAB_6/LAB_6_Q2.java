// Stack.java
////////////////////////////////////////////////////////////////
class myStack
   {
   private int maxSize;        // size of stack array
   private int[] stackArray;
   private int top;            // top of stack
//--------------------------------------------------------------
// This is the constructor that takes as an argument the maximum size
// s that it ever needs to be
   public myStack(int s)         // constructor
      {
      maxSize = s;             // set array size
      stackArray = new int[maxSize];  // create array
      top = -1;                // no items yet
      }
//--------------------------------------------------------------
   public void push(int j)    // put item on top of stack
      {
      stackArray[++top] = j;     // increment top, insert item
      }
//--------------------------------------------------------------
   public int pop()           // take item from top of stack
      {
      return stackArray[top--];  // access item, decrement top
      }
//--------------------------------------------------------------
   public int peek()          // peek at top of stack
      {
      return stackArray[top];
      }
//--------------------------------------------------------------
   public boolean isEmpty()    // true if stack is empty
      {
      return (top == -1);
      }
//--------------------------------------------------------------
   public boolean isFull()     // true if stack is full
      {
      return (top == maxSize-1);
      }
	  public void displayStack()
	  {
		  if(!this.isEmpty())
		  {
			  System.out.println("\nStack:: ");
			  for(int i=0;i<=top;++i)
				  System.out.print(this.stackArray[i]+" ");
		  }
	  }
	  public int count()
	  {
		  return top;
	  }
	  
//--------------------------------------------------------------
   }  // end class Stack
////////////////////////////////////////////////////////////////
class StackApp
   {
	   static void ReverseStack(myStack s)
        {
            for (int i = 0; i < s.count(); i++)
            {
                int targetElement = s.pop();
                ReverseStackStep(s, s.count() - i, 0, targetElement);
            }
        }
 
        private static void ReverseStackStep(myStack s, int limit, int currentLevel, int targetElement)
        {
            if (currentLevel == limit)
            {
                s.push(targetElement);
            }
            else
            {
                int element = s.pop();
                ReverseStackStep(s, limit, currentLevel + 1, targetElement);
                s.push(element);
            }
        }
   public static void main(String[] args)
      {
      myStack theStack = new myStack(10);  // make new stack
      theStack.push(20);               // push items onto stack
      theStack.push(40);
      theStack.push(60);
      theStack.push(80);
		
      theStack.displayStack();
      ReverseStack(theStack);
      System.out.println("\nAfter reversing Stack:: ");
      theStack.displayStack();
      }  // end main()
   }  // end class StackApp
////////////////////////////////////////////////////////////////