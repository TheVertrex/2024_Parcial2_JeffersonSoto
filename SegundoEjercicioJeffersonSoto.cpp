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
            for (int j = 0; j < i; ++j) {
                file << "Linea " << j + 1 << " del archivo " << fileName << endl;
            }
        }
        file.close();
    }
}

int main() {
    cout<<"Segundo Ejercicio de Serie II"<<endl;
    cout<<"Crear una funcion que agregue texto a los archivos creados, los archivos deben tener la misma cantidad de lineas segun su numero de archivo por ejemplo: file1 debe tener una linea de texto en su contenido, file2 debe tener 2 lineas y asi sucesivamente."<<endl;
    cout<<""<<endl;
    int numFiles;
    cout << "Ingrese la cantidad de archivos a crear: ";
    cin >> numFiles;

    createFiles(numFiles);

    return 0;
}
