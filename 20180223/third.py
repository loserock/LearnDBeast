#!/bin/python

# Ways to give a check
# https://www.hackerrank.com/contests/w36/challenges/ways-to-give-a-check


import sys


def waysToGiveACheck(board):
    numberOfWays = int(0)
    bKingRow, bKingCol = findOneOnBoard('k', board)
    relRow = bKingRow - 0  # black king's relative row position from promoted pawn
    for pawnCol in promotablePawns(board):
        relCol = bKingCol - pawnCol
        # TODO shall find valid checks given by an other officer after
        #      pawns step
        if (0):
            numberOfWays += 4
            continue
        # find check by knight
        if (abs(relCol) == 1 and relRow == 2) or (relRow == 1 and abs(relCol) == 2):
            numberOfWays += 1
            continue
        # find check by line
        if (relCol == 0 or relRow == 0):
            if (relRow == 0 and board[0][pawnCol + (1 if relCol > 0 else -1):bKingCol:(+1 if relCol > 0 else -1)].strip('#') == ""):
                numberOfWays += 2
            if (relCol == 0 and len({r for r in xrange(1, relRow) if board[r][pawnCol] != '#'}) == 0):
                numberOfWays += 2
        # find check by diagonal
        if abs(relCol) == relRow:
            if len({r for r, c in zip(xrange(0, relRow), xrange(pawnCol, bKingCol, (+1 if relCol > 0 else -1))) if r > 0 and board[r][c] != '#'}) == 0:
                numberOfWays += 2
    return numberOfWays


def promotablePawns(board):
    # TODO to step with a pawn can be forbidden, when it leads to a check to
    # the white king
    return [i for i, f in enumerate(board[1]) if f == 'P' and board[0][i] == '#']


def findOneOnBoard(figure, board):
    return ([r, c] for r, line in enumerate(board) for c, field in enumerate(line) if field == figure).next()


if __name__ == "__main__":
    t = int(raw_input().strip())
    for a0 in xrange(t):
        board = []
        for board_i in xrange(8):
            board_temp = raw_input().strip()
            board.append(board_temp)
        result = waysToGiveACheck(board)
        print result
