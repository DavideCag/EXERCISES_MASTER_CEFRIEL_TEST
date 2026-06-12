#include "config_parser.h"
#include <cctype>
#include <cstdlib>

ConfigPair *ParseConfigLine(const std::string &line)
{
    if (line.empty())
    {
        return nullptr;
    }

    size_t equals_pos = line.find('=');
    if (equals_pos == std::string::npos)
    {
        return nullptr; // Nessun segno '=' trovato
    }

    ConfigPair *pair = new ConfigPair();
    pair->key = line.substr(0, equals_pos);
    pair->value = line.substr(equals_pos + 1);

    return pair;
}

bool IsValidKeyName(const std::string &key)
{
    if (key.empty())
        return false;
    for (char c : key)
    {
        if (!std::isalnum(c))
        { // Accetta solo lettere e numeri
            return false;
        }
    }
    return true;
}

KeyGenerator::KeyGenerator(int seed)
{
    srand(seed);
}

std::string KeyGenerator::GenerateKey(std::string charspace)
{
    int charlen = charspace.size();
    std::string newKey = "";

    for (int i = 0; i < 10; i++)
    {
        int nextChar = rand() % charlen;
        newKey.append(charspace, nextChar, 1);
    }

    return newKey;
}

std::string KeyGenerator::GenerateValidKey()
{
    std::string charspace = "abcdefghijklmnopqrstuvwxyz0123456789";

    return this->GenerateKey(charspace);
}

std::string KeyGenerator::GenerateNotValidKey()
{
    std::string notValidCharactes = "!£$%&/*#@;:";
    std::string charspace = "abcdefghijklmnopqrstuvwxyz0123456789" + notValidCharactes;
    std::string newKey = "";

    bool keyIsValid = false;

    while (!keyIsValid)
    {
        newKey = this->GenerateKey(charspace);

        int i = 0;

        while (i < newKey.size() && !keyIsValid)
        {
            char keyCharToTest = newKey[i];
            keyIsValid = notValidCharactes.find(keyCharToTest) != std::string::npos;
            
            i++;
        }
    }

    return newKey;
}