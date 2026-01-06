# JsonPencil
> ⚠️ **Note: This project is currently under active development.**
> APIs are subject to change without notice. Use at your own risk.


![Language](https://img.shields.io/badge/language-C%2B%2B-blue)
![License](https://img.shields.io/badge/license-MIT-green)

**JsonPencil** is a lightweight, dependency-free C++ library designed for simply generating JSON strings.
It focuses on ease of use and portability, making it ideal for configuration files, game save data, and simple API requests.

## 🚀 Features

* **Zero Dependencies:** Uses only standard C++ libraries (`<string>`, `<vector>`, `<variant>`). No need to install heavy frameworks like Boost or RapidJSON.
* **Easy Integration:** Just copy the source code into your project and it works.
* **Simple Syntax:** Intuitive API to insert integers, strings, and arrays.
* **Mixed Arrays:** Supports arrays containing both `int` and `std::string`.

## 📦 Requirements

* **C++17** or later (Required for `std::variant`).

## 📖 Usage

### 1. Basic JSON Generation

You can easily create a JSON object by inserting keys and values.

```cpp
#include "JsonPencil.h" // Assuming the class is defined here
#include <iostream>

int main() {
    // 1. Initialize
    Json json;

    // 2. Insert Data
    json.Insert("id", 101);
    json.Insert("name", "JsonPencil");
    json.Insert("status", "Active");

    // 3. Finalize and Output
    json.Update(); // Don't forget to call Update() to close the JSON object
    std::cout << json.GetJsonData() << std::endl;
}
```
**output**
```bash
{
"id": 101,
"name": "JsonPencil",
"status": "Active"
}
```
## 📦 Installation

### Using CMake

You can easily include this project using CMake.

1. Clone the repository:
   ```bash
   git clone https://github.com/nekomanma634/JsonPencil.git
   ```
