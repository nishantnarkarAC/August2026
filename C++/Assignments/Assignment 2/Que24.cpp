#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int level = 1;

class Entity
{
private:
    string name;
    int health;
    int level;
    string type;

public:

    Entity& setName(const string& name)
    {
        this->name = name;
        return *this;
    }

    Entity& setHealth(int health)
    {
        this->health = health;
        return *this;
    }

    Entity& setLevel(int level)
    {
        this->level = level;
        return *this;
    }

    Entity& setType(const string& type)
    {
        this->type = type;
        return *this;
    }

    string getName() const
    {
        return name;
    }

    int getHealth() const
    {
        return health;
    }

    int getLevel() const
    {
        return level;
    }

    string getType() const
    {
        return type;
    }

    void displayInfo() const
    {
        cout << "Name   : " << name << endl;
        cout << "Health : " << health << endl;
        cout << "Level  : " << level << endl;
        cout << "Type   : " << type << endl;
    }
};

namespace Physics
{
    double clamp(double val, double min, double max)
    {
        if (val < min)
            return min;

        if (val > max)
            return max;

        return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}

namespace GameMath
{
    int clamp(int val, int min, int max)
    {
        if (val < min)
            return min;

        if (val > max)
            return max;

        return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}



namespace Engine
{
    namespace Audio
    {
        void playSound(string name)
        {
            cout << "Playing: " << name << endl;
        }
    }
}



int main()
{


    Entity player, enemy, item;

    player.setName("Aragorn")
          .setHealth(100)
          .setLevel(10)
          .setType("Player");

    enemy.setName("Orc")
         .setHealth(60)
         .setLevel(5)
         .setType("Enemy");

    item.setName("HealthPotion")
        .setHealth(0)
        .setLevel(1)
        .setType("Item");


    cout << "===== ENTITY INFORMATION =====" << endl;

    cout << "\nPlayer:" << endl;
    player.displayInfo();

    cout << "\nEnemy:" << endl;
    enemy.displayInfo();

    cout << "\nItem:" << endl;
    item.displayInfo();



    cout << "\n===== NAMESPACE DEMO =====" << endl;

    cout << "Physics Clamp : "
         << Physics::clamp(120.5, 0.0, 100.0)
         << endl;

    cout << "GameMath Clamp : "
         << GameMath::clamp(120, 0, 100)
         << endl;

    cout << "Physics Lerp : "
         << Physics::lerp(0, 100, 0.5)
         << endl;

    cout << "GameMath Lerp : "
         << GameMath::lerp(20, 40, 0.25)
         << endl;


    
    {
        using namespace Physics;

        cout << "Limited Scope Lerp : "
             << lerp(10, 20, 0.5)
             << endl;
    }



    int R, C;

    cout << "\nEnter rows and columns: ";
    cin >> R >> C;

    srand(time(0));

    
    int** gameMap = new int*[R];

    
    for (int i = 0; i < R; i++)
    {
        gameMap[i] = new int[C];
    }


    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            gameMap[i][j] = rand() % 5;
        }
    }



    cout << "\n===== GAME MAP ("
         << R << " x " << C
         << ") =====" << endl;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << gameMap[i][j] << " ";
        }

        cout << endl;
    }

    
    cout << "\nLegend: "
         << "0=Grass "
         << "1=Water "
         << "2=Mountain "
         << "3=Forest "
         << "4=Dungeon"
         << endl;


    int count[5] = {0};

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            count[gameMap[i][j]]++;
        }
    }


    cout << "\nTile Count:" << endl;

    cout << "Grass    : " << count[0] << endl;
    cout << "Water    : " << count[1] << endl;
    cout << "Mountain : " << count[2] << endl;
    cout << "Forest   : " << count[3] << endl;
    cout << "Dungeon  : " << count[4] << endl;



    for (int i = 0; i < R; i++)
    {
        delete[] gameMap[i];
    }

    delete[] gameMap;



    int level = 10;

    cout << "\n===== SCOPE RESOLUTION =====" << endl;

    cout << "Local level  : " << level << endl;
    cout << "Global level : " << ::level << endl;


    Engine::Audio::playSound("sword_clash");


    return 0;
}