vi pal_array(string s)
{
    int n = si(s);
    s = "@" + s + "$";

    vi len(n + 1);
    int l = 1, r = 1;

    forsn(i, 1, n+1) {
        len[i] = min(r - i, len[l + (r - i)]);

        while (s[i - len[i]] == s[i + len[i]]) len[i]++;

        if (i + len[i] > r) l = i - len[i], r = i + len[i];
    }

    len.erase(begin(len));
    return len;
}
