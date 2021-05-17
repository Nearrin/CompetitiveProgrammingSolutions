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
    new_regex=[]
    for c in regex:
        if c=='*':
            assert len(new_regex[-1])==1
            assert new_regex[-1]!='*'
            new_regex[-1]=new_regex[-1]+'*'
        else:
            new_regex.append(c)
    for c in new_regex:
        if len(c) == 1:
            cnt += 1
            new = Node(cnt)
            nodes.append(new)
            last.edges.append(Edge(new, c))
            last = new
        else:
            cnt += 1
            new = Node(cnt)
            nodes.append(new)
            last.edges.append(Edge(new, 'none'))
            last = new
            last.edges.append(Edge(last, c[0]))
    last.is_end = True
    return nodes

def dfs(n,vis,n_to_n):
    if not vis[n]:
        vis[n]=1
        for e in n_to_n[n].edges:
            if e.char=='none':
                dfs(e.dest.name,vis,n_to_n)

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        nfa=create_nfa(p)
        name_to_node=[None]*len(nfa)
        for n in nfa:
            name_to_node[n.name]=n
        vis=[0]*len(nfa)
        dfs(0,vis,name_to_node)
        now=[name_to_node[i] for i in range(len(nfa))if vis[i]]
        for c in s:
            vis=[0]*len(nfa)
            for n in now:
                for e in n.edges:
                    if e.char=='.'or e.char==c:
                        dfs(e.dest.name,vis,name_to_node)
            now=[name_to_node[i] for i in range(len(nfa))if vis[i]]
        return any(i.is_end for i in now)
            
            
        
