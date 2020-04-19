#include <iostream>

using namespace std;

void subtract(int* x, int* y, int* result, int size)
{
    for(int i = 0; i < size; i++)
    {
        result[i] = y[i] - x[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n], b[n], result[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    
    subtract(a, b, result, n);
    int c[n], k = 0; 
    for(int i = 0; i < n; i++)
    {
        if(result[i] < 0)
        {
            c[k] = -result[i];
        }
        else
        {
            c[k] = result[i];
        }
        k++;
        
    }
    int ans = 0, m = 0;
    for(int i = 0; i < n; i++)
    {
        ans = result[0];
        if (ans < result[i])
        {
            ans = result[i];
            m = i; 
        }
        
    }

    cout << m+1; 

}
