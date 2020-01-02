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

if NOT exist .\DArray\DArray.exe (
    g++ .\DArray\main.cpp -std=c++11 -o .\DArray\DArray
    ECHO .\DArray\DArray
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

if NOT exist .\Ackerman\Ackerman.exe (
    g++ .\Ackerman\main.cpp -std=c++11 -o .\Ackerman\Ackerman
    ECHO .\Ackerman\Ackerman
)

if NOT exist .\RegulaFalsi\RegulaFalsi.exe (
    g++ .\RegulaFalsi\main.cpp -std=c++11 -o .\RegulaFalsi\RegulaFalsi
    ECHO .\RegulaFalsi\RegulaFalsi
)

if NOT exist .\NimsGame\NimsGame.exe (
    g++ .\NimsGame\main.cpp -std=c++11 -o .\NimsGame\NimsGame
    ECHO .\NimsGame\NimsGame
)

if NOT exist .\Hanoi\Hanoi.exe (
    g++ .\Hanoi\main.cpp -std=c++11 -o .\Hanoi\Hanoi
    ECHO .\Hanoi\Hanoi
)

if NOT exist .\NQueens\NQueens.exe (
    g++ .\NQueens\main.cpp -std=c++11 -o .\NQueens\NQueens
    ECHO .\NQueens\NQueens
)

g++ .\InterpolationSearch\main.cpp -std=c++11 -o .\InterpolationSearch\InterpolationSearch

if NOT exist .\InterpolationSearch\InterpolationSearch.exe (
    g++ .\InterpolationSearch\main.cpp -std=c++11 -o .\InterpolationSearch\InterpolationSearch
    ECHO .\InterpolationSearch\InterpolationSearch
)
