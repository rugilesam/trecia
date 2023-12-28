# trecia

**Įdiegimo bei naudojimosi instrukcija:** reikia atsisiųsti failus ir sudėti į bendrą aplanką. Jame sukurkite du aplankus, "src" ir "include", į "src" dedame visus .cpp failus, o į "include" visus .h failus. Toliau instrukcijos pateiktos "mac OS" operacinės naudotojiems:
1) Atsidaryti aplankalo direkorijos terminalą;
2) Tada įveskite "chmod +x RUNMEE.sh"
3) Po to įveskite "./RUNMEE.sh"
   Toliau įvedinėti tai ko prašo programa terminale.

**Instrukcija su .dmg failu:** repozitorijoje yra prisegtas failas "v3.0.dmg", skirtas atlikti panašią funkciją, kaip atlieka setup.exe/msi failai. Jų nebuvo galima realizuoti, nes dirbama ant macOS operacinės sistemos. Todėl buvo naudojamas .dmg failas. Su .dmg failo pagalba, galima dalintis exec failu su kitais macOS naudotojais. 





Atlikta analizė, skirta palyginti spartą naudojant struktūrą ir klasę. Analizė atlikta su vektoriaus konteinerius, greičiausia strategija ir 100000, 1000000 failais.

| | struct: 100 000 | class: 100 000 | struct: 1 000 000 | class: 1 000 000|
|---|---|---|---|---|
|Įrašų nuskaitymas | 0,15551 s|0,10456 s | 1,22481 s|1,22002 s|
|Surūšiavimas į dvi grupes | 0,00376 s  | 0,00372 s | 0,03544 s| 0,03610 s |
|Kietiakų įrašymas į failą |0,14884 s |0,16007 s | 1,55084 s|1,53779 s |
|Vargšiukų įrašymas į failą |0,03850 s |0,03982 s | 0,38948 s|0,38379 s|
|Testo laikas | 0,38915 s|0,35206 s | 3,62439 s|3,44468 s |

Palyginimas: class spartesnė, nei struct.

Kompiuterio duomenys:

CPU - Apple M1 chip 8-core CPU with 4 perform­ance cores and 4 efficiency cores

RAM - 16 GB

HDD - 256 GB SSD
