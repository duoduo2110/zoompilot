#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_516126113711711650);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6452492328306863760);
void car_H_mod_fun(double *state, double *out_561367379597116933);
void car_f_fun(double *state, double dt, double *out_777691313942151638);
void car_F_fun(double *state, double dt, double *out_7802811861687659975);
void car_h_25(double *state, double *unused, double *out_2649276739528629921);
void car_H_25(double *state, double *unused, double *out_8631820846315120304);
void car_h_24(double *state, double *unused, double *out_4474589522987235323);
void car_H_24(double *state, double *unused, double *out_7642273628388931746);
void car_h_30(double *state, double *unused, double *out_1591893975104609062);
void car_H_30(double *state, double *unused, double *out_1715130504823503549);
void car_h_26(double *state, double *unused, double *out_2678620623461073389);
void car_H_26(double *state, double *unused, double *out_6073419908520375088);
void car_h_27(double *state, double *unused, double *out_5686062790972962606);
void car_H_27(double *state, double *unused, double *out_3889893816623928460);
void car_h_29(double *state, double *unused, double *out_2195209859781086579);
void car_H_29(double *state, double *unused, double *out_5603256543493479493);
void car_h_28(double *state, double *unused, double *out_6629572643874625041);
void car_H_28(double *state, double *unused, double *out_7761088513146541549);
void car_h_31(double *state, double *unused, double *out_4121558486821721015);
void car_H_31(double *state, double *unused, double *out_8601174884438159876);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}