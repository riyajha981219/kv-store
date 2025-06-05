#include <iostream>
#include "KeyValueStore.hpp"
#include <mutex>

int main() {
    // std::cout << "ThreadKV: In-Memory Key-Value Store\n";
    // return 0;

    KeyValueStore kv;

    kv.set("language", "C++");
    auto val = kv.get("language");
    if (val) std::cout << "language: " << *val << std::endl;
    
    kv.deleteKey("language");
    auto missing = kv.get("language");
    if (!missing) std::cout << "language key deleted.\n";

    return 0;
}