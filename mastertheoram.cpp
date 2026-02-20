/*  SOLUTIONS EXPERIMENT ONE

1.   ANSWER:  T(n)=3T(n/2)+O(nlogn)

     Reason : 	As 3 recursive calls for size (n/2);
                While loop for log(n) times
                For loop for n times



2. 
T(n) =  aT(n/b) + f(n)

a = 3
b = 2

Answer :  T(n)=O(n^[log2(​3)]) ...O(n power - log3  base 2)

*/ 

#include <iostream>
using namespace std;

long long operations = 0;
int maxDepth = 0;

void func(int n, int depth) {
    if (depth > maxDepth)
        maxDepth = depth;

    if (n <= 2) {
        operations++;
        return;
    }

    int p = n;

    while (p > 0) {
        for (int i = 0; i < n; i++) {
           
        }
        p = p / 2;
        operations++;
    }

    for (int i = 0; i < n; i++) {
        operations++;    
    }

    for (int i = 0; i < n; i++) {
        operations++;       
    }

    func(n/2, depth+1);
    func(n/2, depth+1);
    func(n/2, depth+1);
}

int main() {
    int sizes[4] = {30, 500, 20, 90};

    for (int i = 0; i < 4; i++) {
        operations = 0;
        maxDepth = 0;

        func(sizes[i], 1);

        cout << "n = " << sizes[i] << endl;
        cout << "Operations = " << operations << endl;
        cout << "Recursion Depth = " << maxDepth << endl;
        cout << "-------------------" << endl;
    }
}