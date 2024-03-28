arr = [1, 2, 3]
pl = 0
pr = 2
pm = 1

vl = arr[pl]
vr = arr[pr] 
vm = arr[pm]

arr[pl], arr[pr] = arr[pr], arr[pl]
print(arr)
