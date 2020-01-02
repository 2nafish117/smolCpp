#include <iostream>

typedef unsigned int u32;

int interp_search(int* arr, u32 len, int elem)
{
    int ix1 = 0, ix2 = len - 1;
    int iy1 = arr[ix1], iy2 = arr[ix2];

    while(true)
    {
        if(ix1 > ix2)
            return -1;

        if(ix1 == ix2)
        {
            if(arr[ix1] == elem)
                return ix1;
            return -1;
        }

        int estimated_pos = (elem - iy1) * (ix2 - ix1) / (iy2 - iy1) + ix1;
        
        if(estimated_pos > ix2 || estimated_pos < ix1)
            return -1;

        if(arr[estimated_pos] == elem)
            return estimated_pos;

        if(arr[estimated_pos] < elem)
        {
            // search in right partition
            ix1 = estimated_pos + 1;
            iy1 = arr[ix1];
            continue;
        }

        if(arr[estimated_pos] > elem)
        {
            // search in left partition
            ix2 = estimated_pos - 1;
            iy2 = arr[ix2];
            continue;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {2, 4, 7, 17, 23, 27, 55, 78, 345};
    u32 len = sizeof(arr) / sizeof(int);
    int elem = 4;
    std::cout << "findd what?\n";
    std::cin >> elem;
    int index = interp_search(arr, len, elem);
    std::cout << "found: " << elem << " at " << index << " (" << (index >= 0 ? arr[index] : -1) << ")\n";
    return 0;
}