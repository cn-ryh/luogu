// P1789 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
    int hx[13] = {0,-1,0,1,-2,-1,0,1,2,-1,0,1,0};
    int hy[13] = {-2,-1,-1,-1,0,0,0,0,0,1,1,1,2};
    int yx[25] = {-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2};
    int yy[25] = {-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,0,1,1,1,1,1,2,2,2,2,2};
    int n;
    cin>>n;
    bool maps[n][n];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            maps[i][j] = true;
        }
    }
    int hn,yn;
    cin>>hn;
    cin>>yn;
    for(int i = 0; i<hn; i++)
    {
        int x,y;
        cin>>x>>y;
        for(int j = 0; j<13; j++)
        {
            int tx = x+hx[j]-1;
            int ty = y+hy[j]-1;
            if(tx>=0 && tx<n&&ty>=0&&ty<n)
            {
                maps[tx][ty]=false;
            }
        }
    }

    for(int i = 0; i<yn; i++)
    {
        int x,y;
        cin>>x>>y;
        for(int j = 0; j<25; j++)
        {
            int tx = x+yx[j]-1;
            int ty = y+yy[j]-1;
            if(tx>=0 && tx<n&&ty>=0&&ty<n)
            {
                maps[tx][ty]=false;
            }
        }
    }
    int flag = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(maps[i][j])
            {
                flag++;
            }
        }
    }
    cout<<flag<<endl;
}
