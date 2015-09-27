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
 
//1234
//1,234
 
// 104450 -> 104,450
// 123123123 -> 123,123,123
 
// 1000000 -> 10,00,000
// 00010100

const int en_style[4] = { 3, 7, 11, 15 };
const int in_style[5] = { 3, 6, 9, 12, 15 };

string formatNum(int num) {
    
    bool flag_negative(false);
    if( num<0 ) {
        num*=-1;
        flag_negative = true;
    }
    
    stringstream ss;
    ss << num;
    string num_str = ss.str();
    //cout << num_str << endl;

    // en_style
    //int count = (num_str.size()-1) / 3;
    // in_style
    int count = (num_str.size()-2) / 2;
    //cout << count << endl;
    
    if( count>0 ) {
        int old_size = num_str.size();
        //cout << old_size << endl;
        int new_size = old_size + count;
        num_str.resize( new_size );
        //cout << new_size << endl;
        for( int i=new_size-1, j=old_size-1, k=0, m=0; i>=0; --i, ++k ) {
            //cout << k << endl;
            //cout << en_style[m] << endl;
            //if( k%4==3 ) {
            if( k==in_style[m] ){
                num_str[i] = ',';
                //num_str[k] = ',';
                ++m;
            }
            else {
                num_str[i] = num_str[j];
                //num_str[k] = num_str[j];
                --j;
            }
        }
    }
    //reverse( num_str.begin(), num_str.end() );
    //cout << num_str << endl;
    
    if( flag_negative )
        num_str = '-' + num_str;
    
    return num_str;
}
 
int main() {
    string res;
    int _num;
    cin >> _num;
     
    res = formatNum(_num);
    cout << res;
     
    return 0;
}
