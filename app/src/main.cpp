#include <iostream>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

#include <fstream> 
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <thread>
using std::thread;

#include "vision_system.h"

using std::cin;
using std::cout;
using std::endl;

int main(){

    //ifstream input_file(fila_a)); // file da cui estratte i dati di input linea 1
    // Estrazione contenuti da input files
    const string file_a{"../arrivi_linea_a.txt"};
    const string file_b{"../arrivi_linea_b.txt"};

    ifstream input_file_a(file_a); // file da cui estratte i dati di input linea 1
    for(int i = 0; i < 15; i++){
        string input_line1 = read_input_file(input_file_a);
        cout << "- " << input_line1 << endl;
    }
    input_file_a.close();

    cout << endl;

    ifstream input_file_b(file_b); // file da cui estratte i dati di input linea 2
    for(int i = 0; i < 15; i++){
        string input_line2 = read_input_file(input_file_b);
        cout << "- " << input_line2 << endl;
    }
    input_file_b.close();
/*
    thread thread_line1{};
    thread thread_line2{};
*/

}