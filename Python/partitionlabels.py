def partitionlabels(s):
    last = {c: i for i, c in enumerate(s)} #char to last index mapping in s

    res = []
    size = end = 0
    for i, c in enumerate(s):
        size += 1
        print(last[c])
        end = max(end, last[c]) #update end to the farthest last index of chars seen so far

        if i == end: #if current index reaches the end of the partition
            res.append(size) #append the size of the partition
            size = 0 #reset size for next partition

    return res

if __name__ == "__main__":
    s = "ababcbacadefegdehijhklij"
    assert partitionlabels(s) == [9, 7, 8]