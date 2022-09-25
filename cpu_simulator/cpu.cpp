#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <exception>

void mov(const std::string&);
void add(const std::string&);
void sub(const std::string&);
void mul(const std::string&);
void div(const std::string&);
void read(const std::string&);
void inc(const std::string&);
void dec(const std::string&);
void jmp(const std::string&);
void je(const std::string&);
void jne(const std::string&);
void jg(const std::string&);
void jl(const std::string&);
void file_open();
std::string lastLine(std::ifstream&);
std::map<std::string, int> reg;

int main() {
    std::fstream newfile;
    std::string str;
    newfile.open("cpu.txt");
    if (newfile.is_open()) {
        while (getline(newfile, str)) {
            read(str);
        }
        newfile.close();
    }
    else {
        std::cout << "fail is not open" << std::endl;
    }
}

void read(const std::string& str) {
    int i = 0;
    std::string st = "";
    while (str[i] != ' ') {
        st += str[i];
        ++i;
    }
    if ("mov" == st) {
        mov(str);
    }
    else if ("add" == st) {
        add(str);
    }
    else if ("sub" == st) {
        sub(str);
    }
    else if ("mul" == st) {
        mul(str);
    }
    else if ("div" == st) {
        div(str);
    }
    else if ("inc" == st) {
        inc(str);
    }
    else if ("dec" == st) {
        dec(str);
    }
    else if ("jmp" == st) {
        jmp(str);
    }
    else if ("je" == st) {
        je(str);
    }
    else if ("jne" == st) {
        jne(str);
    }
    else if ("jg" == st) {
        jg(str);
    }
    else if ("jl" == st) {
        jl(str);
    }
}

void mov(const std::string& str) {
    int i = 0;
    std::string st1 = "";
    std::string st2 = "";
    while (str[i] != ' ') {
        ++i;
    }
    while (str[i] == ' ') {
        ++i;
    }
    while (str[i] != ',') {
        st1 += str[i];
        ++i;
    }
    ++i;
    while (str[i] != ' ') {
        st2 += str[i];
        ++i;
    }
    if (st1 == "r0" || st1 == "r1" || st1 == "r2" || st1 == "r3" || st1 == "r4" || st1 == "r5" || st1 == "r6" || st1 == "r7" || st1 == "r8" || st1 == "r9") {
        reg[st1];
    }
    else {
        throw std::logic_error("Incorrect name!");
    }
    if (st2 == "r0" || st2 == "r1" || st2 == "r2" || st2 == "r3" || st2 == "r4" || st2 == "r5" || st2 == "r6" || st2 == "r7" || st2 == "r8" || st2 == "r9") {
        reg[st1] = reg[st2];
    }
    else {
        reg[st1] = std::stoi(st2);
    }
}

void add(const std::string& str) {
    int i = 0;
    std::string st1 = "";
    std::string st2 = "";
    while (str[i] != ' ') {
        ++i;
    }
    while (str[i] == ' ') {
        ++i;
    }
    while (str[i] != ',') {
        st1 += str[i];
        ++i;
    }
    ++i;
    while (str[i] != ' ') {
        st2 += str[i];
        ++i;
    }
    if (st2 == "r0" || st2 == "r1" || st2 == "r2" || st2 == "r3" || st2 == "r4" || st2 == "r5" || st2 == "r6" || st2 == "r7" || st2 == "r8" || st2 == "r9") {
        reg[st1] += reg[st2];
    }
    else {
        reg[st1] += std::stoi(st2);
    }
}

void sub(const std::string& str) {
    int i = 0;
    std::string st1 = "";
    std::string st2 = "";
    while (str[i] != ' ') {
        ++i;
    }
    while (str[i] == ' ') {
        ++i;
    }
    while (str[i] != ',') {
        st1 += str[i];
        ++i;
    }
    ++i;
    while (str[i] != ' ') {
        st2 += str[i];
        ++i;
    }
    if (st2 == "r0" || st2 == "r1" || st2 == "r2" || st2 == "r3" || st2 == "r4" || st2 == "r5" || st2 == "r6" || st2 == "r7" || st2 == "r8" || st2 == "r9") {
        reg[st1] -= reg[st2];
    }
    else {
        reg[st1] -= std::stoi(st2);
    }
}

void mul(const std::string& str) {
    int i = 0;
    std::string st1 = "";
    std::string st2 = "";
    while (str[i] != ' ') {
        ++i;
    }
    while (str[i] == ' ') {
        ++i;
    }
    while (str[i] != ',') {
        st1 += str[i];
        ++i;
    }
    ++i;
    while (str[i] != ' ') {
        st2 += str[i];
        ++i;
    }
    if (st2 == "r0" || st2 == "r1" || st2 == "r2" || st2 == "r3" || st2 == "r4" || st2 == "r5" || st2 == "r6" || st2 == "r7" || st2 == "r8" || st2 == "r9") {
        reg[st1] *= reg[st2];
    }
    else {
        reg[st1] *= std::stoi(st2);
    }
}

