/*
Remove duplicate characters from the string.
Estimate the complexity of the implemented algorithm.
*/

// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.

#include <iostream>

int main(int argc, char** argv) {
    
    // O(n) solution
    std::string inputString;
    while( getline(std::cin,inputString) )
    {
        // check input
        std::cout<<"input: "<<inputString<<std::endl;
        // remove duplicate characters
        bool visited[256];
        // init
        for(int i=0; i<256; ++i)
            visited[i] = false;
        // process
        int k(0);
        for(int i=0; i<inputString.size(); ++i) {
            int j = inputString[i];
            //std::cout<<inputString[i]<<" "<<j<<std::endl;
            if( !visited[j] ) {
                visited[j] = true;
                inputString[k++] = inputString[i];
            }
        }
        //std::cout<<inputString<<std::endl;
        inputString.resize(k);
        // check result
        std::cout<<"output: "<<inputString<<std::endl;
    }
    
    return 0;
    
}
