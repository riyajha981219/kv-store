#pragma once
#include <string>
#include <mutex>
#include <unordered_map>
#include <shared_mutex>
#include <optional>

class KeyValueStore {
    public:
        void set(const std::string& key, const std::string& value);
        std::optional<std::string> get(const std::string& key);
        void deleteKey(const std::string& key);
    
    private:
        std::unordered_map<std::string, std::string> store_;
        mutable std::shared_mutex mutex_;
};