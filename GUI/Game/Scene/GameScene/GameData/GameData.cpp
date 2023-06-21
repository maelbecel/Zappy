/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** GameData
*/

#include "GameData.hpp"

uint GameData::timeUnit = 0;
uint GameData::gameSpeed = 0;

GameData::GameData() : _mapSize(sf::Vector2i(0, 0)), _gameScale(1.0f), _scale(sf::Vector2f(1.0f, 1.0f)), _position(sf::Vector2f(0, 900 / 2))
{
    _teams = std::vector<std::string>();

    GameData::timeUnit = 0;
    GameData::gameSpeed = 0;
};

int GameData::parse(std::string &line)
{
    if (line.find("msz") != std::string::npos)     // msz = map size
        return setMapSize(line);
    else if (line.find("sgt") != std::string::npos) // sgt = time unit
        return setTimeUnit(line);
    else if (line.find("sst") != std::string::npos) // sst = time unit with modification
        return addTimeUnit(line);
    else if (line.find("bct") != std::string::npos) // bct = content of a tile
        return setTileContent(line);
    else if (line.find("tna") != std::string::npos) // tna = team name
        return setTeamName(line);
    else if (line.find("pnw") != std::string::npos) // pnw = Connection of a new player
        return setPlayer(line);
    else if (line.find("pdi") != std::string::npos) // pdi = Death of a player
        return deletePlayer(line);
    else if (line.find("ppo") != std::string::npos) // ppo = Position of the player
        return setPlayerMovement(line);
    else if (line.find("plv") != std::string::npos) // plv = Player's level
        return setPlayerLevel(line);
    else if (line.find("pin") != std::string::npos) // pin = Player's inventory
        return setPlayerInventory(line);
    else if (line.find("pex") != std::string::npos) // pex = Expulsion
        return PlayerExpulsion(line);
    else if (line.find("pbc") != std::string::npos) // pbc = Broadcast
        return PlayerBroadcast(line);
    else if (line.find("pdr") != std::string::npos) // pdr = Player drop resources
        return PlayerDropResource(line);
    else if (line.find("pgt") != std::string::npos) // pgt = Player collecting resources
        return PlayerCollectResource(line);

    // Eggs Command
    else if (line.find("enw") != std::string::npos) // enw = An egg was laid by a player
        return CreateEgg(line);
    else if (line.find("edi") != std::string::npos) // edi = Death of an egg
        return KillEgg(line);
    else if (line.find("ebo") != std::string::npos) // ebo = Player connection from an egg
        return KillEgg(line);
    else
        return 0;
}

int GameData::setMapSize(const std::string &mapSize)
{
    if (_mapSize.x != 0 && _mapSize.y != 0)
        return 0;
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
    return 0;
}

int GameData::setTimeUnit(const std::string &timeUnit)
{
    std::string temp;
    std::string t;

    std::stringstream(timeUnit) >> temp >> t;

    try {
        int time = std::stoi(t);

        if (GameData::timeUnit == 0)
            GameData::gameSpeed = time;

        GameData::timeUnit = time;
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::setTimeUnit");
    }
    return 0;
}

int GameData::addTimeUnit(const std::string &timeUnit)
{
    std::string temp;
    std::string t;

    std::stringstream(timeUnit) >> temp >> t;

    try {
        int time = std::stoi(t);

        GameData::gameSpeed = time;
        GameData::timeUnit += time;
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::addTimeUnit");
    }
    return 0;
}

int GameData::setMultipleTileContent(const std::string &tiles)
{
    std::vector<std::string> tilesVector;

    std::stringstream ss(tiles);
    std::string temp;

    while (ss >> temp)
        tilesVector.push_back(temp);
    
    for (auto &tile : tilesVector)
        setSingleTileContent(tile);
    return 0;
}

