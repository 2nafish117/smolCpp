@ECHO OFF

if NOT exist .\Vignere\Vignere.exe (
    g++ .\Vignere\main.cpp -std=c++11 -o .\Vignere\Vignere
    ECHO .\Vignere\Vignere
)

if NOT exist .\Complex\Complex.exe (
    g++ .\Complex\Complex.cpp -std=c++11 -c -o .\Complex\Complex.o
    g++ .\Complex\main.cpp .\Complex\Complex.o -std=c++11 -o .\Complex\Complex
    ECHO .\Complex\Complex
)

if NOT exist .\dynamic_array\dynamic_array.exe (
    g++ .\dynamic_array\dynamic_array.cpp -std=c++11 -o .\dynamic_array\dynamic_array
    ECHO .\dynamic_array\dynamic_array
)

if NOT exist .\ParenBalance\ParenBalance.exe (
    g++ .\ParenBalance\main.cpp -std=c++11 -o .\ParenBalance\ParenBalance
    ECHO .\ParenBalance\ParenBalance
)

if NOT exist .\KeyLogger\KeyLogger.exe (
    g++ .\KeyLogger\main.cpp -std=c++11 -o .\KeyLogger\KeyLogger
    ECHO .\KeyLogger\KeyLogger
)

if NOT exist .\Matrix\Matrix.exe (
    g++ .\Matrix\main.cpp -std=c++11 -o .\Matrix\Matrix
    ECHO .\Matrix\Matrix
)



