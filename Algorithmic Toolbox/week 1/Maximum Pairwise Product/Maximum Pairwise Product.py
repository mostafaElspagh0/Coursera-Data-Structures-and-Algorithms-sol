input()
numbers = list(map(int,input().split()))
maxTwo = sorted(numbers[0:2])
if len(numbers) > 2 :
    for i in numbers [2:] :
        if i >= maxTwo[1] :
            maxTwo[0] = maxTwo[1]
            maxTwo[1] = i
        elif i > maxTwo[0] :
            maxTwo[0] = i 
print(maxTwo[0] * maxTwo[1])