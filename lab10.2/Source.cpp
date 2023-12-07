#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int CountWords(const string& str)
{
    int count = 0;
    size_t startPos = 0;

    while (true)
    {
        // Знаходимо початок наступного слова
        startPos = str.find_first_not_of(' ', startPos);
        if (startPos == string::npos)
            break;  // Всі слова перевірені

        // Знаходимо кінець поточного слова
        size_t endPos = str.find_first_of(' ', startPos);
        if (endPos == string::npos)
            endPos = str.length();

        // Перевіряємо, чи перший і останній символ співпадають
        if (str[startPos] == str[endPos - 1])
            count++;

        startPos = endPos;  // Переходимо до наступного слова
    }

    return count;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream inputFile("t.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening file" << endl;
        return 1; // Помилка відкриття файлу
    }

    string input;
    getline(inputFile, input);

    int wordCount = CountWords(input);
    cout << "кількість слів, у яких перший і останній символ – однакові: " << wordCount << endl;

    inputFile.close();

    return 0;
}
