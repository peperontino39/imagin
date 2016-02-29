
#include "FileIO.h"

template <class _Ty>
int FileIO::load(const std::string& path, _Ty& data)
{
    std::fstream in_file(path, std::ios::in | std::ios::binary);

    if (!in_file) return 1;

    DOUT << "loading : " << path << " : FileIO" << std::endl;

    while (!in_file.eof()) in_file.read((char*)&data, sizeof(_Ty));

    return 0;
}
template <class _Ty>
int FileIO::save(const std::string& path, const _Ty& data)
{
    std::fstream out_file(path, std::ios::out | std::ios::binary);

    if (!out_file) return 1;

    DOUT << "saveing : " << path << " : FileIO" << std::endl;

    out_file.write((char*)&data, sizeof(_Ty));

    return 0;
}
template <class _Ty>
int FileIO::load(const std::string& path, std::vector<_Ty>& array)
{
    std::fstream in_file(path, std::ios::in | std::ios::binary);

    if (!in_file) return 1;

    DOUT << "loading : " << path << " : FileIO" << std::endl;

    while (!in_file.eof())
    {
        _Ty temp;
        in_file.read((char*)&temp, sizeof(_Ty));
        if (in_file.tellg() % sizeof(_Ty) == 0) array.push_back(temp);
    }

    return 0;
}
template <class _Ty>
int FileIO::save(const std::string& path, const std::vector<_Ty>& array)
{
    std::fstream out_file(path, std::ios::out | std::ios::binary);

    if (!out_file) return 1;

    DOUT << "saveing : " << path << " : FileIO" << std::endl;

    for (auto obj : array) out_file.write((char*)&obj, sizeof(_Ty));

    return 0;
}