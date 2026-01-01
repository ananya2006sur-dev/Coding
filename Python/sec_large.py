def sec_max(l):
    if len(l) < 2:
        return None
    largest = second = float('-inf') 
    for num in l: #O(n) 
        if num > largest:
            second = largest 
            largest = num 
        elif num > second and num != largest:
            second = num
    if second == float('-inf'):
        return None
    return second 

#Total time complexity of sec_max function is O(n)