void div(const std::string& str) {
    int i = 0;
    std::string st1 = "";
    std::string st2 = "";
    while (str[i] != ' ') {
        ++i;
    }
    while (str[i] == ' ') {
        ++i;
    }
    while (str[i] != ',') {
        st1 += str[i];
        ++i;
    }
    ++i;
    while (str[i] != ' ') {
        st2 += str[i];
        ++i;
    }
    if (st2 == "r0" || st2 == "r1" || st2 == "r2" || st2 == "r3" || st2 == "r4" || st2 == "r5" || st2 == "r6" || st2 == "r7" || st2 == "r8" || st2 == "r9") {
        reg[st1] /= reg[st2];
    }
    else {
        reg[st1] /= std::stoi(st2);
    }
}

void inc(const std::string& str) {
    int i = 0;
    std::string st1 = "";
    while (str[i] != ' ') {
        ++i;
    }
    while (str[i] == ' ') {
        ++i;
    }
    while (str[i] != ' ') {
        st1 += str[i];
        ++i;
    }
    reg[st1] += 1;
}

void dec(const std::string& str) {
    int i = 0;
    std::string st1 = "";
    while (str[i] != ' ') {
        ++i;
    }
    while (str[i] == ' ') {
        ++i;
    }
    while (str[i] != ' ') {
        st1 += str[i];
        ++i;
    }
    reg[st1] -= 1;
}

void jmp(const std::string& str) {
    int i = 0;
    std::string st1 = "";
    while (str[i] != ' ') {
        ++i;
    }
    while (str[i] == ' ') {
        ++i;
    }
    while (str[i] != ' ') {
        st1 += str[i];
        ++i;
    }
    std::fstream newfile;
    std::string string;
    newfile.open("cpu.txt");
    int count = 0;
    if (newfile.is_open()) {
        while (getline(newfile, string)) {
            int i = 0;
            std::string st2 = "";
            while (string[i] != ' ') {
                st2 += string[i];
                ++i;
            }
            ++count;
            if (st1 == st2) {
                std::fstream file;
                std::string string1;
                file.open("cpu.txt");
                int count1 = 0;
                if (file.is_open()) {
                    while (getline(file, string1)) {
                        int j = 0;
                        std::string str2 = "";
                        while (string1[j] != ' ') {
                            str2 += string1[j];
                            ++j;
                        }
                        ++count1;
                        if (count1 == count) {
                            ++count;
                            read(string1);
                        }
                    }
                    file.close();
                }
                else {
                    std::cout << "fail is not open" << std::endl;
                }
            }
        }
        newfile.close();
    }
    else {
        std::cout << "fail is not open" << std::endl;
    }
    exit(0);
}

std::string lastLine(std::ifstream& in) {
    std::string line;
    while (in >> std::ws && std::getline(in, line));
    return line;
}

void je(const std::string& str1) {
    file_open();
    std::ifstream file("temp.txt");
    if (file) {
        std::string line = lastLine(file);
        int i = 0;
        std::string st1 = "";
        std::string st2 = "";
        while (line[i] != ' ') {
            ++i;
        }
        while (line[i] == ' ') {
            ++i;
        }
        while (line[i] != ',') {
            st1 += line[i];
            ++i;
        }
        ++i;
        while (line[i] != ' ') {
            st2 += line[i];
            ++i;
        }
        if (st2 == "r0" || st2 == "r1" || st2 == "r2" || st2 == "r3" || st2 == "r4" || st2 == "r5" || st2 == "r6" || st2 == "r7" || st2 == "r8" || st2 == "r9") {
            if (reg[st1] == reg[st2]) {
                jmp(str1);
            }
        }
        else {
            if (reg[st1] == std::stoi(st2)) {
                jmp(str1);
            }
        }
    }
}

void jne(const std::string& str1) {
    file_open();
    std::ifstream file("temp.txt");
    if (file) {
        std::string line = lastLine(file);
        int i = 0;
        std::string st1 = "";
        std::string st2 = "";
        while (line[i] != ' ') {
            ++i;
        }
        while (line[i] == ' ') {
            ++i;
        }
        while (line[i] != ',') {
            st1 += line[i];
            ++i;
        }
        ++i;
        while (line[i] != ' ') {
            st2 += line[i];
            ++i;
        }
        if (st2 == "r0" || st2 == "r1" || st2 == "r2" || st2 == "r3" || st2 == "r4" || st2 == "r5" || st2 == "r6" || st2 == "r7" || st2 == "r8" || st2 == "r9") {
            if (reg[st1] != reg[st2]) {
                jmp(str1);
            }
        }
        else {
            if (reg[st1] != std::stoi(st2)) {
                jmp(str1);
            }
        }
    }
}

