/******************************************************************************
 * @file        button.hpp
 * @brief       Push button module for GuardianBand.
 *
 * @details
 * Provides an abstraction for the GuardianBand push button. The module
 * initializes the GPIO and provides button state information. The interface
 * is designed to be extended later with debouncing, click detection and
 * press duration handling without changing the application layer.
 *
 * Author : Aswin Babu K
 ******************************************************************************/

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "gpio_driver.hpp"

class Button
{
public:

    Button();

    ~Button() = default;

    Button(const Button&) = delete;
    Button& operator=(const Button&) = delete;

    /**
     * @brief Initialize button GPIO.
     *
     * @return ESP_OK on success.
     */
    esp_err_t init();

    /**
     * @brief Update button state.
     *
     * @note Reserved for future debouncing and event detection.
     */
    void update();

    /**
     * @brief Check whether the button is currently pressed.
     *
     * @return true if pressed.
     * @return false otherwise.
     */
    bool isPressed() const;

private:

    GpioDriver m_gpio;
};

#endif // BUTTON_HPP