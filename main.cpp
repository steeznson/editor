#include<filesystem>
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
//#define BSD

using namespace std;

int main(int argc, char *argv[]){
    // clean input
    if (argc > 2){
        cout << "Only provide one argument" << endl;
        exit(1);
    } else if (argc != 2){
        cout << "Provide a target file" << endl;
        exit(1);
    }

    // get outfile
    string target = argv[1];
#ifdef BSD
    std::__fs::filesystem::path targetpath = std::__fs::filesystem::current_path();
#else
    path targetpath = current_path();
#endif
    targetpath /= target;
    ofstream outfile(targetpath, ios::out | ios::binary);

    // write out
    string input;
    vector<string> lines;
    do {
        getline(cin, input);
        input.append("\n");
        lines.push_back(input);
    } while (input != ".\n");

    for (int i = 0; i < (int) lines.size() - 1; ++i){
        outfile << lines[i];
    }
    outfile.close();

    return 0;
}
