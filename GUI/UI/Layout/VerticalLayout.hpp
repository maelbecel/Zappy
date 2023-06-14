/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** VerticalLayout
*/

#ifndef VERTICALLAYOUT_HPP_
    #define VERTICALLAYOUT_HPP_

    #include "ILayout.hpp"

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
    class VerticalLayout : public ILayout {
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

            /**
             * @brief Add an element to the layout
             *
             * @param element The element to add
             */
            void addElement(T &element) override;

        // Attributes
        private:
            std::vector<T *> _elements; /*!< The elements of the layout */
            LayoutProperties properties; /*!< Properties of the layout */
    };
};

#endif /* !VERTICALLAYOUT_HPP_ */
