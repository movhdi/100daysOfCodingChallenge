#include <iostream>
#include <string>
#include <streambuf>
#include <filesystem>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <ios>

namespace fs = std::filesystem;
void remove_empty_lines(fs::path filepath)
{
    std::ifstream myfile;
    myfile.open(filepath / "example.txt", std::ios::in);
    if (!myfile.is_open())
    {
        throw std::runtime_error("Can not open input file!");
    }

    std::ofstream resultfile(filepath / "example2.txt", std::ios::out | std::ios::trunc);

    if (!resultfile.is_open())
    {
        throw std::runtime_error("Can not create output file!");
    }
    std::string line;
    while (std::getline(myfile, line))
    {
        if (line.length() > 0 && line.find_first_not_of(' ') != line.npos)
        {
            resultfile << line << '\n';
        }
    }
    myfile.close();
    resultfile.close();
    fs::remove(filepath);
}
int main()
{
    fs::path path = "/home/med/100daysOfCodingChallenge/p34_deleteEmptyLines/";
    remove_empty_lines(path);
    return 0;
}

// Morals of the story
/*
ios::out    is the default mode for std::ofstream, it means that output operations can be used
            (i.e. you can write to the file).

ios::app    (short for append) means that instead of overwriting the file from the beginning,
            all output operations are done at the end of the file.
            This is only meaningful if the file is also open for output.

ios::trunc  (short for truncate) means that when the file is opened, the old contents are immediately removed.
            Again, this is only meaningful if the file is also open for output.
*/
