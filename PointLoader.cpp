#include "PointLoader.h"

PointLoader::PointLoader(const std::string &file_path, char separator) : m_filePath(file_path), m_separator(separator) {}

std::vector<Point> PointLoader::LoadData() {
    std::vector<Point> data;
    std::ifstream file(m_filePath);
    if (!file.is_open())
        std::cerr << "Dataset not found!" << std::endl;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream line_stream(line);
        float x, y;
        if (line_stream >> x >> m_separator >> y) {
            data.push_back(Point(x, y));
        }
    }
    file.close();
    return data;
  }
