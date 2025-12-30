def merge_the_tools(string, k):
    # your code goes here
    for kiter in range(0, len(string), k):
        distinct = set(c for c in string[kiter:kiter+k])
        distinct = ''.join(list(distinct))
        print(distinct)

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)