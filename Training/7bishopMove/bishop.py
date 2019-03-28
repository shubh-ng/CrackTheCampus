def fillBoard(board,FEN):
    b_r=b_c=0
    for p in FEN:
        lwr = p.lower()
        if lwr>="a" and lwr<="z":
            board[b_r][b_c] = p
            print(board[b_r][b_c],end=" ")
            b_c += 1
        elif p=="/":
            b_r += 1
            b_c = 0
            print()            
        else:
            for i in range(int(p)):
                board[b_r][b_c] = "0"
                print(board[b_r][b_c],end=" ")                
                b_c += 1
    return board
# main
FEN = input()
ROWS = COLS = 8
for item in board:
    for i in item:
        print(i,end=" ")
    print()
fillBoard(board,FEN)
for item in board:
    for i in item:
        print(i,end=" ")
    print()
