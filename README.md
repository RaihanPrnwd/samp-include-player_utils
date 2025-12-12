=======================================================================
README - player_utils.inc
=======================================================================

Bahasa Indonesia [ID] / English [EN]
-------------------------------------

====================================
ID [Penjelasan & Dokumentasi Lengkap]
====================================

player_utils.inc adalah include Pawn/PAWN Script untuk San Andreas Multiplayer (SAMP), 
yang menyajikan berbagai fungsi utilitas siap pakai untuk memudahkan pengembangan fitur-fitur player, 
mulai dari validasi, messaging, manipulasi posisi, status, hingga utility kendaraan.

// English Translation
player_utils.inc is a Pawn/PAWN Script include for San Andreas Multiplayer (SAMP),
which provides various ready-to-use utility functions to ease the development of player features,
ranging from validation, messaging, position manipulation, status checking, to vehicle utilities.

Dibuat oleh: Raihan Purnawadi  
Github: https://github.com/RaihanPrnwd  

-------------------------
FITUR UTAMA / MAIN FEATURES
-------------------------

1. **Validasi Player**  
   - *IsValidPlayer(playerid)* : Mengecek apakah playerid valid dan terhubung.
     // English: Checks if the playerid is valid and connected.
   - *IsActivePlayer(playerid)* : Mengecek apakah player masih aktif (bukan NPC, tidak mati).
     // English: Checks if the player is still active (not NPC, not dead).

2. **Pengiriman Pesan (Messaging)**  
   - *SendMsg(playerid, color, msg[])* : Kirim pesan warna ke player dengan validasi.
     // English: Sends a colored message to a player with validation.
   - *MsgToAll(color, msg[])* : Kirim pesan ke semua player online.
     // English: Sends a message to all online players.
   - *SendGlobalOOC(color, msg[])* : Broadcast OOC/chat ke semua player (fungsi khusus, mirip MsgToAll).
     // English: Broadcasts OOC/chat to all players (special function, similar to MsgToAll).

3. **Nama Player & Data**  
   - *GetPlayerNameEx(playerid, dest[], len)* : Ambil nama player TANPA underscore (diganti spasi).  
     // English: Gets the player name WITHOUT underscores (replaced with spaces).
   - *pName(playerid)* : Dapatkan nama player sebagai string (dengan underscore, jika ada).
     // English: Gets the player's name as a string (with underscores if present).

4. **Posisi, Lokasi, & Radius**  
   - *CountOnlinePlayers()* : Hitung jumlah player online saat ini.
     // English: Counts the current number of online players.
   - *GetClosestPlayer(playerid)* : Cari player terdekat dari playerid.
     // English: Finds the nearest player to playerid.
   - *IsPlayerInRadius(fromid, toid, Float:radius)* : Cek dua player apakah dalam radius tertentu satu sama lain.
     // English: Checks if two players are within a certain radius from each other.

5. **Teleport Utility**  
   - *TeleportPlayer(playerid, Float:x, Float:y, Float:z, Float:a=0.0)* : Teleport player aman ke posisi, termasuk facing angle & reset kamera.
     // English: Safely teleports player to a position, including facing angle & camera reset.

6. **Atribut Player (Health, Money, Armor, Skin, dsb.)**  
   - *SetPlayerMoneyEx(playerid, amount)* : Set uang player (reset lalu beri amount).
     // English: Sets player money (reset then give amount).
   - *GetPlayerMoneyEx(playerid)* : Ambil uang player (bisa diubah ke custom system).
     // English: Gets player money (can be adapted for custom money system).
   - *SetPlayerFullHealth(playerid)* : Set health ke 100% instan.
     // English: Instantly sets player's health to 100%.
   - *SetPlayerFullArmour(playerid)* : Set armour ke 100%.
     // English: Sets player's armour to 100%.
   - *SetPlayerSkinEx(playerid, skinid)* : Ganti skin player (dengan validasi).
     // English: Change player's skin (with validation).
   - *FreezePlayer(playerid)* : Membekukan/disable movement.
     // English: Freezes/disables movement.
   - *UnfreezePlayer(playerid)* : Membebaskan movement.
     // English: Unfreezes movement.

7. **Status & State**  
   - *KickPlayer(playerid, msg[])* : Kick player dengan pesan custom & delay short timer.
     // English: Kicks player with custom message & short timer delay.
   - *KillPlayer(playerid)* : Membunuh/mematikan player langsung.
     // English: Instantly kills the player.
   - *RespawnPlayer(playerid)* : Respawn/force spawn ke spawn aslinya.
     // English: Respawns/forces spawn to original spawn.

