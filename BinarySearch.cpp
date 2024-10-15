

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 0,1,2,3,4,5,6,7,8, 9,10 => key = 8
// 1,2,3,4,5,6,7,8,9,10,11 => min = 0; max = 10; mid = 5
//           6             => min = 6; max = 10; mid = 8
//     3           9       => min = 6; max = 7 ; mid = 6
// 1       5   7        11 => min = 7; max = 7 ; mid = 7
//   2   4      >8   10

// 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 => key = 11
//                   10                               => min = 0; max = 19; mid = 9
//                                  15                => min = 10;max = 19; mid = 14
//                                                    => min = 10;max = 13; mid = 11
//                         12                         => min = 10;max = 11; mid = 10
//                      11
size_t* BinarySearch(vector<int>& arr, int& key)
{
    size_t l = 0;
    size_t h = arr.size() - 1;
    size_t m = (l + h) / 2;

    while (l <= h)
    {
        if (arr[m] == key)
            return &(m);
        else if (arr[m] < key)
            l = m + 1;
        else
            h = m - 1;
        m = (l + h) / 2;
    }

    return NULL;
}

int main()
{
    vector<int> arr = { 23123,4241,342,5,562,334,2,125,654,64,34,23469,897,564 };
    int key = 23469;
    sort(arr.begin(),arr.end());
    size_t* index = BinarySearch(arr, key);
    int data = -1;
    if (index != NULL)
        data = (int)*index;
    cout << "key: " << data << "\n";
    cout << "Hello World!\n";
}

