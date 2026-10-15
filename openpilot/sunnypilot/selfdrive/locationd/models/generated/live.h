#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_6663532000035183071);
void live_err_fun(double *nom_x, double *delta_x, double *out_860087882369678370);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2871833341579702269);
void live_H_mod_fun(double *state, double *out_5528357984404481412);
void live_f_fun(double *state, double dt, double *out_4256228382502305421);
void live_F_fun(double *state, double dt, double *out_3448404805035501680);
void live_h_4(double *state, double *unused, double *out_2548226963345583965);
void live_H_4(double *state, double *unused, double *out_6528650590929638144);
void live_h_9(double *state, double *unused, double *out_6750778503528936286);
void live_H_9(double *state, double *unused, double *out_2371482854574860661);
void live_h_10(double *state, double *unused, double *out_7494778367666607458);
void live_H_10(double *state, double *unused, double *out_6598312574112292273);
void live_h_12(double *state, double *unused, double *out_5739223806255008822);
void live_H_12(double *state, double *unused, double *out_7149749615977231811);
void live_h_35(double *state, double *unused, double *out_5781354434259252800);
void live_H_35(double *state, double *unused, double *out_8551431425407306096);
void live_h_32(double *state, double *unused, double *out_1478367747997360046);
void live_H_32(double *state, double *unused, double *out_7008831225453791024);
void live_h_13(double *state, double *unused, double *out_4906027368706948218);
void live_H_13(double *state, double *unused, double *out_5769692696393044654);
void live_h_14(double *state, double *unused, double *out_6750778503528936286);
void live_H_14(double *state, double *unused, double *out_2371482854574860661);
void live_h_33(double *state, double *unused, double *out_2170623326770583108);
void live_H_33(double *state, double *unused, double *out_5400874420768448492);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}