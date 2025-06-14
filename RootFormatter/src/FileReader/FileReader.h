#pragma once

#include <filesystem>
#include <string>


namespace Tools
{

class FileReader final
{
public:
    [[nodiscard]]
    static std::string ReadFile(const std::filesystem::path& path);


    FileReader() = delete;
    FileReader(const FileReader&) = delete;
    FileReader(FileReader&&) = delete;
    ~FileReader() = delete;

    FileReader& operator = (const FileReader&) = delete;
    FileReader& operator = (FileReader&&) = delete;

};

}  // namespace Tools
