/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ALayout
*/

#ifndef ALAYOUT_HPP_
    #define ALAYOUT_HPP_

    #include "ILayout.hpp"

    #include <vector>

namespace UI {

    /**
     * @brief Abstract class for layouts
     *
     * @tparam T The type of the elements of the layout
     */
    template <typename T>
    class ALayout : public ILayout {
        // Constructor & Destructor (default)
        public:

            /**
             * @brief Construct a new ALayout object
             *
             * @param properties Properties of the layout
             */
            ALayout(LayoutProperties properties) : _properties(properties) {};
            ~ALayout() = default;

        // Pure Virtual Methods
        public:

            /**
             * @brief Apply the layout logic to the container
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

        // Override Methods
        public:

            /**
            * @brief Add an element to the layout
            *
            * @param element The element to add
            */
            void addElement(T &element) override
            {
                _elements.push_back(&element);
            }

        // Attributes
        protected:
            LayoutProperties _properties; /*!< Properties of the layout */
            std::vector<T *> _elements;   /*!< Elements of the layout */
    };
};

#endif /* !ALAYOUT_HPP_ */
