// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Rules/Rule.hpp>
#include <baba-is-auto/Rules/Rule.hpp>

#include <pybind11/pybind11.h>

using namespace baba_is_auto;

void AddRule(pybind11::module& m)
{
    pybind11::class_<Rule>(m, "Rule")
        .def(pybind11::init<Object, Object, Object>())
        .def("GetObjects", &Rule::GetObjects)
        .def("__eq__",
             [](const Rule& left, const Rule& right) { return left == right; })
        .def(pybind11::pickle(
        [](const Rule& r) { // dump
            std::tuple<Object, Object, Object> objects = r.GetObjects();
            return pybind11::make_tuple(std::get<0>(objects), std::get<1>(objects), std::get<2>(objects));
        },
        [](pybind11::tuple t) { // load
            return Rule{t[0].cast<Object>(), t[1].cast<Object>(), t[2].cast<Object>()};
        }
        ));
}