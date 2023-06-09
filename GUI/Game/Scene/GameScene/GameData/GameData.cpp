/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** GameData
*/

#include "GameData.hpp"

uint GameData::timeUnit = 0;

GameData::GameData() : _mapSize(sf::Vector2i(0, 0)), _gameScale(1.0f), _scale(sf::Vector2f(1.0f, 1.0f)), _position(sf::Vector2f(0, 900 / 2))
{
    _teams = std::vector<std::string>();

    GameData::timeUnit = 0;
};

void GameData::parse(std::string &line)
{
    if (line.find("msz") != std::string::npos)     // msz = map size
        return setMapSize(line);
    else if (line.find("sgt") != std::string::npos) // sgt = time unit
        return setTimeUnit(line);
    else if (line.find("bct") != std::string::npos) // bct = content of a tile
        return setTileContent(line);
    else if (line.find("tna") != std::string::npos) // tna = team name
        return setTeamName(line);
    // TODO: add other commands
    else
        return;
}

void GameData::setMapSize(const std::string &mapSize)
{
    if (_mapSize.x != 0 && _mapSize.y != 0)
        return;
    std::string temp;
    std::string x;
    std::string y;

    std::stringstream(mapSize) >> temp >> x >> y;

    try {
        _mapSize.x = std::stoi(x);
        _mapSize.y = std::stoi(y);
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::setMapSize");
    }

    _noise.setSize(_mapSize.x, _mapSize.y);
    _noise.generateNoise();
}

void GameData::setTimeUnit(const std::string &timeUnit)
{
    std::string temp;
    std::string t;

    std::stringstream(timeUnit) >> temp >> t;

    try {
        GameData::timeUnit = std::stoi(t);
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::setTimeUnit");
    }
}

void GameData::setTileContent(const std::string &tileContent)
{
    std::string temp;
    std::string x;
    std::string y;
    std::string q0;
    std::string q1;
    std::string q2;
    std::string q3;
    std::string q4;
    std::string q5;
    std::string q6;

    std::cout << tileContent << std::endl;
    std::stringstream(tileContent) >> temp >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6;

    try {
        int xInt = std::stoi(x);
        int yInt = std::stoi(y);
        int q0Int = std::stoi(q0);
        int q1Int = std::stoi(q1);
        int q2Int = std::stoi(q2);
        int q3Int = std::stoi(q3);
        int q4Int = std::stoi(q4);
        int q5Int = std::stoi(q5);
        int q6Int = std::stoi(q6);

        _map[std::make_pair(xInt, yInt)] = std::make_shared<Tile>(Tile(sf::Vector2i(xInt, yInt), q0Int, q1Int, q2Int, q3Int, q4Int, q5Int, q6Int));
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::setTileContent");
    }
}

void GameData::setTeamName(const std::string &name)
{
    std::string temp;
    std::string n;

    std::stringstream(name) >> temp >> n;

    for (auto &team : _teams)
        if (team.compare(n) == 0)
            return;
    _teams.push_back(n);
}

sf::Vector2i GameData::getMapSize() const
{
    return _mapSize;
}

std::vector<std::string> GameData::getTeams() const
{
    return _teams;
}

std::map<std::pair<int, int>, std::shared_ptr<Tile>> GameData::getMap() const
{
    return _map;
}

uint GameData::getTimeUnit() const
{
    return GameData::timeUnit;
}

double **GameData::getNoise() const
{
    return _noise.getNoise();
}

sf::Vector2f GameData::getScale() const
{
    return _scale;
}

sf::Vector2f GameData::getPosition() const
{
    return _position;
}

void GameData::setScale(const sf::Vector2f &scale)
{
    if (scale.x > 10.0f || scale.y > 10.0f)
        return;
    else if (scale.x < 0.0f || scale.y < 0.0f)
        return;
    _scale = scale;
}

void GameData::setPosition(const sf::Vector2f &position)
{
    _position = position;
}
