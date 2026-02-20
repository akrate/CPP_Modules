#include "tool.hpp"

int open_end_read(std::string file, std::string s1, std::string s2)
{
    std::string text;
    std::ifstream readfile(file.c_str());
    if (!readfile)
    {
        std::cout << "Error opening file\n";
        return 1;
    }
    if (s1.empty())
    {
        std::cout << "s1 is empty\n";
        return 1;
    }
    file.append(".replace");
    std::ofstream myfile(file.c_str());
    int len = s1.length();
    while (getline(readfile,text))
    {
        std::string::size_type res = text.find(s1);
        if (res == std::string::npos)
            myfile << text << std::endl;
        else 
        {
            while (res != std::string::npos)
            {
                text.erase(res,len);
                text.insert(res,s2);
                res = text.find(s1);
            }
            myfile << text << std::endl;
        }
    }
    readfile.close();
    myfile.close();
    return 0;
}