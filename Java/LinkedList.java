public class LinkedList {
    // Node inner class
    class Node {
        int data;
        Node next;
        
        // Node constructor
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
    
    // Head of the linked list
    Node head;
    
    // Constructor to initialize empty linked list
    public LinkedList() {
        this.head = null;
    }
    
    // Insert a node at the beginning of the list
    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
        System.out.println("Inserted " + data + " at the beginning");
    }
    
    // Insert a node at the end of the list
    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        
        // If list is empty, make new node as head
        if (head == null) {
            head = newNode;
        } else {
            // Traverse to the last node
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
        System.out.println("Inserted " + data + " at the end");
    }
    
    // Delete the first occurrence of a node with given data
    public void delete(int data) {
        if (head == null) {
            System.out.println("List is empty. Cannot delete.");
            return;
        }
        
        // If head node contains the data to be deleted
        if (head.data == data) {
            head = head.next;
            System.out.println("Deleted " + data + " from the list");
            return;
        }
        
        // Search for the node to be deleted
        Node current = head;
        while (current.next != null && current.next.data != data) {
            current = current.next;
        }
        
        // If node was found, delete it
        if (current.next != null) {
            current.next = current.next.next;
            System.out.println("Deleted " + data + " from the list");
        } else {
            System.out.println(data + " not found in the list");
        }
    }
    
    // Display all nodes in the list
    public void display() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        
        Node current = head;
        System.out.print("Linked List: ");
        while (current != null) {
            System.out.print(current.data);
            if (current.next != null) {
                System.out.print(" -> ");
            }
            current = current.next;
        }
        System.out.println();
    }
    
    // Search for a value in the list
    public boolean search(int data) {
        Node current = head;
        while (current != null) {
            if (current.data == data) {
                System.out.println(data + " found in the list");
                return true;
            }
            current = current.next;
        }
        System.out.println(data + " not found in the list");
        return false;
    }
    
    // Main method to test the linked list implementation
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        
        System.out.println("=== Linked List Operations ===\n");
        
        // Insert operations
        System.out.println("1. Inserting elements:");
        list.insertAtEnd(10);
        list.insertAtEnd(20);
        list.insertAtEnd(30);
        list.insertAtBeginning(5);
        list.display();
        System.out.println();
        
        // Search operation
        System.out.println("2. Searching for elements:");
        list.search(20);
        list.search(100);
        System.out.println();
        
        // Delete operation
        System.out.println("3. Deleting elements:");
        list.delete(10);
        list.display();
        list.delete(5);
        list.display();
        list.delete(30);
        list.display();
        System.out.println();
        
        // Final state
        System.out.println("4. Final state:");
        list.display();
    }
}



