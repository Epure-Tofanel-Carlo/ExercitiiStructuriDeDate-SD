#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[n],i,sorted = 0,j,v2[n],v3[n],element;
    cin>>element;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        v2[i] = v[i];
        v3[i] = v[i];

    }
    // bubble sort
    while (sorted == 0)
    {
        sorted = 1;
        for (i = 0; i < n-1; i++)
        {

            if (v[i] > v[i+1])
            {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                sorted = 0;
            }
        }

    }
    for (i = 0; i < n; i++)
    {
        cout << v[i]<<" ";
    }
    cout<<endl;




    //insertion sort
    for(i = 1 ; i < n ; i++)
    {
        int p = i;

        while(p > 0 && v2[p] < v2[p-1])
        {
            int aux = v2[p];
            v2[p] = v2[p-1];
            v2[p-1] = aux;
            p--;
        }

    }
    for (i = 0; i < n; i++)
    {
        cout << v2[i]<<" ";
    }
    cout<<endl;


    //selection sort
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(v3[i] < v3[j])
            {
                int aux = v3[i];
                v3[i] = v3[j];
                v3[j] = aux;
            }

    for (i = 0; i < n; i++)
    {
        cout << v3[i]<<" ";
    }
    cout<<endl;

    //cautare secventiala pentru element
    int poz = -1;
    for (i = 0 ; i < n; i++)
    {
        if (v[i] == element )
        {

            poz = i;

            break;
        }
    }

    cout << poz << endl;

    //cautare binara

    int stg = 0, dr = n-1;
    poz = n;
    while (stg <= dr)
    {
        int mij = (stg + dr) / 2;
        if (v[mij] >= element)
        {
            poz = mij;
            dr = mij - 1;
        }
        else stg = mij + 1;
    }
    if (v[poz] == element)
        cout << poz;
    else cout << -1;


    return 0;

}

