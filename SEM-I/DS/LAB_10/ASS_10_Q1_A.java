// dfs.java
// demonstrates depth-first search
// to run this program: C>java DFSApp
////////////////////////////////////////////////////////////////

class Link
   {
   public int iData;              // data item (key)
   public Link next;              // next link in list
// -------------------------------------------------------------
   public Link(int id, Link newNext) // constructor
      {
      iData = id;
      next = newNext;
      }
// -------------------------------------------------------------
   public void displayLink()      // display ourself
      {
      System.out.print("{" + iData + "} ");
      }
   }  // end class Link

   
class LinkList
   {
   private Link first;            // ref to first link on list

// -------------------------------------------------------------
   public LinkList()              // constructor
      {
      first = null;               // no links on list yet
      }
// -------------------------------------------------------------
   public void insertFirst(int id)
      {                           // make new link and make it point to
				  // the old first
      Link newLink = new Link(id, first);
      first = newLink;            // now first points to this
      }
// -------------------------------------------------------------
   public Link find(int key)      // find link with given key
      {                          
      // if empty linked list, then return null
      if(first == null)
	return null;

      // otherwise scan list until a node with key is found
      Link current = first;              // start at 'first'
      while(current.iData != key)        // while no match,
         {
         if(current.next == null)        // if end of list,
            return null;                 // didn't find it
         else                            // not end of list,
            current = current.next;      // go to next link
         }
      return current;                    // found it
      }
// -------------------------------------------------------------
   public Link delete(int key)    // delete link with given key
      {                           // (assumes non-empty list)
      Link current = first;              // search for link
      Link previous = first;
      while(current.iData != key)
         {
         if(current.next == null)
            return null;                 // didn't find it
         else
            {
            previous = current;          // go to next link
            current = current.next;
            }
         }                               // found it
      if(current == first)               // if first link,
         first = first.next;             //    change first
      else                               // otherwise,
         previous.next = current.next;   //    bypass it
      return current;
      }
// -------------------------------------------------------------
   public void displayList()      // display the list
      {
      System.out.print("List (first-->last): ");
      Link current = first;       // start at beginning of list
      while(current != null)      // until end of list,
         {
         current.displayLink();   // print data
         current = current.next;  // move to next link
         }
      System.out.println("");
      }
// -------------------------------------------------------------
    void insertLast(int x)
	{
		// Make a new node containing x
		Link newNode = new Link(x, null);
		
		// If list is empty, then make first point to the new node
		if(first == null)
			first = newNode;

		// otherwise scan to the end of the list
		Link current = first;
		while(current.next != null)
			current = current.next;

		// connect the new node after current
		current.next = newNode;

	}
// -------------------------------------------------------------
// Removes all of the elements from this list.
	void clear()
	{
		first = null;
	}
// -------------------------------------------------------------
// Retrieves, but does not remove, the first (first element) of this list.
	int element()
	{
		if(first != null)
			return first.iData;

		return 0;
	}
// -------------------------------------------------------------
// Returns the element at the specified position in this list.
	int get(int index)
	{
	
		// Initialize current and initialize a counter
		Link current = first;
		int count = 0;

		// Scan as many nodes as specified by index
		while(count < index)
		{
			// check to make sure that we have not scanned
			// past the end of the list; if not move 
			// current and increment counter
			if(current != null)
			{
				current = current.next;
				count++;
			}
			else
				return 0;
		}

		// We have reached index
       		if(current != null)
			return current.iData;
                else
                	return 0;
	}	
// -------------------------------------------------------------
	int removeFirst()
	{
		Link temp = first;

		if(first != null)
		{
			first = first.next;
			return temp.iData;
		}
		else
			return 0;
	}

	int size()
	{
		Link curr = first;
		int count = 0;
		
		while (curr.next != null)
		{
			count++;
			curr = curr.next;
		}
		return count;
	}
	
	void SCCUtil(LinkList list[], boolean isVisited[], StackX stack)
	{
		Link curr = first;
		int temp = curr.iData;
		while (curr!= null)
		{
			if(!isVisited[curr.iData])
			{
				isVisited[curr.iData] = true;
				list[curr.iData].SCCUtil(list, isVisited, stack);
			}
			curr = curr.next;
		}
		
		stack.push(temp);
	}

   }  // end class LinkList


