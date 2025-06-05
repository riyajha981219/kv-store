#include "KeyValueStore.hpp"
#include <mutex>

void KeyValueStore::set(const std::string& key, const std::string& value) {
    std::unique_lock lock(mutex_);
    store_[key] = value;
}

std::optional<std::string> KeyValueStore::get(const std::string& key) {
    std::shared_lock lock(mutex_);
    auto it = store_.find(key);
    if (it != store_.end()) {
        return it->second;
    }
    return std::nullopt;
}

void KeyValueStore::deleteKey(const std::string& key) {
    std::unique_lock lock(mutex_);
    store_.erase(key);
}