class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for row in board:
            row=[v for v in row if v!='.']
            if len(row)!=len(set(row)):
                return False
        for c_idx in range(len(board[0])):
            col=[row[c_idx]for row in board]
            col=[v for v in col if v!='.']
            if len(col)!=len(set(col)):
                return False
        for x in [0,3,6]:
            for y in [0,3,6]:
                col=[]
                for dx in range(3):
                    for dy in range(3):
                        col.append(board[x+dx][y+dy])
                col=[v for v in col if v!='.']
                if len(col)!=len(set(col)):
                    return False
        return True
