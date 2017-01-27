#include <bits/stdc++.h>

using namespace std;

bool Check(vector<vector<char> > arr,char val)
{
    int c1 = 0,
        c2 = 0,
        c3 = 0,
        c4 = 0;

    for(int i = 0;i < 3;i++)
    {
        if(arr[i][i] == val)
            c1++;
        if(arr[2-i][i] == val)
            c2++;
        c3 = 0;
        c4 = 0;
        for(int j = 0;j < 3;j++)
        {
            if(arr[i][j] == val)
                c3++;
            if(arr[j][i] == val)
                c4++;
        }
        if(c3 == 3 || c4 == 3)
            return true;
    }

    if(c1 == 3 || c2 == 3)
        return true;
    else
        return false;
}

int main()
{
    int row,col;
    int Count=0 ;
    bool p1 = true;

    vector<vector<char> > xo(3,vector<char> (3));

    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            xo[i][j] = ' ';
        }
    }
    cout<<"------------"<<endl;
    for(int i =0; i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            if(j == 0)
                cout<<" "<<xo[i][j]<<" | ";
            else
                cout<<xo[i][j]<<" | ";
        }
        cout<<"\n------------\n";
    }
    while(true)
    {
        cin>>row>>col;
        Count++ ;
        if(row > 3 || col > 3 || row < 1 || col < 1 || xo[row-1][col-1] != ' ')
        {
            cout<<"Invalid Input"<<endl;
            continue;
        }
        system("CLS");
        if(p1)
            xo[row-1][col-1] = 'x';
        else
            xo[row-1][col-1] = 'o';

        cout<<"------------"<<endl;
        for(int i =0; i < 3;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                if(j == 0)
                    cout<<" "<<xo[i][j]<<" | ";
                else
                    cout<<xo[i][j]<<" | ";
            }
            cout<<"\n------------\n";
        }
        if(p1)
        {
            if(Check(xo,'x'))
            {
                cout<<"Player 1 Won"<<endl;
                break;
            }
            p1 = false;
        }
        else
        {
            if(Check(xo,'o'))
            {
                cout<<"Player 2 Won"<<endl;
                break;
            }
            p1 = true;
        }
        if (Count > 8 && Check(xo,'x') == 0) { cout << "TIE" << endl ; break ; }
        if (Count > 8 && Check(xo,'o') == 0) { cout << "TIE" << endl ; break ; }
    }
    return 0;
}
