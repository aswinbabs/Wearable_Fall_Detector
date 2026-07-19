idf_component_register(

    SRCS
        "src/led.cpp"
        "src/button.cpp"
        "src/buzzer.cpp"

    INCLUDE_DIRS
        "include"

    REQUIRES
        DRIVER
        UTILITY
        freertos
)