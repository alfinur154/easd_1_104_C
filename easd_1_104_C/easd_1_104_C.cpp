//1. Karena agar menyelesaikan suatu masalah dengan cepat, efisien, dan  berurut
//2. Static dan dynamic
//3. faktor mempengaruhinya ialah Data tidak urut, Data kosong
//4. buble short, karena menurut saya ialah
//5. logliner Quick short , Quadratic 
//6. Selection sort             

#include <iostream>
using namespace std;

int Nur[24];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
    while (true)
    {
        cout << "Masukkan panjang Element Array : ";
        cin >> n;

        if (n <= 24)
            break;
        else
            cout << "\nMaksimum panjang array adalah 24" << endl;
    }
    cout << "\n________________________" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "\n________________________" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> Nur[i];
    }
}
void swap(int x, int y)
{
    int temp;

    temp = Nur[x];
    Nur[x] = Nur[y];
    Nur[y] = temp;

}

void q_short(int low, int high)
{
    int pivot, i, al;
    if (low > high)
        return;

    pivot = Nur[low];

    i = low + i;
    al = high;

    while (i <= al)
    {
        while ((Nur[i] <= pivot) && (i <= high))
        {
            i++;
            cmp_count++;
        }
        cmp_count++;

        while ((Nur[al] > pivot) && (al >= low))
        {
            al--;
            cmp_count++;
        }
        cmp_count++;

        if (i < al)
        {
            swap(i, al);
            mov_count++;
        }
    }
    if (low < al)
    {
        swap(low, al);
        mov_count++;
    }
    q_short(low, al);

    q_short(al + 1, high);
}
void display() {
    cout << "\n___________________" << endl;
    cout << "Sorted Array" << endl;
    cout << "\n___________________" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << Nur[i] << " ";
    }

    cout << "\n\nNumber of comparassions: " << cmp_count << endl;
    cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
    input();
    q_short(0, n - 1);
    display();
    system("pause");

    return 0;
}
