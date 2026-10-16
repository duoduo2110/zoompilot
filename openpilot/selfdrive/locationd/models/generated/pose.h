#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4645079504083643561);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8420684883175596638);
void pose_H_mod_fun(double *state, double *out_128471273322292035);
void pose_f_fun(double *state, double dt, double *out_188652859594172953);
void pose_F_fun(double *state, double dt, double *out_4781680299052032321);
void pose_h_4(double *state, double *unused, double *out_8500877248821780926);
void pose_H_4(double *state, double *unused, double *out_882632275377004642);
void pose_h_10(double *state, double *unused, double *out_129882769792186245);
void pose_H_10(double *state, double *unused, double *out_8952108773135808839);
void pose_h_13(double *state, double *unused, double *out_3365336184021117032);
void pose_H_13(double *state, double *unused, double *out_8493263483693705571);
void pose_h_14(double *state, double *unused, double *out_2948924321739108136);
void pose_H_14(double *state, double *unused, double *out_4845873131716489171);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}