8. **Mute / Unmute System (Low-level)**  
   - Variabel: *g_PlayerMuted[MAX_PLAYERS]* (bool)
     // English: Variable (bool array): g_PlayerMuted[MAX_PLAYERS]
   - *MutePlayer(playerid)* : Membisukan player (muted).
     // English: Mutes the player.
   - *UnmutePlayer(playerid)* : Membuka mute.
     // English: Unmutes the player.
   - *IsPlayerMuted(playerid)* : Cek apakah player dibisukan.
     // English: Checks if the player is muted.
   - Cocok dicolok di event OnPlayerText GM/FS kamu!
     // English: Suitable for hooking inside the OnPlayerText event in your GM/FS!
   - Contoh:  if(IsPlayerMuted(playerid)) return 0;
     // English Example: if(IsPlayerMuted(playerid)) return 0;

9. **Utility Animasi Cepat**  
   - *PlayerAnim(playerid, lib[], name[], ...)* : Mainkan animasi dengan parameter lengkap dan default cepat.
     // English: Plays an animation with fast and complete parameters.
   - *ClearAnim(playerid)* : Hentikan semua animasi player.
     // English: Stops all player animations.

10. **Utility Kendaraan (Dasar)**  
    - *IsPlayerInVehicleEx(playerid)* : Cek apakah player naik kendaraan.
      // English: Checks if player is in a vehicle.
    - *GetVehicleIDOfPlayer(playerid)* : Ambil id vehicle yang dinaiki, jika ada.
      // English: Gets the vehicle ID player is in, if any.
    - *RemovePlayerFromVehicleEx(playerid)* : Paksa keluar dari kendaraan (dengan validasi).
      // English: Forces player out of vehicle (with validation).

11. **Random Player Helper**  
    - *GetRandomOnlinePlayer(exclude = -1)* : Ambil id player online random, dapat dikecualikan id sendiri atau lain.
      // English: Gets a random online player ID, can exclude self or other ID.

----------------------------------------
CONTOH PENGGUNAAN (Bahasa Indonesia)
----------------------------------------
```pwn
#include <player_utils>

public OnPlayerConnect(playerid)
{
    SendMsg(playerid, 0x00FD00FF, "Selamat datang!");
    if(CountOnlinePlayers() >= 10) 
        MsgToAll(0xFFFFFFAA, "Server sudah ramai!");
    // Cek apakah player di kendaraan
    if(IsPlayerInVehicleEx(playerid)) RemovePlayerFromVehicleEx(playerid);
    // Freeze 5 detik di spawn
    FreezePlayer(playerid);
    SetTimerEx("UnfreezePl", 5000, false, "i", playerid);
    return 1;
}

forward UnfreezePl(playerid);
public UnfreezePl(playerid) { UnfreezePlayer(playerid); }

public OnPlayerText(playerid, text[])
{
    if(IsPlayerMuted(playerid))
    {
        SendMsg(playerid, 0xFF5555FF, "Kamu sedang dibisukan admin.");
        return 0;
    }
    return 1;
}
```

----------------------------------------
EXAMPLE USAGE (English)
----------------------------------------
```pwn
#include <player_utils>

public OnPlayerConnect(playerid)
{
    SendMsg(playerid, 0x00FD00FF, "Welcome!");
    if(CountOnlinePlayers() >= 10) 
        MsgToAll(0xFFFFFFAA, "The server is crowded now!");
    if(IsPlayerInVehicleEx(playerid)) RemovePlayerFromVehicleEx(playerid);
    FreezePlayer(playerid);
    SetTimerEx("UnfreezePl", 5000, false, "i", playerid);
    return 1;
}

forward UnfreezePl(playerid);
public UnfreezePl(playerid) { UnfreezePlayer(playerid); }

public OnPlayerText(playerid, text[])
{
    if(IsPlayerMuted(playerid))
    {
        SendMsg(playerid, 0xFF5555FF, "You are muted by admin.");
        return 0;
    }
    return 1;
}
```

----------------------------------------
CARA PEMAKAIAN / HOW TO USE
----------------------------------------
1. Letakkan player_utils.inc ke folder pawno/include di server SAMP kamu.
   // English: Put player_utils.inc into the pawno/include folder on your SAMP server.
2. Tambahkan di skrip GM/FS kamu:  #include <player_utils>
   // English: Add to your GM/FS script:  #include <player_utils>
3. Langsung gunakan semua fungsi di atas di script Anda.
   // English: Directly use all the above functions in your script.

----------------------------------------
CREDIT & LICENSE
----------------------------------------
* Dibuat oleh Raihan Purnawadi (https://github.com/RaihanPrnwd)
  // English: Created by Raihan Purnawadi (https://github.com/RaihanPrnwd)
* Bebas digunakan, diedit, dan dibagikan - HARUS SERTAKAN KREDIT PEMBUAT.  
  // English: Free to use, modify and share - CREDIT TO THE ORIGINAL AUTHOR IS REQUIRED.

=======================================================================
