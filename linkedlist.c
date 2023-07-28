#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* next;
};

typedef struct node Node;

// Function to create a new node
Node* create_node(int value) 
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) 
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to append an item to the end of the list
void append(Node** list, int value) 
{
    Node* new_node = create_node(value);
    if (new_node == NULL) 
    {
        return;
    }

    if (*list == NULL) 
    {
        *list = new_node;
    } 
    else 
    {
        Node* last_node = *list;
        while (last_node->next != NULL) 
        {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
}

// Function to extend the list by appending elements from the given iterable
void extend(Node** list, int iterable[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        Node* new_node = create_node(iterable[i]);
        if (new_node == NULL) 
        {
            return;
        }

        if (*list == NULL) 
        {
            *list = new_node;
        } else {
            Node* last_node = *list;
            while (last_node->next != NULL) 
            {
                last_node = last_node->next;
            }
            last_node->next = new_node;
        }
    }
}

// Function to insert an item at a specified index in the list
void insert(Node** list, int index, int value) 
{
    if (index < 0) 
    {
        fprintf(stderr, "Index out of range.\n");
        return;
    }

    Node* new_node = create_node(value);
    if (new_node == NULL) 
    {
        return;
    }

    if (index == 0) 
    {
        // Insert at the beginning of the list
        new_node->next = *list;
        *list = new_node;
    } else {
        Node* current = *list;
        Node* prev = NULL;
        int i = 0;

        while (current != NULL && i < index) 
        {
            prev = current;
            current = current->next;
            i++;
        }

        if (i < index) 
        {
            fprintf(stderr, "Index out of range.\n");
            free(new_node);
            return;
        }

        new_node->next = current;
        if (prev != NULL) 
        {
            prev->next = new_node;
        } 
        else
        {
            *list = new_node;
        }
    }
}

// Function to remove the first occurrence of the specified item from the list
void remove_element(Node** list, int value)
{
    Node* current = *list;
    Node* prev = NULL;

    while (current != NULL)
    {
        if (current->value == value)
        {
            if (prev == NULL)
            {
                *list = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
}

// Function to remove and return the item at the specified index (or the last item if no index is provided)
int pop(Node** list, int index)
{
    if (*list == NULL)
    {
        fprintf(stderr, "List is empty.\n");
        return -1;
    }

    Node* current = *list;
    Node* prev = NULL;
    int i = 0;

    while (current != NULL && i < index)
    {
        prev = current;
        current = current->next;
        i++;
    }

    if (current == NULL)
    {
        fprintf(stderr, "Index out of range.\n");
        return -1;
    }

    // Remove the item at the specified index
    if (prev == NULL)
    {
        // Element to remove is the head
        *list = current->next;
    } else {
        prev->next = current->next;
    }

    int value = current->value;
    free(current);
    return value;
}

// Function to remove all items from the list
void clear_list(Node** list)
{
    Node* current = *list;
    while (current != NULL)
    {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *list = NULL;
}

// Function to return the index of the first occurrence of the specified item within the given start and end indexes
int find_index(Node* list, int value, int start, int end)
{
    int index = 0;
    while (list != NULL)
    {
        if (index >= start && (end < 0 || index <= end) && list->value == value)
        {
            return index;
        }
        list = list->next;
        index++;
    }
    return -1;
}

// Function to return the number of occurrences of the specified item in the list
int count(Node* list, int value)
{
    int count = 0;
    while (list != NULL)
    {
        if (list->value == value)
        {
            count++;
        }
        list = list->next;
    }
    return count;
}

// Function to sort the list in ascending order using Bubble Sort
void sort(Node** list) {
    if (*list == NULL || (*list)->next == NULL)
    {
        return; // Empty list or single node list (already sorted)
    }

    int swapped;
    Node* current;
    Node* last = NULL;

    do
    {
        swapped = 0;
        current = *list;

        while (current->next != last)
        {
            if (current->value > current->next->value)
            {
                // Swap the nodes
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    }
    while (swapped);
}

// Function to reverse the order of the items in the list
void reverse(Node** list)
{
    Node* prev = NULL;
    Node* current = *list;
    Node* next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *list = prev;
}

// Function to create a shallow copy of the list
Node* copy(Node* list)
{
    Node* new_list = NULL;
    Node* current = list;
    while (current != NULL)
    {
        append(&new_list, current->value);
        current = current->next;
    }
    return new_list;
}

// Function to print the list
void print_list(Node* list)
{
    while (list != NULL)
    {
        printf("%i\n", list->value);
        list = list->next;
    }
}

int main(void)
{
    Node* list = NULL;

    // rest of the code...

    clear_list(&list);
    return 0;
}

   
