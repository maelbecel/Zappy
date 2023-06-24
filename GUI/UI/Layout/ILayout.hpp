/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** ILayout
*/

#ifndef ILAYOUT_HPP_
    #define ILAYOUT_HPP_

    #include <SFML/Graphics.hpp>
    #include <memory>

    #include "IWidget.hpp"

namespace UI {

    /**
     * @brief Interface that design a layout system
     * A layout system is a way to organize the widgets in a container
     * Like <div> in HTML
     */
    class ILayout {

        // Methods
        public:

            /**
             * @brief Apply the layout logic to the container
             * Call this function after adding all the widgets to the container
             * // VerticalLayout example:
             * [Widget1]
             * [Widget2]
             * [Widget3]
             * 
             * // HorizontalLayout example:
             * [Widget1] [Widget2] [Widget3]
             * 
             * // GridLayout example:
             * [Widget1] [Widget2]
             * [Widget3] [Widget4]
             */
            virtual void applyLayout() = 0;

            /**
             * @brief Add an element to the layout
             * Call this function to add a widget to the container
             * @param element The element to add
             */
            virtual void addElement(std::shared_ptr<IWidget> element) = 0;

            /**
             * @brief Get the Elements object
             * Get the elements of the layout
             * @return IWidget The elements of the layout
             */
            virtual std::vector<std::shared_ptr<IWidget>> getElements() = 0;
    };

    /**
     * @brief Struct that design the properties of a layout
     * He stock :
     * - the type of the layout
     * - the position of the first widget
     * - the spacing between each widget
     */
    class LayoutProperties {

        // Constructor (default) & Destructor (default)
        public:
            LayoutProperties() = default;
            ~LayoutProperties() = default;

        // Attributes
        public:
            sf::Vector2f position; /*!< Position of the first widget */
            double spacing;        /*!< Spacing between each widget */
    };
};

#endif /* !ILAYOUT_HPP_ */
