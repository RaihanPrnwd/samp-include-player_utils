/*
    ============================================================
    INCLUDE: SA-MP Player Utility (player_utils.inc)
    ------------------------------------------------------------
    [ID] Include fungsi-fungsi dasar dan lanjutan terkait player di SA-MP.
    [EN] Powerful include for basic and advanced SA-MP player scripting.

    Author: Raihan Purnawadi
    Github: https://github.com/RaihanPrnwd
    Silakan gunakan & share, jangan hapus kredit pembuat!
    Feel free to use & share, but do not remove this credit!
    ============================================================
*/

/*
[ID]
Deskripsi:
Include ini menyediakan berbagai fungsi siap pakai untuk memudahkan scripting fitur player di SA-MP.
Meliputi: validasi, pengiriman pesan, posisi, pencarian, uang, armor, skin, freeze/unfreeze, mute, teleport, animations, dan banyak lagi!

Cukup #include <player_utils> pada script Anda. Plug and Play!

[EN]
Description:
This include packs ready-to-use functions for handling players in SA-MP scripting.
Covers: validation, messaging, positions, search, money, armor, skin, freeze/unfreeze, mute, teleport, animations, and more!

Just #include <player_utils> in your script. Plug and Play!
*/

// ---------- KONFIGURASI MAKSIMUM PLAYER / PLAYER COUNT
#include <a_samp>
#if !defined MAX_PLAYERS
    #define MAX_PLAYERS 1000
#endif

// ==================== VALIDATIONS ====================

/* Cek player valid (connected) */
stock IsValidPlayer(playerid)
{
    return (playerid >= 0 && playerid < MAX_PLAYERS && IsPlayerConnected(playerid));
}

/* Cek player masih aktif & belum dead */
stock IsActivePlayer(playerid)
{
    return (IsValidPlayer(playerid) && !IsPlayerNPC(playerid) && GetPlayerState(playerid) != PLAYER_STATE_WASTED);
}

// ====================== MESSAGING ======================

/* Kirim pesan warna ke player */
stock SendMsg(playerid, color, msg[])
{
    if(IsValidPlayer(playerid))
        return SendClientMessage(playerid, color, msg);
    return 0;
}

/* Kirim pesan ke semua player */
stock MsgToAll(color, const msg[])
{
    for(new i=0; i<MAX_PLAYERS; i++)
        if(IsPlayerConnected(i))
            SendClientMessage(i, color, msg);
}

/* Fungsi khusus: Kirim chat OOC/Global ke semua */
stock SendGlobalOOC(color, const msg[])
{
    for(new i=0; i<MAX_PLAYERS; i++)
        if(IsPlayerConnected(i))
            SendClientMessage(i, color, msg);
}

// ===================== NAMES & DATA =====================

/* Dapatkan nama player (tanpa underscore) */
stock GetPlayerNameEx(playerid, dest[], len)
{
    if(!IsValidPlayer(playerid))
    {
        format(dest, len, "N/A");
        return 0;
    }
    GetPlayerName(playerid, dest, len);
    for (new i = 0; dest[i] != '\0'; i++)
        if (dest[i] == '_') dest[i] = ' ';
    return 1;
}

/* GetPlayerName dalam satu string */
stock pName(playerid)
{
    static pname[MAX_PLAYER_NAME+1];
    GetPlayerName(playerid, pname, sizeof(pname));
    return pname;
}

// ================== LOCATIONS & DISTANCE ====================

/* Ambil total jumlah player online */
stock CountOnlinePlayers()
{
    new count = 0;
    for(new i = 0; i < MAX_PLAYERS; i++)
        if(IsPlayerConnected(i))
            count++;
    return count;
}

/* Mendapatkan player terdekat dari playerid */
stock GetClosestPlayer(playerid)
{
    if(!IsValidPlayer(playerid)) return -1;
    new Float:px, Float:py, Float:pz;
    GetPlayerPos(playerid, px, py, pz);

    new closeid = -1, Float:mindist = 999999.0;
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(i == playerid || !IsPlayerConnected(i)) continue;
        new Float:x, Float:y, Float:z;
        GetPlayerPos(i, x, y, z);
        new Float:dist = floatsqroot( (px-x)*(px-x) + (py-y)*(py-y) + (pz-z)*(pz-z) );
        if(dist < mindist)
        {
            mindist = dist;
            closeid = i;
        }
    }
    return closeid;
}

/* Cek apakah 2 player dalam radius tertentu */
stock IsPlayerInRadius(fromid, toid, Float:radius)
{
    if(!IsValidPlayer(fromid) || !IsValidPlayer(toid)) return 0;
    new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;
    GetPlayerPos(fromid, x1, y1, z1);
    GetPlayerPos(toid, x2, y2, z2);
    return floatsqroot((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2)) <= radius;
}

