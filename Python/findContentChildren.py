import sortings
def findContentChildren(self, g, s):
    sortings.bubblesort(g)
    sortings.bubblesort(s)
    i = j = 0
    while i < len(g) and j < len(s):
        if g[i] <= s[j]:
            i += 1
        j += 1
    return i