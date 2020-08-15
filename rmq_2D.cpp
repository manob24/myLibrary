#include<bits/stdc++.h>
using namespace std;

/*
Preprocess : O(n*m*logn*logm)

    we create a table[ 1+logn ][ n ][ 1+logm ][ m ]
    Each box of the table[ 1+logn ][ n ] is a sparse table of size [ 1+logm ][ m ]
    Let us see what table[ jr ][ ir ][ jc ][ ic ] actually contains:
    It contains the minimum element from column ic to ic-1+2^jc of all rows from ir to ir-1+2^jr
    In other words, it contain the minimum element in the submatrix [ (ir,ic), (ir-1+2^jr , ic-1+2^jc) ]
    where submatrix [ (x1,y1),(x2,y2) ] denotes the submatrix with x1,y1 as its top left-most and x2,y2 as its bottom right-most point.
    Now you can easily conclude that, table[ 0 ][ ir ][ jc ][ ic ] is nothing but the 1D RMQ table if we take our array as row ir 
*/

