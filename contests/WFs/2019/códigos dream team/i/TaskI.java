package main;

import lib.InputReader;
import java.io.PrintWriter;

public class TaskI {
    int height;
    int width;
    char[][] grid;
    String[] functions;
    String[] programs;
    int[] startState;
    Node[] functionNodes;

    abstract class Node {
        int[] answer = new int[height * width * 4];
        int[] state = new int[height * width * 4];

        public int execute(int from) {
            if (state[from] == 1) {
                return -1;
            }
            if (state[from] == 2) {
                return answer[from];
            }
            state[from] = 1;
            answer[from] = realExecute(from);
            state[from] = 2;
            return answer[from];
        }

        protected abstract int realExecute(int from);
    }

    class NotInitializedNode extends Node {
        @Override
        protected int realExecute(int from) {
            throw new RuntimeException();
        }
    }

    class EmptyNode extends Node {
        @Override
        protected int realExecute(int from) {
            return from;
        }
    }

    class ConcatenationNode extends Node {
        Node a;
        Node b;

        public ConcatenationNode(Node a, Node b) {
            this.a = a;
            this.b = b;
        }

        @Override
        protected int realExecute(int from) {
            int first = a.execute(from);
            if (first < 0) {
                return -1;
            }
            return b.execute(first);
        }
    }

    class ConditionNode extends Node {
        int condition;
        Node ifTrue;
        Node ifFalse;

        public ConditionNode(int condition, Node ifTrue, Node ifFalse) {
            this.condition = condition;
            this.ifTrue = ifTrue;
            this.ifFalse = ifFalse;
        }

        @Override
        protected int realExecute(int from) {
            boolean isTrue;
            if (condition >= 0) {
                int dir = from % 4;
                isTrue = condition == dir;
            } else {
                int dir = from % 4;
                int nfrom = from / 4;
                int col = nfrom % width;
                int row = nfrom / width;
                int nrow = row + DIR_DROW[dir];
                int ncol = col + DIR_DCOL[dir];
                isTrue = !((nrow >= 0 && nrow < height && ncol >= 0 && ncol < width && grid[nrow][ncol] == '.'));
            }
            if (isTrue) {
                return ifTrue.execute(from);
            } else {
                return ifFalse.execute(from);
            }
        }
    }

    class MoveForwardNode extends Node {
        @Override
        protected int realExecute(int from) {
            int dir = from % 4;
            from /= 4;
            int col = from % width;
            int row = from / width;
            int nrow = row + DIR_DROW[dir];
            int ncol = col + DIR_DCOL[dir];
            if (nrow >= 0 && nrow < height && ncol >= 0 && ncol < width && grid[nrow][ncol] == '.') {
                row = nrow;
                col = ncol;
            }
            return (row * width + col) * 4 + dir;
        }
    }

    class TurnLeftNode extends Node {
        @Override
        protected int realExecute(int from) {
            int dir = from % 4;
            from /= 4;
            dir = (dir + 1) % 4;
            return from * 4 + dir;
        }
    }

    static final String DIRS = "nwse";
    static final int[] DIR_DROW = new int[]{-1, 0, 1, 0};
    static final int[] DIR_DCOL = new int[]{0, -1, 0, 1};

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        height = in.nextInt();
        width = in.nextInt();
        int numFunctions = in.nextInt();
        int numPrograms = in.nextInt();
        grid = new char[height][];
        for (int r = 0; r < height; ++r) grid[r] = in.next().toCharArray();
        functions = new String[26];
        for (int i = 0; i < numFunctions; ++i) {
            String s = in.next();
            functions[s.charAt(0) - 'A'] = s.substring(2);
        }
        programs = new String[numPrograms];
        startState = new int[numPrograms];
        for (int i = 0; i < numPrograms; ++i) {
            int startRow = in.nextInt() - 1;
            int startCol = in.nextInt() - 1;
            int startDir = DIRS.indexOf(in.next().charAt(0));
            startState[i] = (startRow * width + startCol) * 4 + startDir;
            programs[i] = in.next();
        }
        functionNodes = new Node[26];
        for (int i = 0; i < 26; ++i) if (functions[i] != null) {
            functionNodes[i] = new ConcatenationNode(new NotInitializedNode(), new EmptyNode());
        }
        for (int i = 0; i < 26; ++i) if (functions[i] != null) {
            Node newNode = parse(functions[i]);
            ((ConcatenationNode) functionNodes[i]).a = newNode;
        }
        for (int i = 0; i < numPrograms; ++i) {
            Node program = parse(programs[i]);
            int res = program.execute(startState[i]);
            if (res < 0) {
                out.println("inf");
            } else {
                int dir = res % 4;
                res /= 4;
                int col = res % width;
                int row = res / width;
                out.println((row + 1) + " " + (col + 1) + " " + DIRS.charAt(dir));
            }
        }
    }

    private Node parse(String code) {
        if (code.isEmpty()) {
            return new EmptyNode();
        }
        switch (code.charAt(0)) {
            case 'm':
                return new ConcatenationNode(new MoveForwardNode(), parse(code.substring(1)));

            case 'l':
                return new ConcatenationNode(new TurnLeftNode(), parse(code.substring(1)));

            case 'i': {
                int cond = DIRS.indexOf(code.charAt(1));
                int balance = 0;
                int pos = 2;
                while (true) {
                    if (code.charAt(pos) == '(')
                        ++balance;
                    else if (code.charAt(pos) == ')')
                        --balance;
                    ++pos;
                    if (balance == 0) break;
                }
                Node ifTrue = parse(code.substring(3, pos - 1));
                int startAt = pos;
                while (true) {
                    if (code.charAt(pos) == '(')
                        ++balance;
                    else if (code.charAt(pos) == ')')
                        --balance;
                    ++pos;
                    if (balance == 0) break;
                }
                Node ifFalse = parse(code.substring(startAt + 1, pos - 1));
                return new ConcatenationNode(new ConditionNode(cond, ifTrue, ifFalse), parse(code.substring(pos)));
            }

            case 'u': {
                int cond = DIRS.indexOf(code.charAt(1));
                int balance = 0;
                int pos = 2;
                while (true) {
                    if (code.charAt(pos) == '(')
                        ++balance;
                    else if (code.charAt(pos) == ')')
                        --balance;
                    ++pos;
                    if (balance == 0) break;
                }
                Node ifFalse = parse(code.substring(3, pos - 1));
                Node x = new ConditionNode(cond, new EmptyNode(), new ConcatenationNode(ifFalse, new NotInitializedNode()));
                ((ConcatenationNode) ((ConditionNode) x).ifFalse).b = x;
                return new ConcatenationNode(x, parse(code.substring(pos)));
            }

            default: {
                return new ConcatenationNode(functionNodes[code.charAt(0) - 'A'], parse(code.substring(1)));
            }
        }
    }
}
