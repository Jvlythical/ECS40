#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include "board.h"

Board::Board() {
		
}

void Board::print_board(void)
{
        int file, rank;

        for (rank=RANK_8; rank>=RANK_1; rank--) {
                printf("%d ", 1+rank);
                for (file=FILE_A; file<=FILE_H; file++) {
                        putchar(' ');
                        putchar(PIECE2CHAR(board[SQ(file,rank)]));
                }
                putchar('\n');
        }
        printf("   a b c d e f g h\n%d. %s to move. %s%s%s%s ",
                1+ply/2, WTM ? "White" : "Black",
                board[CASTLE] & CASTLE_WHITE_KING ? "K" : "",
                board[CASTLE] & CASTLE_WHITE_QUEEN ? "Q" : "",
                board[CASTLE] & CASTLE_BLACK_KING ? "k" : "",
                board[CASTLE] & CASTLE_BLACK_QUEEN ? "q" : ""
        );
        if (board[EP]) print_square(board[EP]);
        putchar('\n');
}

void Board::print_square(int square)
{
        putchar(FILE2CHAR(F(square)));
        putchar(RANK2CHAR(R(square)));
}


void Board::setup_board(const char *fen)
{
        int file=FILE_A, rank=RANK_8;

        while (xisspace(*fen)) fen++;

        memset(board, 0, sizeof board);

        while (rank>RANK_1 || file<=FILE_H) {
                int piece = EMPTY;
                int count = 1;

                switch (*fen) {
                case 'K': piece = WHITE_KING; break;
                case 'Q': piece = WHITE_QUEEN; break;
                case 'R': piece = WHITE_ROOK; break;
                case 'B': piece = WHITE_BISHOP; break;
                case 'N': piece = WHITE_KNIGHT; break;
                case 'P': piece = WHITE_PAWN; break;
                case 'k': piece = BLACK_KING; break;
                case 'r': piece = BLACK_ROOK; break;
                case 'q': piece = BLACK_QUEEN; break;
                case 'b': piece = BLACK_BISHOP; break;
                case 'n': piece = BLACK_KNIGHT; break;
                case 'p': piece = BLACK_PAWN; break;
                case '/': rank -= 1; file = FILE_A; fen++; continue;
                case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8':
                        count = *fen - '0';
                        break;
                default:
                        puts("fen error\n");
                        return;
                }
                do {
                        board[SQ(file,rank)] = piece;
                        file++;
                } while (--count);
                fen++;
        }
        ply = (fen[1] == 'b');
        board[LAST] = ply;
        fen += 2;

        while (*fen) {
                switch (*fen) {
                case 'K': board[CASTLE] |= CASTLE_WHITE_KING; break;
                case 'Q': board[CASTLE] |= CASTLE_WHITE_QUEEN; break;
                case 'k': board[CASTLE] |= CASTLE_BLACK_KING; break;
                case 'q': board[CASTLE] |= CASTLE_BLACK_QUEEN; break;
                case 'a': case 'b': case 'c': case 'd':
                case 'e': case 'f': case 'g': case 'h':
                        board[EP] = SQ(CHAR2FILE(*fen),WTM?RANK_5:RANK_4);
                        break;
                default:
                        break;
                }
                fen++;
        }
        reset();
        print_board();
}

void Board::reset(void)
{
        move_sp = move_stack;
        undo_sp = undo_stack;
        hash_stack[ply] = compute_hash();
}

/* Compute 32-bit Zobrist hash key. Normally 32 bits this is too small,
   but for MSCP's small searches it is OK */
unsigned long Board::compute_hash(void)
{
        unsigned long hash = 0;
        int sq;

        for (sq=0; sq<64; sq++) {
                if (board[sq] != EMPTY) {
                        hash ^= zobrist[board[sq]-1][sq];
                }
        }
        return hash ^ WTM;
}

byte* Board::getBoard () 
{
	return this->board;
}

byte& Board::operator[](int index) {
	return board[index];
}
