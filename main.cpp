#include<limits.h>
#include<stdlib.h>
#include<unistd.h>
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char *argv[]){
    if (argc > 2){
        cout << "Only provide one argument" << endl;
        exit(1);
    } else if (argc != 2){
        cout << "Provide a target file" << endl;
        exit(1);
    }
    string target = argv[1];
    char cwd[PATH_MAX];
    string currentpath = getcwd(cwd, sizeof(cwd));
    string fulltarget = currentpath + "/" + target;
    const char *cstr = fulltarget.c_str();
    FILE *out = fopen(cstr, "w");
    string towrite;
    getline(cin, towrite);
    const char *output = towrite.c_str();
    fputs(output, out);
    return 0;
}