int GameData::setSingleTileContent(const std::string &tile)
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

    std::stringstream(tile) >> temp >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6;

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

        
        // Check if the map[x][y] already exists
        if (_map.find(std::make_pair(xInt, yInt)) != _map.end()) {
            _map[std::make_pair(xInt, yInt)]->setNewResources(q0Int, q1Int, q2Int, q3Int, q4Int, q5Int, q6Int);
            return 0;
        }
        _map[std::make_pair(xInt, yInt)] = std::make_shared<Tile>(Tile(sf::Vector2i(xInt, yInt), q0Int, q1Int, q2Int, q3Int, q4Int, q5Int, q6Int));
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::setSingleTileContent");
    }
    return 0;
}

int GameData::setTileContent(const std::string &tileContent)
{
    if (tileContent.find("bct") != tileContent.rfind("bct"))
        return setMultipleTileContent(tileContent);
    return setSingleTileContent(tileContent);
}

int GameData::setTeamName(const std::string &name)
{
    std::string temp;
    std::string n;

    std::stringstream(name) >> temp >> n;

    for (auto &team : _teams)
        if (team.compare(n) == 0)
            return 0;
    _teams.push_back(n);
    return 1;
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

std::shared_ptr<Tile> GameData::getTile(int x, int y) const
{
    if (_map.find(std::make_pair(x, y)) == _map.end())
        return nullptr;
    return _map.at(std::make_pair(x, y));
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

int GameData::setPlayer(const std::string &player)
{
    std::string temp;
    std::string name;
    std::string x;
    std::string y;
    std::string orientation;
    std::string level;
    std::string team;

    std::stringstream(player) >> temp >> name >> x >> y >> orientation >> level >> team;

    try {
        // Check if the #n players already exists
        if (_players.find(name) != _players.end())
            return 0;

        int xInt = std::stoi(x);
        int yInt = std::stoi(y);
        int oriantationInt = std::stoi(orientation);
        int levelInt = std::stoi(level);

        int index = 1;

        for (auto &t : _teams) {
            if (t.compare(team) == 0)
                break;
            index++;
        }

        _players[name] = std::make_shared<Player>(Player(sf::Vector2i(xInt, yInt), oriantationInt, levelInt, team, index));
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::setPlayer");
    }
    return 0;
}

int GameData::setPlayerMovement(const std::string &player)
{
    std::string temp;
    std::string name;
    std::string x;
    std::string y;
    std::string orientation;

    std::stringstream(player) >> temp >> name >> x >> y >> orientation;

    try {
        // Check if the #n players didn't exists
        if (_players.find(name) == _players.end())
            return 0;
        
        int xInt = std::stoi(x);
        int yInt = std::stoi(y);
        int oriantationInt = std::stoi(orientation);

        _players[name]->setPosition(sf::Vector2i(xInt, yInt), oriantationInt);
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::setPlayerMovement");
    }
    return 0;
}

int GameData::setPlayerLevel(const std::string &player)
{
    std::string temp;
    std::string name;
    std::string level;

    std::stringstream(player) >> temp >> name >> level;

    try {
        // Check if the #n players didn't exists
        if (_players.find(name) == _players.end())
            return 0;

        int levelInt = std::stoi(level);

        _players[name]->setLevel(levelInt);
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::setPlayerLevel");
    }
    return 0;
}

int GameData::setPlayerInventory(const std::string &player)
{
    std::string temp;
    std::string name;
    std::string x;
    std::string y;
    std::string q0;
    std::string q1;
    std::string q2;
    std::string q3;
    std::string q4;
    std::string q5;
    std::string q6;

    std::stringstream(player) >> temp >> name >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6;

    try {
        // Check if the #n players didn't exists
        if (_players.find(name) == _players.end())
            return 0;

        int xInt = std::stoi(x);
        int yInt = std::stoi(y);

        _players[name]->setPosition(sf::Vector2i(xInt, yInt));

        int q0Int = std::stoi(q0);
        int q1Int = std::stoi(q1);
        int q2Int = std::stoi(q2);
        int q3Int = std::stoi(q3);
        int q4Int = std::stoi(q4);
        int q5Int = std::stoi(q5);
        int q6Int = std::stoi(q6);

        _players[name]->setInventory(q0Int, q1Int, q2Int, q3Int, q4Int, q5Int, q6Int);
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::setPlayerInventory");
    }
    return 0;
}

int GameData::PlayerExpulsion(const std::string &player)
{
    std::string temp;
    std::string name;

    std::stringstream(player) >> temp >> name;

    try {
        // Check if the #n players didn't exists
        if (_players.find(name) == _players.end())
            return 0;
        sf::Vector2i pos = _players[name]->getPosition();

        _players[name]->setExpulsion(true);
        for (auto &player : _players) {
            if (player.second->getPosition() == pos) {
                player.second->expulse();
                return 0;
            }
        }
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::PlayerExpulsion");
    }
    return 0;
}

int GameData::PlayerBroadcast(const std::string &player)
{
    std::string temp;
    std::string name;

    std::stringstream(player) >> temp >> name;

    try {
        // Check if the #n players didn't exists
        if (_players.find(name) == _players.end())
            return 0;

        _players[name]->setBroadcast(true);
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::setPlayerBroadcast");
    }
    return 0;
}

int GameData::PlayerCollectResource(const std::string &player)
{
    std::string temp;
    std::string name;
    std::string nomber;

    std::stringstream(player) >> temp >> name >> nomber;

    try {
        // Check if the #n players didn't exists
        if (_players.find(name) == _players.end())
            return 0;

        std::shared_ptr<Tile> tile = getTile(_players[name]->getPosition().x, _players[name]->getPosition().y);

        _players[name]->collectResource(std::stoi(nomber), tile);

    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::setPlayerCollectResource");
    }
    return 0;
}

int GameData::PlayerDropResource(const std::string &player)
{
    std::string temp;
    std::string name;
    std::string nomber;

    std::stringstream(player) >> temp >> name >> nomber;

    try {
        // Check if the #n players didn't exists
        if (_players.find(name) == _players.end())
            return 0;

        std::shared_ptr<Tile> tile = getTile(_players[name]->getPosition().x, _players[name]->getPosition().y);

        _players[name]->dropResource(std::stoi(nomber), tile);
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::setPlayerDropResource");
    }
    return 0;
}

int GameData::deletePlayer(const std::string &player)
{
    std::string temp;
    std::string name;

    std::stringstream(player) >> temp >> name;

    try {
        // Check if the #n players didn't exists
        if (_players.find(name) == _players.end())
            return 0;

        _players.erase(name);
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::deletePlayer");
    }
    return 0;
}

std::map<std::string, std::shared_ptr<Player>> GameData::getPlayers() const
{
    return _players;
}

int GameData::CreateEgg(const std::string &egg)
{
    std::string temp;
    std::string egg_name;
    std::string player_name;
    std::string x;
    std::string y;

    std::stringstream(egg) >> temp >> egg_name >> player_name >> x >> y;

    try {
        // Player didn't exists
        if (_players.find(player_name) == _players.end())
            return 0;

        // Check if the #e eggs didn't exists
        if (_eggs.find(egg_name) != _eggs.end())
            return 0;

        int index = 1;

        for (auto &team : _teams) {
            if (team.compare(_players[player_name]->getTeam()) == 0)
                break;
            index++;
        }

        _eggs[egg_name] = std::make_shared<Eggs>(sf::Vector2i(std::stoi(x), std::stoi(y)), player_name, _players[player_name]->getTeam(), index);
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::CreateEgg");
    }
    return 2;
}

int GameData::KillEgg(const std::string &egg)
{
    std::string temp;
    std::string egg_name;

    std::stringstream(egg) >> temp >> egg_name;

    try {
        // Check if the #e eggs didn't exists
        if (_eggs.find(egg_name) == _eggs.end())
            return 0;

        _eggs.erase(egg_name);
    } catch (std::invalid_argument &e) {
        throw Error::InvalidArgument("GameData::KillEgg");
    }
    return 0;
}

std::map<std::string, std::shared_ptr<Eggs>> GameData::getEggs() const
{
    return _eggs;
}
