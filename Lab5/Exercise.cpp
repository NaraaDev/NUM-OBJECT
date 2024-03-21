#include <iostream>
using namespace std;

class Employee
{
public:
    int no;
    char *name;
    char *position;
    float hour;
    Employee(){
        name = new char[4];
        strcpy(name, "test");
        position = new char[7];
        strcpy(position, "ажилчин");
        no = 0;
        hour = 0;
    }

    Employee(int num, char *n, char *p, float h){
        no = num;
        hour = h;
        name = new char[strlen(n)+1];
        strcpy(name, n);
        position = new char[strlen(p)+1];
        strcpy(position, p);
    }

    ~Employee(){
        cout<< "The employee with " << no << " no is deleted"<<endl;
        delete []name;
        delete []position;
    }

     void copy(Employee &emp){
        if(name != NULL){
            delete []name;
        }
        if(position != NULL){
            delete []position;
        }
        name = new char[strlen(emp.name)+1];
        strcpy(name, emp.name);
        position = new char[strlen(emp.position)+1];
        strcpy(position, emp.position);
        no = emp.no;
        hour = emp.hour;
    }

    void get()
    {
        string n(name);
        string p(position);
        cout << "Дугаар: " << no << endl;
        cout << "Нэр: " << n  << endl;
        cout << "Албан тушаал: " <<p << endl;
        cout << "Ажилласан цаг: " << hour << endl;
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
    int n;
    cout<<"Ажилчдын тоог оруулна уу"<<endl;
    cin>>n;
    Employee *arr[n];
    for(int i=0;i<n;i++){
        char name[20],position[20];
        int id;
        float hour;
        cout<<i<<"-р ажилчны мэдээллийг оруулна уу"<< endl;
        cin>>name>>position>>id>>hour;
        bool id_unique = true;
        for(int j=0;j<i;j++){
            if(arr[j]->no == id){
                id_unique = false;
            }
        }
        if(!id_unique){
            cout<< "Ижил id тай тул , өөр id оруулна уу"<<endl;
        }else{
            arr[i] = new Employee(id,name,position,hour);
        }
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(!strcmp(arr[i]->name,arr[j]->name)){
                Employee &temp = *arr[i];
                arr[i]->copy(*arr[j]);
                arr[j]->copy(temp);
            }
        }
    }
    for(int i=0;i<n;i++){
        string name(arr[i]->name);
        cout<<name<<endl;
    }
    
    return 0;
}
