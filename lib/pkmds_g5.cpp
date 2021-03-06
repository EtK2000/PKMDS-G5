/*
Copyright (C) 2013  codemonkey85

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_g5.h>
#include <pkmds/pokeprng.h>
#else
#include "../../PKMDS-G5/include/pkmds/pkmds_g5.h"
#include "../../PKMDS-G5/include/pkmds/pokeprng.h"
#endif
int balltoitem(int ball)
{
    int item = 0;
    switch((Balls::balls)ball)
    {
    case Balls::pokeball:
        item = (int)Items::pokeball;
        break;
    case Balls::pokeball_:
        item = (int)Items::pokeball;
        break;
    case Balls::cherishball:
        item = (int)Items::cherishball;
        break;
    case Balls::compball:
        item = (int)Items::sportball;
        break;
    case Balls::diveball:
        item = (int)Items::diveball;
        break;
    case Balls::dreamball:
        item = (int)Items::dreamball;
        break;
    case Balls::duskball:
        item = (int)Items::duskball;
        break;
    case Balls::fastball:
        item = (int)Items::fastball;
        break;
    case Balls::friendball:
        item = (int)Items::friendball;
        break;
    case Balls::greatball:
        item = (int)Items::greatball;
        break;
    case Balls::healball:
        item = (int)Items::healball;
        break;
    case Balls::heavyball:
        item = (int)Items::heavyball;
        break;
    case Balls::levelball:
        item = (int)Items::levelball;
        break;
    case Balls::loveball:
        item = (int)Items::loveball;
        break;
    case Balls::lureball:
        item = (int)Items::lureball;
        break;
    case Balls::luxuryball:
        item = (int)Items::luxuryball;
        break;
    case Balls::masterball:
        item = (int)Items::masterball;
        break;
    case Balls::moonball:
        item = (int)Items::moonball;
        break;
    case Balls::nestball:
        item = (int)Items::nestball;
        break;
    case Balls::netball:
        item = (int)Items::netball;
        break;
    case Balls::premierball:
        item = (int)Items::premierball;
        break;
    case Balls::quickball:
        item = (int)Items::quickball;
        break;
    case Balls::repeatball:
        item = (int)Items::repeatball;
        break;
    case Balls::safariball:
        item = (int)Items::safariball;
        break;
    case Balls::timerball:
        item = (int)Items::timerball;
        break;
    case Balls::ultraball:
        item = (int)Items::ultraball;
        break;
    default:
        item = (int)Items::pokeball;
        break;
    }
    return item;
}
const byte t_shuffle[24][4] = {
    {0,1,2,3}, {0,1,3,2}, {0,2,1,3}, {0,2,3,1},
    {0,3,1,2}, {0,3,2,1}, {1,0,2,3}, {1,0,3,2},
    {1,2,0,3}, {1,2,3,0}, {1,3,0,2}, {1,3,2,0},
    {2,0,1,3}, {2,0,3,1}, {2,1,0,3}, {2,1,3,0},
    {2,3,0,1}, {2,3,1,0}, {3,0,1,2}, {3,0,2,1},
    {3,1,0,2}, {3,1,2,0}, {3,2,0,1}, {3,2,1,0}
};
void shuffle(pokemon_obj * pkm, bool un) {
    byte * raw = reinterpret_cast<byte*>(pkm);
    byte temp[128];
    byte mode = (((((uint32*) raw)[0] >> 0xD) & 0x1F) % 24);

    if (un) {
        memcpy(&(temp[t_shuffle[mode][0] * 32]), &raw[8 + 0 * 32], 32);
        memcpy(&(temp[t_shuffle[mode][1] * 32]), &raw[8 + 1 * 32], 32);
        memcpy(&(temp[t_shuffle[mode][2] * 32]), &raw[8 + 2 * 32], 32);
        memcpy(&(temp[t_shuffle[mode][3] * 32]), &raw[8 + 3 * 32], 32);
    } else {
        memcpy(&(temp[0 * 32]), &raw[8 + t_shuffle[mode][0] * 32], 32);
        memcpy(&(temp[1 * 32]), &raw[8 + t_shuffle[mode][1] * 32], 32);
        memcpy(&(temp[2 * 32]), &raw[8 + t_shuffle[mode][2] * 32], 32);
        memcpy(&(temp[3 * 32]), &raw[8 + t_shuffle[mode][3] * 32], 32);
    }
    memcpy(&raw[8], &temp, 128);
}
void shuffle(pokemon_obj & pkm, bool un) {
    byte * raw = reinterpret_cast<byte*>(&pkm);
    byte temp[128];
    byte mode = (((((uint32*) raw)[0] >> 0xD) & 0x1F) % 24);

    if (un) {
        memcpy(&(temp[t_shuffle[mode][0] * 32]), &raw[8 + 0 * 32], 32);
        memcpy(&(temp[t_shuffle[mode][1] * 32]), &raw[8 + 1 * 32], 32);
        memcpy(&(temp[t_shuffle[mode][2] * 32]), &raw[8 + 2 * 32], 32);
        memcpy(&(temp[t_shuffle[mode][3] * 32]), &raw[8 + 3 * 32], 32);
    } else {
        memcpy(&(temp[0 * 32]), &raw[8 + t_shuffle[mode][0] * 32], 32);
        memcpy(&(temp[1 * 32]), &raw[8 + t_shuffle[mode][1] * 32], 32);
        memcpy(&(temp[2 * 32]), &raw[8 + t_shuffle[mode][2] * 32], 32);
        memcpy(&(temp[3 * 32]), &raw[8 + t_shuffle[mode][3] * 32], 32);
    }
    memcpy(&raw[8], &temp, 128);
}
void unshufflepkm(pokemon_obj *pkm)
{
    shuffle(pkm,true);
}
void shufflepkm(pokemon_obj *pkm)
{
    shuffle(pkm,false);
}
void unshufflepkm(pokemon_obj &pkm)
{
    shuffle(pkm,true);
}
void shufflepkm(pokemon_obj &pkm)
{
    shuffle(pkm,false);
}
void pkmcrypt(pokemon_obj& pkm){
    pkmprng prng;
    prng.mseed = pkm.checksum;
    uint16 * words = reinterpret_cast<uint16*>(&pkm);
    for(int i = 4; i < 68; i++)
    {
        words[i] = (words[i]) ^ (prng.nextnum() >> 0x10);
    };
}
void pkmcrypt(party_field& pkm, uint32 pid){
    pkmprng prng;
    prng.mseed = pid;
    uint16 * words = reinterpret_cast<uint16*>(&pkm);
    for(int i = 0x0; i < 0x2a; i++)
    {
        words[i] = (words[i]) ^ (prng.nextnum() >> 0x10);
    };
}
void pkmcrypt(party_field* pkm, uint32 pid){
    pkmprng prng;
    prng.mseed = pid;
    uint16 * words = reinterpret_cast<uint16*>(pkm);
    for(int i = 0x0; i < 0x2a; i++)
    {
        words[i] = (words[i]) ^ (prng.nextnum() >> 0x10);
    };
}
void encryptpkm(pokemon_obj& pkm){
    shufflepkm(pkm);
    pkmcrypt(pkm);
    pkm.ispartydatadecrypted = 0;
    pkm.isboxdatadecrypted = 0;
}
void decryptpkm(pokemon_obj& pkm){
    pkmcrypt(pkm);
    unshufflepkm(pkm);
    pkm.ispartydatadecrypted = 1;
    pkm.isboxdatadecrypted = 1;
}
void encryptpkm(party_pkm& pkm){
    shufflepkm(pkm.pkm_data);
    pkmcrypt(pkm.pkm_data);
    pkmcrypt(pkm.party_data,pkm.pkm_data.pid);
    pkm.pkm_data.ispartydatadecrypted = 0;
    pkm.pkm_data.isboxdatadecrypted = 0;
}
void decryptpkm(party_pkm& pkm){
    pkmcrypt(pkm.pkm_data);
    pkmcrypt(pkm.party_data,pkm.pkm_data.pid);
    unshufflepkm(pkm.pkm_data);
    pkm.pkm_data.ispartydatadecrypted = 1;
    pkm.pkm_data.isboxdatadecrypted = 1;
}
void encryptpkm(party_pkm* pkm){
    shufflepkm(pkm->pkm_data);
    pkmcrypt(&(pkm->pkm_data));
    pkmcrypt(&(pkm->party_data),pkm->pkm_data.pid);
    pkm->pkm_data.ispartydatadecrypted = 0;
    pkm->pkm_data.isboxdatadecrypted = 0;
}
void decryptpkm(party_pkm* pkm){
    pkmcrypt(&(pkm->pkm_data));
    pkmcrypt(&(pkm->party_data),pkm->pkm_data.pid);
    unshufflepkm(pkm->pkm_data);
    pkm->pkm_data.ispartydatadecrypted = 1;
    pkm->pkm_data.isboxdatadecrypted = 1;
}
void pkmcrypt(pokemon_obj* pkm){
    pkmprng prng;
    prng.mseed = pkm->checksum;
    uint16 * words = reinterpret_cast<uint16*>(pkm);
    for(int i = 4; i < 68; i++)
    {
        words[i] = (words[i]) ^ (prng.nextnum() >> 0x10);
    };
}
void encryptpkm(pokemon_obj* pkm){
    shufflepkm(pkm);
    pkmcrypt(pkm);
    pkm->ispartydatadecrypted = 0;
    pkm->isboxdatadecrypted = 0;
}
void decryptpkm(pokemon_obj* pkm){
    pkmcrypt(pkm);
    unshufflepkm(pkm);
    pkm->ispartydatadecrypted = 1;
    pkm->isboxdatadecrypted = 1;
}
uint16 getchecksum(bw2savblock_obj &block, const int start, const int length){
    byte* data = reinterpret_cast<byte*>(&block);
    int sum = 0xFFFF;
    for ( int i = start; i < start + length; i++ ){
        sum = (sum << 8) ^ SeedTable[ (byte)(data[i] ^ (byte)(sum>>8)) ];};
    return (uint16)sum;
}
void calcpartychecksum(bw2savblock_obj &block)
{
    uint16 chk = getchecksum(block,0x18E00,0x534);
    byte* data = reinterpret_cast<byte*>(&block);
    memcpy(&*(data+0x19336),&chk,2);
}
void calcboxchecksum(bw2savblock_obj &block, int boxindex, bool bw2){
    int start = (0x400 + (boxindex * 0x1000));
    uint16 chk = getchecksum(block,start,boxsize);
    block.boxes[boxindex].checksum = chk;
    byte* data = reinterpret_cast<byte*>(&block);
    if (bw2)
        memcpy(data + (long)BW2_OFFSETS::chkcalcloc + 2 + (boxindex * 2), &chk, 2);
    else
        memcpy(data + (long)BW_OFFSETS::chkcalcloc + 2 + (boxindex * 2), &chk, 2);
}
void calcchecksum(bw2savblock_obj &block, int start, int length, int loc){
    byte* data = reinterpret_cast<byte*>(&block);
    int sum = 0xFFFF;
    for ( int i = start; i < start + length; i++ )
        sum = (sum << 8) ^ SeedTable[ (byte)(data[i] ^ (byte)(sum>>8)) ];
    uint16 chk = (uint16)sum;
    memcpy(&*(data+loc),&chk,2);
}
uint16 getchkfromsav(bw2savblock_obj &block, bool bw2){
    byte* data = reinterpret_cast<byte*>(&block);
    uint16 chk;
    if (bw2)
        chk = (data[(long)BW2_OFFSETS::chkloc]) + (data[(long)BW2_OFFSETS::chkloc+1] * 256);
    else
        chk = (data[(long)BW_OFFSETS::chkloc]) + (data[(long)BW_OFFSETS::chkloc+1] * 256);
    return chk;
}
void calcchecksum(pokemon_obj& pkm) // Calculates and assigns the checksum for the given Pokemon object.
{
    uint32 chk = 0;
    uint16* p = (uint16*)&pkm;
    for (uint16* i = p + 0x04; i < p + 0x43; i++)
    {
        chk += *i;
    };
    chk = chk & 0xffff;
    pkm.checksum = chk;
}
uint16 getchecksum(bw2savblock_obj *block, const int start, const int length){
    byte* data = reinterpret_cast<byte*>(block);
    int sum = 0xFFFF;
    for ( int i = start; i < start + length; i++ ){
        sum = (sum << 8) ^ SeedTable[ (byte)(data[i] ^ (byte)(sum>>8)) ];};
    return (uint16)sum;
}
void calcpartychecksum(bw2savblock_obj *block)
{
    uint16 chk = getchecksum(block,0x18E00,0x534);
    byte* data = reinterpret_cast<byte*>(block);
    memcpy(&*(data+0x19336),&chk,2);
}
void calcboxchecksum(bw2savblock_obj *block, int boxindex, bool bw2){
    int start = (0x400 + (boxindex * 0x1000));
    uint16 chk = getchecksum(block,start,boxsize);
    block->boxes[boxindex].checksum = chk;
    byte* data = reinterpret_cast<byte*>(block);
    if (bw2)
        memcpy(data + (long)BW2_OFFSETS::chkcalcloc + 2 + (boxindex * 2), &chk, 2);
    else
        memcpy(data + (long)BW_OFFSETS::chkcalcloc + 2 + (boxindex * 2), &chk, 2);
}
void calcchecksum(bw2savblock_obj *block, int start, int length, int loc){
    byte* data = reinterpret_cast<byte*>(block);
    int sum = 0xFFFF;
    for ( int i = start; i < start + length; i++ )
        sum = (sum << 8) ^ SeedTable[ (byte)(data[i] ^ (byte)(sum>>8)) ];
    uint16 chk = (uint16)sum;
    memcpy(&*(data+loc),&chk,2);
}
uint16 getchkfromsav(bw2savblock_obj *block, bool bw2){
    byte* data = reinterpret_cast<byte*>(block);
    uint16 chk;
    if (bw2)
        chk = (data[(long)BW2_OFFSETS::chkloc]) + (data[(long)BW2_OFFSETS::chkloc+1] * 256);
    else
        chk = (data[(long)BW_OFFSETS::chkloc]) + (data[(long)BW_OFFSETS::chkloc+1] * 256);
    return chk;
}
void calcchecksum(pokemon_obj* pkm) // Calculates and assigns the checksum for the given Pokemon object.
{
    uint32 chk = 0;
    uint16* p = (uint16*)pkm;
    for (uint16* i = p + 0x04; i < p + 0x43; i++)
    {
        chk += *i;
    };
    chk = chk & 0xffff;
    pkm->checksum = chk;
}
bool savisbw2(bw2sav_obj &sav)
{
    return (getchecksum(sav.cur,(long)BW2_OFFSETS::chkcalcloc,(long)BW2_OFFSETS::chkcalclen)) == (getchkfromsav(sav.cur,true));
}
bool savisbw2(bw2sav_obj *sav)
{
    return (getchecksum(sav->cur,(long)BW2_OFFSETS::chkcalcloc,(long)BW2_OFFSETS::chkcalclen)) == (getchkfromsav(sav->cur,true));
}
void fixsavchecksum(bw2sav_obj &sav)
{
    if(savisbw2(sav))
    {
        calcchecksum(sav.cur, (long)BW2_OFFSETS::chkcalcloc, (long)BW2_OFFSETS::chkcalclen, (long)BW2_OFFSETS::chkloc);
    }
    else
    {
        calcchecksum(sav.cur, (long)BW_OFFSETS::chkcalcloc, (long)BW_OFFSETS::chkcalclen, (long)BW_OFFSETS::chkloc);
    }
}
void fixsavchecksum(bw2sav_obj *sav)
{
    if(savisbw2(sav))
    {
        calcchecksum(sav->cur, (long)BW2_OFFSETS::chkcalcloc, (long)BW2_OFFSETS::chkcalclen, (long)BW2_OFFSETS::chkloc);
    }
    else
    {
        calcchecksum(sav->cur, (long)BW_OFFSETS::chkcalcloc, (long)BW_OFFSETS::chkcalclen, (long)BW_OFFSETS::chkloc);
    }
}
void write(const char* file_name, pokemon_obj& data) // Writes the given Pokemon data to the given file name.
{
    int encryptstatus[2] = {data.ispartydatadecrypted,data.isboxdatadecrypted};
    data.ispartydatadecrypted = 0;
    data.isboxdatadecrypted = 0;
    std::ofstream *out = new std::ofstream(file_name,std::ios::binary);
    out->write(reinterpret_cast<char*>(&data), sizeof(pokemon_obj));
    out->close();
    delete out;
    out = 0;
    data.ispartydatadecrypted = encryptstatus[0];
    data.isboxdatadecrypted = encryptstatus[1];
}
void write(const char* file_name, pokemon_obj* data) // Writes the given Pokemon data to the given file name.
{
    int encryptstatus[2] = {data->ispartydatadecrypted,data->isboxdatadecrypted};
    data->ispartydatadecrypted = 0;
    data->isboxdatadecrypted = 0;
    std::ofstream *out = new std::ofstream(file_name,std::ios::binary);
    out->write(reinterpret_cast<char*>(data), sizeof(pokemon_obj));
    out->close();
    delete out;
    out = 0;
    data->ispartydatadecrypted = encryptstatus[0];
    data->isboxdatadecrypted = encryptstatus[1];
}
void write(const char* file_name, bw2sav_obj& data) //
{
    std::ofstream *out = new std::ofstream(file_name,std::ios::binary);
    out->write(reinterpret_cast<char*>(&data), sizeof(bw2sav_obj));
    out->close();
    delete out;
    out = 0;
}
void write(const char* file_name, bw2sav_obj *data) //
{
    std::ofstream *out = new std::ofstream(file_name,std::ios::binary);
    out->write(reinterpret_cast<char*>(data), sizeof(bw2sav_obj));
    out->close();
    delete out;
    out = 0;
}
void read(const char* file_name, pokemon_obj& data) // Reads the given file and assigns the data to the given Pokemon object.
{
    std::ifstream *in = new std::ifstream(file_name,std::ios::binary);
    in->read(reinterpret_cast<char*>(&data), sizeof(pokemon_obj));
    in->close();
    delete in;
    in = 0;
}
void read(const char* file_name, pokemon_obj *data) // Reads the given file and assigns the data to the given save file object.
{
    std::ifstream *in = new std::ifstream(file_name,std::ios::binary);
    in->read(reinterpret_cast<char*>(data), sizeof(pokemon_obj));
    in->close();
    delete in;
    in = 0;
}
void read(const char* file_name, bw2sav_obj& data) // Reads the given file and assigns the data to the given save file object.
{
    std::ifstream *in = new std::ifstream(file_name,std::ios::binary);
    in->read(reinterpret_cast<char*>(&data), sizeof(bw2sav_obj));
    in->close();
    delete in;
    in = 0;
}
void read(const char* file_name, bw2sav_obj *data) // Reads the given file and assigns the data to the given save file object.
{
    std::ifstream *in = new std::ifstream(file_name,std::ios::binary);
    in->read(reinterpret_cast<char*>(data), sizeof(bw2sav_obj));
    in->close();
    delete in;
    in = 0;
}
std::wstring getpkmnickname(const pokemon_obj &pkm)
{
#ifdef __linux__
    return getwstring((char*)pkm.nickname, 22);
#else
    return getwstring(pkm.nickname);
#endif
}
std::wstring getpkmotname(const pokemon_obj &pkm)
{
#ifdef __linux__
    return getwstring((char*)pkm.otname, 16);
#else
    return getwstring(pkm.otname);
#endif
}
void setpkmnickname(pokemon_obj &pkm, wchar_t input[], int length){
    if(length > 8){length = 8;}
    memset(&pkm.nickname, '\0', 20);
    memcpy(&pkm.nickname,input,length*2);
    memset(&pkm.nickname[length], 0xffff, 2);
    //pkm.ivs.isnicknamed = 1;
}
void setpkmotname(pokemon_obj &pkm, wchar_t input[], int length){
    if(length > 8){length = 8;}
    memset(&pkm.otname, '\0', 20);
    memcpy(&pkm.otname,input,length*2);
    memset(&pkm.otname[length], 0xffff, 2);
}
std::wstring getpkmnickname(const pokemon_obj *pkm)
{
#ifdef __linux__
    return getwstring((char*)pkm->nickname, 22);
#else
    return getwstring(pkm->nickname);
#endif
}
std::wstring getpkmotname(const pokemon_obj *pkm)
{
#ifdef __linux__
    return getwstring((char*)pkm->otname, 16);
#else
    return getwstring(pkm->otname);
#endif
}
void setpkmnickname(pokemon_obj *pkm, wchar_t input[], int length){
    if(length > 8){length = 8;}
    memset(&pkm->nickname, '\0', 20);
    memcpy(&pkm->nickname,input,length*2);
    memset(&pkm->nickname[length], 0xffff, 2);
    //pkm.ivs.isnicknamed = 1;
}
void setpkmotname(pokemon_obj *pkm, wchar_t input[], int length){
    if(length > 8){length = 8;}
    memset(&pkm->otname, '\0', 20);
    memcpy(&pkm->otname,input,length*2);
    memset(&pkm->otname[length], 0xffff, 2);
}
Genders::genders getpkmgender(const pokemon_obj &pkm)
{
    if (pkm.forms.female){return Genders::female;};
    if (pkm.forms.genderless){return Genders::genderless;};
    return Genders::male;
}
Genders::genders getpkmgender(const pokemon_obj *pkm)
{
    if (pkm->forms.female){return Genders::female;};
    if (pkm->forms.genderless){return Genders::genderless;};
    return Genders::male;
}
void setpkmgender(pokemon_obj &pkm, int gender)
{
    switch (gender)
    {
    case Genders::male:
        pkm.forms.female = false;
        pkm.forms.genderless = false;
        break;
    case Genders::female:
        pkm.forms.female = true;
        pkm.forms.genderless = false;
        break;
    case Genders::genderless:
        pkm.forms.female = false;
        pkm.forms.genderless = true;
        break;
    }
}
bool getpkmshiny(const pokemon_obj &pkm){
    uint32 p1, p2, E, F;
    p1 = (pkm.pid & 0xFFFF0000) >> 16;
    p2 = pkm.pid & 0xFFFF;
    E = pkm.tid ^ pkm.sid;
    F = p1 ^ p2;
    return (E ^ F) < 8;
}
bool pkmmetasegg(const pokemon_obj &pkm){
    return ((pkm.eggdate.year != 0) & (pkm.eggdate.month != 0) & (pkm.eggdate.day != 0));
}
void setpkmgender(pokemon_obj *pkm, int gender)
{
    switch (gender)
    {
    case Genders::male:
        pkm->forms.female = false;
        pkm->forms.genderless = false;
        break;
    case Genders::female:
        pkm->forms.female = true;
        pkm->forms.genderless = false;
        break;
    case Genders::genderless:
        pkm->forms.female = false;
        pkm->forms.genderless = true;
        break;
    }
}
bool getpkmshiny(const pokemon_obj *pkm){
    uint32 p1, p2, E, F;

    p1 = (pkm->pid & 0xFFFF0000) >> 16;
    p2 = pkm->pid & 0xFFFF;
    E = pkm->tid ^ pkm->sid;
    F = p1 ^ p2;
    return (E ^ F) < 8;
}
bool pkmmetasegg(const pokemon_obj *pkm){
    return ((pkm->eggdate.year != 0) & (pkm->eggdate.month != 0) & (pkm->eggdate.day != 0));
}
void swap_pkm(box_obj &frombox, const int fromslot, box_obj &tobox, const int toslot)
{
    pokemon_obj frompkm, topkm;
    frompkm = frombox.pokemon[fromslot];
    topkm = tobox.pokemon[toslot];
    frombox.pokemon[fromslot] = topkm;
    tobox.pokemon[toslot] = frompkm;
}
void put_pkm(box_obj &box, const int slot, pokemon_obj &pkm, const bool isencrypted)
{
    if(! isencrypted)
    {
        encryptpkm(pkm);
    }
    box.pokemon[slot] = pkm;
}
void swap_pkm(box_obj *frombox, const int fromslot, box_obj *tobox, const int toslot)
{
    pokemon_obj frompkm, topkm;
    frompkm = frombox->pokemon[fromslot];
    topkm = tobox->pokemon[toslot];
    frombox->pokemon[fromslot] = topkm;
    tobox->pokemon[toslot] = frompkm;
}
void put_pkm(box_obj *box, const int slot, pokemon_obj *pkm, const bool isencrypted)
{
    if(! isencrypted)
    {
        encryptpkm(pkm);
    }
    box->pokemon[slot] = *pkm;
}
void remove_pkm(box_obj &box, const int slot)
{
    // TODO: Test blank pkm
    //pokemon_obj blank = {};
    pokemon_obj blank;
    memset(&blank,0,sizeof(blank));
    encryptpkm(blank);
    box.pokemon[slot] = blank;
}
void remove_pkm(box_obj *box, const int slot)
{
    //pokemon_obj blank = {};
    pokemon_obj blank;
    memset(&blank,0,sizeof(blank));
    encryptpkm(blank);
    box->pokemon[slot] = blank;
}
void depositpkm(bw2savblock_obj * block, const int party_slot, box_obj * box, const int box_slot)
{
    // TODO: Deposit pokemon
}
double getpkmhappiness(const pokemon_obj &pkm)
{
    return pkm.tameness / 255.0;
}
double getpkmhappiness(const pokemon_obj *pkm)
{
    return pkm->tameness / 255.0;
}
int getpkmhatchsteps(const pokemon_obj &pkm)
{
    return (pkm.tameness * 255);
}
int getpkmhatchsteps(const pokemon_obj *pkm)
{
    return (pkm->tameness * 255);
}
std::string getgendername(const int gender)
{
    switch(gender)
    {
    case Genders::male:
        return "Male";
    case Genders::female:
        return "Female";
    case Genders::genderless:
        return "Genderless";
    default:
        return "Male";
    }
}
std::string getpkmotgendername(const pokemon_obj &pkm)
{
    return getgendername(pkm.metlevel_otgender.otgender);
}
int gethiddenpowerpower(const pokemon_obj &pkm)
{
    int power = 0;
    int u=0,v=0,w=0,x=0,y=0,z=0;
    if((pkm.ivs.hp % 4 == 2) | (pkm.ivs.hp % 4 == 3)){u = 1;}
    if((pkm.ivs.attack % 4 == 2) | (pkm.ivs.attack % 4 == 3)){v = 1;}
    if((pkm.ivs.defense % 4 == 2) | (pkm.ivs.defense % 4 == 3)){w = 1;}
    if((pkm.ivs.speed % 4 == 2) | (pkm.ivs.speed % 4 == 3)){x = 1;}
    if((pkm.ivs.spatk % 4 == 2) | (pkm.ivs.spatk % 4 == 3)){y = 1;}
    if((pkm.ivs.spdef % 4 == 2) | (pkm.ivs.spdef % 4 == 3)){z = 1;}
    power = (int)(floor((double)(((u + 2 * v + 4 * w + 8 * x + 16 * y + 32 * z) * 40 / 63) + 30)));
    return power;
}
int gethiddenpowertype(const pokemon_obj &pkm)
{
    int type = 0;
    int a=0,b=0,c=0,d=0,e=0,f=0;
    a = (int)(!(pkm.ivs.hp % 2 == 0));
    b = (int)(!(pkm.ivs.attack % 2 == 0));
    c = (int)(!(pkm.ivs.defense % 2 == 0));
    d = (int)(!(pkm.ivs.speed % 2 == 0));
    e = (int)(!(pkm.ivs.spatk % 2 == 0));
    f = (int)(!(pkm.ivs.spdef % 2 == 0));
    type = (int)(floor((double)((a + 2 * b + 4 * c + 8 * d + 16 * e + 32 * f) * 15 / 63)));
    return hiddenpowertypes[type];
}
std::string getpkmotgendername(const pokemon_obj *pkm)
{
    return getgendername(pkm->metlevel_otgender.otgender);
}
int gethiddenpowerpower(const pokemon_obj *pkm)
{
    int power = 0;
    int u=0,v=0,w=0,x=0,y=0,z=0;
    if((pkm->ivs.hp % 4 == 2) | (pkm->ivs.hp % 4 == 3)){u = 1;}
    if((pkm->ivs.attack % 4 == 2) | (pkm->ivs.attack % 4 == 3)){v = 1;}
    if((pkm->ivs.defense % 4 == 2) | (pkm->ivs.defense % 4 == 3)){w = 1;}
    if((pkm->ivs.speed % 4 == 2) | (pkm->ivs.speed % 4 == 3)){x = 1;}
    if((pkm->ivs.spatk % 4 == 2) | (pkm->ivs.spatk % 4 == 3)){y = 1;}
    if((pkm->ivs.spdef % 4 == 2) | (pkm->ivs.spdef % 4 == 3)){z = 1;}
    power = (int)(floor((double)(((u + 2 * v + 4 * w + 8 * x + 16 * y + 32 * z) * 40 / 63) + 30)));
    return power;
}
int gethiddenpowertype(const pokemon_obj *pkm)
{
    int type = 0;
    int a=0,b=0,c=0,d=0,e=0,f=0;
    a = (int)(!(pkm->ivs.hp % 2 == 0));
    b = (int)(!(pkm->ivs.attack % 2 == 0));
    c = (int)(!(pkm->ivs.defense % 2 == 0));
    d = (int)(!(pkm->ivs.speed % 2 == 0));
    e = (int)(!(pkm->ivs.spatk % 2 == 0));
    f = (int)(!(pkm->ivs.spdef % 2 == 0));
    type = (int)(floor((double)((a + 2 * b + 4 * c + 8 * d + 16 * e + 32 * f) * 15 / 63)));
    return hiddenpowertypes[type];
}
std::string getballname(const int ball)
{
    return ballnames[ball];
}
std::string getballname(const pokemon_obj &pkm)
{
    return getballname(pkm.ball);
}
std::string getballname(const pokemon_obj *pkm)
{
    return getballname(pkm->ball);
}
std::wstring getboxname(const bw2savblock_obj *block,int boxnum)
{
    std::wstring name;
#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
    std::string str_name = block->boxnames[boxnum];
    wchar_t boxname_buffer[11];
    memset(boxname_buffer,0,11);
    mbstowcs(boxname_buffer, str_name.c_str(), 11);
#else
    name = block->boxnames[boxnum];
#endif
#endif

    if(name.find((wchar_t)0xffff))
    {
        name = name.substr(0,name.find((wchar_t)0xffff));
    }
    return name;
}
std::wstring getboxname(const bw2savblock_obj &block,int boxnum)
{
    std::wstring name;
#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
    std::string str_name = block.boxnames[boxnum];
    wchar_t boxname_buffer[11];
    memset(boxname_buffer,0,11);
    mbstowcs(boxname_buffer, str_name.c_str(), 11);
#else
    name = block.boxnames[boxnum];
#endif
#endif

    if(name.find((wchar_t)0xffff))
    {
        name = name.substr(0,name.find((wchar_t)0xffff));
    }
    return name;
}
time_t * advstrttime(const bw2savblock_obj &block)
{
    time_t * ret = new time_t;
    *ret = block.adventurestarted + 946684800;
    return ret;
}
time_t * advstrttime(const bw2savblock_obj *block)
{
    time_t * ret = new time_t;
    *ret = block->adventurestarted + 946684800;
    return ret;
}
std::string advstrttimestring(const bw2savblock_obj &block)
{
    time_t * adstarttime = new time_t;
    adstarttime = advstrttime(&block);
    tm * ptm;
    ptm = gmtime(adstarttime);
    ptm->tm_year += 1900;
    std::ostringstream o;
    o << ptm->tm_year << "/" << ptm->tm_mon << "/" << ptm->tm_mday << " " << ptm->tm_hour << ":" << ptm->tm_min << ":" << ptm->tm_sec;
    std::string retval;
    retval = o.str().c_str();
    return retval;
}
std::string advstrttimestring(const bw2savblock_obj *block)
{
    time_t * adstarttime = new time_t;
    adstarttime = advstrttime(block);
    tm * ptm;
    ptm = gmtime(adstarttime);
    ptm->tm_year += 1900;
    std::ostringstream o;
    o << ptm->tm_year << "/" << ptm->tm_mon << "/" << ptm->tm_mday << " " << ptm->tm_hour << ":" << ptm->tm_min << ":" << ptm->tm_sec;
    std::string retval;
    retval = o.str().c_str();
    return retval;
}
std::wstring getsavtrainername(const bw2savblock_obj & block)
{
#ifdef __linux__
    return getwstring((char*)block.trainername, 0x10);
#else
    return getwstring(block.trainername);
#endif
}
std::wstring getsavtrainername(const bw2savblock_obj * block)
{
#ifdef __linux__
    return getwstring((char*)block->trainername, 0x10);
#else
    return getwstring(block->trainername);
#endif
}
std::wstring getwstring(std::wstring in)
{
    std::wstring out = in;
    if(out.find((wchar_t)0xffff))
    {
        out = out.substr(0,out.find((wchar_t)0xffff));
    }
    return out;
}
std::wstring getwstring(std::string in)
{
    std::string out = in;
    if(out.find((char)0xffff))
    {
        out = out.substr(0,out.find((char)0xffff));
    }
    std::wstring retval(out.begin(), out.end());
    return retval;
}
std::wstring getwstring(char* in, int len)
{
    unsigned char arr[24]; //Large enough for longest text value stored in game
    memset(arr,'\0',24);
    memcpy(arr,&in,len);
    for(int i = 0; i < len; i++)
    {
        if(arr[i] == 0xFF) break;
        else arr[i] = in[2*i];
    }
    std::string out = (char*)arr;
    std::wstring retval(out.begin(), out.end());
    return retval;
}
