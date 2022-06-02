// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Games/Game.hpp>
#include <baba-is-auto/Games/Game.hpp>

#include <pybind11/pybind11.h>

using namespace baba_is_auto;

void AddGame(pybind11::module& m)
{
    pybind11::class_<Game>(m, "Game")
        .def(pybind11::init<std::string_view>())
        .def(pybind11::init<Map, RuleManager, PlayState, ObjectType>())
        .def("Reset", &Game::Reset)
        .def("GetMap", static_cast<Map& (Game::*)()>(&Game::GetMap))
        .def("GetMap", static_cast<const Map& (Game::*)() const>(&Game::GetMap))
        .def("GetRuleManager", &Game::GetRuleManager)
        .def("GetPlayState", &Game::GetPlayState)
        .def("GetPlayerIcon", &Game::GetPlayerIcon)
        .def("MovePlayer", &Game::MovePlayer)
        .def("CanMove", &Game::CanMove)
        .def(pybind11::pickle(
        [](const Game& g) { // dump
            return pybind11::make_tuple(g.GetMap(), g.GetRuleManager(), g.GetPlayState(), g.GetPlayerIcon());
        },
        [](pybind11::tuple t) { // load
            return Game{t[0].cast<Map>(), t[1].cast<RuleManager>(), t[2].cast<PlayState>(), t[3].cast<ObjectType>()};
        }
    ));
}