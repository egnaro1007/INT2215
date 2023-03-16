#include <iostream>
#include <ctime>
using namespace std;

void render(bool** mine, int m, int n);
int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    
    bool **mine;


    for (int i = 0; i < m; i++)
    {
        mine[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {   
            mine[i][j] = new bool;
            mine[i][j] = false;
        }
    }
    
    int numberOfMine = k;
    while (numberOfMine > 0)
    {
        int x = rand() % n;
        int y = rand() % m;

        if (mine[x][y] == false) {
            mine[x][y] = true;
            numberOfMine--;
        }
    }
    
    render(mine, m, n);
}

void render(bool** mine, int m, int n) {
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(mine[i][j] == true) std::cout << 'X';
            else std::cout << '*';
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}