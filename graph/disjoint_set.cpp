#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

class DisjointSet {
    private:
        vi root;

    public:
        DisjointSet(int size);
        bool union_set(int a, int b);
        int find_set(int a);
};

DisjointSet::DisjointSet(int size) {
    root.assign(size+1, 0);
    for(int i = 0; i <= size; i++) {
        root[i] = i;
    }
}

bool DisjointSet::union_set(int a, int b) {
    int fa = find_set(a);
    int fb = find_set(b);

    if(fa == fb) {
        return false;
    }
    root[fb] = fa;

    return true;
}

int DisjointSet::find_set(int a) {
    if(a == root[a]) return a;
    return find_set(root[a]);
}
