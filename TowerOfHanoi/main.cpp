#include <iostream>
#include <stack>
using namespace std;

//recursively print stack
void printRods(stack<int> rod)
{
    if (rod.empty())
    {
        return;
    }
    int num = rod.top();
    rod.pop();
    cout << num << ' ';
    printRods(rod);
}

//move numbers from one stack to another
void moveNum(stack<int> &fromRod, stack<int> &toRod)
{
    int tmp = fromRod.top();
    fromRod.pop();
    toRod.push(tmp);
}

//process stacks
void towerOfHanoi(int n, stack<int> &fromRod, stack<int> &toRod,
                  stack<int> &midRod)
{
    if (n == 0) //base case
    {
        return;
    }
    towerOfHanoi(n - 1, fromRod, midRod, toRod);
    moveNum(fromRod, toRod);
    towerOfHanoi(n - 1, midRod, toRod, fromRod);
}

int main()
{
    //initialize stacks
    int N = 5;
    stack<int> A;
    stack<int> B;
    stack<int> C;
    
    //push stacks in descending order
    A.push(5);
    A.push(4);
    A.push(3);
    A.push(2);
    A.push(1);
 
    //print initial stacks
    cout << "A: ";
    printRods(A);
    cout << endl;
    
    cout << "B: ";
    printRods(B);
    cout << endl;
    
    cout << "C: ";
    printRods(C);
    cout << endl << endl;
    
    //perform recursion
    towerOfHanoi(N, A, C, B);
    
    //print final stacks
    cout << "A: ";
    printRods(A);
    cout << endl;
    
    cout << "B: ";
    printRods(B);
    cout << endl;
    
    cout << "C: ";
    printRods(C);
    cout << endl;
    return 0;
}
