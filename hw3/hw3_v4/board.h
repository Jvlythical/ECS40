#ifndef BOARD_H
#define BOARD_H

typedef unsigned char byte;

extern int ply;
extern unsigned long zobrist[12][64];   /* Hash-key construction */
extern unsigned long hash_stack[1024]; /* History of hashes, for repetition */
extern signed char undo_stack[6*1024], *undo_sp; /* Move undo administration */
extern struct move move_stack[1024], *move_sp; /* History of moves */
//extern int WTM;  /* White-to-move predicate */

//#define WTM (~ply & 1)

inline int WTM () {
	return (~ply & 1);
}

const int CASTLE_WHITE_KING =  1;
const int CASTLE_WHITE_QUEEN = 2;
const int CASTLE_BLACK_KING = 4;
const int CASTLE_BLACK_QUEEN = 8;

struct move {
        short move;
        unsigned short prescore;
};

/* enum defintions begin  */
enum {                  /* 64 squares */
        A1, A2, A3, A4, A5, A6, A7, A8,
        B1, B2, B3, B4, B5, B6, B7, B8,
        C1, C2, C3, C4, C5, C6, C7, C8,
        D1, D2, D3, D4, D5, D6, D7, D8,
        E1, E2, E3, E4, E5, E6, E7, E8,
        F1, F2, F3, F4, F5, F6, F7, F8,
        G1, G2, G3, G4, G5, G6, G7, G8,
        H1, H2, H3, H4, H5, H6, H7, H8,
        CASTLE,         /* Castling rights */
        EP,             /* En-passant square */
        LAST            /* Ply number of last capture or pawn push */
};

enum {
	EMPTY,
	WHITE_KING, WHITE_QUEEN, WHITE_ROOK,
	WHITE_BISHOP, WHITE_KNIGHT, WHITE_PAWN,
	BLACK_KING, BLACK_QUEEN, BLACK_ROOK,
	BLACK_BISHOP, BLACK_KNIGHT, BLACK_PAWN
};

enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8 };

/* Inline macro function definitions begin */

inline int xisspace (int c) {
	return isspace (c);
}

inline int SQ (int f, int r) {
	return (((f) << 3) | (r));
}

inline int PIECE2CHAR (int p) {
	return ("-KQRBNPkqrbnp"[p]);
}

inline int FILE2CHAR (int f) {
	return ('a' + (f));
}

inline int RANK2CHAR (int r) {
	return ('1' + (r));
}

inline int CHAR2FILE (int c) {
	return ((c) - 'a');
}

inline int F (int square) {
	return ((square) >> 3);	
}

inline int R (int square) {
	return ((square) & 7);
}

class Board {
	public:
		Board (int num);
		~Board ();
		void print_board(void);
		void print_square(int square);
		void setup_board(const char *fen);
		void reset (void);
		unsigned long compute_hash (void);
		byte* getBoard ();
		Board setBoard ();
		byte& operator[](int index);

	private:
		byte *board;
};

#endif
