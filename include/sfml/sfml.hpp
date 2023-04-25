/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-nathan.donat-filliod
** File description:
** opengl
*/

#ifndef OPENGL_HPP_
#define OPENGL_HPP_

#include "graphicals/ADisplayModule.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"

class LibSfml : public ADisplayModule {
    public:
        LibSfml();
        ~LibSfml() = default;

        void createWindow(int, int) override;
        void closeWindow() override;
        void refreshWindow() override;
        virtual int detectInput() override;
        virtual std::tuple<int, int> detectMouse() override;
        void displayMap(std::vector<std::string>, int, int, int) override;
        void event(void);
        void createShapes();
        void setShapes();
        void setLevel(int);
        void setScore(int);
        void displayGame(std::vector<std::string>);
        void displayMenu(std::vector<std::string>);
    private:
        sf::RenderWindow win;
        sf::Event ev;
        sf::CircleShape wall;
	    sf::CircleShape fruit;
	    sf::CircleShape player;
	    sf::CircleShape floor;
        sf::CircleShape head;
        sf::Font font;
        sf::Text _score;
        sf::Text _lvl;
        sf::Text _text;
};

#endif /* !OPENGL_HPP_ */
