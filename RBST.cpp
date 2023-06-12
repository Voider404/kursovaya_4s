#include "RBST.h"

namespace RBST
{
    int getsize(RBS_Tree* p)
    {
        if (!p) return 0;
        return p->size;
    }

    void fixsize(RBS_Tree* p)
    {
        p->size = getsize(p->left) + getsize(p->right) + 1;
    }

    RBS_Tree* find(RBS_Tree* p, Newspaper& k)
    {
        if (!p) return 0;

        if (k == p->key)
            return p;

        if (k < p->key)
            return find(p->left, k);
        else
            return find(p->right, k);
    }

    RBS_Tree* insert(RBS_Tree* p, Newspaper& k)
    {
        if (!p) return new RBS_Tree(k);

        if (rand() % (p->size + 1) == 0)
            return insertroot(p, k);

        if (p->key > k)
            p->left = insert(p->left, k);
        else
            p->right = insert(p->right, k);

        fixsize(p);
        return p;
    }

    RBS_Tree* rotateright(RBS_Tree* p)
    {
        RBS_Tree* q = p->left;
        if (!q) return p;

        p->left = q->right;
        q->right = p;
        q->size = p->size;

        fixsize(p);
        return q;
    }

    RBS_Tree* rotateleft(RBS_Tree* q)
    {
        RBS_Tree* p = q->right;
        if (!p) return q;

        q->right = p->left;
        p->left = q;
        p->size = q->size;

        fixsize(q);
        return p;
    }

    RBS_Tree* insertroot(RBS_Tree* p, Newspaper& k)
    {
        if (!p) return new RBS_Tree(k);

        if (k < p->key)
        {
            p->left = insertroot(p->left, k);
            return rotateright(p);
        }
        else
        {
            p->right = insertroot(p->right, k);
            return rotateleft(p);
        }
    }

    RBS_Tree* join(RBS_Tree* p, RBS_Tree* q)
    {
        if (!p) return q;
        if (!q) return p;

        if (rand() % (p->size + q->size) < p->size)
        {
            p->right = join(p->right, q);
            fixsize(p);
            return p;
        }
        else
        {
            q->left = join(p, q->left);
            fixsize(q);
            return q;
        }
    }

    RBS_Tree* remove(RBS_Tree* p, Newspaper& k)
    {
        if (!p) return p;

        if (p->key == k)
        {
            RBS_Tree* q = join(p->left, p->right);
            delete p;
            return q;
        }
        else if (k < p->key)
            p->left = remove(p->left, k);
        else
            p->right = remove(p->right, k);

        return p;
    }
}