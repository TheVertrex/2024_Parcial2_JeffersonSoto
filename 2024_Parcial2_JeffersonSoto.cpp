#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

void createFiles(int numFiles) {
    string folderName = (numFiles % 2 == 0) ? "par" : "impar";
    fs::path desktopPath = fs::path(getenv("USERPROFILE")) / "Desktop";
    fs::create_directories(desktopPath / folderName);

    for (int i = 1; i <= numFiles; ++i) {
        string fileName = "file" + to_string(i) + ".txt";
        ofstream file(desktopPath / folderName / fileName);
        if (!file) {
            cerr << "Error al crear el archivo: " << fileName << endl;
        } else {
            cout << "Archivo creado: " << fileName << endl;
        }
        file.close();
    }
}

int main() {
    cout<<"Primer Ejercicio de Serie II"<<endl;
    cout<<"Crear una funcion que pregunte al usuario cuantos archivos desea crear, si la cantidad de archivos a crear es par, los archivos debe almacenarlos en el directorio de Escritorio y subcarpeta llamada par, de lo contrario si el numero proporcionado por el usuario es impar los archivos debe almacenarlos en el mismo directorio en unaa carpeta llamada impar, los archivos deben tener el nombre con el siguiente formato file1, file2, file3, etc."<<endl;
    int numFiles;
    cout << "Ingrese la cantidad de archivos a crear: ";
    cin >> numFiles;

    createFiles(numFiles);

    return 0;
}
