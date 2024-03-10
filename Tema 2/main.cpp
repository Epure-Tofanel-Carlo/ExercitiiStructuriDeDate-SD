#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    // exercitiu 1
    int n, a[10000];
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        int element;
        cin >> element;
        a[i] = element;
    }
    sort(a, a + n) ;
    cout << a[0] << " " << a[n - 1] << endl;

    // exercitiu 2
    int k;
    int n_2;
    cin >> n_2;
    int a_2[10000];
    for (int i = 0 ; i < n_2 ; i++)
    {
        int element;
        cin >> element;
        a_2[i] = element;
    }
    cin >> k;
    for (int i = 0 ; i < n_2 ;)
    {
        if (a_2[i] == k) {
            for (int j = i; j < n_2 - 1; j++) {
                a_2[j] = a_2[j + 1];
            }
            n_2--;
        } else {
            i++;
        }
    }
    for (int i = 0 ; i < n_2 ; i ++)
    {
        cout<< a_2[i] << " ";
    }
    cout << endl;

    //exercitiul 3
    int t, k_2;
    int n_3;
    cin >> n_3;
    int a_3[10000];
    for (int i = 0 ; i < n_3 ; i++)
    {
        int element;
        cin >> element;
        a_3[i] = element;
    }
    cin >> t;
    cin >> k_2;
    for (int i = 0 ; i < n_3 ; i++)
    {
        if (a_3[i] == k_2) {
            for (int j = n_3; j > i; j--) {
                a_3[j] = a_3[j - 1];
            }
            a_3[i + 1] = t;
            n_3++;
            break;
        }
    }
    for (int i = 0 ; i < n_3 ; i ++)
    {
        cout<< a_3[i] << " ";
    }
    cout << endl;

    //exercitiul 4
    int n_4;
    int a_4[10000];
    cin >> n_4;
    for (int i = 0 ; i < n_4 ; i++)
    {
        int element;
        cin >> element;
        a_4[i] = element;
    }
    int i = 0;
    sort(a_4, a_4 + n_4);
    while ( i < n_4) {
        if ( i == n_4-1 || a_4[i] != a_4[i + 1]) { // am gasit elementul singular
            cout << a_4[i] << endl;
            break;
        }
        i += 2; // sarim peste perechile de elemente egale
    }

    //exercitiul 5

    int polinom[10000];
    int grad_maxim;
    cin >> grad_maxim;
    for (int i = 0 ; i <= grad_maxim ; i++)
    {
        cin >> polinom[i];
    }
    int termen;
    cin >> termen;
    int rezultat = 0;
    for (int i = 0 ; i <= grad_maxim ; i++)
    {
        rezultat = polinom[i]*(pow(termen, i)) + rezultat;
    }
    cout << rezultat << endl;

    //exercitul 6

    int polinom_1[10000];
    int polinom_2[10000];
    int grad_maxim_1;
    int grad_maxim_2;
    cin >> grad_maxim_1;
    for (int i = 0 ; i <= grad_maxim_1 ; i++)
    {
        cin >> polinom_1[i];
    }
    cin >> grad_maxim_2;
    for (int i = 0 ; i <= grad_maxim_2 ; i++)
    {
        cin >> polinom_2[i];
    }
    int rezultat_1[10000];
    if (grad_maxim_1 > grad_maxim_2)
    {
        for (int i = 0 ; i <= grad_maxim_1 ; i++)
        {
            rezultat_1[i] = polinom_1[i] + polinom_2[i];
        }
        for (int i = 0 ; i <= grad_maxim_1 ; i++)
        {
            cout << rezultat_1[i] << " ";
        }
    }
    else
    {
        for (int i = 0 ; i <= grad_maxim_2 ; i++)
        {
            rezultat_1[i] = polinom_1[i] + polinom_2[i];
        }
        for (int i = 0 ; i <= grad_maxim_2 ; i++)
        {
            cout << rezultat_1[i] << " ";
        }
    }

    cout << endl;


    return 0;
}