// ChatGPT_Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// TODO: Wanted to show permissions but it requires additional function, TBD in the future (ex. 9)

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <sstream>
#include <vector>
#include <random>
#include <functional>
#include <algorithm>
#include <chrono>
#include <map>
#include <regex>
#include <thread>
#include <numeric>
#include <bitset>
#include <random>
#include <iterator>
#include <locale>
#include <time.h>
#include <tuple>
#include <queue>

void simple_task(std::string msg)
{
    std::cout << msg << std::endl;
}

int main()
{
    // 1st exercise - Read data from a file
    // We assume that file does exist in the system for simplicity of this exercise
    std::string fileText;
    std::ifstream fileRead("Test.txt");
    while (std::getline(fileRead, fileText))
    {
        std::cout << fileText << std::endl;
    }
    fileRead.close();

    // 2nd exercise - Sorting vector
    std::vector<int> vecContainer{ 5,20,30,40,11,23 };
    std::sort(vecContainer.begin(), vecContainer.end());
    std::cout << "\nFirst sorting (ascending): ";
    for (auto element : vecContainer)
    {
        std::cout << " " << element << " ";
    }
    std::cout << "\nSecond sorting (descending): ";
    std::sort(vecContainer.begin(), vecContainer.end(), std::greater<int>());
    for (auto element : vecContainer)
    {
        std::cout << " " << element << " ";
    }

    // 3rd exercise - User input to uppercase (two options)
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

    // 4th exercise - Finding element in a vector
    std::vector<int>::iterator it;
    it = std::find(vecContainer.begin(), vecContainer.end(), 2);
    if (it != vecContainer.end())
        std::cout << "\nElement found in myvector: " << *it << '\n';
    else
        std::cout << "\nElement not found in myvector\n";

    // 5th exercise - Measuring time it takes to execute a piece of code
    auto start = std::chrono::steady_clock::now();
    // some action
    std::cout << "\nShowing some text" << std::endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_sec = end - start;
    std::cout << "Elapsed time: " << elapsed_sec.count() << std::endl;

    // 6th exercise - map usage
    std::map<std::string, int> wordCountMap;
    std::istringstream textStream(fileText);
    std::string word;
    std::cout << fileText << std::endl;
    while (textStream >> word)
    {
        wordCountMap[word]++;
    }
    for (const auto& element : wordCountMap)
    {
        std::cout << element.first << ": " << element.second << std::endl;
    }

    // 7th exercise - regex to validate email address
    std::string valid_mail = "test.2l@gmail.com";
    std::string wrong_mail = "test.lgmail@com";
    std::regex regex_pattern(R"([_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4}))");
    if (std::regex_match(wrong_mail, regex_pattern))
    {
        std::cout << "\ngood mail" << std::endl;
    }
    else
    {
        std::cout << "\nwrong mail" << std::endl;
    }

    // 8th exercise - thread library to perform an action in parallel
    std::thread thread1(simple_task, "First thread");
    std::thread thread2(simple_task, "Second thread");
    std::cout << "Thread 1 id: " << thread1.get_id() << "\n" << "Thread 2 id: " << thread2.get_id() << std::endl;
    thread2.detach();
    std::cout << "\nThread test" << std::endl;
    //thread2.join();
    thread1.join();

    // 9th exercise - use filesystem to list files in a directory
    std::string my_path = "C:\\Users\\Azmuth";
    for (const auto file : std::filesystem::directory_iterator(my_path))
    {
        std::cout << file.path() << std::endl;
    }

    // 10th exercise - numeric library to calculate sum a list of numbers
    int sum = std::accumulate(vecContainer.begin(), vecContainer.end(), 0);
    std::cout << "\nSum of numbers in a vector: " << sum << std::endl;

    // 11th exercise - bitset library to perform binary operations
    std::bitset<4> bitset1{ 0b1110 };
    std::bitset<4> bitset2{ 0b1011 };

    std::cout << "Bitset1: " << bitset1 << " Bitset2: " << bitset2 << std::endl;
    std::cout << "And operation: " << (bitset1 & bitset2) << std::endl;
    std::cout << "Or operation: " << (bitset1 | bitset2) << std::endl;
    bitset1 |= 0b0001;
    std::cout << "Bitset1: " << bitset1 << std::endl;

    // 12th exercise - random library to generate password
    const char alphanum[] = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int pass_length = 20;
    srand(time(0));
    for (int i = 0; i < pass_length; i++)
    {
        std::cout << alphanum[rand() % sizeof(alphanum) - 1];
    }
    std::cout << "\n";

    // 13th exercise - fstream library to write data to a file
    std::ofstream fileWrite;
    fileWrite.open("TestWrite.txt");
    fileWrite << "This is a very simple text to be put in the file called TestWrite just to see if it works \n";
    fileWrite.close();

    // 14th exercise - iterator library to reverse the order of elements in a vector
    std::vector<int> vecTest{ 5,20,30,40,11,23 };
    std::cout << "Original vector: ";
    for (int x : vecTest) 
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::reverse(vecTest.begin(), vecTest.end());

    std::cout << "Reversed vector: ";
    for (int x : vecTest) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // 15th exercise - locale library to format numbers and dates according to the user's location
    std::locale userSetting("en_US.UTF-8");
    double testNum = 1234567.01;
    std::cout.imbue(userSetting);
    std::cout << "Formatted number: " << std::fixed << std::setprecision(4) << testNum << std::endl;

    std::time_t now = std::time(nullptr);
    std::tm timeinfo;
    localtime_s(&timeinfo, &now);
    std::cout << "Formatted date: " << std::put_time(&timeinfo, "%c") << std::endl;

    // 16th exercise - tuple class to store and manipulate a set of values
    std::tuple<std::string, int> tupleProd = std::make_tuple("Test Prod", 5);
    //Display values
    std::cout << "Product name: " << std::get<0>(tupleProd) << std::endl;
    std::cout << "Product value: " << std::get<1>(tupleProd) << std::endl;
    //Change value and show it
    std::get<1>(tupleProd) = 12;
    std::cout << "Product name: " << std::get<0>(tupleProd) << std::endl;
    std::cout << "Product value: " << std::get<1>(tupleProd) << std::endl;

    // 17th exercise - queue container to simulate a line of customers at a store
    std::queue<std::string> queueTest;
    queueTest.push("John");
    queueTest.push("Alice");
    queueTest.push("Bob");
    queueTest.push("Tom");

    std::cout << "Initial line of customers:" << std::endl;
    while (!queueTest.empty()) {
        std::cout << queueTest.front() << std::endl;
        queueTest.pop();
    }
    //std::cout << queueTest.front() << std::endl;


    return 0;
}
