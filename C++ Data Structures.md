# C++ Data Structures

## C-style Array

```cpp
int arr[1024];
for (int i = 0; i < 1024; ++i) {
    arr[i] = i * 2;  // {0, 2, 4, 6, ..., 2046}
}

int target = 501;

// std::binary_search
if (std::binary_search(std::begin(arr), std::end(arr), target)) {
    std::cout << target << " exists in the array.\n";
} else {
    std::cout << target << " not found in the array.\n";
}

// std::lower_bound
auto it = std::lower_bound(std::begin(arr), std::end(arr), target);

if (it != std::end(arr)) {
    std::cout << "Lower bound found at index: " << (it - std::begin(arr))
              << " with value: " << *it << '\n';
} else {
    std::cout << "Lower bound not found (target is greater than all elements).\n";
}

```

## Vector

- initialize 2D array

```cpp
fill(curr.begin(), curr.end(), 0);
```

```cpp
vector<vector<int>> vec(n, vector<int>(n, 0));
```

```cpp
vector<vector<int>> vec{{ 1, 1, 1 }, { 2, 2, 2 }};
```

- `std::binary_search` and `std::lower_bound`

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student {
    std::string name;
    int age;

    // Constructor
    Student(std::string n, int a) : name(n), age(a) {}

    // Comparator for sorting
    bool operator<(const Student& other) const {
        return name < other.name || (name == other.name && age < other.age);
    }

    // Equality operator for binary_search
    bool operator==(const Student& other) const {
        return name == other.name && age == other.age;
    }
};

int main() {
    std::vector<Student> students = {
        {"Alice", 19}, {"Alice", 21}, {"Bob", 20}, {"Charlie", 25}, {"David", 22}
    };

    // Sorting is required for binary search algorithms
    std::sort(students.begin(), students.end());

    // Using std::binary_search to check if a student exists
    Student target("Alice", 21);
    if (std::binary_search(students.begin(), students.end(), target)) {
        std::cout << target.name << " - " << target.age << " exists in the list.\n";
    } else {
        std::cout << target.name << " - " << target.age << " not found.\n";
    }

    // Using std::lower_bound to find the first Alice
    Student searchKey("Alice", 0);  // Age set to 0 to find the first "Alice"
    auto it = std::lower_bound(students.begin(), students.end(), searchKey);

    if (it != students.end() && it->name == "Alice") {
        std::cout << "First Alice found: " << it->name << " - " << it->age << '\n';
    } else {
        std::cout << "Alice not found.\n";
    }

    return 0;
}
```

## Priority Queue

- prioritize small numbers

```cpp
std::priority_queue<int, vector<int>, greater<int>> pq;
```

- Initialize pq with a vector

```cpp
vector<int> v = {9, 8, 6, 10, 4, 2};
priority_queue<int> pq2(v.begin(), v.end());
```

- custom comparator

```cpp
struct Student {
    std::string name;
    int age;

    Student(std::string n, int a) : name(n), age(a) {}

    // Define priority order: lexicographical name, then younger age has higher priority
    bool operator<(const Student& other) const {
        if (name != other.name) {
            return name > other.name;  // Reverse for max-heap, to make it min-heap
        }
        return age > other.age;  // Younger students have higher priority
    }
};

std::priority_queue<Student> pq;
```

## Set
