#include "FileReader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

#include "Logger/Logger.h"

namespace Tools
{

// TODO(4rtemTrickster): Возможно загружать сразу весь файл не лучшая идея
// хотя врятли когда то можно будет встретить исходники больше 2 или 4 гб
std::string FileReader::ReadFile(const std::filesystem::path& path)
{
    LOG_TRACE("Reading file: " + path.string());

    std::fstream fs(path, std::ios_base::in);

    if (!fs.is_open())
    {
        throw std::runtime_error("Cannot open file: " + path.string());
    }

    fs.seekg(0, std::ios_base::end);
    const std::fstream::pos_type file_size = fs.tellg();

    if (std::fstream::pos_type(-1) == file_size)
    {
        std::stringstream ss;
        ss << "Can't get current position of the get pointer!\n";
        ss << "File: ";
        ss << path.string();

        throw std::runtime_error(ss.str());
    }

    std::string ret;
    fs.seekg(0, std::fstream::beg);
    ret.resize(file_size + 1LL);
    fs.read(ret.data(), file_size);

    return ret;
}

}  // namespace Tools
