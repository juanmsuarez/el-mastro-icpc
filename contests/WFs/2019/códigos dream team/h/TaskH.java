package main;

import lib.InputReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TaskH {
    static int k;

    static class Vertex {
        int mark;
        Vertex next;
        List<Vertex> prev = new ArrayList<>();
        int[] atDistance;
        int maxDistance;
        int totalAtMostK;

        public void dfs() {
            Vertex biggestChild = null;
            for (Vertex child : prev) if (child.mark != 2) {
                child.dfs();
                if (biggestChild == null || child.maxDistance > biggestChild.maxDistance) {
                    biggestChild = child;
                }
            }
            if (biggestChild == null) {
                atDistance = new int[1];
                atDistance[0] = 1;
                maxDistance = 0;
                totalAtMostK = 1;
                return;
            }
            maxDistance = biggestChild.maxDistance + 1;
            atDistance = biggestChild.atDistance;
            totalAtMostK = biggestChild.totalAtMostK;
            while (atDistance.length <= maxDistance) {
                atDistance = Arrays.copyOf(atDistance, 2 * atDistance.length);
            }
            ++atDistance[maxDistance];
            ++totalAtMostK;
            for (Vertex child : prev) if (child.mark != 2 && child != biggestChild) {
                totalAtMostK += child.totalAtMostK;
                for (int i = 0; i <= child.maxDistance; ++i) {
                    atDistance[maxDistance - 1 - i] += child.atDistance[child.maxDistance - i];
                }
            }
            if (maxDistance > k) {
                totalAtMostK -= atDistance[maxDistance - k - 1];
            }
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        k = in.nextInt();
        Vertex[] v = new Vertex[n];
        for (int i = 0; i < n; ++i) {
            v[i] = new Vertex();
        }
        for (int i = 0; i < n; ++i) {
            v[i].next = v[in.nextInt() - 1];
            v[i].next.prev.add(v[i]);
        }
        for (Vertex any : v) if (any.atDistance == null) {
            Vertex cur = any;
            while (cur.mark == 0) {
                cur.mark = 1;
                cur = cur.next;
            }
            List<Vertex> cycle = new ArrayList<>();
            while (cur.mark == 1) {
                cur.mark = 2;
                cycle.add(cur);
                cur = cur.next;
            }
            for (Vertex root : cycle) {
                root.dfs();
            }
            int maxDistance = 0;
            for (Vertex root : cycle) {
                maxDistance = Math.max(maxDistance, root.maxDistance + 2 * cycle.size());
            }
            int[] atDistance = new int[maxDistance + 1];
            int totalAtMostK = 0;
            maxDistance -= 2 * cycle.size();
            for (int iter = 0; iter < 2; ++iter) {
                for (Vertex root : cycle) {
                    ++maxDistance;
                    if (maxDistance > k) {
                        totalAtMostK -= atDistance[maxDistance - k - 1];
                    }
                    if (iter == 1) {
                        for (int i = 0; i <= root.maxDistance; ++i) {
                            atDistance[maxDistance - cycle.size() - i] -= root.atDistance[root.maxDistance - i];
                            if (i + cycle.size() <= k) {
                                totalAtMostK -= root.atDistance[root.maxDistance - i];
                            }
                        }
                    }
                    for (int i = 0; i <= root.maxDistance; ++i) {
                        atDistance[maxDistance - i] += root.atDistance[root.maxDistance - i];
                        if (i <= k) {
                            totalAtMostK += root.atDistance[root.maxDistance - i];
                        }
                    }
                    if (iter == 1) {
                        root.totalAtMostK = totalAtMostK;
                    }
                }
            }
        }
        for (Vertex a : v) {
            out.println(a.totalAtMostK);
        }
    }
}
