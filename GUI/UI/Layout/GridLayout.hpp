/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** GridLayout
*/

#ifndef GRIDLAYOUT_HPP_
    #define GRIDLAYOUT_HPP_

    #include "ALayout.hpp"

namespace UI {
    /**
     * @brief Layout that organize the widgets in a grid
     * 
     * [Widget1] [Widget2]
     * [Widget3] [Widget4]
     * 
     * @tparam T The type of the elements of the layout
     */
    template <typename T>
    class GridLayout : public ALayout<T> {
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

        // Attributes
        private:
            size_t _nbColumns; /*!< Number of columns of the grid */
    };
};

#endif /* !GRIDLAYOUT_HPP_ */
