#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

// Function to map type names to C++ type strings

std::string capitalize(const std::string& str) {
    if (str.empty()) return str;
    return std::string(1, toupper(str[0])) + str.substr(1);
}

std::string getTypeString(const std::string& type) {
    static const std::map<std::string, std::string> typeMap = {
        {"int", "int"},
        {"float", "float"},
        {"double", "double"},
        {"std::string", "std::string"}
    };

    auto it = typeMap.find(type);
    if (it != typeMap.end()) {
        return it->second;
    }
    return "UnknownType"; // Default for unsupported types
}

void createHeaderFile(const std::string& className, const std::vector<std::pair<std::string, std::string>>& members) {
    std::ofstream headerFile(className + ".hpp");
    
    if (!headerFile) {
        std::cerr << "Error: Could not open file " << className << ".hpp for writing.\n";
        return;
    }

    headerFile << "#ifndef " << className << "_HPP\n";
    headerFile << "#define " << className << "_HPP\n\n";
    headerFile << "#include <string>\n\n";
    
    headerFile << "class " << className << " {\n";
    headerFile << "public:\n";
    headerFile << "    // Constructors\n";
    headerFile << "    " << className << "();\n";
    
    // Constructor with parameters for all members
    headerFile << "    " << className << "(";
    for (int i = 0; i < members.size(); ++i) {
        if (i > 0) headerFile << ", ";
        headerFile << getTypeString(members[i].first) << " " << members[i].second;
    }
    headerFile << ");\n";
    
    headerFile << "    " << className << "(const " << className << "& other);\n";
    headerFile << "    " << className << "& operator=(const " << className << "& other);\n";
    headerFile << "    ~" << className << "();\n\n";
    
    for (const auto& member : members) {
        headerFile << "    void set" << capitalize(member.second) << "(" << getTypeString(member.first) << " value);\n";
        headerFile << "    " << getTypeString(member.first) << " get" << capitalize(member.second) << "() const;\n";
    }
    
    headerFile << "\nprivate:\n";
    for (const auto& member : members) {
        headerFile << "    " << getTypeString(member.first) << " " << member.second << ";\n";
    }
    
    headerFile << "};\n\n";
    headerFile << "#endif // " << className << "_HPP\n";
    
    headerFile.close();
}

void createSourceFile(const std::string& className, const std::vector<std::pair<std::string, std::string>>& members) {
    std::ofstream sourceFile(className + ".cpp");

    if (!sourceFile) {
        std::cerr << "Error: Could not open file " << className << ".cpp for writing.\n";
        return;
    }

    sourceFile << "#include \"" << className << ".hpp\"\n\n";
    
    sourceFile << className << "::" << className << "() {}\n\n";
    
    // Constructor implementation
    sourceFile << className << "::" << className << "(";
    for (int i = 0; i < members.size(); ++i) {
        if (i > 0) sourceFile << ", ";
        sourceFile << getTypeString(members[i].first) << " " << members[i].second;
    }
    sourceFile << ") :\n";
    for (int i = 0; i < members.size(); ++i) {
        if (i > 0) sourceFile << ",\n";
        sourceFile << "    " << members[i].second << "(" << members[i].second << ")";
    }
    sourceFile << " {}\n\n";
    
    sourceFile << className << "::" << className << "(const " << className << "& other) {\n";
    for (const auto& member : members) {
        sourceFile << "    this->" << member.second << " = other." << member.second << ";\n";
    }
    sourceFile << "}\n\n";
    
    sourceFile << className << "& " << className << "::operator=(const " << className << "& other) {\n";
    sourceFile << "    if (this != &other) {  // Self-assignment check\n";
    for (const auto& member : members) {
        sourceFile << "        this->" << member.second << " = other." << member.second << ";\n";
    }
    sourceFile << "    }\n";
    sourceFile << "    return *this;\n";
    sourceFile << "}\n\n";
    
    sourceFile << className << "::~" << className << "() {}\n\n";
    
    for (const auto& member : members) {
        sourceFile << "void " << className << "::set" << member.second << "(" << getTypeString(member.first) << " value) {\n";
        sourceFile << "    " << member.second << " = value;\n";
        sourceFile << "}\n\n";
        
        sourceFile << getTypeString(member.first) << " " << className << "::get" << member.second << "() const {\n";
        sourceFile << "    return " << member.second << ";\n";
        sourceFile << "}\n\n";
    }
    
    sourceFile.close();
}

int main() {
    std::string className;
    int numMembers;
    
    std::cout << "Enter the class name: ";
    std::getline(std::cin, className);
    
    std::cout << "Enter the number of members: ";
    std::cin >> numMembers;
    std::cin.ignore(); // To ignore the newline after the number input
    
    std::vector<std::pair<std::string, std::string>> members(numMembers);
    
    for (int i = 0; i < numMembers; ++i) {
        std::string type, name;
        std::cout << "Enter type and name of member " << (i + 1) << " (e.g., int age): ";
        std::cin >> type >> name;
        std::cin.ignore(); // To ignore the newline after the input
        members[i] = std::make_pair(type, name);
    }
    
    createHeaderFile(className, members);
    createSourceFile(className, members);
    
    std::cout << "Files " << className << ".hpp and " << className << ".cpp have been created.\n";
    
    return 0;
}
