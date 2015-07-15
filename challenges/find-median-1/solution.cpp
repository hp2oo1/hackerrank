/*
Problem Statement:
Given that integers are read from a data stream,
find the median of elements read so far in an efficient way.
https://www.hackerrank.com/challenges/find-median-1

Solution Idea:
First, we traverse the list of numbers to build up a minheap and maxheap
in an attempt to efficiently separate the stream of incoming numbers.
Then we move values between the minheap and maxheap until their sizes differ by at most one item.
The median is the extra item, or otherwise the average of the minheap and maxheap values.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // using mycomparison:
    typedef std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;
    
    mypq_type maxHeap;
    mypq_type minHeap(mycomparison(true));
    
    int N;
    cin >> N;
    int count(0), a, b;
    float median;
    while( count<N ) {
        count++;
        cin >> a;
        if( count==1 ) {
            maxHeap.push(a);
            median = a;
        }
        else if( count==2 ) {
            b = maxHeap.top();
            maxHeap.pop();
            if( a>b ) {
                maxHeap.push(b);
                minHeap.push(a);
            }
            else {
                maxHeap.push(a);
                minHeap.push(b);
            }
            median = float(a+b)/2;
        }
        else {
            if( a>median ) {
                minHeap.push(a);
            }
            else {
                maxHeap.push(a);
            }
            //
            while( maxHeap.size()>minHeap.size()+1 ) {
                b = maxHeap.top();
                maxHeap.pop();
                minHeap.push( b );
            }
            while( minHeap.size()>maxHeap.size()+1 ) {
                b = minHeap.top();
                minHeap.pop();
                maxHeap.push( b );
            }
            //
            if( maxHeap.size()>minHeap.size() ) {
                median = maxHeap.top();
            }
            else if( maxHeap.size()<minHeap.size() ) {
                median = minHeap.top();
            }
            else {
                median = float(maxHeap.top()+minHeap.top())/2;
            }
        }
        //
        cout << fixed << setprecision(1) << median << endl;
    }
    return 0;
}
