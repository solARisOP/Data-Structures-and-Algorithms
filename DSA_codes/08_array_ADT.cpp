#include <iostream>
using namespace std;

class array
{
protected:
    int total_size;
    int used_size;
    int *arr;

public:

    array(int tsize, int usize)
    {
        total_size = tsize;
        used_size = usize;
        arr = new int[total_size];  
        

        // for (int i = 0; i < used_size; i++)
        // {
        //     cout << "enter the element " << i + 1 << " : "<<endl;
        //     cin >> arr[i];
        // }

        // for (int i = 0; i < used_size; i++)
        // {
        //     cout << arr[i] << endl;
        // }
    }

    void setval()
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << "enter the element " << i + 1 << " : "<<endl;
            cin >> arr[i];
        }
    }

    void show()
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    array marks(20, 5);
    marks.setval();
    marks.show();

    return 0;
}