#pragma once

#include <iostream>
#include <Windows.h>
#include <forward_list>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <conio.h>

using namespace std;

class HelpCenter {
public:

    HelpCenter() { cout << "HelpCenter::Constructor" << endl; }
    ~HelpCenter() { cout << "HelpCenter::Destructor" << endl; }

    void printAll() {
        f1->reverse();
        auto p = vec->begin();
        for (auto i = f1->begin(); i != f1->end(); i++) {
            cout << "  " << i->first << ":" << endl;
            for (int i = 0; i < p->size(); i++) { // vec->size() == vec[0][] 
                cout << " 1." << i + 1 << " " << p->at(i) << endl;
            }
            p++;
        }
    }
    void findHelp(string name) {
        f1->reverse();
        auto result = find_if(f1->begin(), f1->end(), [&name](const pair<string, vector<vector<string>>>& element) {
            return element.first == name;
            });

        if (result == f1->end()) {
            cout << "Термін не знайдено!";
        }
        else {
            cout << "Термін Знайдено !\n" << endl;

            cout << "  " << result->first << ":" << endl;
            for (int i = 0; i < result->second.begin()->size(); i++) {
                cout << " 1" << "." << i << " " << result->second.begin()->at(i) << endl;
            }
        }
    }

    void addHelp(const unique_ptr<vector<vector<string>>>& vec, string& key) {
        f1->push_front(make_pair(key, *vec));
    };


protected:
    unique_ptr<vector<vector<string>>> vec = make_unique<vector<vector<string>>>();
    unique_ptr<forward_list<pair<string, vector<vector<string>>>>> f1 = make_unique<forward_list<pair<string, vector<vector<string>>>>>();
};

class Menu : public HelpCenter {
public:
    void mainMenu() {
        int choice = 0;
        cout << "1. Добавити новий термін" << endl;
        cout << "2. Вивести всі терміни" << endl;
        cout << "3. Знайти термін" << endl;
        cout << "  Your choice -> ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            addTerm();
        }
        if (choice == 2) {
            system("cls");
            printAll();
            cout << "\n" << "Press any button to continue ...";
            (void)_getch();
            system("cls");
            mainMenu();

        }
        if (choice == 3) {
            system("cls");
            string name;
            cout << "Введіть термін який шукаєте: ";
            getline(cin >> ws, name);
            findHelp(name);
            cout << "\n" << "Press any button to continue ...";
            (void)_getch();
            system("cls");
            mainMenu();

        }
        if (choice < 1 || choice > 3) {

        }
    }

    void addTerm() {
        string key;
        string exp;
        cout << "Введіть ключове слово ";
        getline(cin >> ws, key);
        cout << "Введіть пояснення до слова (не більше 5 рядків). Для завершення введіть 0" << endl;

        vec->push_back({});
        auto p = vec->end() - 1;

        for (int i = 0; i < 5; i++) {
            getline(cin >> ws, exp);
            if (exp != "0") {
                p->push_back(exp);
            }
            else {
                cout << endl;
                break;
            }
        }

        addHelp(vec, key);
        system("cls");
        mainMenu();
    }

};
