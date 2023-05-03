#ifndef POINTLOADER_H_INCLUDED
#define POINTLOADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Point.h"

class PointLoader {
    public:
        PointLoader(const std::string &file_path, char separator = ';');
        std::vector<Point> LoadData();

    private:
        std::string m_filePath;
        char m_separator = ';';
};

#endif // POINTLOADER_H_INCLUDED
