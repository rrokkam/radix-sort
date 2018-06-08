import sys

def radix_sort(array, base=2):
    place_value = base
    while place_value <= max(array):
	
        # Initialize the buckets.
	buckets = [[] for i in range(base)]

        # Sort into buckets by digit
        for num in array:
            digit = (num // place_value) % base
            buckets[digit].append(num)

        # Recombine buckets. 
        # In the next run of the while loop, the items will be sorted by the
        # place_value bit, then by the place_value//base bit, etc.
        array = [num for bucket in buckets for num in bucket]
        place_value *= base

    return array

if __name__ == '__main__':
    array = map(int, sys.stdin.readline().split())
    print(radix_sort(array))
	
