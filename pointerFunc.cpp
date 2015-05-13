#include <iostream> 
#include <algorithm> // header for swap function
#include <chrono> // header for timing

typedef bool (*comparison)(int, int);

bool ascending(int a, int b) {
    return a > b;
}

bool descending(int a, int b) {
    return a < b;
}

void selectionSort(int *array, int sizeofArray, comparison compare) {
    using namespace std;

    // I think it would be more pure to time around this for loop.
    for (int element = 0; element < sizeofArray; element++) {
        int largestElement = element; 
        for (int remainingElement = element + 1; remainingElement < sizeofArray; remainingElement++) {
            if (compare(array[remainingElement], array[largestElement])) {
                largestElement = remainingElement; 
            }    
        }
        swap(array[element], array[largestElement]);
    }

}

// Should do some validation to make sure elements past in are legit.
void printArray(int *array, int sizeofArray) {
    using namespace std;
    
    cout << "numberArray: {";
    for (int index = 0; index < sizeofArray; index++) {

        cout << " " << array[index];
        if (index < sizeofArray - 1) {
            cout << ", ";
        }

    }
    cout << " }" << endl;
}

int main(int argc, char *argv[]) {
    using namespace std;

    char order;
    do {
        cout << "Type the letter 'a' for ascending order or 'd' for descending order: ";
        cin >> order;
    } while(order != 'a' && order != 'd');

    int numberArray[] = {4, 12, 1, 0, 18, 21, 14, 2, 90, 0, 1, 10};
    int sizeofArray = sizeof(numberArray)/sizeof(numberArray[0]);

    cout << "Initial ";
    printArray(numberArray, sizeofArray); 
    
    // Starting time
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();

    if (order == 'a') {
        selectionSort(numberArray, sizeofArray, ascending);
    }
    else if (order == 'd') {
        selectionSort(numberArray, sizeofArray, descending);
    }
    else {
        cout << "Invalid order input." << endl;
    } 
 
    // Ending time
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();

    cout << "Sorted ";
    printArray(numberArray, sizeofArray);  

    // Change in time 
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1);

    cout << "Took: " << time_span.count() << " seconds" << endl;

    return 0;
}

