// 1000000 -> 1,000,000 EN
// 1000000 -> 10,00,000 IN

#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
struct StyleBase {
    static int computeCommaCount( int size ) {
        return T::computeCommaCount( size );
    }
    static bool isComma( int position ) {
        return T::isComma( position );
    }
};

struct StyleEN : StyleBase<StyleEN> {
    static int computeCommaCount( int size ) {
        return (size-1) / 3;
    }
    static bool isComma( int position ) {
        return position % 4 == 3;
    }
};

struct StyleIN : StyleBase<StyleIN> {
    static int computeCommaCount( int size ) {
        return (size-2) / 2;
    }
    static bool isComma( int position ) {
        return position>0 && position%3==0;
    }
};

template<typename T>
string formatNum( int number, const StyleBase<T>& style ) {
    
    bool flag_negative(false);
    if( number<0 ) {
        flag_negative = true;
        number *= -1;
    }
    
    stringstream ss;
    ss<<number;
    string result( ss.str() );
    
    int old_size = result.size();
    int count = style.computeCommaCount( old_size );
    //cout<<count<<endl;
    
    int new_size = old_size + count;
    result.resize( new_size );
    int i(old_size-1), j(new_size-1), k(0);
    while( i>=0 ) {
        //cout<<k<<endl;
        if( style.isComma(k) ) {
            result[j] = ',';
        }
        else {
            result[j] = result[i];
            --i;
        }
        ++k;
        --j;
    }
    
    if( flag_negative )
        result = '-'+result;
    
    return result;
}

int main() {
    
    int number;
    cin>>number;
    
    StyleBase<StyleEN> styleEN;
    StyleBase<StyleIN> styleIN;
    
    cout<<formatNum( number, styleEN )<<endl;
    cout<<formatNum( number, styleIN )<<endl;

}
