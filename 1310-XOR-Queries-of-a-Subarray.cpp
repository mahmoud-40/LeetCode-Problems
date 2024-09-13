class Solution {
public:
class Node
{
public:
    int v = 0; 
    Node() {}
    Node(int val)
    {
        v = val; // 2. Node constructor will change depending on, what we need to initialize
    }

    void merge(const Node &l, const Node &r)
    {                  // v is each nodes data, while l & r are children
        v = l.v ^ r.v; // 3. Merge function (merge logic can change)
    }
};

class Update
{
public:
    int v = 0;
    // 4. this is identity Transformation - default update value assigned before or after the operation
    Update(){};
    Update(int val)
    {
        v = val; // 5. Update constructor initialization
    }

    void combine(const Update &otherUpdate, const int &tl, const int &tr)
    {                       // combing the update, to give to chidren in future
        v += otherUpdate.v; // 6. OtherUpdate is the newest update ['=' or '+=' depends on 'assign/set' vs 'add']
    }

    void apply(Node &node, const int &tl, const int &tr) const
    {
        node.v += (tr - tl + 1) * v; // 7. applying the update received on the node
    }
};

template <typename node, typename update>
class SegTree
{
public:
    int tree_size;
    // t is the segment Tree
    vector<node> seg_data;
    vector<update> unpropUpd; // the actual val of un-propogated updates to be processed
    vector<bool> isLazy;      // tells if a certain node is storing un-propogated updates or not
    node identityElement;
    update identityTransformation;

    SegTree() {}
    SegTree(int l)
    {
        tree_size = l;
        seg_data.resize(4 * tree_size);
        isLazy.resize(4 * tree_size);
        unpropUpd.resize(4 * tree_size);
        identityElement = node();
        identityTransformation = update();
    }

    // asking v, to remember that he has 'val' update for his range
    void apply(const int &v, const int &tl, const int &tr, const update &upd)
    { // [tl, tr] is node range
        if (tl != tr)
        { // leaf nodes can't be lazy, as they have no-one to propogate to
            isLazy[v] = true;
            unpropUpd[v].combine(upd, tl, tr); // stacking up the unpropogaed value, which i'll propogate down
        }
        upd.apply(seg_data[v], tl, tr); // this "= shows assign update", "+= shows range add update"
    }

    // assigning the value whatsoever we had on 'v' to its children ('2*v' & '2*v+1')
    void pushDown(const int &v, const int &tl, const int &tr)
    {
        if (!isLazy[v])
            return;        // if not lazy then no push-down required
        isLazy[v] = false; // no more lazy
        int tm = (tl + tr) / 2;
        apply(2 * v, tl, tm, unpropUpd[v]);         // propogates to left child
        apply(2 * v + 1, tm + 1, tr, unpropUpd[v]); // propogates to right child
        unpropUpd[v] = identityTransformation;      // identity-transformation -- updated the children(job done)
    }

    // Build Segment Tree -- init(a, 1, 0, len-1);
    template <typename T>
    void init(const T &a, const int &v, const int &tl, const int &tr)
    {
        if (tl == tr)
        {
            seg_data[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        init(a, 2 * v, tl, tm);
        init(a, 2 * v + 1, tm + 1, tr);
        seg_data[v].merge(seg_data[2 * v], seg_data[2 * v + 1]);
    }

    // Query input question is = [l, r] included -- query(1, 0, len-1, l, r)
    node query(const int &v, const int &tl, const int &tr, const int &l, const int &r)
    {
        if (tl > r || tr < l)
            return identityElement; // no overlap
        if (l <= tl && tr <= r)
            return seg_data[v]; // Full overlap

        // Partial Overlap
        pushDown(v, tl, tr); // we remove the lazy tag before going down, so children have correct info
        int tm = (tl + tr) / 2;
        node leftAns = query(2 * v, tl, tm, l, r);
        node rightAns = query(2 * v + 1, tm + 1, tr, l, r);
        node ans;
        ans.merge(leftAns, rightAns);
        return ans;
    }

    // Update at index id of nums to a value val (assign/override/set) -- update(1, 0, len-1, l, r, val)
    void update_range(const int &v, const int &tl, const int &tr, const int &l, const int &r, const update &upd)
    {
        // reached leaf node
        if (l <= tl && tr <= r)
        { // full overlap -- apply update and return back
            apply(v, tl, tr, upd);
            return;
        }
        if (tl > r || tr < l)
            return; // no overlap

        // Partial Overlap
        pushDown(v, tl, tr);
        int tm = (tl + tr) / 2;
        update_range(2 * v, tl, tm, l, r, upd);
        update_range(2 * v + 1, tm + 1, tr, l, r, upd);
        seg_data[v].merge(seg_data[2 * v], seg_data[2 * v + 1]);
    }

    // over-ridden functions
    template <typename T>
    void init(const T &a)
    {
        init(a, 1, 0, tree_size - 1);
    }

    node query(const int &l, const int &r)
    {
        return query(1, 0, tree_size - 1, l, r);
    }

    void update_range(const int &l, const int &r, const update &upd)
    {
        update_range(1, 0, tree_size - 1, l, r, upd);
    }
};

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        SegTree<Node, Update> tree(arr.size());
        tree.init(arr);
        for(auto q : queries){
            int x = tree.query(q[0], q[1]).v;
            ans.push_back(x);
        }
        return ans;
    }
};