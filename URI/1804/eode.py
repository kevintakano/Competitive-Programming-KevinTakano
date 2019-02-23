class BIT:
    """Implementation of a Binary Indexed Tree (Fennwick Tree)"""
    def __init__(self, list):
        """"Initialize BIT with list in O(n)"""
        self.array = [0] + list
        for idx in range(1, len(self.array)):
            idx2 = idx + (idx & -idx)
            if idx2 < len(self.array):
                self.array[idx2] += self.array[idx]

    def prefix_query(self, idx):
        """Computes prefix sum of up to including the idx-th element"""
        idx += 1
        result = 0
        while idx:
            result += self.array[idx]
            idx -= idx & -idx
        return result

    def range_query(self, from_idx, to_idx):
        """Computes the range sum between two indices (both inclusive)"""
        return self.prefix_query(to_idx) - self.prefix_query(from_idx - 1)

    def update(self, idx, add):
        """Add a value to the idx-th element"""
        idx += 1
        while idx < len(self.array):
            self.array[idx] += add
            idx += idx & -idx

import sys
import bisect

MAX = 100001

buggy = []
index_map = {}

r = sys.stdin.readline
p = sys.stdout.write

n = int(r())

buggy = list(map(int,r().rstrip().split()))
bittree = BIT(buggy)

for line in sys.stdin:
    op, abd  = line.split()
    abd = int(abd)-1
    if op == 'a':
        bittree.update(abd,-buggy[abd])
    else:
        s = bittree.prefix_query(abd) - buggy[abd]

        p(str(s) + '\n')



