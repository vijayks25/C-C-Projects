#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int gridSize = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = gridSize / 2;
    y = gridSize / 2;
    fruitX = rand() % gridSize;
    fruitY = rand() % gridSize;
    score = 0;
}

void Draw()
{
    system("cls");
    for (int i = 0; i < gridSize + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (j == 0 || j == gridSize - 1)
                cout << "#";
            else if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
                cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < gridSize + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 72: dir = UP; break;    // Up arrow key (Page Up)
        case 80: dir = DOWN; break;  // Down arrow key (Page Down)
        case 75: dir = LEFT; break;  // Left arrow key
        case 77: dir = RIGHT; break; // Right arrow key
        case 'x': gameOver = true; break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i]; prev2Y = tailY[i];
        tailX[i] = prevX; tailY[i] = prevY;
        prevX = prev2X; prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT: x--; break;
    case RIGHT: x++; break;
    case UP: y--; break;
    case DOWN: y++; break;
    }

    if (x >= gridSize) x = 0; else if (x < 0) x = gridSize - 1;
    if (y >= gridSize) y = 0; else if (y < 0) y = gridSize - 1;
}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(100); // Add a slight delay between frames (100 milliseconds)
    }
    return 0;
}
