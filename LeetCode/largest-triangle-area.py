class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        ans=0
        cross=lambda u,v:u[0]*v[1]-u[1]*v[0]
        for u in points:
            for v in points:
                for w in points:
                    ans=max(ans,abs(cross(u,v)+cross(v,w)+cross(w,u))/2)
        return ans
