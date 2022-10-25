import java.util.*;
 
class Node {
    // initialising data field and next pointer of node
    int data;
    Node next;
 
    Node(int d) {
        this.data = d;
        this.next = null;
    }
}
 
class detectCycle {
    Node head;
 
    // creating a linked list using array
    public void buildLinkedlist(int A[], int noOfNodes) {
        int i;
        Node temp, last;
        temp = new Node(A[0]);
        temp.next = null;
        head = temp;
        last = temp;
        for (i = 1; i < noOfNodes; i++) {
            temp = new Node(A[i]);
            temp.next = null;
            last.next = temp;
            last = temp;
        }
    }
 
    //printing of linkedList
    public void printLinkedlist() {
        List<String> allNodesList = new ArrayList<>();
        Node temp = head;
        while (temp != null) {
            allNodesList.add(Integer.toString(temp.data));
            temp = temp.next;
        }
        System.out.println(String.join(" -> ", allNodesList));
    }
 
    public void detectCycle_linkedList() {
        int flag=0;
        Node slow, fast;
        slow = fast = head;
        while (slow != null && fast != null && fast.next!=null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                flag = 1;
                break;
            }
        }
        if(flag==1)
        {
            System.out.println("Cycle detected in given LinkedList");
        }
        else{
            System.out.println("Cycle is not detected in given LinkedList");
        }
 
    }
 
    public static void main(String[] args) {
        int[] linkedlistElements = new int[] { 1, 2, 3, 4, 5 };
        int numberOfNodes = 5;

        // initialising object of linkedlist class
        detectCycle ll = new detectCycle();
        ll.buildLinkedlist(linkedlistElements, numberOfNodes);
        System.out.print("Given Linked List ");
        ll.printLinkedlist();

        //40 is connected to 10
        ll.head.next.next.next.next=ll.head.next.next;
        ll.detectCycle_linkedList();
 
    }
}
 
