/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** VerticalLayout
*/

#ifndef VERTICALLAYOUT_HPP_
    #define VERTICALLAYOUT_HPP_

    #include "ALayout.hpp"

namespace UI {

    /**
     * @brief Layout that organize the widgets vertically
     * 
     * [Widget1]
     * [Widget2]
     * [Widget3]
     * 
     * @tparam T The type of the elements of the layout
     */
    template <typename T>
    class VerticalLayout : public ALayout<T> {
        // Constructor & Destructor (default)
        public:

            /**
             * @brief Construct a new Vertical Layout object
             *
             * @param properties Properties of the layout
             */
            VerticalLayout(LayoutProperties properties);
            ~VerticalLayout() = default;

        // Methods
        public:

            /**
             * @brief Apply the layout logic to the container
             * Models :
             *  [Widget1]
             *  [Widget2]
             *  [Widget3]
             */
            void applyLayout() override;
    };
};

#endif /* !VERTICALLAYOUT_HPP_ */
