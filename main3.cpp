#include <iostream>
#include <locale>
#define MAX 20
using namespace std;

class bankers
{
    private:
        // Матрица текущего распределения ресурсов для каждого процесса
        int al[MAX][MAX];
        // Матрица максимальных требований ресурсов для каждого процесса
        int m[MAX][MAX];
        // Матрица необходимого количества ресурсов (разница между максимальными требованиями и текущим распределением)
        int n[MAX][MAX];
        // Массив доступных ресурсов
        int avail[MAX];
        // Количество процессов
        int nop;
        // Количество ресурсов
        int nor;
        // Счетчик для безопасного порядка выполнения процессов
        int k;
        // Массив для хранения безопасного порядка выполнения процессов
        int result[MAX];
        // Номер процесса
        int pnum;
        // Массив для хранения текущих доступных ресурсов
        int work[MAX];
        // Массив флагов завершения процессов
        int finish[MAX];

    public:
        // Конструктор класса, инициализирующий переменные
        bankers();
        // Метод для ввода данных о процессах и ресурсах
        void input();
        // Основной метод, реализующий алгоритм банкира
        void method();
        // Метод для проверки, можно ли удовлетворить запросы процесса
        int search(int);
        // Метод для вывода результатов
        void display();
};

// Конструктор класса, инициализирует все массивы и переменные
bankers::bankers()
{
    k = 0; // Инициализация счетчика для безопасного порядка выполнения процессов
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            al[i][j] = 0; // Инициализация матрицы текущего распределения ресурсов
            m[i][j] = 0;  // Инициализация матрицы максимальных требований ресурсов
            n[i][j] = 0;  // Инициализация матрицы необходимого количества ресурсов
        }
        avail[i] = 0;  // Инициализация массива доступных ресурсов
        result[i] = 0; // Инициализация массива результатов
        finish[i] = 0; // Инициализация массива флагов завершения процессов
    }
}

void bankers::input()
{
    int i, j;
    cout << "Введите количество процессов:";
    cin >> nop;
    cout << "Введите количество ресурсов:";
    cin >> nor;
    cout << "Введите выделенные ресурсы для каждого процесса: " << endl;
    for (i = 0; i < nop; i++)
    {
        cout << "\nПроцесс " << i;
        for (j = 0; j < nor; j++)
        {
            cout << "\nРесурс " << j << ":";
            cin >> al[i][j];
        }
    }
    cout << "Введите максимальные ресурсы, необходимые для каждого процесса: " << endl;
    for (i = 0; i < nop; i++)
    {
        cout << "\nПроцесс " << i;
        for (j = 0; j < nor; j++)
        {
            cout << "\nРесурс " << j << ":";
            cin >> m[i][j];
            n[i][j] = m[i][j] - al[i][j]; // Вычисление необходимого количества ресурсов
        }
    }
    cout << "Введите текущие доступные ресурсы в системе: ";
    for (j = 0; j < nor; j++)
    {
        cout << "Ресурс " << j << ":";
        cin >> avail[j];
        work[j] = -1; // Инициализация массива текущих доступных ресурсов
    }
    for (i = 0; i < nop; i++)
        finish[i] = 0; // Инициализация флагов завершения процессов
}

void bankers::method()
{
    int i = 0, j, flag;
    while (1)
    {
        if (finish[i] == 0) // Если процесс еще не завершен
        {
            pnum = search(i); // Проверка, можно ли удовлетворить запросы процесса
            if (pnum != -1) // Если запросы могут быть удовлетворены
            {
                result[k++] = i; // Добавление процесса в безопасный порядок
                finish[i] = 1; // Помечаем процесс как завершенный
                for (j = 0; j < nor; j++)
                {
                    avail[j] = avail[j] + al[i][j]; // Освобождение ресурсов, выделенных процессу
                }
            }
        }
        i++;
        if (i == nop) // Если прошли все процессы
        {
            flag = 0;
            for (j = 0; j < nor; j++)
                if (avail[j] != work[j]) // Проверка, изменились ли доступные ресурсы
                    flag = 1;
            for (j = 0; j < nor; j++)
                work[j] = avail[j]; // Обновление текущих доступных ресурсов

            if (flag == 0) // Если доступные ресурсы не изменились, завершаем цикл
                break;
            else
                i = 0; // Иначе, начинаем проверку сначала
        }
    }
}

int bankers::search(int i)
{
    int j;
    for (j = 0; j < nor; j++)
        if (n[i][j] > avail[j]) // Проверка, достаточно ли доступных ресурсов для удовлетворения запросов процесса
            return -1; // Если недостаточно, возвращаем -1
    return 0; // Если достаточно, возвращаем 0
}

void bankers::display()
{
    int i, j;
    cout << endl << "ВЫВОД:";
    cout << endl << "========";
    cout << endl << "ПРОЦЕСС\t     ВЫДЕЛЕНО\t     МАКСИМУМ\t     НУЖНО";
    for (i = 0; i < nop; i++)
    {
        cout << "\nP" << i + 1 << "\t     ";
        for (j = 0; j < nor; j++)
        {
            cout << al[i][j] << "  ";
        }
        cout << "\t     ";
        for (j = 0; j < nor; j++)
        {
            cout << m[i][j] << "  ";
        }
        cout << "\t     ";
        for (j = 0; j < nor; j++)
        {
            cout << n[i][j] << "  ";
        }
    }
    cout << "\nПоследовательность безопасных процессов: \n";
    for (i = 0; i < k; i++)
    {
        int temp = result[i] + 1;
        cout << "P" << temp << " ";
    }
    cout << "\nПоследовательность небезопасных процессов: \n";
    int flg = 0;
    for (i = 0; i < nop; i++)
    {
        if (finish[i] == 0)
        {
            flg = 1;
        }
        cout << "P" << i << " ";
    }
    cout << endl << "РЕЗУЛЬТАТ:";
    cout << endl << "=======";
    if (flg == 1)
        cout << endl << "Система не находится в безопасном состоянии и может возникнуть тупик!!";
    else
        cout << endl << "Система находится в безопасном состоянии и тупик не возникнет!!";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << " АЛГОРИТМ БАНКИРА " << endl;
    bankers B;
    B.input();
    B.method();
    B.display();
}