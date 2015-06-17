#include<iostream>
using namespace std;
 
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }
 
int buildSegment(int *tree, int node, int *a, int i, int j)
{

	if(i == j)
	{
		tree[node] = j;
	}
	else
	{
		int l = buildSegment(tree, node*2, a, i, (i+j)/2);
		int r = buildSegment(tree, node*2 + 1, a, (i+j)/2+1, j);

		if (a[tree[node*2+1]] < a[tree[node*2]])
			tree[node] = tree[node*2+1];
		else
			tree[node] = tree[node*2];
	}
	return tree[node];
}

int query_segment_tree(int *tree, int node, int sb, int se, int *a, int s, int e)
{
    if (sb == s && se == e)
        return tree[node];
         
    int mid = sb + (se-sb)/2;
    if (s > mid)
        return query_segment_tree(tree, 2*node+1, mid+1, se, a, s, e);
         
    if (e <= mid)
        return query_segment_tree(tree, 2*node, sb, mid, a, s, e);
         
    int l = query_segment_tree(tree, 2*node, sb, mid, a, s, mid);
    int r = query_segment_tree(tree, 2*node+1, mid+1, se, a, mid+1, e);
         
    tree[node] = l;
    if (a[r] < a[l])
        tree[node] = r;
         
    return tree[node];
}

int segmentTreeQuery(int *a, int n, int i, int j)
{
	int *tree = new int[n*2];
	buildSegment(tree, 1, a, 0, n-1);
	int ret = query_segment_tree(tree, 1, 0, n-1, a, i, j);
	return ret;
}
 
int main()
{
	int a[] = { 2, 4, 3, 1, 6, 7, 8, 9, 1, 7 };
    cout<<segmentTreeQuery(a, sizeof(a)/sizeof(a[0]), 5, 9);
    return 0;
}