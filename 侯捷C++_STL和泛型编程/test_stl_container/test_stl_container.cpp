/* 关于侯捷老师讲解STL标准库-容器
 * array/vector/list/forward_list/deque属于sequence containers
 * set/multiset/map/multimap属于associative containers
 * unordered_set/unordered_multimap/unordered_map/unordered_multimap属于hashTable Separate Chaining
*/

#include <iostream>
#include <array>
#include <cstdlib> //RAND_MAX
#include <ctime>

// using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::string;

long get_a_target_long()
{
    long target = 0;
    cout << "target (0~" << RAND_MAX << ")" << endl;
    cin >> target;
    return target;
}

string get_a_target_string()
{
    int target = 0;
    char buf[10];

    cout << "target (0~" << RAND_MAX << ")";
    cin >> target;
    snprintf(buf, 10, "%d", target);
    return string(buf);
}

// a大于b
int compareLongs(const void *a, const void *b)
{
    return (*(long *)a - *(long *)b);
}

// 字符串大小对比
int compareStrings(const void *a, const void *b)
{
    if (*(string *)a < *(string *)b)
        return 1;
    else if (*(string *)a < *(string *)b)
        return -1;
    else
        return 0;
}

using namespace std;
namespace jj01
{
    void test_array()
    {
        // using namespace std;
        const int ASIZE = 1000000;
        cout << "\ntest_array()......\n";
        // cout << "input size of array: " << endl;
        // cin >> ASIZE;
        array<long, ASIZE> c;
        clock_t timeStart = clock();
        for (long i = 0; i < ASIZE; ++i)
        {
            c[i] = rand();
        }
        cout << "milli-seconds: " << clock() - timeStart << endl;
        cout << "array.size()= " << c.size() << endl;
        cout << "arrat.front()= " << c.front() << endl;
        cout << "arrat.back()= " << c.back() << endl;
        cout << "arrat.data()= " << c.data() << endl;

        long target = get_a_target_long();
        timeStart = clock();
        qsort(c.data(), ASIZE, sizeof(long), compareLongs);
        long *pItem = (long *)bsearch(&target, c.data(), ASIZE, sizeof(long), compareLongs);
        if (pItem != NULL)
            cout << "found, " << *pItem << endl;
        else
            cout << "not found!" << endl;
    }
}

#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

namespace jj02
{
    void test_vector(long &value)
    {
        cout << "\ntest_vector()......\n";
        vector<string> c;
        char buf[10];

        clock_t timeStart = clock();
        for (long i = 0; i < value; ++i)
        {
            try
            {
                snprintf(buf, 10, "%d", rand());
                c.push_back(string(buf)); //往尾部插入元素
            }
            catch (exception &e)
            {
                cout << "i = " << i << e.what() << '\n'; //如果内存不够，就会发出std::bad_alloc
                abort();
            }
        }
        cout << "milli-seconds: " << clock() - timeStart << endl;
        cout << "vector.size()= " << c.size() << endl;
        cout << "vector.front()= " << c.front() << endl;
        cout << "vector.back()= " << c.back() << endl;
        cout << "vector.data()= " << c.data() << endl;
        cout << "vector.capacity()= " << c.capacity() << endl;

        string target = get_a_target_string();

        {
            timeStart = clock();
            auto pItem = ::find(c.begin(), c.end(), target); //双冒号代表全局

            cout << "::find, milli-seconds: " << clock() - timeStart << endl;
            if (pItem != c.end())
                cout << "found, " << *pItem << endl;
            else
                cout << "not found!" << endl;
        }

        {
            timeStart = clock();
            sort(c.begin(), c.end());
            string *pItem = (string *)bsearch(&target, c.data(), c.size(), sizeof(string), compareStrings);

            cout << "sort() + bsearch(), milli-seconds: " << clock() - timeStart << endl;
            if (pItem != NULL)
                cout << "found, " << *pItem << endl;
            else
                cout << "not found!" << endl;
        }
    }
}

#include <list>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

namespace jj03
{
    void test_list(long &value)
    {
        cout << "\ntest_list()......\n";
        list<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0; i < value; ++i)
        {
            try
            {
                snprintf(buf, 10, "%d", rand());
                c.push_back(string(buf));
            }
            catch (std::exception &e)
            {
                cout << "i= " << i << e.what() << '\n';
                abort();
            }
        }
        cout << "milli-seconds: " << clock() - timeStart << endl;
        cout << "list.size()= " << c.size() << endl;
        cout << "list.front()= " << c.front() << endl;
        cout << "list.back()= " << c.back() << endl;
        cout << "list.max_size()= " << c.max_size() << endl;

        string target = get_a_target_string();

