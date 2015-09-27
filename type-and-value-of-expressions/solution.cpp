#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    char    abc[27];
    char    *ptr = abc;
    strcpy(abc, "abcdefgxyz");
     /*
     * What are the types and values of expressions:
     *
  
     * 1. abc
     * 2. *abc
     * 3. abc[2]
     * 4. &abc[3] //&abc[3] = abc + 3*sizeof(char)
     * 5. abc+4
     * 6. *(abc+5) + 20000  //h  long long x = int * 1LL * int
     * 7. abc[10] //'\0'
     * 8. abc[12] //memset ()
     * 9. &ptr //char**
     */
     
     // 1. abc is a pointer, point to a[0]
     cout << abc << endl;
     // 2. *abc is abc[0], i.e. 'a'
     // unary prefix operator * applied to a pointer, dereference the pointer and obtain an object
     cout << *abc << endl;
     // 3. abc[2] is 'c'
     cout << abc[2] << endl;
     // 4. &abc[3] is the address of a[3]
     cout << &abc[3] << endl;
     // 5. abc+4 is a pointer point to abc[4]
     cout << abc+4 << endl;
     // 6. *(abc+5) + 20000 // 'f'+20000
     // *(abc+5) is abc[5] 'f' and converted to int 102
     cout << *(abc+5) + 20000 << endl;
     // 7. abc[10] i.e. '\0' terminating null character
     cout << abc[10] << endl;
     // 8. abc[12]
     cout << abc[12] << endl;
     // 9. &ptr is the address of pointer ptr
     cout << &ptr << endl;
     
     return 0;
}
