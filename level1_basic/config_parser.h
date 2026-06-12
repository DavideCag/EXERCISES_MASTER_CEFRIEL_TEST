#pragma once
#include <string>

struct ConfigPair {
    std::string key;
    std::string value;
};

// Se la stringa e' valida ("chiave=valore"), alloca dinamicamente un ConfigPair.
// Altrimenti ritorna nullptr. Il chiamante deve fare delete.
ConfigPair* ParseConfigLine(const std::string& line);
bool IsValidKeyName(const std::string& key);

class KeyGenerator{
    private:
        int seed;

    public:
        KeyGenerator(int seed);
        std::string GenerateValidKey();
        std::string GenerateNotValidKey();
    private:
        std::string GenerateKey(std::string charspace);
};