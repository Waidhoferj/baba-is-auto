// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <baba-is-auto/Games/Map.hpp>

#include <fstream>

namespace baba_is_auto
{
Map::Map(std::size_t width, std::size_t height)
    : m_width(width), m_height(height)
{
    m_initObjects.reserve(m_width * m_height);
    m_objects.reserve(m_width * m_height);

    for (std::size_t i = 0; i < m_width * m_height; ++i)
    {
        m_initObjects.emplace_back(
            std::vector<ObjectType>{ ObjectType::ICON_EMPTY });
        m_objects.emplace_back(
            std::vector<ObjectType>{ ObjectType::ICON_EMPTY });
    }
}

Map::Map(std::size_t width, std::size_t height, std::vector<Object> initObjects,
         std::vector<Object> objects)
{
    m_width = width;
    m_height = height;
    m_initObjects = initObjects;
    m_objects = objects;
}

void Map::Reset()
{
    m_objects = m_initObjects;
}

std::size_t Map::GetWidth() const
{
    return m_width;
}

std::size_t Map::GetHeight() const
{
    return m_height;
}

std::vector<Object> Map::GetInitObjects() const
{
    return m_initObjects;
}

std::vector<Object> Map::GetObjects() const
{
    return m_objects;
}

void Map::Load(std::string_view filename)
{
    std::ifstream mapFile(filename.data());

    mapFile >> m_width >> m_height;

    int val = 0;
    for (std::size_t i = 0; i < m_width * m_height; ++i)
    {
        mapFile >> val;

        m_initObjects.emplace_back(
            std::vector<ObjectType>{ static_cast<ObjectType>(val) });
        m_objects.emplace_back(
            std::vector<ObjectType>{ static_cast<ObjectType>(val) });
    }
}

void Map::Write(std::string_view filename)
{
    std::ofstream mapFile;
    mapFile.open(filename.data());

    mapFile << m_width << " " << m_height << "\n";

    for (std::size_t i = 0; i < m_height; ++i)
    {
        for (std::size_t j = 0; j < m_width; ++j)
        {
            std::size_t idx = i * m_height + j;
            if (j == m_width - 1)
            {
                mapFile << static_cast<int>(m_objects.at(idx).GetTypes()[0])
                        << "\n";
            }
            else
            {
                mapFile << static_cast<int>(m_objects.at(idx).GetTypes()[0])
                        << " ";
            }
        }
    }
}

void Map::AddObject(std::size_t x, std::size_t y, ObjectType type)
{
    m_objects.at(y * m_width + x).Add(type);
}

void Map::RemoveObject(std::size_t x, std::size_t y, ObjectType type)
{
    m_objects.at(y * m_width + x).Remove(type);
}

Object& Map::At(std::size_t x, std::size_t y)
{
    return m_objects.at(y * m_width + x);
}

const Object& Map::At(std::size_t x, std::size_t y) const
{
    return m_objects.at(y * m_width + x);
}

std::vector<Position> Map::GetPositions(ObjectType type) const
{
    std::vector<Position> res;

    for (std::size_t y = 0; y < m_height; ++y)
    {
        for (std::size_t x = 0; x < m_width; ++x)
        {
            if (At(x, y).HasType(type))
            {
                res.emplace_back(std::make_pair(x, y));
            }
        }
    }

    return res;
}
}  // namespace baba_is_auto