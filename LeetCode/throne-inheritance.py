from collections import defaultdict
class ThroneInheritance:

    def __init__(self, kingName: str):
        self.c=defaultdict(list)
        self.p={}
        self.king=kingName
        self.dead=set()
        

    def birth(self, parentName: str, childName: str) -> None:
        self.c[parentName].append(childName)
        self.p[childName]=parentName;
        

    def death(self, name: str) -> None:
        self.dead.add(name)

    def getInheritanceOrder(self) -> List[str]:
        cur=[self.king]
        incur=set(cur)
        def f(x):
            for c in self.c[x]:
                if c not in incur:
                    return c
            if x==self.king:
                return None
            return f(self.p[x])
        while True:
            t=f(cur[-1])
            if t is None:
                break
            cur.append(t)
            incur.add(t)
        return [i for i in cur if i not in self.dead]


# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()
