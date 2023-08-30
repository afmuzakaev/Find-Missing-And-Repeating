#include <iostream>
#include <vector>

void findMissingAndRepeating(int arr[], int n) {
    int xor1 = arr[0];
    
    for (int i = 1; i < n; i++) {
        xor1 ^= arr[i];
        xor1 ^= i + 1;
    }
    
    int rightmostSetBit = xor1 & ~(xor1 - 1);
    
    int x = 0, y = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] & rightmostSetBit)
            x ^= arr[i];
        else
            y ^= arr[i];
        
        if ((i + 1) & rightmostSetBit)
            x ^= (i + 1);
        else
            y ^= (i + 1);
    }
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            std::cout << "Repeating number: " << x << std::endl;
            std::cout << "Missing number: " << y << std::endl;
            break;
        }
        
        if (arr[i] == y) {
            std::cout << "Repeating number: " << y << std::endl;
            std::cout << "Missing number: " << x << std::endl;
            break;
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    
    int arr[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    findMissingAndRepeating(arr, n);
    
    return 0;
}
