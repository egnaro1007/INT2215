#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Game {
private:
    int rows, cols, mines;
    bool **mine;
    char **board;
public:
    void init(int m, int n, int k);
    void render();
    void update();
    void over();
};

int main(int argc, const char * argv[])
{
    Game game;
    srand(time(NULL));

    int m, n, k;
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    k = atoi(argv[3]);
    
    game.init(m, n, k);

    while (true)
    {
        game.render();
        game.update();
    }
}

void Game::init(int m, int n, int k){
    rows = m;
    cols = n;
    mines = k;

    board = new char*[m];
    for (int i = 0; i < m; i++)
    {
        board[i] = new char[n];
        for (int j = 0; j < n; j++)
        {   
            board[i][j] = '*';
        }
    }

    mine = new bool*[m];
    for (int i = 0; i < m; i++)
    {
        mine[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {   
            mine[i][j] = false;
        }
    }
    
    int numberOfMine = k;
    while (numberOfMine > 0)
    {
        int x = rand() % m;
        int y = rand() % n;

        if (mine[x][y] == false) {
            mine[x][y] = true;
            numberOfMine--;
        }
    }
}

void Game::render() {
    system("cls");
    std::cout << "+";
    for (int j = 0; j < cols; j++)
    {
        std::cout << "--";
    }
    std::cout << "+\n";

    for (int i = 0; i < rows; i++)
    {
        std::cout << "|";
        for (int j = 0; j < cols; j++)
        {
            std::cout << board[i][j];
            std::cout << ' ';
        }
        std::cout << "|\n";
    }

    std::cout << "+";
    for (int j = 0; j < cols; j++)
    {
        std::cout << "--";
    }
    std::cout << "+\n";
}

void Game::update() {
    int x, y;
    std::cin >> x >> y;
    x--;
    y--;
    if (mine[x][y] == true) {
        over();
    }
    else {
        int value = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (x + i >= 0 && x + i < rows && y + j >= 0 && y + j < cols)
                {
                    if (mine[x + i][y + j] == true) value++;
                }
            }
        }
        board[x][y] = value + '0';
    }
}

void Game::over() {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mine[i][j] == true) board[i][j] = 'X';
        }
    }
    render();
    std::cout <<"YOU'RE DEAD!\n";
    exit(0);
}