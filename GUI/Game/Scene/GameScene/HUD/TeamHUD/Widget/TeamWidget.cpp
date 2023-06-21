/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** TeamWidget
*/

#include "TeamWidget.hpp"

namespace UI {
    //////////////////////////////
    // Constructor & Destructor //
    //////////////////////////////
    TeamWidget::TeamWidget() : AWidget() {};

    TeamWidget::TeamWidget(const std::string &team, int color, const sf::Vector2f &position) : AWidget(position, sf::Vector2f(WIDGET_WIDTH, WIDGET_HEIGHT))
    {
        // /---------|
        // | Picture |/--------|
        // |         | Team    |
        // \---------/\________/

        try {
            // Create the name of the team
            sf::Font *font = FontManager::getFont(UI::ARIAL);

            _team.setString(team);
            _team.setFont(*font);
            _team.setCharacterSize(FONT_SIZE);
            _team.setPosition(position.x + 95.0f, position.y + 60.0f);
            _team.setFillColor(sf::Color::Black);

            // Create the background of the widget
            sf::Texture *texture = TextureManager::getTexture(UI::TEAM_BACKGROUND);

            _background.setTexture(*texture);
            _background.setPosition(position);

            // Create the picture of the team
            texture = TextureManager::getTexture(UI::TEAM_PICTURE);

            _picture.setTexture(*texture);
            _picture.setColor(setTeamColor(color));
            _picture.setScale(2.15f, 2.15f);
            _picture.setPosition(position.x + 19.0f, position.y + 19.0f);

        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of TeamWidget : " << team << std::endl;
        }
    }

    TeamWidget::~TeamWidget() {};

    ///////////////
    // Operators //
    ///////////////
    TeamWidget &TeamWidget::operator=(const TeamWidget &team)
    {
        _team = team._team;
        _picture = team._picture;
        _background = team._background;

        return *this;
    }

    /////////////
    // Methods //
    /////////////
    void TeamWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        // Draw the background
        target.draw(_background, states);

        // Draw the team name
        target.draw(_team, states);

        // Draw the picture
        target.draw(_picture, states);
    }

    sf::Color TeamWidget::setTeamColor(int color)
    {
        if (color == 1)
            return sf::Color(220, 136, 85, 255);
        else if (color == 2)
            return sf::Color(202, 102, 213, 255);
        else if (color == 3)
            return sf::Color::Blue;
        else if (color == 4)
            return sf::Color::Green;
        else if (color == 5)
            return sf::Color::Magenta;
        else if (color == 6)
            return sf::Color::Red;
        else if (color == 7)
            return sf::Color::Yellow;
        else if (color == 8)
            return sf::Color::Cyan;
        return setTeamColor(color - 8);
    }

    bool TeamWidget::isInside(sf::Vector2f mousePos)
    {
        if (mousePos.x >= _background.getPosition().x && mousePos.x <= _background.getPosition().x + _background.getGlobalBounds().width && mousePos.y >= _background.getPosition().y && mousePos.y <= _background.getPosition().y + _background.getGlobalBounds().height)
            return true;
        return false;
    }

    /////////////
    // Setters //
    /////////////
    void TeamWidget::setPosition(const sf::Vector2f &position)
    {
        _background.setPosition(position);
        _team.setPosition(position.x + 95.0f, position.y + 68.0f);
        _picture.setPosition(position.x + 19.0f, position.y + 19.0f);
    }

    std::string TeamWidget::getTeamName() const
    {
        return _team.getString();
    }
};