void jg(const std::string& str1) {
    file_open();
    std::ifstream file("temp.txt");
    if (file) {
        std::string line = lastLine(file);
        int i = 0;
        std::string st1 = "";
        std::string st2 = "";
        while (line[i] != ' ') {
            ++i;
        }
        while (line[i] == ' ') {
            ++i;
        }
        while (line[i] != ',') {
            st1 += line[i];
            ++i;
        }
        ++i;
        while (line[i] != ' ') {
            st2 += line[i];
            ++i;
        }
        if (st2 == "r0" || st2 == "r1" || st2 == "r2" || st2 == "r3" || st2 == "r4" || st2 == "r5" || st2 == "r6" || st2 == "r7" || st2 == "r8" || st2 == "r9") {
            if (reg[st1] > reg[st2]) {
                jmp(str1);
            }
        }
        else {
            if (reg[st1] > std::stoi(st2)) {
                jmp(str1);
            }
        }
    }
}

void jl(const std::string& str1) {
    file_open();
    std::ifstream file("temp.txt");
    if (file) {
        std::string line = lastLine(file);
        int i = 0;
        std::string st1 = "";
        std::string st2 = "";
        while (line[i] != ' ') {
            ++i;
        }
        while (line[i] == ' ') {
            ++i;
        }
        while (line[i] != ',') {
            st1 += line[i];
            ++i;
        }
        ++i;
        while (line[i] != ' ') {
            st2 += line[i];
            ++i;
        }
        if (st2 == "r0" || st2 == "r1" || st2 == "r2" || st2 == "r3" || st2 == "r4" || st2 == "r5" || st2 == "r6" || st2 == "r7" || st2 == "r8" || st2 == "r9")     {
            if (reg[st1] < reg[st2]) {
                jmp(str1);
            }
        }
        else {
            if (reg[st1] < std::stoi(st2)) {
                jmp(str1);
            }
        }
    }
}

void jle(const std::string& str1) {
    file_open();
    std::ifstream file("temp.txt");
    if (file) {
        std::string line = lastLine(file);
        int i = 0;
        std::string st1 = "";
        std::string st2 = "";
        while (line[i] != ' ') {
            ++i;
        }
        while (line[i] == ' ') {
            ++i;
        }
        while (line[i] != ',') {
            st1 += line[i];
            ++i;
        }
        ++i;
        while (line[i] != ' ') {
            st2 += line[i];
            ++i;
        }
        if (st2 == "r0" || st2 == "r1" || st2 == "r2" || st2 == "r3" || st2 == "r4" || st2 == "r5" || st2 == "r6" || st2 == "r7" || st2 == "r8" || st2 == "r9") {
            if (reg[st1] <= reg[st2]) {
                jmp(str1);
            }
        }
        else {
            if (reg[st1] <= std::stoi(st2)) {
                jmp(str1);
            }
        }
    }
}

void jge(const std::string& str1) {
    file_open();
    std::ifstream file("temp.txt");
    if (file) {
        std::string line = lastLine(file);
        int i = 0;
        std::string st1 = "";
        std::string st2 = "";
        while (line[i] != ' ') {
            ++i;
        }
        while (line[i] == ' ') {
            ++i;
        }
        while (line[i] != ',') {
            st1 += line[i];
            ++i;
        }
        ++i;
        while (line[i] != ' ') {
            st2 += line[i];
            ++i;
        }
        if (st2 == "r0" || st2 == "r1" || st2 == "r2" || st2 == "r3" || st2 == "r4" ||st2 == "r5" || st2 == "r6" || st2 == "r7" || st2 == "r8" || st2 == "r9") {
            if (reg[st1] >= reg[st2]) {
                jmp(str1);
            }
        }
        else {
            if (reg[st1] >= std::stoi(st2)) {
                jmp(str1);
            }
        }
    }
}

void file_open() {
    std::fstream newfile;
    std::string str;
    newfile.open("cpu.txt");
    std::ofstream tmp;
    tmp.open("temp.txt");
    if (newfile.is_open()) {
        while (getline(newfile, str)) {
            int i = 0;
            std::string st = "";
            while (str[i] != ' ') {
                st += str[i];
                ++i;
            }
            if ("cmp" == st) {
                tmp << str << std::endl;
            }
        }
        tmp.close();
        newfile.close();
    }
    else {
        std::cout << "fail is not open" << std::endl;
    }
}
