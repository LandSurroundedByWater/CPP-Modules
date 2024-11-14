#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

// Function to map type names to C++ type strings
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

void createHeaderFile(const std::string& className, const std::string& baseClassName, const std::vector<std::pair<std::string, std::string>>& members, bool isDerived) {
    std::ofstream headerFile(className + ".hpp");

    if (!headerFile) {
        std::cerr << "Error: Could not open file " << className << ".hpp for writing.\n";
        return;
    }

    headerFile << "#ifndef " << className << "_HPP\n";
    headerFile << "#define " << className << "_HPP\n\n";
    if (isDerived) {
        headerFile << "#include \"" << baseClassName << ".hpp\"\n\n";
    }
    headerFile << "#include <string>\n\n";

    // Inheritance
    if (isDerived) {
        headerFile << "class " << className << " : public " << baseClassName << " {\n";
    } else {
        headerFile << "class " << className << " {\n";
    }

    headerFile << "public:\n";
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
    headerFile << "    virtual ~" << className << "();\n\n";

    for (const auto& member : members) {
        headerFile << "    void set" << member.second << "(" << getTypeString(member.first) << " value);\n";
        headerFile << "    " << getTypeString(member.first) << " get" << member.second << "() const;\n";
    }

    headerFile << "\nprotected:\n";
    for (const auto& member : members) {
        headerFile << "    " << getTypeString(member.first) << " " << member.second << ";\n";
    }

    headerFile << "};\n\n";
    headerFile << "#endif // " << className << "_HPP\n";

    headerFile.close();
}

void createSourceFile(const std::string& className, const std::string& baseClassName, const std::vector<std::pair<std::string, std::string>>& members, bool isDerived) {
    std::ofstream sourceFile(className + ".cpp");

    if (!sourceFile) {
        std::cerr << "Error: Could not open file " << className << ".cpp for writing.\n";
        return;
    }

    sourceFile << "#include \"" << className << ".hpp\"\n\n";

    sourceFile << className << "::" << className << "() : ";
    if (isDerived) {
        sourceFile << baseClassName << "()";
        if (!members.empty()) sourceFile << ", ";
    }
    sourceFile << "{}\n\n";

    // Constructor implementation
    sourceFile << className << "::" << className << "(";
    for (int i = 0; i < members.size(); ++i) {
        if (i > 0) sourceFile << ", ";
        sourceFile << getTypeString(members[i].first) << " " << members[i].second;
    }
    sourceFile << ") : ";
    if (isDerived) {
        sourceFile << baseClassName << "()";
        if (!members.empty()) sourceFile << ", ";
    }
    for (int i = 0; i < members.size(); ++i) {
        if (i > 0) sourceFile << ", ";
        sourceFile << members[i].second << "(" << members[i].second << ")";
    }
    sourceFile << " {}\n\n";

    sourceFile << className << "::" << className << "(const " << className << "& other) : ";
    if (isDerived) {
        sourceFile << baseClassName << "(other)";
        if (!members.empty()) sourceFile << ", ";
    }
    for (const auto& member : members) {
        sourceFile << member.second << "(other." << member.second << ")";
        if (&member != &members.back()) sourceFile << ", ";
    }
    sourceFile << " {}\n\n";

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

void createClass(const std::string& className, const std::string& baseClassName) {
    int numMembers;
    std::cout << "Enter the number of members for " << className << ": ";
    std::cin >> numMembers;
    std::cin.ignore(); // Ignore newline

    std::vector<std::pair<std::string, std::string>> members(numMembers);
    for (int i = 0; i < numMembers; ++i) {
        std::string type, name;
        std::cout << "Enter type and name of member " << (i + 1) << " (e.g., int age): ";
        std::cin >> type >> name;
        std::cin.ignore(); // Ignore newline
        members[i] = std::make_pair(type, name);
    }

    // Create header and source files
    createHeaderFile(className, baseClassName, members, !baseClassName.empty());
    createSourceFile(className, baseClassName, members, !baseClassName.empty());
}

int main() {
    std::string baseClassName;
    char inheritOption;

    std::cout << "Do you want to create a base class? (y/n): ";
    std::cin >> inheritOption;
    std::cin.ignore(); // Ignore newline

    if (inheritOption == 'y' || inheritOption == 'Y') {
        std::cout << "Enter the base class name: ";
        std::getline(std::cin, baseClassName);

        createClass(baseClassName, "");
    }

    std::string derivedClassName;
    std::cout << "Do you want to create a derived class? (y/n): ";
    std::cin >> inheritOption;
    std::cin.ignore(); // Ignore newline

    if (inheritOption == 'y' || inheritOption == 'Y') {
        std::cout << "Enter the derived class name: ";
        std::getline(std::cin, derivedClassName);

        std::cout << "Enter the base class name that the derived class will inherit from: ";
        std::getline(std::cin, baseClassName);

        createClass(derivedClassName, baseClassName);
    }

    std::cout << "Class files have been created.\n";

    return 0;
}
