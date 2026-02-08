def max_val(l):
    mx = None
    for num in l:
        if mx is None or num > mx:
            mx = num 
    return mx

l = [6, 4, 1, 9, 7]
print(max_val(l)) 