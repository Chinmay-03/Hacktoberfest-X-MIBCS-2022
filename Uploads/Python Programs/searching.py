def linear_searching(arr,value):
    length = len(arr);
    for i in range(0,length):
        if(arr[i]==value):
            return i
    return "Not Found"

def binary_searching(arr,start,end,value):
    mid = (start+end)//2
    if start>end:
        return "Not Found";
    elif arr[mid]==value:
        return mid
    elif arr[mid]>value:
        return binary_searching(arr,start,mid-1,value)
    else:
        return binary_searching(arr,mid+1,end,value)



arr1 = [1,2,5,3,1,56,77,12,113,3,3,4,5,6,7,8]
arr2 = ['Farbi', 'Shaoib', 'Sakura', 'Ritu', 'Mahin', 'Rajjak', 'Ayon']

print(linear_searching(arr1,77))
print(linear_searching(arr2,"Karim"))

arr1.sort()
arr2.sort()

print(binary_searching(arr1,0,len(arr1),77))
print(binary_searching(arr2,0,len(arr2),"Karim"))