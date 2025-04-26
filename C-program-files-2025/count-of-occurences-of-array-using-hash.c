#include <stdio.h>
#include <stdlib.h>

// continuously takes input from console and fills the contiguous `n` blocks of memory in the array `arr`
void cin_array(int arr[],int n) {
  for (int i=0;i<n;i++) {
    scanf("%d", &arr[i]);
  }
}

// a custom data structure containing pointer to an int array - `int * data` and it's size - `int length`
typedef struct {
  int len;
  int* data;
} intlist_t;

int max_element(intlist_t list) {
  int max = 0;
  for (int i=0;i<list.len;i++) {
    if (max < list.data[i]) max = list.data[i];
  }
  return max;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int hash(int val, int factor) {
  return val % factor;
}

void delete_intlist(intlist_t* list) {
  free(list->data);
  list->data = NULL;
}

// returns an `intlist_t` type struct containing an array of all distinct elements of the input array 'arr' of size `n`
intlist_t n_distinct(int arr[], int n) {
  qsort(arr, n, sizeof(int), compare);

  intlist_t list;
  list.data = (int *)malloc(n * sizeof(int));
  int index = 0;

  for (int i = 0; i < n; i++) {
    if (i == 0 || arr[i] != arr[i - 1]) {
      list.data[index++] = arr[i];
    }
  }
  list.len = index;
  return list;
}

// Define a structure for the hashmap entry
typedef struct {
  int key;
  int value;
} hashmap_entry_t;

int main(int argc, char *argv[]) {
  // taking inputs
  int n;
  printf("Enter the size of the array:\t");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements of the array, one by one\n");
  cin_array(arr, n);

  intlist_t distinctlist = n_distinct(arr, n);
  int max_distinct = max_element(distinctlist);

  // Create a static hashmap (an array of hashmap entries)
  // We need to decide on the size of the hashmap. A common approach is
  // to use a size roughly proportional to the number of distinct elements,
  // or a prime number for better distribution. For simplicity, let's use
  // the number of distinct elements as the size. You might want to choose
  // a larger size or a prime number in a real-world scenario to reduce collisions.
  int hashmap_size = distinctlist.len;
  hashmap_entry_t hashmap[hashmap_size];

  // Initialize the hashmap (optional, but good practice to mark entries as empty)
  for (int i = 0; i < hashmap_size; i++) {
    hashmap[i].key = -1; // Use -1 or some other indicator for an empty slot
    hashmap[i].value = 0;
  }

  // Populate the hashmap with the counts of each element in the original array
  for (int i = 0; i < n; i++) {
    int key = arr[i];
    int index = hash(key, hashmap_size);

    // Handle collisions using linear probing (for simplicity)
    while (hashmap[index].key != -1 && hashmap[index].key != key) {
      index = (index + 1) % hashmap_size;
    }

    if (hashmap[index].key == -1) {
      hashmap[index].key = key;
    }
    hashmap[index].value++;
  }

  // Print the contents of the hashmap
  printf("\nOccurrences of elements in the array:\n");
  for (int i = 0; i < hashmap_size; i++) {
    if (hashmap[i].key != -1) {
      printf("%d: %d times\n", hashmap[i].key, hashmap[i].value);
    }
  }

  // deleting dynamically allocated memory
  delete_intlist(&distinctlist);
  return EXIT_SUCCESS;
}
