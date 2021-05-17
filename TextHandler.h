#ifndef TEXT_HANDLER_H
#define TEXT_HANDLER_H

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include "templates.cpp"

class TextHandler {
    private:
        const char* filename;
        std::set<char>* characters;
        std::map<char, int>* charactersStatistics;
        std::set<char>* numbers;
        std::map<char, int>* numbersStatistics;
        std::set<char>* specialSymbols;
        std::map<char, int>* specialSymbolsStatistics;
		std::set<std::string>* word; //
        std::map<std::string, int>* wordStatistics; //
        long long quantity;
		long long wordquantity; // 

        void insert(char symbol, std::set<char>* lst);
        void insert(char symbol, std::map<char, int>* lst);
        bool isLetter(char symbol);
        bool isNumber(char symbol);
        bool isSpecial(char symbol);
		void insert(std::string word, std::set<std::string>* lst); // 
        void insert(std::string word, std::map<std::string, int>* lst); // 
		
    public:
        TextHandler(const char* filename);
        ~TextHandler();

        const std::set<char>& getCharacters() const;
        const std::map<char, int>& getCharactersStatistics() const;
        const std::set<char>& getNumbers() const;
        const std::map<char, int>& getNumbersStatistics() const;
        const std::set<char>& getSpecialSymbols() const;
        const std::map<char, int>& getSpecialSymbolsStatistics() const;
        long long getQuantity() const;
		long long getWordquantity() const; // 
		const std::set<std::string>& getWord() const; //
        const std::map<std::string, int>& getWordStatistics() const; //
		

        void parseText();
};

std::ostream& operator<<(std::ostream& out, const TextHandler& handler);

#endif //TEXT_HANDLER_H