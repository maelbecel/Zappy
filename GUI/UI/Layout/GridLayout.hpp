/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** GridLayout
*/

#ifndef GRIDLAYOUT_HPP_
    #define GRIDLAYOUT_HPP_

    #include "ILayout.hpp"

namespace UI {
    /**
     * @brief Layout that organize the widgets in a grid
     * 
     * [Widget1] [Widget2]
     * [Widget3] [Widget4]
     */
    class GridLayout : public ILayout {

        // Constructor & Destructor (default)
        public:

            /**
             * @brief Construct a new Grid Layout object
             *
             * @param properties Properties of the layout
             * @param nbColumns Number of columns of the grid
             */
            GridLayout(LayoutProperties properties, size_t nbColumns);

            ~GridLayout() = default;

        // Methods
        public:

            /**
             * @brief Apply the layout logic to the container
             * Models :
             *  [Widget1] [Widget2]
             *  [Widget3] [Widget4]
             */
            void applyLayout() override;

            /**
             * @brief Add an element to the layout
             *
             * @param element The element to add
             */
            void addElement(std::shared_ptr<IWidget> element) override;

            /**
             * @brief Get the Elements object
             *
             * @return IWidget The elements of the layout
             */
            std::vector<std::shared_ptr<IWidget>> getElements() override;

        // Attributes
        private:
            std::vector<std::shared_ptr<IWidget>> _elements; /*!< The elements of the layout */
            LayoutProperties properties;                     /*!< Properties of the layout */
            size_t _nbColumns;                               /*!< Number of columns of the grid */
    };
};

#endif /* !GRIDLAYOUT_HPP_ */
