import java.util.Scanner;

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

   public LinkList()              // constructor
    {
      first = null;               // no links on list yet
    }

   public void insertFirst(int id)
    {           // make new link and make it point to
      Link newLink = new Link(id, first);
      first = newLink;           // now first points to this
    }
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
	  
	int size()
	{
		Link curr = first;
		int count = 0;
		
		while (curr != null)
		{
			count++;
			curr = curr.next;
		}
		return count;
	}
	int sum()
	{
		Link curr = first;
		int sum = 0;
		
		while (curr != null)
		{
			sum+=curr.iData;
			curr = curr.next;
		}
		return sum;
	}
	void removeLast()
	{
		Link curr = first;
		int n;
		if(curr.next!=null)
		{
			if(curr.next==null)
			{
				n=curr.iData;
				first = null;
			}
			else
			{
				Link pre = curr;
				curr = curr.next;
				
				while (curr.next!= null)
				{
					pre = curr;
					curr = curr.next;
				}
				n = curr.iData;
				pre.next = null;
			}
			System.out.println("\nNode Deleted from list is:: "+n);
			
		}
		else
			System.out.println("\noops linked-list must has atleast 2 nodes!!");
		
	}
	void append(LinkList L2)
	{
		Link curr = first;
		if(curr!=null)
		{
			while (curr.next!= null)
					curr = curr.next;
			curr.next = L2.first;
		}
		else
			System.out.println("\noops linked-list must not be empty!!");
	}
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
	void  copy(LinkList copyList)
	{
		Link curr = first;
		//LinkList copyList = new LinkList();
		if(curr!=null)
		{
			while(curr!=null)
			{
				copyList.insertLast(curr.iData);
				curr = curr.next;
			}
			copyList.displayList();
			//return copyList;
		}
		else
		{
			System.out.println("\noops linked-list must not be empty!!");
			//return null;
		}
	}
	// -------------------------------------------------------------
    public static void main(String[] args)
	{
		int choice=0;
		Scanner input = new Scanner(System.in);
		
		LinkList L = new LinkList();
		LinkList L2 = new LinkList();
		LinkList copyList = new LinkList();
		L2.insertFirst(50);
		L2.insertFirst(60);
		L2.insertFirst(70);
		do
		{
			System.out.println("\n=====MAIN MENU=====");
			System.out.println("1.INSERT AT FIRST");
			System.out.println("2.DISPLAY");
			System.out.println("3.SIZE");
			System.out.println("4.SUM");
			System.out.println("5.REMOVE LAST ELEMENT");
			System.out.println("6.APPEND");
			System.out.println("7.COPY");
			System.out.println("99.EXIT");
			System.out.println("ENTER YOUR CHOICE:: ");
			choice = input.nextInt();
			switch(choice)
			{
				case 1:
					System.out.println("\nEnter number to insert:: ");
					L.insertFirst(input.nextInt());
					break;
					
				case 2:
					L.displayList();
					break;
				case 3:
					System.out.println("\nTotal Elements in linked-list are::  "+L.size());
					break;
				case 4:
					System.out.println("\nSum of all elements is:: "+L.sum());
					break;
				case 5:	
					L.removeLast();
					L.displayList();
					break;
				case 6:
					System.out.println("linked-list1:: ");
					L.displayList();
					System.out.println("linked-list2:: ");
					L2.displayList();
					L.append(L2);
					System.out.println("\nAfter appending linked-list1:: ");
					L.displayList();
					break;
				case 7:
					L.copy(copyList);
					System.out.println("\nnew copy list is:: ");
					copyList.displayList();
				default:
					System.out.println("\nOoops wrong choice!!");
			}
		}while(choice!=99);

	}
}  // end class LinkList
	