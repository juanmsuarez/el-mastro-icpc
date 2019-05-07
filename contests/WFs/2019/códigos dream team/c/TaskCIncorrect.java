package main;



import lib.InputReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class TaskC {
    int NUM_CELLS = 32;
    static final int REMEMBER = 9;

    int[] cellRow;
    int[] cellCol;
    int[][] cellId;
    static final String NAMES = "bwBW";

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int firstMove = "BW".indexOf(in.next().charAt(0));
        int numMoves = in.nextInt();
        boolean[] isJump = new boolean[numMoves];
        int[][] cells = new int[numMoves][];
        for (int i = 0; i < numMoves; ++i) {
            String s = in.next();
            isJump[i] = s.contains("x");
            String[] parts = s.split("[-x]");
            cells[i] = new int[parts.length];
            for (int j = 0; j < parts.length; ++j) {
                cells[i][j] = Integer.parseInt(parts[j]) - 1;
            }
        }
        cellRow = new int[NUM_CELLS];
        cellCol = new int[NUM_CELLS];
        cellId = new int[8][8];
        int nextId = 0;
        for (int i = 0; i < 8; ++i) {
            Arrays.fill(cellId[i], -1);
            for (int j = 0; j < 8; ++j) {
                if ((i + j) % 2 == 1) {
                    cellId[i][j] = nextId;
                    cellRow[nextId] = i;
                    cellCol[nextId] = j;
                    ++nextId;
                }
            }
        }
        if (nextId != NUM_CELLS) throw new RuntimeException();

        int[] pieceId = new int[NUM_CELLS];
        int[] color = new int[NUM_CELLS];
        boolean[] mustBeKing = new boolean[NUM_CELLS];
        boolean[] promoted = new boolean[NUM_CELLS];
        int[] startsAt = new int[NUM_CELLS];
        Arrays.fill(pieceId, -1);
        int numPieces = 0;
        for (int i = 0; i < numMoves; ++i) {
            int[] seq = cells[i];
            if (pieceId[seq[0]] < 0) {
                startsAt[numPieces] = seq[0];
                pieceId[seq[0]] = numPieces++;
            }
            int who = pieceId[seq[0]];
            pieceId[seq[0]] = -1;
            color[who] = (firstMove + i) % 2;
            if (isJump[i]) {
                for (int j = 0; j + 1 < seq.length; ++j) {
                    int from = seq[j];
                    int to = seq[j + 1];
                    int mid = cellId[(cellRow[from] + cellRow[to]) / 2][(cellCol[from] + cellCol[to]) / 2];
                    if (pieceId[mid] < 0) {
                        startsAt[numPieces] = mid;
                        color[numPieces] = 1 - color[who];
                        mustBeKing[numPieces] = false;
                        ++numPieces;
                    } else {
                        pieceId[mid] = -1;
                    }
                }
            }
            if (color[who] == 0) {
                int prow = -1;
                for (int x : seq) {
                    int row = x / 4;
                    if (prow >= 0 && row < prow) {
                        if (!promoted[who]) mustBeKing[who] = true;
                    }
                    prow = row;
                }
                if (cellRow[seq[seq.length - 1]] == 7) {
                    promoted[who] = true;
                }
            } else {
                int prow = -1;
                for (int x : seq) {
                    int row = x / 4;
                    if (prow >= 0 && row > prow) {
                        if (!promoted[who]) mustBeKing[who] = true;
                    }
                    prow = row;
                }
                if (cellRow[seq[seq.length - 1]] == 0) {
                    promoted[who] = true;
                }
            }

            pieceId[seq[seq.length - 1]] = who;
        }

        state = new int[NUM_CELLS];
        Arrays.fill(state, -2);
        for (int[] x : cells) for (int y : x) state[y] = -1;
        for (int i = 0; i < numPieces; ++i) {
            state[startsAt[i]] = color[i] + (mustBeKing[i] ? 2 : 0);
        }
        int[] startState = state.clone();
        constraintsLeft = new int[NUM_CELLS];
        constraintsRight = new int[NUM_CELLS];

        for (int i = 0; i < numMoves; ++i) {
            int[] seq = cells[i];
            if (state[seq[0]] < 0) throw new RuntimeException();
            if (state[seq[0]] % 2 != (firstMove + i) % 2) throw new RuntimeException();
            if (!isJump[i]) {
                for (int j = 0; j < NUM_CELLS; ++j) {
                    addNoJumpConstraintsOnePiece(j, (firstMove + i) % 2);
                }
            }
            int kind = state[seq[0]];
            state[seq[0]] = -1;
            if (isJump[i]) {
                for (int j = 0; j + 1 < seq.length; ++j) {
                    int from = seq[j];
                    int to = seq[j + 1];
                    int mid = cellId[(cellRow[from] + cellRow[to]) / 2][(cellCol[from] + cellCol[to]) / 2];
                    if (state[mid] < 0) throw new RuntimeException();
                    state[mid] = -1;
                }
            }
            boolean isPromoted = false;
            if (kind == 0) {
                if (cellRow[seq[seq.length - 1]] == 7) {
                    kind += 2;
                    isPromoted = true;
                }
            } else if (kind == 1) {
                if (cellRow[seq[seq.length - 1]] == 0) {
                    kind += 2;
                    isPromoted = true;
                }
            }
            state[seq[seq.length - 1]] = kind;
            if (!isPromoted && isJump[i]) {
                addNoJumpConstraintsOnePiece(seq[seq.length - 1], (firstMove + i) % 2);
            }
        }
        int[] finalState = state.clone();

        int[] p3 = new int[REMEMBER + 1];
        p3[0] = 1;
        for (int i = 1; i < p3.length; ++i) {
            p3[i] = 3 * p3[i - 1];
        }
        int[][] via = new int[NUM_CELLS + 1][p3[REMEMBER]];
        for (int[] x : via) Arrays.fill(x, -1);
        via[0][p3[REMEMBER] - 1] = 0;
        for (int pos = 0; pos < NUM_CELLS; ++pos) {
            int row = cellRow[pos];
            int col = cellCol[pos];
            int left1 = -1;
            if (row >= 1 && col >= 1) {
                left1 = cellId[row - 1][col - 1];
                if (pos - 1 - left1 >= REMEMBER) throw new RuntimeException();
            }
            int left2 = -1;
            if (row >= 2 && col >= 2) {
                left2 = cellId[row - 2][col - 2];
                if (pos - 1 - left2 >= REMEMBER) throw new RuntimeException();
            }
            int right1 = -1;
            if (row >= 1 && col + 1 < 8) {
                right1 = cellId[row - 1][col + 1];
                if (pos - 1 - right1 >= REMEMBER) throw new RuntimeException();
            }
            int right2 = -1;
            if (row >= 2 && col + 2 < 8) {
                right2 = cellId[row - 2][col + 2];
                if (pos - 1 - right2 >= REMEMBER) throw new RuntimeException();
            }
            int max = 2;
            int min = 0;
            if (state[pos] != -2) min = 2;
            for (int old = 0; old < p3[REMEMBER]; ++old) {
                if (via[pos][old] < 0) continue;
                for (int cur = min; cur <= max; ++cur) {
                    int leftCombi = ((left2 < 0 ? 2 : (old / p3[pos - 1 - left2] % 3)) * 3 +
                            (left1 < 0 ? 2 : (old / p3[pos - 1 - left1] % 3))) * 3 + cur;
                    if ((constraintsLeft[pos] & (1 << leftCombi)) != 0) continue;
                    int rightCombi = ((right2 < 0 ? 2 : (old / p3[pos - 1 - right2] % 3)) * 3 +
                            (right1 < 0 ? 2 : (old / p3[pos - 1 - right1] % 3))) * 3 + cur;
                    if ((constraintsRight[pos] & (1 << rightCombi)) != 0) continue;
                    int nxt = (old * 3 + cur) % p3[REMEMBER];
                    via[pos + 1][nxt] = old;
                }
            }
        }

        int[] commonState = new int[NUM_CELLS];
        Arrays.fill(commonState, -1);

        /*int state = 0;
        while (via[NUM_CELLS][state] < 0) ++state;

        for (int pos = NUM_CELLS - 1; pos >= 0; --pos) {
            int prev = via[pos + 1][state];
            if (prev < 0) throw new RuntimeException();
            if (state % 3 < 2) {
                int what = state % 3;
                if (what == 0 && cellRow[pos] == 7 || what == 1 && cellRow[pos] == 0) what += 2;
                commonState[pos] = what;
            }
            state = prev;
        }*/

        char[][] startBoard = new char[8][8];
        char[][] finalBoard = new char[8][8];
        for (char[] x : startBoard)
            Arrays.fill(x, '-');
        for (char[] x : finalBoard)
            Arrays.fill(x, '-');
        for (int pos = 0; pos < NUM_CELLS; ++pos) {
            if (commonState[pos] >= 0) {
                if (startState[pos] >= 0 || finalState[pos] >= 0) throw new RuntimeException();
                startBoard[cellRow[pos]][cellCol[pos]] = finalBoard[cellRow[pos]][cellCol[pos]] = NAMES.charAt(commonState[pos]);
            } else {
                if (startState[pos] >= 0) {
                    startBoard[cellRow[pos]][cellCol[pos]] = NAMES.charAt(startState[pos]);
                } else {
                    startBoard[cellRow[pos]][cellCol[pos]] = '.';
                }
                if (finalState[pos] >= 0) {
                    finalBoard[cellRow[pos]][cellCol[pos]] = NAMES.charAt(finalState[pos]);
                } else {
                    finalBoard[cellRow[pos]][cellCol[pos]] = '.';
                }
            }
        }

        for (int row = 0; row < 8; ++row) {
            out.println(new String(startBoard[row]) + " " + new String(finalBoard[row]));
        }
    }

    int[] state;
    int[] constraintsLeft;
    int[] constraintsRight;

    private void addNoJumpConstraintsOnePiece(int at, int color) {
        for (int osrc = 0; osrc < 3; ++osrc) {
            for (int omid = 0; omid < 3; ++omid) {
                for (int odest = 0; odest < 3; ++odest) {
                    if (state[at] != -2 && osrc != 2) continue;
                    if (state[at] == -2 && osrc != color) continue;
                    boolean isKing = (state[at] >= 2) || (state[at] == -2 && osrc != 2 && (color == 0 && cellRow[at] == 7 || color == 1 && cellRow[at] == 0));
                    for (int dr = -1; dr <= 1; dr += 2) {
                        for (int dc = -1; dc <= 1; dc += 2) {
                            if (!isKing) {
                                if (color == 0) {
                                    if (dr < 0) continue;
                                } else {
                                    if (dr > 0) continue;
                                }
                            }
                            int nr = cellRow[at] + dr * 2;
                            int nc = cellCol[at] + dc * 2;
                            if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8) {
                                int dest = cellId[nr][nc];
                                int mid = cellId[cellRow[at] + dr][cellCol[at] + dc];
                                if (state[dest] != -2 && odest != 2) continue;
                                if (state[mid] != -2 && omid != 2) continue;
                                if (state[mid] >= 0 && state[mid] % 2 == 1 - color || state[mid] == -2 && omid == 1 - color) {
                                    if (state[dest] == -1 || state[dest] == -2 && odest == 2) {
                                        if (dr > 0) {
                                            if (dc > 0) {
                                                constraintsLeft[dest] |= 1 << ((osrc * 3 + omid) * 3 + odest);
                                            } else {
                                                constraintsRight[dest] |= 1 << ((osrc * 3 + omid) * 3 + odest);
                                            }
                                        } else {
                                            if (dc > 0) {
                                                constraintsRight[at] |= 1 << ((odest * 3 + omid) * 3 + osrc);
                                            } else {
                                                constraintsLeft[at] |= 1 << ((odest * 3 + omid) * 3 + osrc);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
