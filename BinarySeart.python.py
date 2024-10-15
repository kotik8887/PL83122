from typing import List, Optional

def binary_search(array: List[int], search_key: int) -> Optional[int]:
    left_index = 0
    high_index = len(array) - 1

    while left_index <= high_index:
        mid_index = (left_index + high_index) // 2
        if array[mid_index] == search_key:
            return mid_index
        elif array[mid_index] < search_key:
            left_index = mid_index + 1
        else:
            high_index = mid_index - 1

    return None

def main():
    array = [23123, 4241, 342, 5, 562, 334, 2, 125, 654, 64, 34, 23469, 897, 564]
    search_key = 23469
    array.sort()
    index = binary_search(array, search_key)
    data = -1
    if index is not None:
        data = index
    print(f"key: {data}")
    print("Hello World!")

if __name__ == "__main__":
    main()
