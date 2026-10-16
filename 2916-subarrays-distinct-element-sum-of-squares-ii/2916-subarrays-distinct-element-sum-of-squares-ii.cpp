
class Solution {
public:
    static const long long MOD = 1000000007LL;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void pull(int node) {
        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].sq =
            (tree[node * 2].sq + tree[node * 2 + 1].sq) % MOD;
    }

    void build(int node, int l, int r) {
        tree[node].sum = 0;
        tree[node].sq = 0;
        tree[node].lazy = 0;

        if (l == r) return;

        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        pull(node);
    }

    void apply(int node, int l, int r, long long v) {
        long long len = r - l + 1;
        long long oldSum = tree[node].sum;

        tree[node].sq =
            (tree[node].sq
             + 2LL * v % MOD * oldSum % MOD
             + len % MOD * v % MOD * v % MOD) % MOD;

        tree[node].sum =
            (oldSum + len % MOD * v % MOD) % MOD;

        tree[node].lazy = (tree[node].lazy + v) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r) return;

        int mid = (l + r) / 2;
        long long v = tree[node].lazy;

        apply(node * 2, l, mid, v);
        apply(node * 2 + 1, mid + 1, r, v);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long v) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, v);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr, v);
        update(node * 2 + 1, mid + 1, r, ql, qr, v);

        pull(node);
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n + 5, Node());

        build(1, 0, n - 1);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last[nums[i]];

            update(1, 0, n - 1, prev + 1, i, 1);

            last[nums[i]] = i;

            ans = (ans + tree[1].sq) % MOD;
        }

        return (int)ans;
    }
};
