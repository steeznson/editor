#include<limits.h>
#include<unistd.h>
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

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
    char cwd[PATH_MAX];
    string currentpath = getcwd(cwd, sizeof(cwd));
    string fulltarget = currentpath + "/" + target;
    ofstream outfile(fulltarget, ios::out | ios::binary);

    // write out
    ostringstream buffer{};
    buffer << cin.rdbuf();
    outfile << buffer.str() << endl;
    return 0;
}
