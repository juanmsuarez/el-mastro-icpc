typedef pii Value; // pii(val, id)
typedef struct node *pnode;
struct node {
    Value val, mini;
    int dirty;
    int prior, size;
    pnode l, r, parent;
    node(Value val):val(val), mini(val), dirty(0), prior(rand()), size(1), l(0), r(0), parent(0) {} // usar rand piola
};

void push(pnode p){ // propagar dirty a los hijos (aca para lazy)
    p->val.first += p->dirty;
    p->mini.first += p->dirty;
    if(p->l) p->l->dirty += p->dirty;
    if(p->r) p->r->dirty += p->dirty;
    p->dirty = 0;
}
static int size(pnode p){ return p ? p->size : 0; } 
static Value mini(pnode p){ return p ? push(p), p->mini : pii(1e9, -1); } 
// Update function and size from children's Value
void pull(pnode p){ // recalcular valor del nodo aca (para rmq)
    p->size = 1 + size(p->l) + size(p->r);
    p->mini = min(min(p->val, mini(p->l)), mini(p->r));//operacion del rmq!
    p->parent = 0;
    if(p->l) p->l->parent = p;
    if(p->r) p->r->parent = p;
}

//junta dos arreglos
pnode merge(pnode l, pnode r){
    if(!l || !r) return l ? l : r;
    push(l), push(r);
    pnode t;

    if(l->prior < r->prior) l->r=merge(l->r, r), t = l;
    else r->l=merge(l, r->l), t = r; 

    pull(t);
    return t;
}

//parte el arreglo en dos, si(l)==tam
void split(pnode t, int tam, pnode &l, pnode &r){
    if(!t) return void(l = r = 0);
    push(t);

    if(tam <= size(t->l)) split(t->l, tam, l, t->l), r = t; 
    else split(t->r, tam - 1 - size(t->l), t->r, r), l = t; 

    pull(t);
}

pnode at(pnode t, int pos){
    if(!t) exit(1);
    push(t);

    if(pos == size(t->l)) return t;
    if(pos < size(t->l)) return at(t->l, pos);

    return at(t->r, pos - 1 - size(t->l));
}
int getpos(pnode t){ // inversa de at
    if(!t->parent) return size(t->l);

    if(t == t->parent->l) return getpos(t->parent) - size(t->r) - 1;

    return getpos(t->parent) + size(t->l) + 1;
}

void split(pnode t, int i, int j, pnode &l, pnode &m, pnode &r){
    split(t, i, l, t), split(t, j-i, m, r);
}
Value get(pnode &p, int i, int j){ // like rmq
    pnode l, m, r;

    split(p, i, j, l, m, r);
    Value ret = mini(m);
    p = merge(l, merge(m, r));

    return ret;
}

void print(const pnode &t){ // for debugging
    if(!t) return;
    push(t);
    print(t->l);
    cout << t->val.first << ' ';
    print(t->r);
}