        {
            timeStart = clock();
            auto pItem = ::find(c.begin(), c.end(), target); //双冒号代表全局

            cout << "::find, milli-seconds: " << clock() - timeStart << endl;
            if (pItem != c.end())
                cout << "found, " << *pItem << endl;
            else
                cout << "not found!" << endl;
        }

        timeStart = clock();
        c.sort();
        cout << "c.sort(), milli-seconds: " << clock() - timeStart << endl;

        // {
        //     timeStart = clock();
        //     sort(c.begin(), c.end());
        //     string *pItem = (string *)bsearch(&target, c.data(), c.size(), sizeof(string), compareStrings);

        //     cout << "sort() + bsearch(), milli-seconds: " << clock() - timeStart << endl;
        //     if (pItem != NULL)
        //         cout << "found, " << *pItem << endl;
        //     else
        //         cout << "not found!" << endl;
    }
}

#include <forward_list>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

namespace jj04
{
    void test_forward_list(long &value)
    {
        cout << "\ntest_forward_list()......\n";
        forward_list<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0; i < value; ++i)
        {
            try
            {
                snprintf(buf, 10, "%d", rand());
                c.push_front(string(buf)); //front_list没有push_back成员函数
            }
            catch (std::exception &e)
            {
                cout << "i= " << i << e.what() << '\n';
                abort();
            }
        }
        cout << "milli-seconds: " << clock() - timeStart << endl;
        // cout << "foward_list.size()= " << c.size() << endl;  //no such member funtion
        cout << "foward_list.front()= " << c.front() << endl;
        // cout << "foward_list.back()= " << c.back() << endl;  //no such member funtion
        cout << "foward_list.max_size()= " << c.max_size() << endl;

        string target = get_a_target_string();

        {
            timeStart = clock();
            auto pItem = ::find(c.begin(), c.end(), target); //双冒号代表全局

            cout << "::find, milli-seconds: " << clock() - timeStart << endl;
            if (pItem != c.end())
                cout << "found, " << *pItem << endl;
            else
                cout << "not found!" << endl;
        }

        timeStart = clock();
        c.sort();
        cout << "c.sort(), milli-seconds: " << clock() - timeStart << endl;
    }
}

#include <deque>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

namespace jj05
{
    void test_deque(long &value)
    {
        cout << "\ntest_deque()......\n";
        deque<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0; i < value; ++i)
        {
            try
            {
                snprintf(buf, 10, "%d", rand());
                c.push_front(string(buf)); //front_list没有push_back成员函数
            }
            catch (std::exception &e)
            {
                cout << "i= " << i << e.what() << '\n';
                abort();
            }
        }
        cout << "milli-seconds: " << clock() - timeStart << endl;
        cout << "deque.size()= " << c.size() << endl;
        cout << "deque.front()= " << c.front() << endl;
        cout << "deque.back()= " << c.back() << endl;
        cout << "deque.max_size()= " << c.max_size() << endl;

        string target = get_a_target_string();

        {
            timeStart = clock();
            auto pItem = ::find(c.begin(), c.end(), target); //双冒号代表全局

            cout << "::find, milli-seconds: " << clock() - timeStart << endl;
            if (pItem != c.end())
                cout << "found, " << *pItem << endl;
            else
                cout << "not found!" << endl;
        }

        timeStart = clock();
        ::sort(c.begin(), c.end());
        cout << "c.sort(), milli-seconds: " << clock() - timeStart << endl;
    }
}

#include <set>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

namespace jj06
{
    void test_multiset(long &value)
    {
        cout << "\ntest_multiset()......\n";
        multiset<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0; i < value; ++i)
        {
            try
            {
                snprintf(buf, 10, "%d", rand());
                c.insert(string(buf));
            }
            catch (std::exception &e)
            {
                cout << "i= " << i << e.what() << '\n';
                abort();
            }
        }

        cout << "milli-seconds: " << clock() - timeStart << endl;
        cout << "multiset.size()= " << c.size() << endl;
        cout << "multiset.max_size()= " << c.max_size() << endl;

        string target = get_a_target_string();

        {
            timeStart = clock();
            auto pItem = ::find(c.begin(), c.end(), target); //双冒号代表全局

            cout << "::find, milli-seconds: " << clock() - timeStart << endl;
            if (pItem != c.end())
                cout << "found, " << *pItem << endl;
            else
                cout << "not found!" << endl;
        }
        {
            timeStart = clock();
            auto pItem = c.find(target);
            cout << "c.find, milli-seconds: " << clock() - timeStart << endl;

            if (pItem != c.end())
                cout << "found, " << *pItem << endl;
            else
                cout << "not found!" << endl;
        }
    }

}

