// Display files in a folder recursively (LINUX environment).

#include <iostream>
#include <string>
#include <cstring>
#include<dirent.h>
using namespace std;

// Recursive function to go throgh folders aand sub-folders to extract files and folders.
void ListFiles(string path)
{
    dirent* fld = nullptr;          // Store the folder/file struct's handle and content into dirent struct. 
    DIR* dp = opendir(path.c_str());    // DIR pointer object structure to hold the directory stream.
    
    if (dp)     // Able to open the directory and got the details.
    {
        while ((fld = readdir(dp)) != nullptr)  // Read the directory and get the data and load into fld folder (dirent struct)
        {
            if (strcmp(fld->d_name, ".") == 0 || strcmp(fld->d_name, "..") == 0) continue;  // Do not consider "." (current) and ".." (parent) folders

            path = (path[path.length()-1] != '/' ? path + "/" : path);      // Standardize the path by adding "/" at the end (if not present)
            string strpath = path + fld->d_name;                                      // Create New path with read folder name.
            
            if (fld->d_type == DT_DIR)      // If the type of the Item is folder, then call ListFiles() recursively to process again.
                ListFiles(strpath);            // Process the current folder.
            else                            // If the item is Not a folder and is a File
                cout << strpath << endl;       // Print the file name.
        } closedir(dp);         // Close directory on exit.
    }
}

// Test the List files function.
void ListFilesTest()
{
    string path = "/home";      // Path where to start from printing.
    ListFiles(path);            // Function to extract recursively and print content.
}

int main()
{
    ListFilesTest();
    return 0;
}
