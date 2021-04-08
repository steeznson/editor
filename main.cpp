#include<algorithm>
#include<filesystem>
#include<fstream>
#include<iostream>
#include<regex>
#include<string>
#include<sstream>
#include<vector>

#include<TextBuffer.h>

using namespace std;


void clean_input(int argc){
    if (argc > 2){
        cout << "Only provide one argument" << endl;
        exit(1);
    } else if (argc != 2){
        cout << "Provide a target file" << endl;
        exit(1);
    }
}

int main(int argc, char *argv[]){
    clean_input(argc);

    // get outfile
    string target = argv[1];
    regex is_number("[[:digit:]]+");
#ifdef BSD
    std::__fs::filesystem::path targetpath = std::__fs::filesystem::current_path();
#else
    std::filesystem::path targetpath = std::filesystem::current_path();
#endif
    targetpath /= target;
    ofstream outfile(targetpath, ios::out | ios::binary);

    // parse input
    string input;
    do {
        getline(cin, input);
        if (input == "p"){
          text_buffer.print();
        } else if (input == "i"){
            cout << "Select line 1-" << text_buffer.get_length() << "\n";
            getline(cin, input);
            if (!(regex_match(input, is_number))){
               cout << "Invalid line number selection\n";
               continue;
            }
            int idx = stoi(input) - 1;
            if (idx < 0 || idx > text_buffer.get_length() - 1){
               cout << "Invalid line number selection\n";
               continue;
            }
            getline(cin, input);
            text_buffer.set_line_idx(input, idx);
        } else if (input != "."){
          text_buffer.set_line(input);
        }
    } while (input != ".");

    // write and tidy up
    for (auto line: text_buffer.get_lines()){
        outfile << line;
    }
    outfile.close();

    return 0;
}
