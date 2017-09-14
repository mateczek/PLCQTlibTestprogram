# Test_qtPLC_lib
To jest program testowy do biblioteki "qtPLC_lib"
1. Skompiluj bibliotekę 
2. Powstały w wyniku kompilacji plik "*.a" skopiuj do katalogu "../lib". W tym samym katalogu umieść plik nagłówkoowy biblioteki
3. Katalog "lib" ma być umieszczony obok katalogu głównego programu. Położenie katalogu z biblioteką implikują wpisy w pliku "*.pro" programu. 
4. Wgraj do sterownika PLC blok danych db30 skonfigurowany jak na zdjęciu https://github.com/mateczek/PLCQTlibTestprogram/blob/master/db30.png
5. Zmień w programie adres ip sterownika na prawidłowy
6. Skompiluj program i uruchom. Jeśli steronwik jest w sieci z wgranym prawidłowym blokiem danch to program powinien się skomunikować i odczytać dane z plc.

program testowany na:

1. windows mingw32
2. window mingw64 (msys2)
3. linux gcc64 
4. rasperyPi
