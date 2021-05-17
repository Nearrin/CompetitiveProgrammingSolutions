from typing import List


def to_int(word, mp):
    return int(''.join([str(mp[i]) for i in word]))


def rng_di(coef, words, result, chars, mp, di):
    fake_mp = {}
    for i in range(len(chars)):
        if mp[i] != -1:
            fake_mp[chars[i]] = mp[i]
        elif coef[chars[i]]*di < 0:
            fake_mp[chars[i]] = 9
        else:
            fake_mp[chars[i]] = 0
    words = [to_int(i, fake_mp)for i in words]
    result = to_int(result, fake_mp)
    return sum(words)-result


def rng(coef, words, result, chars, mp):
    l = rng_di(coef, words, result, chars, mp, -1)
    r = rng_di(coef, words, result, chars, mp, 1)
    if l > r:
        l, r = r, l
    return l, r


def dfs(heads, coef, words, result, chars, mp, used, level):
    r = rng(coef, words, result, chars, mp)
    if r[0] > 0 or r[1] < 0:
        return False
    if level == len(chars) and r==(0,0):
        return True
    if level == len(chars):
        return False
    for i in range(10):
        if not used[i]:
            if i == 0 and chars[level] in heads:
                continue
            used[i] = 1
            mp[level] = i
            if dfs(heads, coef, words, result, chars, mp, used, level+1):
                return True
            mp[level] = -1
            used[i] = 0
    return False


class Solution:
    def isSolvable(self, words: List[str], result: str) -> bool:
        chars = set()
        indexed_chars = []
        heads = set()
        from collections import defaultdict
        coef = defaultdict(int)
        for w in words:
            for i, c in enumerate(w[::-1]):
                coef[c] += 10**i
        for i, c in enumerate(result[::-1]):
            coef[c] -= 10**i
        for w in words+[result]:
            for i, c in enumerate(w):
                indexed_chars.append((i, c))
                if not i:
                    heads.add(c)
        indexed_chars = [i[1] for i in sorted(set(indexed_chars))]
        new_i_c = []
        for c in indexed_chars:
            if c not in chars:
                chars.add(c)
                new_i_c.append(c)
        assert len(new_i_c) == len(chars)
        if len(chars) > 10:
            return False
        mp = [-1]*len(chars)
        used = [0]*10
        return dfs(heads, coef, words, result, new_i_c, mp, used, 0)
        
