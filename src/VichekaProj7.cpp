#include <iostream>
using namespace std;

void menu();

void fill_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is filled from keyboard
void print_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is printed to screen with 5 elements per line
int linear_search(int arr[], int size, int key);
// pre-condition: arr has given size
// post-condition: The index of first occurrence of key in arr is returned. If the key cannot be found in arr, -1 is returned
void select_sort(int arr[], int size);
// pre-condition: arr has given size 
// post-condition: the elements in arr are rearranged from least to largest
void insert_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest
void bubble_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

int main() {
  int choice;
  int a[9];
  do{
    menu();
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice)
    {
      case 1:
      {
        fill_array(a, 9);
        cout << "Enter the key you want to search: ";
        int key;
        cin >> key;
        int index = linear_search(a, 9, key);
        if(index == -1)
          cout << "The key " << key << " is not in array\n";
        else
          cout << "The key " << key << " is #" << (index + 1) << " element in array\n";
          break;
      }
      case 2:
      {
        fill_array(a, 9);
        select_sort(a, 9);
        cout << "After sort, the array is:\n";
        print_array(a, 9);
        break;
      }
      case 3:
      {
        fill_array(a, 9);
        insert_sort(a, 9);
        cout << "After sort, the array is:\n";
        print_array(a, 9);
        break;
      }
      case 4:
      {
        fill_array(a, 9);
        bubble_sort(a, 9);
        cout << "After sort, the array is:\n";
        print_array(a, 9);
        break;
      }
      case 5:
      {
        cout << "Thank you for using the array functions\n";
        break;
      }
      default:
      {
        cout << "Wrong choice. Please choose from menu: ";
        break;
      }  
    }
  }while(choice != 5);
  return 0;
}

// functions implementation
void menu(){
    cout << "**********************************************\n";
	  cout << "** Menu Options:                            **\n";
    cout << "** 1. Fill Array and Perform Linear Search  **\n";
    cout << "** 2. Fill Array and Perform Selection Sort **\n";
    cout << "** 3. Fill Array and Perform Insertion Sort **\n";
    cout << "** 4. Fill Array and Perform Bubble Sort    **\n";
    cout << "** 5. Exit                                  **\n";
    cout << "**********************************************\n";
}

void fill_array(int arr[], int size){
    cout << "Enter your sequence of values into the arra: ";
    for (int i = 0; i<size; i++)
      cin >> arr[i];
}

void print_array(int arr[], int size){
  for (int i = 0; i<size; i++){
	cout << arr[i] << "\t";
	if (i % 4 == 0 && i != 0)
		cout << endl;
  }
  cout << endl;
}

int linear_search(int arr[], int size, int key){
	for (int i = 0; i < size; i++) {
    if (arr[i] == key) {
      return i; 
    }
  }
  return -1; 
}

void select_sort(int arr[], int size){
	if (size > 0){
		for (int i = 0; i < size - 1; i++) {
			int minIndex = i;
			for (int j = i + 1; j < size; j++) {
				if (arr[j] < arr[minIndex]) {
					minIndex = j;
				}
			}
			swap(arr[i], arr[minIndex]);
    }
	} else 
		return;
}

void insert_sort(int arr[], int size){
if (size > 0){
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
} else 
        return;
}

void bubble_sort(int arr[], int size){
  if (size > 0){
    for (int i = 1; i < size - 1; i++) {
      bool swapped = false;
      for (int j = 0; j < size; j++){
        if (arr[j] > arr[j+1]){
          swap(arr[j], arr[j+1]);
          swapped = true;
        }
      }
      if (!swapped)
        break;
    }
  } else 
    return;
}
