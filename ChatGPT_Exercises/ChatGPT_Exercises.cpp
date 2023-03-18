// ChatGPT_Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <string>
#include <algorithm>
#include <chrono>

int main()
{
    std::vector<int> vecContainer{ 5,20,30,40,11,23 };
    std::sort(vecContainer.begin(), vecContainer.end());
    std::cout << "First sorting: ";
    for (auto element : vecContainer)
    {
        std::cout << " " << element << " ";
    }
    std::cout << "\nSecond sorting: ";
    std::sort(vecContainer.begin(), vecContainer.end(), std::greater<int>());
    for (auto element : vecContainer)
    {
        std::cout << " " << element << " ";
    }

    std::cout << std::endl;
    std::string input;
    int offset = 32;
    std::cin >> input;
    for (char ch : input)
    {
        //FIRST OPTION
        //std::cout << "Char: " << ch << " Uppercase: "<< (char)toupper(ch) << std::endl;

        //SECOND OPTION
        if (ch > 96 && ch < 123)
        {
            std::cout << (char)(ch - offset);
        }
        else
        {
            std::cout << ch;
        }
    }

    std::vector<int>::iterator it;
    it = std::find(vecContainer.begin(), vecContainer.end(), 2);
    if (it != vecContainer.end())
        std::cout << "\nElement found in myvector: " << *it << '\n';
    else
        std::cout << "\nElement not found in myvector\n";

    auto start = std::chrono::steady_clock::now();
    // some action
    std::cout << "\nShowing some text" << std::endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_sec = end - start;
    std::cout << "Elapsed time: " << elapsed_sec.count() << std::endl;
    return 0;
}
