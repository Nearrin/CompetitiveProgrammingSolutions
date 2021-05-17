class Edge:
    def __init__(self, dest, char):
        self.dest = dest
        self.char = char


class Node:
    def __init__(self, name):
        self.edges = []
        self.name = name
        self.is_start = False
        self.is_end = False

def create_nfa(regex):
    cnt = 0
    last = Node(0)
    nodes = [last]
    last.is_start = True
    for c in regex:
        if c != '*':
            cnt += 1
            new = Node(cnt)
            nodes.append(new)
            last.edges.append(Edge(new, c))
            last = new
        else:
            last.edges.append(Edge(last, '?'))
    last.is_end = True
    return nodes

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        nfa=create_nfa(p)
        name_to_node=[None]*len(nfa)
        for n in nfa:
            name_to_node[n.name]=n
        now=[nfa[0]]
        for c in s:
            vis=[0]*len(nfa)
            for n in now:
                for e in n.edges:
                    if e.char=='?'or e.char==c:
                        vis[e.dest.name]=1
            now=[name_to_node[i] for i in range(len(nfa))if vis[i]]
        return any(i.is_end for i in now)
            
            
        
