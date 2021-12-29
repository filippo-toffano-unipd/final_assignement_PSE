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

#include <queue>
using std::queue;

#include "vision_system.h"
#include "piece.h"

// Global Variable
queue <Piece> piece_queue_line1;
queue <Piece> piece_queue_line2;

int main(){
    // Estrazione contenuti da input files
    const string file_a{"../arrivi_linea_a.txt"};
    const string file_b{"../arrivi_linea_b.txt"};

    ifstream input_file_a(file_a); // file da cui estratte i dati di input linea 1
    for(int i = 0; i < 2; i++){
        string input_line1 = read_input_file(input_file_a);
        cout << "- " << input_line1 << endl;
        vector<string> split = split_input_element(input_line1);

        // Creazione della cosa
        Piece pezzo(static_cast<uint>(std::stoul(split[0])), static_cast<uint>(std::stoul(split[1])), split[2], std::stof(split[3]));
        piece_queue_line1.push(pezzo);
        cout << "la size della cosa è: "<< piece_queue_line1.size() << endl;


        // Separazione degli elementi 
        for(uint i = 0; i < split.size(); i++)
            cout << split[i] << endl;
    }
    input_file_a.close();

    cout << endl;

    ifstream input_file_b(file_b); // file da cui estratte i dati di input linea 2
    for(int i = 0; i < 2; i++){
        string input_line2 = read_input_file(input_file_b);
        cout << "- " << input_line2 << endl;
    }
    input_file_b.close();

/*
    thread thread_line1{};
    thread thread_line2{};
*/

}