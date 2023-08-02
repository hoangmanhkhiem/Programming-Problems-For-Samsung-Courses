n,k1,k2 = 0,0,0
def BT(x,k):
    if len(x) == n:
        if k == 0 or k >= k1: print(x)
    else:
        if x == '' or k >= k1 : BT(x+'0',0)
        if k < k2 : BT(x + '1' , k+1) 
n,k1,k2 = map(int,input().split())
BT('', 0)