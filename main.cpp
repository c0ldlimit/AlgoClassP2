#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

typedef vector<int>::iterator vec_it;

long int total = 0;

long int total2 = 0;

int find_mid(int n1, int n2, int n3)
{
  int mid;
  if( n1 > n2 )   {
          if( n3 > n2)
                {
                        if( n3 < n1 )
                                mid = n3;
                        else
                                mid = n1;
                }
         else {
                mid = n2;
        }
 }
 else {
        if( n2 > n3 )
         {
                if ( n1 > n3)
                  mid = n1;
                else
                mid = n3;
         }
        else{
                mid = n2;
        }
}
return mid ;
}

void printVector(vector<int> &vec)
{
    vector<int>::iterator it;

    for ( it=vec.begin() ; it!=vec.end(); ++it )
    {
        cout << *it << endl;
    }
}

int ChoosePivot(const vector<int> &vec, const int &length)
{
    return 0; // for now the default pivot is the first index
}

int Partition(vector<int> &vec, int startIdx , int endIdx)
{

    int pivotVal = vec[startIdx]; // default pivot
    int I = startIdx+1;
    int valJ = 0;
    for (int J=I; J<=endIdx; ++J)
    {
        valJ = vec[J];
        ++total2;
        if (valJ < pivotVal)
        {
            vec[J] = vec[I];
            vec[I] = valJ;
            ++I;
        }
    }

    vec[startIdx] = vec[I-1];
    vec[I-1] = pivotVal;

    return I-1; // new pivot location

}




void QuickSort(vector<int> &vec,  int startIdx, int endIdx, const int &length)
{
    if (length==1 || length==0)
    {
        return;
    }

    /*
    int temp = vec[startIdx];
    vec[startIdx] = vec[endIdx];
    vec[endIdx] = temp;
    */

    int midIdx = 0;
    if (length%2==1)
    {
        midIdx = (endIdx+startIdx)/2;
    }
    else
    {
        midIdx = (endIdx+startIdx-1)/2;
    }
    // find middle value the swap with first
    int midVal = find_mid(vec[startIdx],vec[endIdx],vec[midIdx]);
    cout << midVal << endl;
    if (midVal==vec[midIdx])
    {
        int temp = vec[startIdx];
        vec[startIdx] = midVal;
        vec[midIdx] = temp;
    }
    else if (midVal==vec[endIdx])
    {
        int temp = vec[startIdx];
        vec[startIdx] = midVal;
        vec[endIdx] = temp;
    }


    int pivotIdx = Partition(vec,startIdx,endIdx);
    if (length >=2)
    {
        total = total+length-1;
    }

    QuickSort(vec,startIdx,pivotIdx-1,pivotIdx-startIdx);
    QuickSort(vec,pivotIdx+1,endIdx,endIdx-pivotIdx);
}



int main()
{
    /*
    int myints[] = {16,2,77,29,66,4,51,1,3,44,12,5,123,9};
    vector<int> A (myints, myints + sizeof(myints) / sizeof(int) );
    int vecSize = A.size();
    cout << "Printing vector contents" << endl;
    printVector(A);
    cout << endl;

    QuickSort(A,0,vecSize-1,vecSize);
    cout << "Printing quick-sorted vector contents" << endl;
    printVector(A);
    return 0;*/

    vector<int> F;
    ifstream infile("C:\\Documents and Settings\\c\\My Documents\\Downloads\\QuickSort.txt");
    int I;
    if (!infile) {
        cout << "There was a problem opening file "
             << " for reading."
             << endl;
        return 0;
    }
    cout << "Opened for reading." << endl;
    while (infile >> I) {
        F.push_back(I);
    }
    int n = F.size();
    //cout << "Printing vector contents" << endl;
    //printVector(F);
    QuickSort(F,0,n-1,n);
    //cout << "Printing quick-sorted vector contents" << endl;
    //printVector(F);
    cout << "total: " << total << endl;
    cout << "total2: " << total2 << endl;
    return 0;
}
