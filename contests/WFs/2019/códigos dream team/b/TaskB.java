package main;

import lib.InputReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        long h = in.nextLong();
        long alpha = in.nextLong();
        long beta = in.nextLong();
        long[] x = new long[n];
        long[] y = new long[n];
        for (int i = 0; i < n; ++i) {
            x[i] = in.nextLong();
            y[i] = in.nextLong();
        }
        long[] maxRight = new long[n];
        long[] maxLeft = new long[n];
        for (int i = 0; i < n; ++i) {
            maxLeft[i] = maxRight[i] = 2 * (h - y[i]);
            for (int j = 0; j < n; ++j) if (i != j) {
                long dx = Math.abs(x[i] - x[j]);
                long dy = h - y[j];
                long upto = 2 * (dx + dy) + floorSqrt(8 * dx * dy);
                if (x[j] < x[i]) {
                    maxLeft[i] = Math.min(maxLeft[i], upto);
                } else {
                    maxRight[i] = Math.min(maxRight[i], upto);
                }
            }
        }
        long[] best = new long[n];
        best[0] = alpha * (h - y[0]);
        for (int i = 1; i < n; ++i) {
            best[i] = Long.MAX_VALUE;
            for (int j = 0; j < i; ++j) if (best[j] < Long.MAX_VALUE) {
                long dist = x[i] - x[j];
                if (dist <= maxRight[j] && dist <= maxLeft[i]) {
                    best[i] = Math.min(best[i], best[j] + alpha * (h - y[i]) + beta * dist * dist);
                }
            }
        }
        long res = best[n - 1];
        if (res == Long.MAX_VALUE) {
            out.println("impossible");
        } else {
            out.println(res);
        }
    }

    private long floorSqrt(long max) {
        long d = (long) Math.floor(Math.sqrt(max));
        while (d * d > max) --d;
        while ((d + 1) * (d + 1) <= max) ++d;
        return d;
    }
}
