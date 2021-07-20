import math
import sys
import collections
import bisect
import time
import random
from itertools import permutations
def get_ints():return map(int, sys.stdin.readline().strip().split())
def get_list():return list(map(int, sys.stdin.readline().strip().split()))
def get_string():return sys.stdin.readline().strip()
for t in range(int(input())):
    n,c=get_ints()
    arr=[0]*(10**4 +10)
    for i in range(n):
        l,r=get_ints()
        for j in range(l+1,r):
            arr[j]+=1
    #print(arr)
    ans=n
    arr.sort(reverse=True)
    pos=0
    while c>0 and pos<len(arr):
        ans+=arr[pos]
        pos+=1
        c-=1
    print("Case" + " #" + str(t + 1) + ":", ans)