#include <iostream>
using namespace std;

class Employee
{
public:
    int id;
    string name;
    string position;
    float hour;

    void set_default()
    {
        id = 0;
        name = "";
        position = "ажилчин";
        hour = 0;
    }

    void set(int setId, string setName, string setPosition, float setHour)
    {
        id = setId;
        name = setName;
        position = setPosition;
        hour = setHour;
    }

    void get()
    {
        cout << "Дугаар: " << id << '\n';
        cout << "Нэр: " << name << '\n';
        cout << "Албан тушаал: " << position << '\n';
        cout << "Ажилласан цаг: " << hour << '\n';
    }

    float director_salary() 
    {
        return hour * 6000;
    }

    float calculate_salary()
    {
        float salary = hour * 5500;
        if (position == "захирал")
        {
            salary += director_salary();
        }
        return salary;
    }

    bool add_hour(float h)
    {
        if (0 <= h && h <= 24)
        {
            hour += h;
            return true;
        }
        return false;
    }
};

int main()
{
    Employee workerBat, workerBold;
    workerBat.set(1, "Бат", "ажилчин", 0);
    workerBold.set(2, "Болд", "захирал", 10);
    workerBat.get();
    workerBold.get();
    workerBat.add_hour(10);
    workerBat.get();
    cout << workerBat.calculate_salary() << '\n';
    cout << workerBold.calculate_salary() << '\n';
    return 0;
}
