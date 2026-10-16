#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4645079504083643561) {
   out_4645079504083643561[0] = delta_x[0] + nom_x[0];
   out_4645079504083643561[1] = delta_x[1] + nom_x[1];
   out_4645079504083643561[2] = delta_x[2] + nom_x[2];
   out_4645079504083643561[3] = delta_x[3] + nom_x[3];
   out_4645079504083643561[4] = delta_x[4] + nom_x[4];
   out_4645079504083643561[5] = delta_x[5] + nom_x[5];
   out_4645079504083643561[6] = delta_x[6] + nom_x[6];
   out_4645079504083643561[7] = delta_x[7] + nom_x[7];
   out_4645079504083643561[8] = delta_x[8] + nom_x[8];
   out_4645079504083643561[9] = delta_x[9] + nom_x[9];
   out_4645079504083643561[10] = delta_x[10] + nom_x[10];
   out_4645079504083643561[11] = delta_x[11] + nom_x[11];
   out_4645079504083643561[12] = delta_x[12] + nom_x[12];
   out_4645079504083643561[13] = delta_x[13] + nom_x[13];
   out_4645079504083643561[14] = delta_x[14] + nom_x[14];
   out_4645079504083643561[15] = delta_x[15] + nom_x[15];
   out_4645079504083643561[16] = delta_x[16] + nom_x[16];
   out_4645079504083643561[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8420684883175596638) {
   out_8420684883175596638[0] = -nom_x[0] + true_x[0];
   out_8420684883175596638[1] = -nom_x[1] + true_x[1];
   out_8420684883175596638[2] = -nom_x[2] + true_x[2];
   out_8420684883175596638[3] = -nom_x[3] + true_x[3];
   out_8420684883175596638[4] = -nom_x[4] + true_x[4];
   out_8420684883175596638[5] = -nom_x[5] + true_x[5];
   out_8420684883175596638[6] = -nom_x[6] + true_x[6];
   out_8420684883175596638[7] = -nom_x[7] + true_x[7];
   out_8420684883175596638[8] = -nom_x[8] + true_x[8];
   out_8420684883175596638[9] = -nom_x[9] + true_x[9];
   out_8420684883175596638[10] = -nom_x[10] + true_x[10];
   out_8420684883175596638[11] = -nom_x[11] + true_x[11];
   out_8420684883175596638[12] = -nom_x[12] + true_x[12];
   out_8420684883175596638[13] = -nom_x[13] + true_x[13];
   out_8420684883175596638[14] = -nom_x[14] + true_x[14];
   out_8420684883175596638[15] = -nom_x[15] + true_x[15];
   out_8420684883175596638[16] = -nom_x[16] + true_x[16];
   out_8420684883175596638[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_128471273322292035) {
   out_128471273322292035[0] = 1.0;
   out_128471273322292035[1] = 0.0;
   out_128471273322292035[2] = 0.0;
   out_128471273322292035[3] = 0.0;
   out_128471273322292035[4] = 0.0;
   out_128471273322292035[5] = 0.0;
   out_128471273322292035[6] = 0.0;
   out_128471273322292035[7] = 0.0;
   out_128471273322292035[8] = 0.0;
   out_128471273322292035[9] = 0.0;
   out_128471273322292035[10] = 0.0;
   out_128471273322292035[11] = 0.0;
   out_128471273322292035[12] = 0.0;
   out_128471273322292035[13] = 0.0;
   out_128471273322292035[14] = 0.0;
   out_128471273322292035[15] = 0.0;
   out_128471273322292035[16] = 0.0;
   out_128471273322292035[17] = 0.0;
   out_128471273322292035[18] = 0.0;
   out_128471273322292035[19] = 1.0;
   out_128471273322292035[20] = 0.0;
   out_128471273322292035[21] = 0.0;
   out_128471273322292035[22] = 0.0;
   out_128471273322292035[23] = 0.0;
   out_128471273322292035[24] = 0.0;
   out_128471273322292035[25] = 0.0;
   out_128471273322292035[26] = 0.0;
   out_128471273322292035[27] = 0.0;
   out_128471273322292035[28] = 0.0;
   out_128471273322292035[29] = 0.0;
   out_128471273322292035[30] = 0.0;
   out_128471273322292035[31] = 0.0;
   out_128471273322292035[32] = 0.0;
   out_128471273322292035[33] = 0.0;
   out_128471273322292035[34] = 0.0;
   out_128471273322292035[35] = 0.0;
   out_128471273322292035[36] = 0.0;
   out_128471273322292035[37] = 0.0;
   out_128471273322292035[38] = 1.0;
   out_128471273322292035[39] = 0.0;
   out_128471273322292035[40] = 0.0;
   out_128471273322292035[41] = 0.0;
   out_128471273322292035[42] = 0.0;
   out_128471273322292035[43] = 0.0;
   out_128471273322292035[44] = 0.0;
   out_128471273322292035[45] = 0.0;
   out_128471273322292035[46] = 0.0;
   out_128471273322292035[47] = 0.0;
   out_128471273322292035[48] = 0.0;
   out_128471273322292035[49] = 0.0;
   out_128471273322292035[50] = 0.0;
   out_128471273322292035[51] = 0.0;
   out_128471273322292035[52] = 0.0;
   out_128471273322292035[53] = 0.0;
   out_128471273322292035[54] = 0.0;
   out_128471273322292035[55] = 0.0;
   out_128471273322292035[56] = 0.0;
   out_128471273322292035[57] = 1.0;
   out_128471273322292035[58] = 0.0;
   out_128471273322292035[59] = 0.0;
   out_128471273322292035[60] = 0.0;
   out_128471273322292035[61] = 0.0;
   out_128471273322292035[62] = 0.0;
   out_128471273322292035[63] = 0.0;
   out_128471273322292035[64] = 0.0;
   out_128471273322292035[65] = 0.0;
   out_128471273322292035[66] = 0.0;
   out_128471273322292035[67] = 0.0;
   out_128471273322292035[68] = 0.0;
   out_128471273322292035[69] = 0.0;
   out_128471273322292035[70] = 0.0;
   out_128471273322292035[71] = 0.0;
   out_128471273322292035[72] = 0.0;
   out_128471273322292035[73] = 0.0;
   out_128471273322292035[74] = 0.0;
   out_128471273322292035[75] = 0.0;
   out_128471273322292035[76] = 1.0;
   out_128471273322292035[77] = 0.0;
   out_128471273322292035[78] = 0.0;
   out_128471273322292035[79] = 0.0;
   out_128471273322292035[80] = 0.0;
   out_128471273322292035[81] = 0.0;
   out_128471273322292035[82] = 0.0;
   out_128471273322292035[83] = 0.0;
   out_128471273322292035[84] = 0.0;
   out_128471273322292035[85] = 0.0;
   out_128471273322292035[86] = 0.0;
   out_128471273322292035[87] = 0.0;
   out_128471273322292035[88] = 0.0;
   out_128471273322292035[89] = 0.0;
   out_128471273322292035[90] = 0.0;
   out_128471273322292035[91] = 0.0;
   out_128471273322292035[92] = 0.0;
   out_128471273322292035[93] = 0.0;
   out_128471273322292035[94] = 0.0;
   out_128471273322292035[95] = 1.0;
   out_128471273322292035[96] = 0.0;
   out_128471273322292035[97] = 0.0;
   out_128471273322292035[98] = 0.0;
   out_128471273322292035[99] = 0.0;
   out_128471273322292035[100] = 0.0;
   out_128471273322292035[101] = 0.0;
   out_128471273322292035[102] = 0.0;
   out_128471273322292035[103] = 0.0;
   out_128471273322292035[104] = 0.0;
   out_128471273322292035[105] = 0.0;
   out_128471273322292035[106] = 0.0;
   out_128471273322292035[107] = 0.0;
   out_128471273322292035[108] = 0.0;
   out_128471273322292035[109] = 0.0;
   out_128471273322292035[110] = 0.0;
   out_128471273322292035[111] = 0.0;
   out_128471273322292035[112] = 0.0;
   out_128471273322292035[113] = 0.0;
   out_128471273322292035[114] = 1.0;
   out_128471273322292035[115] = 0.0;
   out_128471273322292035[116] = 0.0;
   out_128471273322292035[117] = 0.0;
   out_128471273322292035[118] = 0.0;
   out_128471273322292035[119] = 0.0;
   out_128471273322292035[120] = 0.0;
   out_128471273322292035[121] = 0.0;
   out_128471273322292035[122] = 0.0;
   out_128471273322292035[123] = 0.0;
   out_128471273322292035[124] = 0.0;
   out_128471273322292035[125] = 0.0;
   out_128471273322292035[126] = 0.0;
   out_128471273322292035[127] = 0.0;
   out_128471273322292035[128] = 0.0;
   out_128471273322292035[129] = 0.0;
   out_128471273322292035[130] = 0.0;
   out_128471273322292035[131] = 0.0;
   out_128471273322292035[132] = 0.0;
   out_128471273322292035[133] = 1.0;
   out_128471273322292035[134] = 0.0;
   out_128471273322292035[135] = 0.0;
   out_128471273322292035[136] = 0.0;
   out_128471273322292035[137] = 0.0;
   out_128471273322292035[138] = 0.0;
   out_128471273322292035[139] = 0.0;
   out_128471273322292035[140] = 0.0;
   out_128471273322292035[141] = 0.0;
   out_128471273322292035[142] = 0.0;
   out_128471273322292035[143] = 0.0;
   out_128471273322292035[144] = 0.0;
   out_128471273322292035[145] = 0.0;
   out_128471273322292035[146] = 0.0;
   out_128471273322292035[147] = 0.0;
   out_128471273322292035[148] = 0.0;
   out_128471273322292035[149] = 0.0;
   out_128471273322292035[150] = 0.0;
   out_128471273322292035[151] = 0.0;
   out_128471273322292035[152] = 1.0;
   out_128471273322292035[153] = 0.0;
   out_128471273322292035[154] = 0.0;
   out_128471273322292035[155] = 0.0;
   out_128471273322292035[156] = 0.0;
   out_128471273322292035[157] = 0.0;
   out_128471273322292035[158] = 0.0;
   out_128471273322292035[159] = 0.0;
   out_128471273322292035[160] = 0.0;
   out_128471273322292035[161] = 0.0;
   out_128471273322292035[162] = 0.0;
   out_128471273322292035[163] = 0.0;
   out_128471273322292035[164] = 0.0;
   out_128471273322292035[165] = 0.0;
   out_128471273322292035[166] = 0.0;
   out_128471273322292035[167] = 0.0;
   out_128471273322292035[168] = 0.0;
   out_128471273322292035[169] = 0.0;
   out_128471273322292035[170] = 0.0;
   out_128471273322292035[171] = 1.0;
   out_128471273322292035[172] = 0.0;
   out_128471273322292035[173] = 0.0;
   out_128471273322292035[174] = 0.0;
   out_128471273322292035[175] = 0.0;
   out_128471273322292035[176] = 0.0;
   out_128471273322292035[177] = 0.0;
   out_128471273322292035[178] = 0.0;
   out_128471273322292035[179] = 0.0;
   out_128471273322292035[180] = 0.0;
   out_128471273322292035[181] = 0.0;
   out_128471273322292035[182] = 0.0;
   out_128471273322292035[183] = 0.0;
   out_128471273322292035[184] = 0.0;
   out_128471273322292035[185] = 0.0;
   out_128471273322292035[186] = 0.0;
   out_128471273322292035[187] = 0.0;
   out_128471273322292035[188] = 0.0;
   out_128471273322292035[189] = 0.0;
   out_128471273322292035[190] = 1.0;
   out_128471273322292035[191] = 0.0;
   out_128471273322292035[192] = 0.0;
   out_128471273322292035[193] = 0.0;
   out_128471273322292035[194] = 0.0;
   out_128471273322292035[195] = 0.0;
   out_128471273322292035[196] = 0.0;
   out_128471273322292035[197] = 0.0;
   out_128471273322292035[198] = 0.0;
   out_128471273322292035[199] = 0.0;
   out_128471273322292035[200] = 0.0;
   out_128471273322292035[201] = 0.0;
   out_128471273322292035[202] = 0.0;
   out_128471273322292035[203] = 0.0;
   out_128471273322292035[204] = 0.0;
   out_128471273322292035[205] = 0.0;
   out_128471273322292035[206] = 0.0;
   out_128471273322292035[207] = 0.0;
   out_128471273322292035[208] = 0.0;
   out_128471273322292035[209] = 1.0;
   out_128471273322292035[210] = 0.0;
   out_128471273322292035[211] = 0.0;
   out_128471273322292035[212] = 0.0;
   out_128471273322292035[213] = 0.0;
   out_128471273322292035[214] = 0.0;
   out_128471273322292035[215] = 0.0;
   out_128471273322292035[216] = 0.0;
   out_128471273322292035[217] = 0.0;
   out_128471273322292035[218] = 0.0;
   out_128471273322292035[219] = 0.0;
   out_128471273322292035[220] = 0.0;
   out_128471273322292035[221] = 0.0;
   out_128471273322292035[222] = 0.0;
   out_128471273322292035[223] = 0.0;
   out_128471273322292035[224] = 0.0;
   out_128471273322292035[225] = 0.0;
   out_128471273322292035[226] = 0.0;
   out_128471273322292035[227] = 0.0;
   out_128471273322292035[228] = 1.0;
   out_128471273322292035[229] = 0.0;
   out_128471273322292035[230] = 0.0;
   out_128471273322292035[231] = 0.0;
   out_128471273322292035[232] = 0.0;
   out_128471273322292035[233] = 0.0;
   out_128471273322292035[234] = 0.0;
   out_128471273322292035[235] = 0.0;
   out_128471273322292035[236] = 0.0;
   out_128471273322292035[237] = 0.0;
   out_128471273322292035[238] = 0.0;
   out_128471273322292035[239] = 0.0;
   out_128471273322292035[240] = 0.0;
   out_128471273322292035[241] = 0.0;
   out_128471273322292035[242] = 0.0;
   out_128471273322292035[243] = 0.0;
   out_128471273322292035[244] = 0.0;
   out_128471273322292035[245] = 0.0;
   out_128471273322292035[246] = 0.0;
   out_128471273322292035[247] = 1.0;
   out_128471273322292035[248] = 0.0;
   out_128471273322292035[249] = 0.0;
   out_128471273322292035[250] = 0.0;
   out_128471273322292035[251] = 0.0;
   out_128471273322292035[252] = 0.0;
   out_128471273322292035[253] = 0.0;
   out_128471273322292035[254] = 0.0;
   out_128471273322292035[255] = 0.0;
   out_128471273322292035[256] = 0.0;
   out_128471273322292035[257] = 0.0;
   out_128471273322292035[258] = 0.0;
   out_128471273322292035[259] = 0.0;
   out_128471273322292035[260] = 0.0;
   out_128471273322292035[261] = 0.0;
   out_128471273322292035[262] = 0.0;
   out_128471273322292035[263] = 0.0;
   out_128471273322292035[264] = 0.0;
   out_128471273322292035[265] = 0.0;
   out_128471273322292035[266] = 1.0;
   out_128471273322292035[267] = 0.0;
   out_128471273322292035[268] = 0.0;
   out_128471273322292035[269] = 0.0;
   out_128471273322292035[270] = 0.0;
   out_128471273322292035[271] = 0.0;
   out_128471273322292035[272] = 0.0;
   out_128471273322292035[273] = 0.0;
   out_128471273322292035[274] = 0.0;
   out_128471273322292035[275] = 0.0;
   out_128471273322292035[276] = 0.0;
   out_128471273322292035[277] = 0.0;
   out_128471273322292035[278] = 0.0;
   out_128471273322292035[279] = 0.0;
   out_128471273322292035[280] = 0.0;
   out_128471273322292035[281] = 0.0;
   out_128471273322292035[282] = 0.0;
   out_128471273322292035[283] = 0.0;
   out_128471273322292035[284] = 0.0;
   out_128471273322292035[285] = 1.0;
   out_128471273322292035[286] = 0.0;
   out_128471273322292035[287] = 0.0;
   out_128471273322292035[288] = 0.0;
   out_128471273322292035[289] = 0.0;
   out_128471273322292035[290] = 0.0;
   out_128471273322292035[291] = 0.0;
   out_128471273322292035[292] = 0.0;
   out_128471273322292035[293] = 0.0;
   out_128471273322292035[294] = 0.0;
   out_128471273322292035[295] = 0.0;
   out_128471273322292035[296] = 0.0;
   out_128471273322292035[297] = 0.0;
   out_128471273322292035[298] = 0.0;
   out_128471273322292035[299] = 0.0;
   out_128471273322292035[300] = 0.0;
   out_128471273322292035[301] = 0.0;
   out_128471273322292035[302] = 0.0;
   out_128471273322292035[303] = 0.0;
   out_128471273322292035[304] = 1.0;
   out_128471273322292035[305] = 0.0;
   out_128471273322292035[306] = 0.0;
   out_128471273322292035[307] = 0.0;
   out_128471273322292035[308] = 0.0;
   out_128471273322292035[309] = 0.0;
   out_128471273322292035[310] = 0.0;
   out_128471273322292035[311] = 0.0;
   out_128471273322292035[312] = 0.0;
   out_128471273322292035[313] = 0.0;
   out_128471273322292035[314] = 0.0;
   out_128471273322292035[315] = 0.0;
   out_128471273322292035[316] = 0.0;
   out_128471273322292035[317] = 0.0;
   out_128471273322292035[318] = 0.0;
   out_128471273322292035[319] = 0.0;
   out_128471273322292035[320] = 0.0;
   out_128471273322292035[321] = 0.0;
   out_128471273322292035[322] = 0.0;
   out_128471273322292035[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_188652859594172953) {
   out_188652859594172953[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_188652859594172953[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_188652859594172953[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_188652859594172953[3] = dt*state[12] + state[3];
   out_188652859594172953[4] = dt*state[13] + state[4];
   out_188652859594172953[5] = dt*state[14] + state[5];
   out_188652859594172953[6] = state[6];
   out_188652859594172953[7] = state[7];
   out_188652859594172953[8] = state[8];
   out_188652859594172953[9] = state[9];
   out_188652859594172953[10] = state[10];
   out_188652859594172953[11] = state[11];
   out_188652859594172953[12] = state[12];
   out_188652859594172953[13] = state[13];
   out_188652859594172953[14] = state[14];
   out_188652859594172953[15] = state[15];
   out_188652859594172953[16] = state[16];
   out_188652859594172953[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4781680299052032321) {
   out_4781680299052032321[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4781680299052032321[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4781680299052032321[2] = 0;
   out_4781680299052032321[3] = 0;
   out_4781680299052032321[4] = 0;
   out_4781680299052032321[5] = 0;
   out_4781680299052032321[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4781680299052032321[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4781680299052032321[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4781680299052032321[9] = 0;
   out_4781680299052032321[10] = 0;
   out_4781680299052032321[11] = 0;
   out_4781680299052032321[12] = 0;
   out_4781680299052032321[13] = 0;
   out_4781680299052032321[14] = 0;
   out_4781680299052032321[15] = 0;
   out_4781680299052032321[16] = 0;
   out_4781680299052032321[17] = 0;
   out_4781680299052032321[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4781680299052032321[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4781680299052032321[20] = 0;
   out_4781680299052032321[21] = 0;
   out_4781680299052032321[22] = 0;
   out_4781680299052032321[23] = 0;
   out_4781680299052032321[24] = 0;
   out_4781680299052032321[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4781680299052032321[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4781680299052032321[27] = 0;
   out_4781680299052032321[28] = 0;
   out_4781680299052032321[29] = 0;
   out_4781680299052032321[30] = 0;
   out_4781680299052032321[31] = 0;
   out_4781680299052032321[32] = 0;
   out_4781680299052032321[33] = 0;
   out_4781680299052032321[34] = 0;
   out_4781680299052032321[35] = 0;
   out_4781680299052032321[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4781680299052032321[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4781680299052032321[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4781680299052032321[39] = 0;
   out_4781680299052032321[40] = 0;
   out_4781680299052032321[41] = 0;
   out_4781680299052032321[42] = 0;
   out_4781680299052032321[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4781680299052032321[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4781680299052032321[45] = 0;
   out_4781680299052032321[46] = 0;
   out_4781680299052032321[47] = 0;
   out_4781680299052032321[48] = 0;
   out_4781680299052032321[49] = 0;
   out_4781680299052032321[50] = 0;
   out_4781680299052032321[51] = 0;
   out_4781680299052032321[52] = 0;
   out_4781680299052032321[53] = 0;
   out_4781680299052032321[54] = 0;
   out_4781680299052032321[55] = 0;
   out_4781680299052032321[56] = 0;
   out_4781680299052032321[57] = 1;
   out_4781680299052032321[58] = 0;
   out_4781680299052032321[59] = 0;
   out_4781680299052032321[60] = 0;
   out_4781680299052032321[61] = 0;
   out_4781680299052032321[62] = 0;
   out_4781680299052032321[63] = 0;
   out_4781680299052032321[64] = 0;
   out_4781680299052032321[65] = 0;
   out_4781680299052032321[66] = dt;
   out_4781680299052032321[67] = 0;
   out_4781680299052032321[68] = 0;
   out_4781680299052032321[69] = 0;
   out_4781680299052032321[70] = 0;
   out_4781680299052032321[71] = 0;
   out_4781680299052032321[72] = 0;
   out_4781680299052032321[73] = 0;
   out_4781680299052032321[74] = 0;
   out_4781680299052032321[75] = 0;
   out_4781680299052032321[76] = 1;
   out_4781680299052032321[77] = 0;
   out_4781680299052032321[78] = 0;
   out_4781680299052032321[79] = 0;
   out_4781680299052032321[80] = 0;
   out_4781680299052032321[81] = 0;
   out_4781680299052032321[82] = 0;
   out_4781680299052032321[83] = 0;
   out_4781680299052032321[84] = 0;
   out_4781680299052032321[85] = dt;
   out_4781680299052032321[86] = 0;
   out_4781680299052032321[87] = 0;
   out_4781680299052032321[88] = 0;
   out_4781680299052032321[89] = 0;
   out_4781680299052032321[90] = 0;
   out_4781680299052032321[91] = 0;
   out_4781680299052032321[92] = 0;
   out_4781680299052032321[93] = 0;
   out_4781680299052032321[94] = 0;
   out_4781680299052032321[95] = 1;
   out_4781680299052032321[96] = 0;
   out_4781680299052032321[97] = 0;
   out_4781680299052032321[98] = 0;
   out_4781680299052032321[99] = 0;
   out_4781680299052032321[100] = 0;
   out_4781680299052032321[101] = 0;
   out_4781680299052032321[102] = 0;
   out_4781680299052032321[103] = 0;
   out_4781680299052032321[104] = dt;
   out_4781680299052032321[105] = 0;
   out_4781680299052032321[106] = 0;
   out_4781680299052032321[107] = 0;
   out_4781680299052032321[108] = 0;
   out_4781680299052032321[109] = 0;
   out_4781680299052032321[110] = 0;
   out_4781680299052032321[111] = 0;
   out_4781680299052032321[112] = 0;
   out_4781680299052032321[113] = 0;
   out_4781680299052032321[114] = 1;
   out_4781680299052032321[115] = 0;
   out_4781680299052032321[116] = 0;
   out_4781680299052032321[117] = 0;
   out_4781680299052032321[118] = 0;
   out_4781680299052032321[119] = 0;
   out_4781680299052032321[120] = 0;
   out_4781680299052032321[121] = 0;
   out_4781680299052032321[122] = 0;
   out_4781680299052032321[123] = 0;
   out_4781680299052032321[124] = 0;
   out_4781680299052032321[125] = 0;
   out_4781680299052032321[126] = 0;
   out_4781680299052032321[127] = 0;
   out_4781680299052032321[128] = 0;
   out_4781680299052032321[129] = 0;
   out_4781680299052032321[130] = 0;
   out_4781680299052032321[131] = 0;
   out_4781680299052032321[132] = 0;
   out_4781680299052032321[133] = 1;
   out_4781680299052032321[134] = 0;
   out_4781680299052032321[135] = 0;
   out_4781680299052032321[136] = 0;
   out_4781680299052032321[137] = 0;
   out_4781680299052032321[138] = 0;
   out_4781680299052032321[139] = 0;
   out_4781680299052032321[140] = 0;
   out_4781680299052032321[141] = 0;
   out_4781680299052032321[142] = 0;
   out_4781680299052032321[143] = 0;
   out_4781680299052032321[144] = 0;
   out_4781680299052032321[145] = 0;
   out_4781680299052032321[146] = 0;
   out_4781680299052032321[147] = 0;
   out_4781680299052032321[148] = 0;
   out_4781680299052032321[149] = 0;
   out_4781680299052032321[150] = 0;
   out_4781680299052032321[151] = 0;
   out_4781680299052032321[152] = 1;
   out_4781680299052032321[153] = 0;
   out_4781680299052032321[154] = 0;
   out_4781680299052032321[155] = 0;
   out_4781680299052032321[156] = 0;
   out_4781680299052032321[157] = 0;
   out_4781680299052032321[158] = 0;
   out_4781680299052032321[159] = 0;
   out_4781680299052032321[160] = 0;
   out_4781680299052032321[161] = 0;
   out_4781680299052032321[162] = 0;
   out_4781680299052032321[163] = 0;
   out_4781680299052032321[164] = 0;
   out_4781680299052032321[165] = 0;
   out_4781680299052032321[166] = 0;
   out_4781680299052032321[167] = 0;
   out_4781680299052032321[168] = 0;
   out_4781680299052032321[169] = 0;
   out_4781680299052032321[170] = 0;
   out_4781680299052032321[171] = 1;
   out_4781680299052032321[172] = 0;
   out_4781680299052032321[173] = 0;
   out_4781680299052032321[174] = 0;
   out_4781680299052032321[175] = 0;
   out_4781680299052032321[176] = 0;
   out_4781680299052032321[177] = 0;
   out_4781680299052032321[178] = 0;
   out_4781680299052032321[179] = 0;
   out_4781680299052032321[180] = 0;
   out_4781680299052032321[181] = 0;
   out_4781680299052032321[182] = 0;
   out_4781680299052032321[183] = 0;
   out_4781680299052032321[184] = 0;
   out_4781680299052032321[185] = 0;
   out_4781680299052032321[186] = 0;
   out_4781680299052032321[187] = 0;
   out_4781680299052032321[188] = 0;
   out_4781680299052032321[189] = 0;
   out_4781680299052032321[190] = 1;
   out_4781680299052032321[191] = 0;
   out_4781680299052032321[192] = 0;
   out_4781680299052032321[193] = 0;
   out_4781680299052032321[194] = 0;
   out_4781680299052032321[195] = 0;
   out_4781680299052032321[196] = 0;
   out_4781680299052032321[197] = 0;
   out_4781680299052032321[198] = 0;
   out_4781680299052032321[199] = 0;
   out_4781680299052032321[200] = 0;
   out_4781680299052032321[201] = 0;
   out_4781680299052032321[202] = 0;
   out_4781680299052032321[203] = 0;
   out_4781680299052032321[204] = 0;
   out_4781680299052032321[205] = 0;
   out_4781680299052032321[206] = 0;
   out_4781680299052032321[207] = 0;
   out_4781680299052032321[208] = 0;
   out_4781680299052032321[209] = 1;
   out_4781680299052032321[210] = 0;
   out_4781680299052032321[211] = 0;
   out_4781680299052032321[212] = 0;
   out_4781680299052032321[213] = 0;
   out_4781680299052032321[214] = 0;
   out_4781680299052032321[215] = 0;
   out_4781680299052032321[216] = 0;
   out_4781680299052032321[217] = 0;
   out_4781680299052032321[218] = 0;
   out_4781680299052032321[219] = 0;
   out_4781680299052032321[220] = 0;
   out_4781680299052032321[221] = 0;
   out_4781680299052032321[222] = 0;
   out_4781680299052032321[223] = 0;
   out_4781680299052032321[224] = 0;
   out_4781680299052032321[225] = 0;
   out_4781680299052032321[226] = 0;
   out_4781680299052032321[227] = 0;
   out_4781680299052032321[228] = 1;
   out_4781680299052032321[229] = 0;
   out_4781680299052032321[230] = 0;
   out_4781680299052032321[231] = 0;
   out_4781680299052032321[232] = 0;
   out_4781680299052032321[233] = 0;
   out_4781680299052032321[234] = 0;
   out_4781680299052032321[235] = 0;
   out_4781680299052032321[236] = 0;
   out_4781680299052032321[237] = 0;
   out_4781680299052032321[238] = 0;
   out_4781680299052032321[239] = 0;
   out_4781680299052032321[240] = 0;
   out_4781680299052032321[241] = 0;
   out_4781680299052032321[242] = 0;
   out_4781680299052032321[243] = 0;
   out_4781680299052032321[244] = 0;
   out_4781680299052032321[245] = 0;
   out_4781680299052032321[246] = 0;
   out_4781680299052032321[247] = 1;
   out_4781680299052032321[248] = 0;
   out_4781680299052032321[249] = 0;
   out_4781680299052032321[250] = 0;
   out_4781680299052032321[251] = 0;
   out_4781680299052032321[252] = 0;
   out_4781680299052032321[253] = 0;
   out_4781680299052032321[254] = 0;
   out_4781680299052032321[255] = 0;
   out_4781680299052032321[256] = 0;
   out_4781680299052032321[257] = 0;
   out_4781680299052032321[258] = 0;
   out_4781680299052032321[259] = 0;
   out_4781680299052032321[260] = 0;
   out_4781680299052032321[261] = 0;
   out_4781680299052032321[262] = 0;
   out_4781680299052032321[263] = 0;
   out_4781680299052032321[264] = 0;
   out_4781680299052032321[265] = 0;
   out_4781680299052032321[266] = 1;
   out_4781680299052032321[267] = 0;
   out_4781680299052032321[268] = 0;
   out_4781680299052032321[269] = 0;
   out_4781680299052032321[270] = 0;
   out_4781680299052032321[271] = 0;
   out_4781680299052032321[272] = 0;
   out_4781680299052032321[273] = 0;
   out_4781680299052032321[274] = 0;
   out_4781680299052032321[275] = 0;
   out_4781680299052032321[276] = 0;
   out_4781680299052032321[277] = 0;
   out_4781680299052032321[278] = 0;
   out_4781680299052032321[279] = 0;
   out_4781680299052032321[280] = 0;
   out_4781680299052032321[281] = 0;
   out_4781680299052032321[282] = 0;
   out_4781680299052032321[283] = 0;
   out_4781680299052032321[284] = 0;
   out_4781680299052032321[285] = 1;
   out_4781680299052032321[286] = 0;
   out_4781680299052032321[287] = 0;
   out_4781680299052032321[288] = 0;
   out_4781680299052032321[289] = 0;
   out_4781680299052032321[290] = 0;
   out_4781680299052032321[291] = 0;
   out_4781680299052032321[292] = 0;
   out_4781680299052032321[293] = 0;
   out_4781680299052032321[294] = 0;
   out_4781680299052032321[295] = 0;
   out_4781680299052032321[296] = 0;
   out_4781680299052032321[297] = 0;
   out_4781680299052032321[298] = 0;
   out_4781680299052032321[299] = 0;
   out_4781680299052032321[300] = 0;
   out_4781680299052032321[301] = 0;
   out_4781680299052032321[302] = 0;
   out_4781680299052032321[303] = 0;
   out_4781680299052032321[304] = 1;
   out_4781680299052032321[305] = 0;
   out_4781680299052032321[306] = 0;
   out_4781680299052032321[307] = 0;
   out_4781680299052032321[308] = 0;
   out_4781680299052032321[309] = 0;
   out_4781680299052032321[310] = 0;
   out_4781680299052032321[311] = 0;
   out_4781680299052032321[312] = 0;
   out_4781680299052032321[313] = 0;
   out_4781680299052032321[314] = 0;
   out_4781680299052032321[315] = 0;
   out_4781680299052032321[316] = 0;
   out_4781680299052032321[317] = 0;
   out_4781680299052032321[318] = 0;
   out_4781680299052032321[319] = 0;
   out_4781680299052032321[320] = 0;
   out_4781680299052032321[321] = 0;
   out_4781680299052032321[322] = 0;
   out_4781680299052032321[323] = 1;
}
void h_4(double *state, double *unused, double *out_8500877248821780926) {
   out_8500877248821780926[0] = state[6] + state[9];
   out_8500877248821780926[1] = state[7] + state[10];
   out_8500877248821780926[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_882632275377004642) {
   out_882632275377004642[0] = 0;
   out_882632275377004642[1] = 0;
   out_882632275377004642[2] = 0;
   out_882632275377004642[3] = 0;
   out_882632275377004642[4] = 0;
   out_882632275377004642[5] = 0;
   out_882632275377004642[6] = 1;
   out_882632275377004642[7] = 0;
   out_882632275377004642[8] = 0;
   out_882632275377004642[9] = 1;
   out_882632275377004642[10] = 0;
   out_882632275377004642[11] = 0;
   out_882632275377004642[12] = 0;
   out_882632275377004642[13] = 0;
   out_882632275377004642[14] = 0;
   out_882632275377004642[15] = 0;
   out_882632275377004642[16] = 0;
   out_882632275377004642[17] = 0;
   out_882632275377004642[18] = 0;
   out_882632275377004642[19] = 0;
   out_882632275377004642[20] = 0;
   out_882632275377004642[21] = 0;
   out_882632275377004642[22] = 0;
   out_882632275377004642[23] = 0;
   out_882632275377004642[24] = 0;
   out_882632275377004642[25] = 1;
   out_882632275377004642[26] = 0;
   out_882632275377004642[27] = 0;
   out_882632275377004642[28] = 1;
   out_882632275377004642[29] = 0;
   out_882632275377004642[30] = 0;
   out_882632275377004642[31] = 0;
   out_882632275377004642[32] = 0;
   out_882632275377004642[33] = 0;
   out_882632275377004642[34] = 0;
   out_882632275377004642[35] = 0;
   out_882632275377004642[36] = 0;
   out_882632275377004642[37] = 0;
   out_882632275377004642[38] = 0;
   out_882632275377004642[39] = 0;
   out_882632275377004642[40] = 0;
   out_882632275377004642[41] = 0;
   out_882632275377004642[42] = 0;
   out_882632275377004642[43] = 0;
   out_882632275377004642[44] = 1;
   out_882632275377004642[45] = 0;
   out_882632275377004642[46] = 0;
   out_882632275377004642[47] = 1;
   out_882632275377004642[48] = 0;
   out_882632275377004642[49] = 0;
   out_882632275377004642[50] = 0;
   out_882632275377004642[51] = 0;
   out_882632275377004642[52] = 0;
   out_882632275377004642[53] = 0;
}
void h_10(double *state, double *unused, double *out_129882769792186245) {
   out_129882769792186245[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_129882769792186245[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_129882769792186245[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8952108773135808839) {
   out_8952108773135808839[0] = 0;
   out_8952108773135808839[1] = 9.8100000000000005*cos(state[1]);
   out_8952108773135808839[2] = 0;
   out_8952108773135808839[3] = 0;
   out_8952108773135808839[4] = -state[8];
   out_8952108773135808839[5] = state[7];
   out_8952108773135808839[6] = 0;
   out_8952108773135808839[7] = state[5];
   out_8952108773135808839[8] = -state[4];
   out_8952108773135808839[9] = 0;
   out_8952108773135808839[10] = 0;
   out_8952108773135808839[11] = 0;
   out_8952108773135808839[12] = 1;
   out_8952108773135808839[13] = 0;
   out_8952108773135808839[14] = 0;
   out_8952108773135808839[15] = 1;
   out_8952108773135808839[16] = 0;
   out_8952108773135808839[17] = 0;
   out_8952108773135808839[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8952108773135808839[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8952108773135808839[20] = 0;
   out_8952108773135808839[21] = state[8];
   out_8952108773135808839[22] = 0;
   out_8952108773135808839[23] = -state[6];
   out_8952108773135808839[24] = -state[5];
   out_8952108773135808839[25] = 0;
   out_8952108773135808839[26] = state[3];
   out_8952108773135808839[27] = 0;
   out_8952108773135808839[28] = 0;
   out_8952108773135808839[29] = 0;
   out_8952108773135808839[30] = 0;
   out_8952108773135808839[31] = 1;
   out_8952108773135808839[32] = 0;
   out_8952108773135808839[33] = 0;
   out_8952108773135808839[34] = 1;
   out_8952108773135808839[35] = 0;
   out_8952108773135808839[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8952108773135808839[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8952108773135808839[38] = 0;
   out_8952108773135808839[39] = -state[7];
   out_8952108773135808839[40] = state[6];
   out_8952108773135808839[41] = 0;
   out_8952108773135808839[42] = state[4];
   out_8952108773135808839[43] = -state[3];
   out_8952108773135808839[44] = 0;
   out_8952108773135808839[45] = 0;
   out_8952108773135808839[46] = 0;
   out_8952108773135808839[47] = 0;
   out_8952108773135808839[48] = 0;
   out_8952108773135808839[49] = 0;
   out_8952108773135808839[50] = 1;
   out_8952108773135808839[51] = 0;
   out_8952108773135808839[52] = 0;
   out_8952108773135808839[53] = 1;
}
void h_13(double *state, double *unused, double *out_3365336184021117032) {
   out_3365336184021117032[0] = state[3];
   out_3365336184021117032[1] = state[4];
   out_3365336184021117032[2] = state[5];
}
void H_13(double *state, double *unused, double *out_8493263483693705571) {
   out_8493263483693705571[0] = 0;
   out_8493263483693705571[1] = 0;
   out_8493263483693705571[2] = 0;
   out_8493263483693705571[3] = 1;
   out_8493263483693705571[4] = 0;
   out_8493263483693705571[5] = 0;
   out_8493263483693705571[6] = 0;
   out_8493263483693705571[7] = 0;
   out_8493263483693705571[8] = 0;
   out_8493263483693705571[9] = 0;
   out_8493263483693705571[10] = 0;
   out_8493263483693705571[11] = 0;
   out_8493263483693705571[12] = 0;
   out_8493263483693705571[13] = 0;
   out_8493263483693705571[14] = 0;
   out_8493263483693705571[15] = 0;
   out_8493263483693705571[16] = 0;
   out_8493263483693705571[17] = 0;
   out_8493263483693705571[18] = 0;
   out_8493263483693705571[19] = 0;
   out_8493263483693705571[20] = 0;
   out_8493263483693705571[21] = 0;
   out_8493263483693705571[22] = 1;
   out_8493263483693705571[23] = 0;
   out_8493263483693705571[24] = 0;
   out_8493263483693705571[25] = 0;
   out_8493263483693705571[26] = 0;
   out_8493263483693705571[27] = 0;
   out_8493263483693705571[28] = 0;
   out_8493263483693705571[29] = 0;
   out_8493263483693705571[30] = 0;
   out_8493263483693705571[31] = 0;
   out_8493263483693705571[32] = 0;
   out_8493263483693705571[33] = 0;
   out_8493263483693705571[34] = 0;
   out_8493263483693705571[35] = 0;
   out_8493263483693705571[36] = 0;
   out_8493263483693705571[37] = 0;
   out_8493263483693705571[38] = 0;
   out_8493263483693705571[39] = 0;
   out_8493263483693705571[40] = 0;
   out_8493263483693705571[41] = 1;
   out_8493263483693705571[42] = 0;
   out_8493263483693705571[43] = 0;
   out_8493263483693705571[44] = 0;
   out_8493263483693705571[45] = 0;
   out_8493263483693705571[46] = 0;
   out_8493263483693705571[47] = 0;
   out_8493263483693705571[48] = 0;
   out_8493263483693705571[49] = 0;
   out_8493263483693705571[50] = 0;
   out_8493263483693705571[51] = 0;
   out_8493263483693705571[52] = 0;
   out_8493263483693705571[53] = 0;
}
void h_14(double *state, double *unused, double *out_2948924321739108136) {
   out_2948924321739108136[0] = state[6];
   out_2948924321739108136[1] = state[7];
   out_2948924321739108136[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4845873131716489171) {
   out_4845873131716489171[0] = 0;
   out_4845873131716489171[1] = 0;
   out_4845873131716489171[2] = 0;
   out_4845873131716489171[3] = 0;
   out_4845873131716489171[4] = 0;
   out_4845873131716489171[5] = 0;
   out_4845873131716489171[6] = 1;
   out_4845873131716489171[7] = 0;
   out_4845873131716489171[8] = 0;
   out_4845873131716489171[9] = 0;
   out_4845873131716489171[10] = 0;
   out_4845873131716489171[11] = 0;
   out_4845873131716489171[12] = 0;
   out_4845873131716489171[13] = 0;
   out_4845873131716489171[14] = 0;
   out_4845873131716489171[15] = 0;
   out_4845873131716489171[16] = 0;
   out_4845873131716489171[17] = 0;
   out_4845873131716489171[18] = 0;
   out_4845873131716489171[19] = 0;
   out_4845873131716489171[20] = 0;
   out_4845873131716489171[21] = 0;
   out_4845873131716489171[22] = 0;
   out_4845873131716489171[23] = 0;
   out_4845873131716489171[24] = 0;
   out_4845873131716489171[25] = 1;
   out_4845873131716489171[26] = 0;
   out_4845873131716489171[27] = 0;
   out_4845873131716489171[28] = 0;
   out_4845873131716489171[29] = 0;
   out_4845873131716489171[30] = 0;
   out_4845873131716489171[31] = 0;
   out_4845873131716489171[32] = 0;
   out_4845873131716489171[33] = 0;
   out_4845873131716489171[34] = 0;
   out_4845873131716489171[35] = 0;
   out_4845873131716489171[36] = 0;
   out_4845873131716489171[37] = 0;
   out_4845873131716489171[38] = 0;
   out_4845873131716489171[39] = 0;
   out_4845873131716489171[40] = 0;
   out_4845873131716489171[41] = 0;
   out_4845873131716489171[42] = 0;
   out_4845873131716489171[43] = 0;
   out_4845873131716489171[44] = 1;
   out_4845873131716489171[45] = 0;
   out_4845873131716489171[46] = 0;
   out_4845873131716489171[47] = 0;
   out_4845873131716489171[48] = 0;
   out_4845873131716489171[49] = 0;
   out_4845873131716489171[50] = 0;
   out_4845873131716489171[51] = 0;
   out_4845873131716489171[52] = 0;
   out_4845873131716489171[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_4645079504083643561) {
  err_fun(nom_x, delta_x, out_4645079504083643561);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8420684883175596638) {
  inv_err_fun(nom_x, true_x, out_8420684883175596638);
}
void pose_H_mod_fun(double *state, double *out_128471273322292035) {
  H_mod_fun(state, out_128471273322292035);
}
void pose_f_fun(double *state, double dt, double *out_188652859594172953) {
  f_fun(state,  dt, out_188652859594172953);
}
void pose_F_fun(double *state, double dt, double *out_4781680299052032321) {
  F_fun(state,  dt, out_4781680299052032321);
}
void pose_h_4(double *state, double *unused, double *out_8500877248821780926) {
  h_4(state, unused, out_8500877248821780926);
}
void pose_H_4(double *state, double *unused, double *out_882632275377004642) {
  H_4(state, unused, out_882632275377004642);
}
void pose_h_10(double *state, double *unused, double *out_129882769792186245) {
  h_10(state, unused, out_129882769792186245);
}
void pose_H_10(double *state, double *unused, double *out_8952108773135808839) {
  H_10(state, unused, out_8952108773135808839);
}
void pose_h_13(double *state, double *unused, double *out_3365336184021117032) {
  h_13(state, unused, out_3365336184021117032);
}
void pose_H_13(double *state, double *unused, double *out_8493263483693705571) {
  H_13(state, unused, out_8493263483693705571);
}
void pose_h_14(double *state, double *unused, double *out_2948924321739108136) {
  h_14(state, unused, out_2948924321739108136);
}
void pose_H_14(double *state, double *unused, double *out_4845873131716489171) {
  H_14(state, unused, out_4845873131716489171);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
