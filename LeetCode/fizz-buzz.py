def f(n):
    if n%15==0:
        return 'FizzBuzz'
    if n%3==0:
        return 'Fizz'
    if n%5==0:
        return 'Buzz'
    return str(n)
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        return list(map(f,range(1,n+1)))
        
