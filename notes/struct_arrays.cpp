#include <iostream>

using namespace std;

const int MaxN=100;
const int MaxM=100;
const int MaxO=10000;
struct OfferT{
    int C;
    int P;
    int Price;
};
typedef OfferT OfferArray[MaxO];

bool exactlySameProductsForTheNextTwoCompanies(int compA,int compB,int M,int prices[MaxN+1][MaxM+1]);

int main()
{
    cerr << "Orders" << endl;

//declaration

    int N;
    int M;
    int O;
    OfferArray offers;

    int mostExpensiveProduct;
    int companyWithMostProduct;
    int cntProdsO1C;
    int prodsO1C[MaxM];
    int compA;
    int compB;

// input
    cin >> N;
    cin >> M;
    cin >> O;
    for (int i=0;i<O;i++) {
        cin >> offers[i].C;
        cin >> offers[i].P;
        cin >> offers[i].Price;
    }

/// algorithm implementation

/// A
    int maxi=0;
    mostExpensiveProduct=offers[maxi].P;
    for (int i=1;i<O;i++) {
        if (offers[i].Price > offers[maxi].Price) {
            maxi=i;
            mostExpensiveProduct=offers[maxi].P;
        } else if ((offers[i].Price == offers[maxi].Price) && (mostExpensiveProduct>offers[i].P)) {
            mostExpensiveProduct=offers[i].P;
        }
    }

    /// transform the array of structure to matrix
    int prices[MaxN+1][MaxM+1]={};
    for (int i=0;i<O;i++) {
        prices[offers[i].C][offers[i].P]=offers[i].Price;
    }

    /* dump */
    cerr << "dump:" << endl;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            cerr << prices[i][j] << "\t";
        }
        cerr << endl;
    }
    /* */

/// B
    int p4c[MaxN+1]={};
    /// for all companies
    for (int i=1;i<=N;i++) {
        /// calculation
        for (int j=1;j<=M;j++) {
            if (prices[i][j]!=0) {
                p4c[i]++;
            }
        }
    }
    /// maximum pick
    companyWithMostProduct=1;
    for (int i=2;i<=N;i++) {
        if (p4c[i]>p4c[companyWithMostProduct]) {
            companyWithMostProduct=i;
        }
    }

/// C
    int c4p[MaxM+1]={};
    /// for all products
    for (int i=1;i<=M;i++) {
        /// calculation
        for (int j=1;j<=N;j++) {
            if (prices[j][i]!=0) {
                c4p[i]++;
            }
        }
    }

    /// selection
    cntProdsO1C=0;
    for (int i=1;i<=M;i++) {
        if (c4p[i]==1) {
            cntProdsO1C++;
            prodsO1C[cntProdsO1C]=i;
        }
    }

/// D
    compA=1;
    bool found=false;
    while ((compA<N) && !found){
        compB=compA+1;
        while ((compB<=N) && !found){
            /// decision for every
            found=exactlySameProductsForTheNextTwoCompanies(compA,compB,M,prices);
            compB++;
        }
        compA++;
    }
    compA--;
    compB--;


    // output

    cout << "#" << endl;
    cout << mostExpensiveProduct << endl;
    cout << "#" << endl;
    cout << companyWithMostProduct << endl;
    cout << "#" << endl;
    cout << cntProdsO1C << endl;
    if (cntProdsO1C>0) {
        for (int i=1;i<=cntProdsO1C;i++) {
            cout << prodsO1C[i] << " ";
        }
        cout << endl;
    }
    cout << "#" << endl;
    if (compA==N-1) {
        cout << "-1" << endl;
    } else {
        cout << compA << " " << compB << endl;
    }

    return 0;
}

bool exactlySameProductsForTheNextTwoCompanies(int compA,int compB,int M,int prices[MaxN+1][MaxM+1]){
    int i=1;
    while ((i<=M) && (((prices[compA][i]==0) && (prices[compB][i]==0)) || ((prices[compA][i]!=0) && (prices[compB][i]!=0)))) {
        i++;
    }
    return (i>M);
}
