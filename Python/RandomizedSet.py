class RandomizedSet(object):
    def __init__(self):
        import random
        self.r = random.choice
        self.numMap = {}
        self.numList = []

    def insert(self, val):
        res = val not in self.numMap
        if res: 
            self.numMap[val] = len(self.numList)
            self.numList.append(val)
        return res
    
    def remove(self, val):
        res = val in self.numMap
        if res:
            idx = self.numMap[val]
            lastVal = self.numList[-1]
            self.numList[idx] = lastVal
            self.numList.pop()
            self.numMap[lastVal] = idx
            del self.numMap[val]
        return res

    def getRandom(self):
        return self.r(self.numList)

if __name__ == "__main__":
    obj = RandomizedSet()
    print(obj.insert(1))  # True
    print(obj.insert(2))  # True
    print(obj.insert(3))  # True
    print(obj.remove(2))  # True
    print(obj.getRandom())  # Randomly returns 1 or 3
    print(obj.remove(4))  # False
    print(obj.getRandom())  # Randomly returns 1 or 3