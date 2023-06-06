/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** HorizontalLayout
*/

#ifndef HORIZONTALLAYOUT_HPP_
    #define HORIZONTALLAYOUT_HPP_

    #include "ALayout.hpp"

namespace UI {

    /**
     * @brief Layout that organize the widgets horizontally
     * 
     * [Widget1] [Widget2] [Widget3]
     * 
     * @tparam T The type of the elements of the layout
     */
    template <typename T>
    class HorizontalLayout : public ALayout<T> {
        // Constructor & Destructor (default)
        public:

            /**
            * @brief Construct a new Horizontal Layout object
            *
            * @param properties Properties of the layout
            */
            HorizontalLayout(LayoutProperties properties);
            ~HorizontalLayout() = default;

        // Methods
        public:

            /**
             * @brief Apply the layout logic to the container
             * Models :
             *  [Widget1] [Widget2] [Widget3]
             */
            void applyLayout() override;
    };
};

#endif /* !HORIZONTALLAYOUT_HPP_ */
