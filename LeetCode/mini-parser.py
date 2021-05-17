# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        a,i=[],0
        while i<len(s):
            if s[i]=='-' or s[i].isdigit():
                j=i
                while j+1<len(s) and (s[j+1]=='-' or s[j+1].isdigit()):
                    j+=1
                a.append(NestedInteger(int(s[i:j+1])))
                i=j
            elif s[i]=='[':
                a.append(s[i])
            elif s[i]==']':
                t=NestedInteger()
                j=len(a)-1
                while a[j]!='[':
                    j-=1
                for k in range(j+1,len(a)):
                    t.add(a[k])
                for k in range(j,len(a)):
                    a.pop()
                a.append(t)
            #print(a)
            i+=1
        return a[0]
