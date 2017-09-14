# Test_qtPLC_lib
To jest program testowy do biblioteki "qtPLC_lib"
1. skompiluj bibliotekę 
2. powstały w wyniku kompilacji plik "*.a" skopiuj do katalogu "../lib" w tym samym katalogu umieść plik nagłówkoowy biblioteki
3. katalog lim ma być umieszczony obok katalogu głównego programu. położenie katalogu z biblioteką implikują wpisy w pliku "*.pro" programu. 
4. wgraj do sterownika PLC blok danych db30 skonfigurowany jak na zdjęciu
5. zmień adres ip sterownika na swój własny 
6. skompiluj program i uruchom. jeśli steronwik jest w sieci z wgranym prawidłowym blokiem danch program powinien się skomunikować i odczytać dane z plc.

program testowany na:

windows mingw32
window mingw64 (msys2)
linux gcc64 
rasperyPi
