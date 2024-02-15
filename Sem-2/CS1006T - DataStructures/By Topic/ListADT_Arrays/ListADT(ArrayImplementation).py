class List:
    def __init__(self):
        self.current = 0
        self.size = 4
    def IsEmpty(self):
        return self.current== 0
    def IsFull(self):
        return self.current == self.size-1
    def Insertion(self,val):
        if(not self.IsFull()):
            return 1
        else:
            return 0
a = List()
print(a.Insertion(1))
        





