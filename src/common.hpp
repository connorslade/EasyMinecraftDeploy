#include <vector>

void debugPrint(std::string text, int colorcode, std::string stringEnd = "\n");
void errorPrint(std::string text, int colorcode, int exitCode);
void tokenize(std::string const &str, const char delim, std::vector<std::string> &out);
auto read_file(std::string path) -> std::string ;
std::string getNewVersion(std::string baseUri, std::string name);
std::string getNewVersionAsString(std::string serverUri);
bool saveFile(std::string filePath, std::string content);
bool makeDir(const char *filePath);
bool exists(const std::string &name);
std::string stringToLower(std::string data);
std::string getConfig(std::string configOption, std::string defult, std::string defultPrint);