class StackX
{
	private final int SIZE = 20;
	private int[] st;
	private int top;
	// -----------------------------------------------------------
	public StackX() // constructor
	{
		st = new int[SIZE]; // make array
		top = -1;
	}
	// -----------------------------------------------------------
	public void push(int j) // put item on stack
	{ st[++top] = j; }
	// -----------------------------------------------------------
	public int pop() // take item off stack
	{ return st[top--]; }
	// ------------------------------------------------------------
	public int peek() // peek at top of stack
	{ return st[top]; }
	// ------------------------------------------------------------
	public boolean isEmpty() // true if nothing on stack-
	{ return (top == -1); }
	// ------------------------------------------------------------
} // end class StackX
////////////////////////////////////////////////////////////////
class Vertex
{
	public char label; // label (e.g. 'A')
	public boolean wasVisited;
	// ------------------------------------------------------------
	public Vertex(char lab) // constructor
	{
		label = lab;
		wasVisited = false;
	}
// ------------------------------------------------------------
} // end class Vertex
////////////////////////////////////////////////////////////////
class Graph
{
	private final int MAX_VERTS = 20;
	private Vertex vertexList[]; // list of vertices
	private LinkList list[];
	private int nVerts; // current number of vertices
	private StackX theStack;
	// -----------------------------------------------------------
	public Graph() // constructor
	{
		vertexList = new Vertex[MAX_VERTS];
		// adjacency matrix
		list = new LinkList[MAX_VERTS];
		nVerts = 0;
		
		theStack = new StackX();
	} // end constructor
	// -----------------------------------------------------------
	public void addVertex(char lab)
	{
		vertexList[nVerts++] = new Vertex(lab);
	}
	// -----------------------------------------------------------
	/*public void initializeList()
	{
	    for(int i=0;i<nVerts;++i)
	        list[i].displayList();
	}*/
	public void addEdge(int start, int end)
	{
		System.out.print(start + " "+ end);
		list[start].insertLast(end);
	}
	// ------------------------------------------------------------
	public void displayVertex(int v)
	{
		System.out.print(vertexList[v].label);
	}
	public void SCC()
	{
		boolean isvisited[] = new boolean[nVerts];
		StackX stack = new StackX();
		
		for(int i=0;i<nVerts;++i)
			isvisited[i] = false;
		
		for(int i=0;i<nVerts;++i)
			if(!isvisited[i])
				list[i].SCCUtil(list, isvisited, stack);
		
		for(int i=0;i<nVerts;++i)
		{
			System.out.print(stack.peek());
			stack.pop();
		}
	}
	
	// ------------------------------------------------------------
} // end class Graph
////////////////////////////////////////////////////////////////
public class ASS_10_Q1_A
{
	public static void main(String[] args)
	{
		Graph theGraph = new Graph();
		theGraph.addVertex('A'); // 0 (start for dfs)
		theGraph.addVertex('B'); // 1
		theGraph.addVertex('C'); // 2
		theGraph.addVertex('D'); // 3
		theGraph.addVertex('E'); // 4
		theGraph.addVertex('F'); // 5
		theGraph.addVertex('G'); // 6
		theGraph.addVertex('H'); // 7
	    //theGraph.initializeList();
		theGraph.addEdge(0, 3); // AD
		
		/*theGraph.addEdge(0, 4); // AE
		theGraph.addEdge(1, 4); // BE
		theGraph.addEdge(2, 5); // CF
		theGraph.addEdge(3, 6); // DG
		theGraph.addEdge(4, 6); // EG
		theGraph.addEdge(5, 7); // FH
		theGraph.addEdge(6, 7); // GH*/
		//System.out.print("Visits: ");
		//theGraph.dfs(); // depth-first search
		
		theGraph.SCC();
		
		System.out.println();
	} // end main()
} // end class DFSApp
////////////////////////////////////////////////////////////////