#include <map> //for using multimap container
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
//
using namespace std;

namespace jj07
{
    void test_multimap(long &value)
    {
        cout << "\ntest_multimap()......\n";
        multimap<long, string> c;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0; i < value; ++i)
        {
            try
            {
                snprintf(buf, 10, "%d", rand());
                c.insert(std::pair<long, string>(i, string(buf))); //i作为key, 随机数buf作为value
            }
            catch (std::exception &e)
            {
                cout << "i= " << i << e.what() << '\n';
                abort();
            }
        }
        cout << "milli-seconds: " << clock() - timeStart << endl;
        cout << "multimap.size()= " << c.size() << endl;
        cout << "multimap.max_size()= " << c.max_size() << endl;

        long target = get_a_target_long();

        //查找目标key
        {
            timeStart = clock();
            auto pItem = c.find(target);
            cout << "c.find, milli-seconds: " << clock() - timeStart << endl;

            if (pItem != c.end())
                cout << "found, " << (*pItem).second << endl;
            else
                cout << "not found!" << endl;
        }
    }

}

// stack栈是先进后出，后进先出
#include <stack>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

namespace jj17
{
    void test_stack(long &value)
    {
        cout << "\ntest_stack()......\n";
        stack<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0; i < value; ++i)
        {
            try
            {
                snprintf(buf, 10, "%d", rand());
                c.push(string(buf)); //front_list没有push_back成员函数
            }
            catch (std::exception &e)
            {
                cout << "i= " << i << e.what() << '\n';
                abort();
            }
        }
        cout << "milli-seconds: " << clock() - timeStart << endl;
        cout << "stack.size()= " << c.size() << endl;
        cout << "stack.top()= " << c.top() << endl;

        c.pop();
        cout << "stack.size()= " << c.size() << endl;
        cout << "stack.top()= " << c.top() << endl;
    }
}

// queue队列是先进先出，后进后出
#include <queue>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

namespace jj18
{
    void test_queue(long &value)
    {
        cout << "\ntest_stack()......\n";
        queue<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0; i < value; ++i)
        {
            try
            {
                snprintf(buf, 10, "%d", rand());
                c.push(string(buf)); //front_list没有push_back成员函数
            }
            catch (std::exception &e)
            {
                cout << "i= " << i << e.what() << '\n';
                abort();
            }
        }
        cout << "milli-seconds: " << clock() - timeStart << endl;
        cout << "queue.size()= " << c.size() << endl;
        cout << "queue.front()= " << c.front() << endl;
        cout << "queue.back()= " << c.back() << endl;
        c.pop();
        cout << "queue.size()= " << c.size() << endl;
        cout << "queue.front()= " << c.front() << endl;
        cout << "queue.back()= " << c.back() << endl;
    }
}

void showmenu()
{
    cout << "please enter: 1, 2, 3, 4, 5, 17, 18\n"
            "0)quit\n"
            "1)test_array\t2)test_vector\n"
            "3)test_list\t4)test_forward_list\n"
            "5)test_deque\t17)test_stack\n"
            "18)test_queue\n";
}
int main()
{
    showmenu();
    int choice;
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "select: " << choice << endl;
            using namespace jj01;
            test_array();
            break;
        case 2:
            cout << "select: " << choice << endl;
            using namespace jj02;
            long value_2;
            cout << "how many elements:  " << endl;
            cin >> value_2;
            test_vector(value_2);
            break;
        case 3:
            cout << "select: " << choice << endl;
            using namespace jj03;
            long value_3;
            cout << "how many elements:  " << endl;
            cin >> value_3;
            test_list(value_3);
            break;
        case 4:
            cout << "select: " << choice << endl;
            using namespace jj04;
            long value_4;
            cout << "how many elements:  " << endl;
            cin >> value_4;
            test_forward_list(value_4);
            break;
        case 5:
            cout << "select: " << choice << endl;
            using namespace jj05;
            long value_5;
            cout << "how many elements:  " << endl;
            cin >> value_5;
            test_deque(value_5);
            break;
        case 17:
            cout << "select: " << choice << endl;
            using namespace jj17;
            long value_17;
            cout << "how many elements:  " << endl;
            cin >> value_17;
            test_stack(value_17);
            break;
        case 18:
            cout << "select: " << choice << endl;
            using namespace jj18;
            long value_18;
            cout << "how many elements:  " << endl;
            cin >> value_18;
            test_stack(value_18);
            break;

        default:
            cout << "quit!" << endl;
        }
        // cout << "please input the namespace jj0_X(1~20, input 0 to quit): " << endl;
        showmenu();
        cin >> choice;
    }

    cout << "bye!\n";
    return 0;
}

