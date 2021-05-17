class Solution:
    def countOfAtoms(self, formula: str) -> str:
        formula='('+formula+')1'
        stack=[]
        i=0
        while i<len(formula):
            if formula[i]=='(':
                stack.append(formula[i])
            elif formula[i]==')':
                t=defaultdict(int)
                while True:
                    v=stack.pop()
                    if v=='(':
                        break
                    for k in v:
                        t[k]+=v[k]
                stack.append(t)
            elif formula[i].isdigit():
                j=i
                while j+1<len(formula) and formula[j+1].isdigit():
                    j+=1
                t=int(formula[i:j+1])
                for k in stack[-1]:
                    stack[-1][k]*=t
                i=j
            else:
                j=i
                while j+1<len(formula) and formula[j+1].islower():
                    j+=1
                stack.append({formula[i:j+1]:1})
                i=j
            i+=1
        answer=""
        for k in sorted(list(stack[0])):
            answer+=k+str(stack[0][k]if stack[0][k]>1else "")
        return answer
