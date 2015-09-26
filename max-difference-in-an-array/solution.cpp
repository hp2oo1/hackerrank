/*
Given an array of integers, a, return the maximum difference of any pair of numbers such that the larger integer in the pair occurs at a higher index (in the array) than the smaller integer. Return -1 if you cannot find a pair that satisfies this condition.
 
You are provided with a function maxDifference which takes in the array as a parameter. You are required to return an integer which is the right answer. The code for parsing the input and displaying the output is provided, so your only task is to complete the body of the provided function so it returns the correct output to the caller. However, for completeness, we describe the input format:
 
Constraints:
1 ≤ N ≤ 1,000,000
-1,000,000 ≤ a[i] ≤ 1,000,000 ∀ i ∈ [0,N-1] 
 
Input Format:
The first line of the input is N (the number of elements in the array), and then followed by N elements each in a separate line. 
 
Sample Input #1:
7
2
3
10
2
4
8
1

Sample Output #1:
8

Explanation:
For the array { 2,3,10,2,4,8,1} given above, 10 is the largest number in the array and 1 is the smallest number in the array. However, the index of 10 is lower than the lowest index that contains a 1 so the condition of the problem is not satisfied. Using zero-based index notation, the correct answer is a[2] - a[0] = 10 - 2 = 8. This satisfies the condition that the larger number in the pair should be positioned at a higher index in the array than the smaller number.
 
Input #2: 
6
7
9
5
6
3
2

Output #2: 
2

Explanation #2:
The value of maxDifference is 9 - 7 = 2.
9 occurs at a[1] and 7 occurs at a[0]. This satisfies the condition that the larger number must have a higher index than the smaller number.
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * Complete the function below.
 */
int maxDifference(vector < int > a) {
/*
    // O(n^2)
    int d_max(-1);
    for(int i=0; i<a.size(); ++i) {
        for(int j=i+1; j<a.size(); ++j) {
            int d = a[j]-a[i];
            //std::cout<<a[i]<<" "<<a[j]<<" "<<d<<std::endl;
            if( d_max<d ) {
                d_max=d;
            }
        }
    }
    //std::cout<<d_max<<std::endl;
    return d_max;
*/
    // O(n)
    int d_max(-1);
    int a_min(a[0]), a_max(a[0]);
    int i_min(0), i_max(0);
    for(int i=0; i<a.size(); ++i) {
        if( a[i] > a_max ) {
            a_max = a[i];
            i_max = i;
        }
        if( a[i] < a_min ) {
            a_min = a[i];
            i_min = i;
        }
        if( i_min > i_max ) {
            i_max = i_min;
            a_max = a_min;
        }
        //        
        int d = a_max - a_min;
        if( d > d_max )
            d_max = d;
    }
    //
    if( d_max > 0 )
        return d_max;
    else
        return -1;
}

int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = maxDifference(_a);
    cout << res;
    
    return 0;
}
