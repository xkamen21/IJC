# IJC

    - Napište testovací program "steg-decode.c", kde ve funkci main načtete ze
    souboru zadaného jako jediný argument programu obrázek ve formátu PPM
    a v něm najdete uloženou "tajnou" zprávu. Zprávu vytisknete na stdout.

    - Zpráva je řetězec znaků (char, včetně '\0') uložený po jednotlivých bitech
    (počínaje LSb) na nejnižších bitech (LSb) vybraných bajtů barevných složek
    v datech obrázku. Dekódování ukončete po dosažení '\0'.
    Pro DU1 budou vybrané bajty určeny prvočísly (počínaje od 23) -- použijte
    Eratostenovo síto a začněte prvočíslem 23.
    Velikost bitového pole musí odpovídat velikosti obrazových dat.

    - Program použije error_exit v případě chyby čtení souboru (chybný formát),
    a v případě, že zpráva není korektně ukončena '\0'. Předpokládejte
    možnost uložení textu zprávy ve formátu UTF-8.

- Použijte program "make" pro překlad/sestavení programu.
- Testovací příkaz:  ./steg-decode du1-obrazek.ppm