/* Teleport player instan (safe) */
stock TeleportPlayer(playerid, Float:x, Float:y, Float:z, Float:a=0.0)
{
    if(!IsValidPlayer(playerid)) return 0;
    SetPlayerPos(playerid, x, y, z);
    SetPlayerFacingAngle(playerid, a);
    SetCameraBehindPlayer(playerid);
    return 1;
}

// ==================== PLAYER ATTRIBUTES =====================

/* Set uang player */
stock SetPlayerMoneyEx(playerid, amount)
{
    ResetPlayerMoney(playerid);
    GivePlayerMoney(playerid, amount);
}

/* Dapatkan uang player (butuh variables jika custom system) */
stock GetPlayerMoneyEx(playerid)
{
    return GetPlayerMoney(playerid);
}

/* Set health/armor player */
stock SetPlayerFullHealth(playerid)
{
    SetPlayerHealth(playerid, 100.0);
}
stock SetPlayerFullArmour(playerid)
{
    SetPlayerArmour(playerid, 100.0);
}

/* Ganti skin player */
stock SetPlayerSkinEx(playerid, skinid)
{
    if(!IsValidPlayer(playerid)) return 0;
    SetPlayerSkin(playerid, skinid);
    return 1;
}

/* Freeze/Unfreeze player (tidak dapat bergerak) */
stock FreezePlayer(playerid)
{
    TogglePlayerControllable(playerid, 0);
}
stock UnfreezePlayer(playerid)
{
    TogglePlayerControllable(playerid, 1);
}

// ==================== PLAYER STATES =======================

/* Kick player dengan pesan */
stock KickPlayer(playerid, msg[])
{
    if(!IsValidPlayer(playerid)) return 0;
    SendClientMessage(playerid, 0xFF444499, msg);
    SetTimerEx("KickEx", 500, false, "i", playerid);
    return 1;
}
forward KickEx(playerid);
public KickEx(playerid) { Kick(playerid); return 1; }

/* Kill/mematikan player */
stock KillPlayer(playerid)
{
    if(IsValidPlayer(playerid)) SetPlayerHealth(playerid, 0.0);
}

/* Respawn player ke spawn */
stock RespawnPlayer(playerid)
{
    if(IsValidPlayer(playerid)) SpawnPlayer(playerid);
}

// ================ MUTE / UNMUTE (chat switch) =============

new bool:g_PlayerMuted[MAX_PLAYERS];

stock MutePlayer(playerid)
{
    g_PlayerMuted[playerid] = true;
}

stock UnmutePlayer(playerid)
{
    g_PlayerMuted[playerid] = false;
}

stock IsPlayerMuted(playerid)
{
    return g_PlayerMuted[playerid];
}

// Contoh usage di OnPlayerText:
// if(IsPlayerMuted(playerid)) return 0;

// ================ FAST ANIMATION UTILS ================

/* Cepat mainkan animasi ke player */
stock PlayerAnim(playerid, lib[], name[], Float:speed = 4.1, loop = 1, lockx = 0, locky = 0, freeze = 0, time = 0, forcesync = 1)
{
    ApplyAnimation(playerid, lib, name, speed, loop, lockx, locky, freeze, time, forcesync);
}

/* Hentikan semua anim player */
stock ClearAnim(playerid)
{
    ClearAnimations(playerid);
}

// ============== PLAYER VEHICLE SHORTCUTS ===============

/* Cek player di kendaraan */
stock IsPlayerInVehicleEx(playerid)
{
    return (IsValidPlayer(playerid) && IsPlayerInAnyVehicle(playerid));
}

/* Get vehicle id yang dinaiki player */
stock GetVehicleIDOfPlayer(playerid)
{
    if(IsPlayerInAnyVehicle(playerid))
        return GetPlayerVehicleID(playerid);
    return -1;
}

/* Keluarkan player dari kendaraan */
stock RemovePlayerFromVehicleEx(playerid)
{
    if(IsPlayerInVehicleEx(playerid)) RemovePlayerFromVehicle(playerid);
}

// ============== RANDOM PLAYER UTILITY ===============

/* Mendapatkan id player random online selain playerid (atau -1) */
stock GetRandomOnlinePlayer(exclude = -1)
{
    new arr[MAX_PLAYERS];
    new count = 0;
    for(new i=0; i<MAX_PLAYERS; i++)
        if(IsPlayerConnected(i) && i != exclude) arr[count++] = i;
    if(count == 0) return -1;
    return arr[random(count)];
}

/*
    ------------------------------------------------------------
    Include player_utils ini dibuat oleh Raihan Purnawadi
    Player utilities include by Raihan Purnawadi
    Share & modifikasi bebas, wajib cantumkan kredit!
    Share and edit as you wish, keep this credit!
    ------------------------------------------------------------
*/


