#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;


int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Uso: " << argv[0] << " <lenguaje> <tema>\n";
        return 1;
    }

    string lang  = argv[1];
    string topic = argv[2];

    string path = "/usr/local/share/manual/data/" + lang + "/" + topic + ".md";

    ifstream file(path);

    if (topic == "temas") {
        string dir = "/usr/local/share/manual/data/" + lang;
        cout << "Temas disponibles en " << lang << ":\n\n";
        for (auto& entry : fs::directory_iterator(dir)) {
            string nombre = entry.path().stem().string();
            cout << "  " << nombre << "\n";
        }
        return 0;
    }
    if (!file.is_open()) {
        cerr << "Tema no encontrado: " << lang << " " << topic << "\n";
        return 1;
    }


    cout << file.rdbuf();
    return 0;
}
