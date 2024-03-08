#include<bits/stdc++.h>
using namespace std;
#define N 1e5+9//注意1e5+9是double而不是long long int
struct Node{
    int u,v;
    bool operator<(const Node &m) const{//operator< 重载了小于运算符
        return u==m.u?v<m.v:u<m.u;//如果两Node的 u 值相等，则比较它们的v值；如果u值不相等，则直接比较u值
    }
}; 

int String2Int(string s){//string转为int
    int res=0;
    for(auto i:s)
        res=res*10+i-'0';
    return res;
}

string Int2String(int n,int w){//把int转为w位string
    string s;
    while(n){
        s+=n%10+'0';
        n/=10;
    }
    while (s.size()<w)
        s+='0';
    reverse(s.begin(),s.end());
    return s;
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int lcm(int a,int b){
    return a/gcd(a,b)*b;
}

// 自定义的比较函数
bool comparePair(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //char s[10];
    //scanf("%[^\n]s",s);
    //string s;
    //getline(cin,s);
    //cout<<s;
    //printf("%s",s);
    string str1="hello world";
    string str2=str1.substr(0,3);//(起始位置，长度)
    const char* array="hello";
    string str3(array);
    string str4(5,'S');//"SSSSS"
    cout<<str1<<endl<<str2<<endl<<str3<<endl<<str4<<endl;
    printf("%s\n",str1.c_str());
    int res1=str2.compare(str1);//假如两个都没有结束之前，比出来了，那结果就只有±1或者0，假如比到一个字符串结束了还没有比出来（也就是说一个字符是另外一个字符的前缀），那str2.compare(str1)返回的就是str2.size()-str1.size()
    int res2=str1.find("wor");//返回值是一个迭代器，指向找到的第一个元素，如果没有找到该元素，那么返回的迭代器等于end()
    cout<<res1<<" "<<res2;
    for(auto i:str1){
        cout<<i;
        i='a';//不会改变str1
    }
    cout<<endl<<str1<<endl;
    for(auto &i:str1){
        cout<<i;
        i='a';//会改变str1
    }
    cout<<endl<<str1<<endl;
    vector<string> words = {"apple", "banana", "orange", "grape"};

    // 使用lambda表达式自定义排序规则
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });

    // 输出排序后的结果
    for (const auto& word : words)
        cout << word << " ";
    
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    int k = 4; // 要找到第4小的元素

    //使用nth_element对数组进行部分排序，使得第k小的元素处于正确的位置上
    //该位置前的数字都比第k小的元素小，后面的都比其大，但没有顺序
    nth_element(nums.begin(), nums.begin() + k - 1, nums.end());

    // 输出结果
    cout << "第" << k << "小的元素是：" << nums[k - 1] << endl;
    for(auto &i:nums)
        cout<<i<<" ";
    vector<int> nums2 = {1, 2, 3, 3, 3, 4, 5, 6, 7};

    // 使用 binary_search 检查元素是否存在
    bool found =binary_search(nums2.begin(), nums2.end(), 3);
    cout << "元素 3 是否存在：" << (found ? "是" : "否") <<endl;

    // 使用 lower_bound 查找第一个大于或等于给定值的元素的位置
    auto lb =lower_bound(nums2.begin(), nums2.end(), 3);
    cout << "第一个大于或等于 3 的元素的位置：" << distance(nums2.begin(), lb) << endl;
    
    //index是x在nums2中的的下标（nums2已排好序）
    int x=3;
    int index=lower_bound(nums2.begin(),nums2.end(),x)-nums2.begin();//lower_bound返回一个迭代器而不是int,所以要减nums2.begin()
    
    // 使用 upper_bound 查找第一个大于给定值的元素的位置
    auto ub = upper_bound(nums2.begin(), nums2.end(), 3);
    cout << "第一个大于 3 的元素的位置：" << distance(nums2.begin(), ub) <<endl;
    
    vector<int> v1 = {1, 2, 3}; 
    next_permutation(v1.begin(), v1.end()); // 将v1改变为其下一个字典顺序排列，返回1，若v1已经是最后一种排序，则返回0，把v1改为第一种排序
    for (int i : v1)
        cout << i << " "; 
    cout << "\n"; 
    vector<int> v2 = {3, 2, 1}; 
    prev_permutation(v2.begin(), v2.end()); // 将v2改变为其上一个字典顺序排列
    for (int i : v2) 
        cout << i << " "; 
    cout << "\n"; 
    char str[50] = "Hello, world!";

    cout << "Before memset: " << str << std::endl;

    // 使用memset将str的前5个字符设置为'-'
    memset(str, '-', 5);

    cout << "After memset: " << str << std::endl;
    vector<int> v3(5); // 创建一个大小为5的向量v1
    fill(v3.begin(), v3.end(), 10); // 将v1的所有元素设置为10
    for (int i : v1)
        cout << i << " ";
    cout << "\n";
    //类型安全：std::fill是类型安全的，它可以用于任何类型的元素，包括整数、浮点数、字符串、自定义类型等。std::memset不是类型安全的，它直接操作内存，只能用于字符数组或者其他POD（Plain Old Data）类型。

    //fill通常用于填充容器，memset通常用于填充字符数组或者其他C风格的数组。

    //fill是C++标准库中的函数，memset是C标准库中的函数，也可以在C++中使用。

    // 使用unique
    vector<int> v4 = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    auto it = unique(v4.begin(), v4.end()); // 移除v2中的连续重复元素，注意不连续的重复元素不能移除
    v4.resize(distance(v4.begin(), it)); // 调整v2的大小
    for (int i : v4)
        cout << i << " ";
    cout << "\n";

    // 创建一个pair
    std::pair<int, std::string> p1 = {1, "Alice"};
    std::cout << "p1: " << p1.first << ", " << p1.second << "\n";

    // 创建一个嵌套的pair
    std::pair<int, std::pair<std::string, std::string>> p2 = {2, {"Bob", "Charlie"}};
    std::cout << "p2: " << p2.first << ", " << p2.second.first << ", " << p2.second.second << "\n";

    //创建一个包含pair的向量，并进行排序(升序)
    //优先比较first,一样则比较second
    std::vector<std::pair<int, std::string>> v = {{3, "David"}, {1, "Eve"}, {2, "Frank"}};
    std::sort(v.begin(), v.end());
    for (const auto& p : v) 
        std::cout << p.first << ", " << p.second << "\n";
    
    // 使用自定义的比较函数进行排序
    std::sort(v.begin(), v.end(), comparePair);

    for (const auto& p : v) 
        std::cout << p.first << ", " << p.second << "\n";
    
    std::vector<int> v5 = {3, 2, 5, 1, 4};
    v5.push_back(6);
    std::sort(v5.begin(), v5.end());
    for (int i : v5) 
        std::cout << i << " ";
    std::cout << "\n";

    // 使用pop_back移除最后一个元素
    v5.pop_back();
    for (int i : v5) 
        std::cout << i << " ";
    std::cout << "\n";

    // 使用insert在第二个位置插入一个元素
    v5.insert(v5.begin() + 1, 7);
    for (int i : v5) 
        std::cout << i << " ";
    std::cout << "\n";

    // 使用erase移除第二个位置的元素
    v5.erase(v5.begin() + 1);
    for (int i : v5) 
        std::cout << i << " ";
    std::cout << "\n";

    // 输出vector的大小
    std::cout << "Size: " << v5.size() << "\n";

    // 使用resize调整vector的大小
    v5.resize(3);
    for (int i : v5) 
        std::cout << i << " ";
    std::cout << "\n";

    // 检查vector是否为空
    std::cout << "Empty: " << (v5.empty() ? "Yes" : "No") << "\n";

    // 添加重复的元素
    v5.insert(v5.end(), {1, 2, 3, 4, 5, 6});
    std::sort(v5.begin(), v5.end());
    auto a= std::unique(v5.begin(), v5.end());//最后一个元素的下一个位置
    v5.resize(std::distance(v5.begin(), a));
    for (int i : v5) 
        std::cout << i << " ";
    std::cout << "\n";

    // 创建一个空的list
    std::list<int> myList;

    // 在list的末尾添加元素
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    // 在list的开始添加元素
    myList.push_front(0);

    // 输出list的元素
    for (int num : myList)
        std::cout << num << " ";
    std::cout << "\n";

    // 删除list的第一个元素
    myList.pop_front();

    // 删除list的最后一个元素
    myList.pop_back();

    // 输出list的元素
    for (int num : myList)
        std::cout << num << " ";
    std::cout << "\n";

    // 插入元素到指定位置
    std::list<int>::iterator loc = myList.begin();
    std::advance(loc, 1); // 移动迭代器到第二个元素
    myList.insert(loc, 10); // 在第二个元素前插入10

    // 输出list的元素
    for (int num : myList) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 删除指定位置的元素
    loc = myList.begin();
    std::advance(loc, 1); // 移动迭代器到第二个元素
    loc = myList.erase(loc); // 删除第二个元素并更新迭代器

    // 输出list的元素
    for (int num : myList)
        std::cout << num << " ";
    std::cout << "\n";

    // 创建一个空的stack
    std::stack<int> myStack;

    // 在stack的顶部添加元素
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // 输出stack的顶部元素
    std::cout << "Top of stack: " << myStack.top() << "\n";

    // 删除stack的顶部元素
    myStack.pop();

    // 输出stack的顶部元素
    std::cout << "Top of stack: " << myStack.top() << "\n";

    // 创建一个空的queue
    std::queue<int> myQueue;

    // 在queue的末尾添加元素
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // 输出queue的首部元素
    std::cout << "Front of queue: " << myQueue.front() << "\n";

    // 删除queue的首部元素
    myQueue.pop();

    // 输出queue的首部元素
    std::cout << "Front of queue: " << myQueue.front() << "\n";

    // 创建一个空的双端队列
    std::deque<int> myDeque;

    // 在双端队列的末尾添加元素
    myDeque.push_back(1);
    myDeque.push_back(2);
    myDeque.push_back(3);

    // 在双端队列的开始添加元素
    myDeque.push_front(0);

    // 输出双端队列的元素
    for (int num : myDeque)
        std::cout << num << " ";
    std::cout << "\n";

    // 创建一个空的优先队列
    std::priority_queue<int> myPQ;

    // 在优先队列中添加元素
    myPQ.push(2);
    myPQ.push(1);
    myPQ.push(3);

    // 输出优先队列的顶部元素
    std::cout << "Top of priority queue: " << myPQ.top() << "\n";

    // 删除优先队列的顶部元素
    myPQ.pop();

    // 输出优先队列的顶部元素
    std::cout << "Top of priority queue: " << myPQ.top() << "\n";

    // 创建一个空的set
    std::set<int> mySet;

    // 在set中添加元素
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(2);
    
    // 输出set的元素
    for (int num : mySet)
        std::cout << num << " ";
    std::cout << "\n";

    // 创建一个空的multiset
    std::multiset<int> myMultiset;

    // 在multiset中添加元素
    myMultiset.insert(2);
    myMultiset.insert(1);
    myMultiset.insert(1);

    // 输出multiset的元素
    for (int num : myMultiset)
        std::cout << num << " ";
    std::cout << "\n";

    // 创建一个空的unordered_set
    std::unordered_set<int> myUnorderedSet;

    // 在unordered_set中添加元素
    myUnorderedSet.insert(1);
    myUnorderedSet.insert(2);
    myUnorderedSet.insert(3);

    // 输出unordered_set的元素
    for (int num : myUnorderedSet)
        std::cout << num << " ";
    std::cout << "\n";

    std::map<std::string, int> myMap;

    // 在map中添加元素
    myMap["apple"] = 1;
    myMap["banana"] = 2;
    myMap["cherry"] = 3;

    // 输出map的元素
    for (const auto &pair : myMap)
        std::cout << pair.first << ": " << pair.second << "\n";

    // 创建一个空的multimap
    std::multimap<std::string, int> myMultimap;

    // 在multimap中添加元素
    myMultimap.insert({"apple", 1});
    myMultimap.insert({"apple", 2});
    myMultimap.insert({"banana", 1});

    // 输出multimap的元素
    for (const auto &pair : myMultimap)
        std::cout << pair.first << ": " << pair.second << "\n";

    // 创建一个空的unordered_map
    std::unordered_map<std::string, int> myUnorderedMap;

    // 在unordered_map中添加元素
    myUnorderedMap["apple"] = 1;
    myUnorderedMap["banana"] = 2;
    myUnorderedMap["cherry"] = 3;

    // 输出unordered_map的元素
    for (const auto &pair : myUnorderedMap)
        std::cout << pair.first << ": " << pair.second << "\n";

    return 0;
}
