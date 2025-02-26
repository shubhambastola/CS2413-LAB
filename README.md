# **CS2413-LAB**

## **Reverse a Singly Linked List**

This function reverses a singly linked list in C using an iterative approach. It modifies the `next` pointers of each node to reverse the list in place.

### **Algorithm**

1. Initialize `previous` as `NULL`.
2. Traverse the list while `head` is not `NULL`:
   - Store the next node.
   - Reverse the `next` pointer.
   - Move `previous` and `head` forward.
3. Return `previous` as the new head.

### **Time Complexity**  
**O(n)**  

---

## **Remove Elements from Linked List**

This program removes all occurrences of a specified value from a singly linked list by updating pointers to skip the matching nodes.

### **Function Definition**

```c
struct ListNode * removeElements(struct ListNode * head, int val);
```

### **Explanation**


1) head: Pointer to the start of the list.
2) val: Value to remove from the list.
3) Return the value in the linked list without the specified value

### **Time Complexity**
**O(n)**

