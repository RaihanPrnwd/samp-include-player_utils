# player_utils.inc
[![License: Freeware Creditware](https://img.shields.io/badge/license-Freeware%20Creditware-brightgreen.svg?style=flat-square)]()
[![Author](https://img.shields.io/badge/Author-Raihan%20Purnawadi-blue.svg?style=flat-square)](https://github.com/RaihanPrnwd)
**SA-MP Player Utility Include**  
_A collection of powerful utility functions for managing and scripting player features in SA-MP._  
**by Raihan Purnawadi**  
GitHub: https://github.com/RaihanPrnwd

---

## 🇮🇩 Deskripsi Bahasa Indonesia

`player_utils.inc` adalah sebuah _include_ untuk Scripting SA-MP yang berisi kumpulan fungsi utility dasar & lanjutan untuk player, siap dipakai pada GameMode (GM) Roleplay, Freeroam, TDM, hingga server custom lain.

Dengan hanya menambahkan:
```pawn
#include <player_utils>
```
ke skrip utama, puluhan fungsi siap pakai untuk player bisa langsung digunakan tanpa membuat dari nol. Cocok untuk menghemat waktu saat membuat/mengelola fitur-fitur player di server!

---

### Fitur Utama

- **Validasi Player**: Cek player valid, aktif, dan tidak NPC/mati.
- **Pesan/Chating**: Fungsi kirim pesan (private/Broadcast/OOC) berwarna ke player atau semua.
- **Pendataan Nama**: Ambil nama tanpa underscore, format nama, dll.
- **Lokasi**: Dapatkan jumlah player online, cari player terdekat, radius, dll.
- **Atribut Player**: Set/Get uang, full health/armor, freeze/unfreeze, ganti skin.
- **Status & Response**: Kick, kill, respawn player dengan aman.
- **Mute System**: Fungsi mute/unmute chat player via script.
- **Animasi Cepat**: Jalankan & hentikan animasi mudah.
- **Utility Kendaraan**: Cek player dalam kendaraan, vehicle ID, dll.
- **Random Player**: Ambil id player acak online (untuk event, dsb).

---

### Contoh Penggunaan

```pawn
SendMsg(playerid, 0x00FF00FF, "Selamat datang di server!");
if(IsActivePlayer(playerid)) { /* ... */ }
new id_terdekat = GetClosestPlayer(playerid);
TeleportPlayer(playerid, 1958.3, 1343.2, 15.3);
```

---

### Daftar Fungsi Penting

- `IsValidPlayer(playerid)`
- `IsActivePlayer(playerid)`
- `SendMsg(playerid, color, msg[])`
- `MsgToAll(color, msg[])`
- `SendGlobalOOC(color, msg[])`
- `GetClosestPlayer(playerid)`
- `IsPlayerInRadius(fromid, toid, radius)`
- `TeleportPlayer(playerid, x, y, z, a)`
- `SetPlayerMoneyEx(playerid, amount)`
- `SetPlayerFullHealth(playerid)`
- `MutePlayer(playerid)` dan `IsPlayerMuted(playerid)`
- `PlayerAnim(playerid, lib, name)`
- `IsPlayerInVehicleEx(playerid)`
- `GetRandomOnlinePlayer()`  
dan lain-lain.

---

### Instalasi & Integrasi

1. **Copy** file `player_utils.inc` ke folder `pawno/include` di server-mu.
2. Tambahkan di bagian atas script utama:
    ```pawn
    #include <player_utils>
    ```
3. Langsung gunakan fungsi utility di mana saja (filterscript/gamemode/callbacks).

---

## 🇬🇧 English Description

`player_utils.inc` is an include for SA-MP Scripting that packs both basic and advanced ready-to-use player utility functions. It is suitable for all GameModes (RP, Freeroam, TDM, custom). Stop writing repetitive code—simply:

```pawn
#include <player_utils>
```

and you have access to dozens of powerful and safe functions for player management!

---

### Features

- **Player Validation**: Check for valid, active, and non-NPC/wasted players.
- **Messaging & Chat**: Send (colored) messages to individual or all players (including global OOC chat).
- **Name Utilities**: Get player name without underscores, formatted names, etc.
- **Location Utilities**: Find closest player, count players online, check radius, etc.
- **Player Attributes**: Set/get money, full health/armor, freeze/unfreeze, change skin.
- **Player Response**: Safe kick, kill, respawn functions.
- **Mute System**: Mute/unmute a player's chat using code only.
- **Fast Animations**: Run/clear animations easily.
- **Vehicle Utilities**: Detect if player is in vehicle, get their vehicle ID, remove from vehicle.
- **Random Player**: Get a random online player (not self).

---

### Usage Example

```pawn
SendMsg(playerid, 0x00FF00FF, "Welcome to the server!");
if(IsActivePlayer(playerid)) { /* ... */ }
new closestid = GetClosestPlayer(playerid);
TeleportPlayer(playerid, 1958.3, 1343.2, 15.3);
```

---

### Main Functions List

- `IsValidPlayer(playerid)`
- `IsActivePlayer(playerid)`
- `SendMsg(playerid, color, msg[])`
- `MsgToAll(color, msg[])`
- `SendGlobalOOC(color, msg[])`
- `GetClosestPlayer(playerid)`
- `IsPlayerInRadius(fromid, toid, radius)`
- `TeleportPlayer(playerid, x, y, z, a)`
- `SetPlayerMoneyEx(playerid, amount)`
- `SetPlayerFullHealth(playerid)`
- `MutePlayer(playerid)` and `IsPlayerMuted(playerid)`
- `PlayerAnim(playerid, lib, name)`
- `IsPlayerInVehicleEx(playerid)`
- `GetRandomOnlinePlayer()`  
_and more!_

---

## License & Credit

- **ID:** Include ini dibuat oleh [Raihan Purnawadi](https://github.com/RaihanPrnwd)
- **EN:** This include was created by [Raihan Purnawadi](https://github.com/RaihanPrnwd)
- Bebas digunakan dan dimodifikasi—wajib mencantumkan kredit pembuat.  
  Free to use and edit—credit is required.

---

Selamat ngoding & happy coding, SAMP Scripters 🚀
