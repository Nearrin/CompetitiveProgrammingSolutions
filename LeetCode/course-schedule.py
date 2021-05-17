class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        c,e=[0]*numCourses,[[]for i in range(numCourses)]
        for u,v in prerequisites:
            e[u].append(v)
        for t in range(numCourses):
            def f(u):
                if not c[u]:
                    c[u]=1
                    r=all(f(v) for v in e[u])
                    c[u]=2
                    return r
                else:
                    return c[u]>1
            if not f(t):
                return False
        return True

