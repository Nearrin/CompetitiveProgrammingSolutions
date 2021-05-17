/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        if(reader.get(0)>target)
            return -1;
        int l=0,r=1;
        while(reader.get(r)<=target)r*=2;
        while(l+1<r){
            int m=(l+r)/2;
            if(reader.get(m)<=target)l=m;
            else r=m;
        }
        if(reader.get(l)==target)return l;else return -1;
    }
};
