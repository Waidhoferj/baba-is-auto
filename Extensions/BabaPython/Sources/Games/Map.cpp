// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Games/Map.hpp>
#include <baba-is-auto/Games/Map.hpp>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

using namespace baba_is_auto;

void AddMap(pybind11::module& m)
{
    pybind11::class_<Map>(m, "Map")
        .def(pybind11::init<>())
        .def(pybind11::init<std::size_t, std::size_t>())
        .def(pybind11::init<std::size_t, std::size_t, std::vector<Object>, std::vector<Object>>())
        .def("Reset", &Map::Reset)
        .def("GetWidth", &Map::GetWidth)
        .def("GetHeight", &Map::GetHeight)
        .def("Load", &Map::Load)
        .def("Write", &Map::Write)
        .def("AddObject", &Map::AddObject)
        .def("RemoveObject", &Map::RemoveObject)
        .def("At",
             static_cast<Object& (Map::*)(std::size_t, std::size_t)>(&Map::At))
        .def(
            "At",
            static_cast<const Object& (Map::*)(std::size_t, std::size_t) const>(
                &Map::At))
        .def("GetPositions", &Map::GetPositions)
        .def("GetInitObjects", &Map::GetInitObjects)
        .def("GetObjects", &Map::GetObjects)
        .def(pybind11::pickle(
        [](const Map& m) { // dump
            return pybind11::make_tuple(m.GetWidth(), m.GetHeight(), m.GetInitObjects(), m.GetObjects());
        },
        [](pybind11::tuple t) { // load
            return Map{t[0].cast<std::size_t>(), t[1].cast<std::size_t>(), t[2].cast<std::vector<Object>>(), t[3].cast<std::vector<Object>>()};
        }
        ));
}